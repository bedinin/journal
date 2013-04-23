drop procedure check_repeat_crossing;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `check_repeat_crossing`(IN i_strafe TEXT,IN i_plint TEXT,IN i_pair TEXT,
						IN i_strafe_prev_strafe TEXT,IN i_plint_prev_plint TEXT,IN i_pair_prev_pair TEXT,
                        IN i_cross_strafe TEXT,IN i_cross_plint TEXT,IN i_cross_pair TEXT,OUT i_return TEXT)
BEGIN
	DECLARE constant_name TEXT;
	DECLARE err INT DEFAULT 1;
	DECLARE v_strafe, 
			v_plint, 
			v_pair,
			v_prev_strafe, 
			v_prev_plint, 
			v_prev_pair TEXT;
	DECLARE v_return TEXT DEFAULT "NORMAL";
	DECLARE v_flag_value BOOL;
	DECLARE flag BOOL DEFAULT TRUE;
	DECLARE cur_select1 CURSOR FOR SELECT 	data.strafe, 
											data.plint, 
											data.pair,
											data.flag_value
									FROM data 
									WHERE 	((data.strafe = i_strafe AND 
											data.plint = i_plint AND  
											data.pair = i_pair) OR
											(data.prev_strafe = i_strafe AND 
											data.prev_plint = i_plint AND  
											data.prev_pair = i_pair) OR
											(data.strafe = i_strafe_prev_strafe AND 
											data.plint = i_plint_prev_plint AND  
											data.pair = i_pair_prev_pair AND
											i_strafe_prev_strafe != "-1" AND 
											i_plint_prev_plint != "-1" AND  
											i_pair_prev_pair != "-1")) AND
											data.del = TRUE;
	
	DECLARE cur_select2 CURSOR FOR SELECT 	data.prev_strafe, 
											data.prev_plint, 
											data.prev_pair
									FROM data 
									WHERE 	(data.strafe = v_strafe AND 
											data.plint = v_plint AND  
											data.pair = v_pair) AND
											data.del = TRUE;
	
	DECLARE CONTINUE HANDLER FOR SQLSTATE "02000" SET err = 0;
	
	OPEN cur_select1;
	REPEAT
		FETCH cur_select1 INTO 	v_strafe, 
								v_plint, 
								v_pair,
								v_flag_value;
		IF err = 1 THEN
		BEGIN
		-- SELECT 	i_strafe,i_plint, i_pair,
		-- 		i_strafe_prev_strafe, i_plint_prev_plint,i_pair_prev_pair,
         --        i_cross_strafe, i_cross_plint, i_cross_pair;
			IF (v_strafe = i_cross_strafe AND v_plint = i_cross_plint AND v_pair = i_cross_pair) THEN
			BEGIN
				SET err = 0;
				SET v_return = "ERROR_REPEAT_CROSSING";
			END;
			ELSE
			BEGIN
				IF v_flag_value = TRUE THEN
				BEGIN					
					SET err = 0;
					SET v_return = "ERROR_FLAG_VALUE_CROSSING";
				END;
				ELSE
				BEGIN
				IF (v_strafe != i_strafe AND v_plint != i_plint AND v_pair != i_pair) THEN
				BEGIN		
					-- SELECT 	v_strafe,v_plint, v_pair;
					OPEN cur_select2;
					FETCH cur_select2 INTO 	v_prev_strafe, 
											v_prev_plint, 
											v_prev_pair;
-- 					SELECT 	v_prev_strafe,v_prev_plint, v_prev_pair;
 					IF (v_strafe != v_prev_strafe AND v_plint != v_prev_plint AND v_pair != v_prev_pair AND err = 1) THEN
					BEGIN
						-- SELECT 	v_strafe,v_plint,v_pair,v_prev_strafe,v_prev_plint,v_prev_pair,i_cross_strafe,i_cross_plint,i_cross_pair;
						call check_repeat_crossing(v_strafe,v_plint,v_pair,v_prev_strafe,v_prev_plint,v_prev_pair,i_cross_strafe,i_cross_plint,i_cross_pair,v_return);
					END;
					END IF;
					CLOSE cur_select2;
					SET err = 1;
				END;
				END IF;	
				IF (v_return != "NORMAL") THEN
						SET err = 0;
					END IF;
				END;
				END IF;
			END;
			END IF;
		END;
		END IF;
	
	UNTIL err = 0 END REPEAT;
	CLOSE cur_select1;
	SET i_return = v_return;
END$$

delimiter ;

