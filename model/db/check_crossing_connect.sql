drop procedure check_crossing_connect;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `check_crossing_connect`(	IN i_strafe TEXT,
																		IN i_plint TEXT,
																		IN i_pair TEXT,
																		IN i_strafe_prev TEXT,
																		IN i_plint_prev TEXT,
																		IN i_pair_prev TEXT,
                        												IN i_cross_strafe TEXT,
																		IN i_cross_plint TEXT,
																		IN i_cross_pair TEXT,
																		OUT i_return TEXT)
BEGIN
	DECLARE constant_name TEXT;
	DECLARE err INT DEFAULT 1;
	DECLARE v_strafe, 
			v_plint, 
			v_pair TEXT;
	DECLARE v_return TEXT DEFAULT "NORMAL";
	DECLARE flag BOOL DEFAULT TRUE;
	DECLARE cur_select_this CURSOR FOR SELECT 	crossing.prev_strafe, 
												crossing.prev_plint, 
												crossing.prev_pair
									FROM 	crossing,data 
									WHERE 	(crossing.this_strafe = i_strafe AND 
											crossing.this_plint = i_plint AND  
											crossing.this_pair = i_pair) AND
											NOT(crossing.prev_strafe = i_strafe_prev AND 
											crossing.prev_plint = i_plint_prev AND  
											crossing.prev_pair = i_pair_prev) AND
											(data.strafe = i_strafe AND 
											data.plint = i_plint AND 
											data.pair = i_pair) AND 
											data.del = TRUE;
	
	DECLARE cur_select_prev CURSOR FOR SELECT 	crossing.this_strafe, 
												crossing.this_plint, 
												crossing.this_pair
									FROM 	crossing,data 
									WHERE 	(crossing.prev_strafe = i_strafe AND 
											crossing.prev_plint = i_plint AND  
											crossing.prev_pair = i_pair) AND
											NOT(crossing.this_strafe = i_strafe_prev AND 
											crossing.this_plint = i_plint_prev AND  
											crossing.this_pair = i_pair_prev) AND
											(data.strafe = i_strafe AND 
											data.plint = i_plint AND 
											data.pair = i_pair) AND 
											data.del = TRUE;
	
	DECLARE CONTINUE HANDLER FOR SQLSTATE "02000" SET err = 0;
	
	OPEN cur_select_this;
	REPEAT
		FETCH cur_select_this INTO 	v_strafe, 
									v_plint, 
									v_pair;
		IF (err = 1 AND v_return = "NORMAL")  THEN
		BEGIN
		-- SELECT 	v_strafe,v_plint, v_pair,
		-- 		i_strafe_prev, i_plint_prev,i_pair_prev,
        --         i_cross_strafe, i_cross_plint, i_cross_pair;
			IF (v_strafe = i_cross_strafe AND v_plint = i_cross_plint AND v_pair = i_cross_pair) THEN
			BEGIN
				SET err = 0;
				SET v_return = "ERROR_REPEAT_CROSSING";
			END;
			ELSE
			BEGIN
				CALL check_crossing_connect(v_strafe,v_plint, v_pair,
											i_strafe,i_plint, i_pair,
											i_cross_strafe, i_cross_plint, i_cross_pair,
											v_return);	
			END;
			END IF;
			
			IF (v_return != "NORMAL") THEN
				SET err = 0;
			END IF;
		END;
		END IF;
	
	UNTIL err = 0 END REPEAT;
	CLOSE cur_select_this;
	
	SET err = 1;

	OPEN cur_select_prev;
	REPEAT
		FETCH cur_select_prev INTO 	v_strafe, 
									v_plint, 
									v_pair;
		IF (err = 1 AND v_return = "NORMAL")  THEN
		BEGIN
		-- SELECT 	v_strafe,v_plint, v_pair,
		-- 		i_strafe_prev, i_plint_prev,i_pair_prev,
        --         i_cross_strafe, i_cross_plint, i_cross_pair;
			IF (v_strafe = i_cross_strafe AND v_plint = i_cross_plint AND v_pair = i_cross_pair) THEN
			BEGIN
				SET err = 0;
				SET v_return = "ERROR_REPEAT_CROSSING";
			END;
			ELSE
			BEGIN
				CALL check_crossing_connect(v_strafe,v_plint, v_pair,
											i_strafe,i_plint, i_pair,
											i_cross_strafe, i_cross_plint, i_cross_pair,
											v_return);	
			END;
			END IF;
			
			IF (v_return != "NORMAL") THEN
				SET err = 0;
			END IF;
		END;
		END IF;
	
	UNTIL err = 0 END REPEAT;
	CLOSE cur_select_prev;

	SET i_return = v_return;
END$$

delimiter ;

