drop procedure check_crossing_flag_value;
-- 
delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `check_crossing_flag_value`(IN i_strafe TEXT,
																		IN i_plint TEXT,
																		IN i_pair TEXT,
																		IN i_strafe_prev TEXT,
																		IN i_plint_prev TEXT,
																		IN i_pair_prev TEXT,
																		OUT i_return TEXT)
BEGIN
	DECLARE constant_name TEXT;
	DECLARE val INT DEFAULT 0;
	DECLARE err INT DEFAULT 1;
	DECLARE v_strafe, 
			v_plint, 
			v_pair,
			v_flag_value TEXT;
	DECLARE v_return TEXT DEFAULT "NORMAL";
	DECLARE flag BOOL DEFAULT TRUE;
	DECLARE not_crossing BOOL DEFAULT TRUE;
	DECLARE cur_select_this CURSOR FOR SELECT 	crossing.prev_strafe, 
												crossing.prev_plint, 
												crossing.prev_pair,
												data.flag_value
									FROM 	crossing,data 
									WHERE 	(
												(
													(
														crossing.this_strafe = i_strafe AND 
														crossing.this_plint = i_plint AND  
														crossing.this_pair = i_pair
													) AND
													NOT (
														crossing.prev_strafe = i_strafe_prev AND 
														crossing.prev_plint = i_plint_prev AND  
														crossing.prev_pair = i_pair_prev
													) AND
													(
														data.strafe = i_strafe AND 
														data.plint = i_plint AND 
														data.pair = i_pair
													)
												) -- OR 
-- 												(
-- 													data.strafe = i_strafe AND 
-- 													data.plint = i_plint AND 
-- 													data.pair = i_pair
-- 												)
											) AND 
											data.del = TRUE;
	
	DECLARE cur_select_prev CURSOR FOR SELECT 	crossing.this_strafe, 
												crossing.this_plint, 
												crossing.this_pair,
												data.flag_value
									FROM 	crossing,data 
									WHERE 	(
												(
													(
														crossing.prev_strafe = i_strafe AND 
														crossing.prev_plint = i_plint AND  
														crossing.prev_pair = i_pair
													) AND
													NOT(
														crossing.this_strafe = i_strafe_prev AND 
														crossing.this_plint = i_plint_prev AND  
														crossing.this_pair = i_pair_prev
													) AND
													(
														data.strafe = i_strafe AND 
														data.plint = i_plint AND 
														data.pair = i_pair
													)
												) -- OR 
-- 												(
-- 													data.strafe = i_strafe AND 
-- 													data.plint = i_plint AND 
-- 													data.pair = i_pair
-- 												)
											) AND 
											data.del = TRUE;
	
	DECLARE cur_select_not_crossing CURSOR FOR 	SELECT 	data.flag_value 
												FROM 	data 
												WHERE 	data.strafe = i_strafe AND 
														data.plint = i_plint AND 
														data.pair = i_pair AND 
														data.del = TRUE;

	DECLARE CONTINUE HANDLER FOR SQLSTATE "02000" SET err = 0;
	-- SELECT i_strafe,i_plint,i_pair,i_strafe_prev,i_plint_prev,i_pair_prev;
	OPEN cur_select_this;
	REPEAT
		FETCH cur_select_this INTO 	v_strafe, 
									v_plint, 
									v_pair,
									v_flag_value;

			-- SELECT 	v_strafe,v_plint, v_pair,
			 -- 		i_strafe, i_plint,i_pair,
			 -- 		val;
		IF (err = 1 AND v_return = "NORMAL")  THEN
		BEGIN
			SET not_crossing = FALSE;
			SELECT COUNT(data.id) INTO val 
			FROM data 
			WHERE 	(data.strafe = i_strafe AND 
					data.plint = i_plint AND 
					data.pair = i_pair AND 
					data.flag_value = TRUE AND 
					data.del = TRUE) OR
					(data.strafe = v_strafe AND 
					data.plint = v_plint AND 
					data.pair = v_pair AND 
					data.flag_value = TRUE AND 
					data.del = TRUE);
		
			IF (val > 0 ) THEN
			BEGIN
				SET err = 0;
				SET v_return = "ERROR_FLAG_VALUE_CROSSING";
			END;
			ELSE
			BEGIN
				CALL check_crossing_flag_value(v_strafe,v_plint, v_pair,
											i_strafe,i_plint, i_pair,
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
	SET val = 0;

	OPEN cur_select_prev;
	REPEAT
		FETCH cur_select_prev INTO 	v_strafe, 
									v_plint, 
									v_pair,
									v_flag_value;
		IF (err = 1 AND v_return = "NORMAL")  THEN
		BEGIN
			SET not_crossing = FALSE;
			SELECT COUNT(data.id) INTO val 
			FROM data 
			WHERE 	(data.strafe = i_strafe AND 
					data.plint = i_plint AND 
					data.pair = i_pair AND 
					data.flag_value = TRUE AND 
					data.del = TRUE) OR
					(data.strafe = v_strafe AND 
					data.plint = v_plint AND 
					data.pair = v_pair AND 
					data.flag_value = TRUE AND 
					data.del = TRUE);
		
			-- SELECT 	v_strafe,v_plint, v_pair,
			-- 		i_strafe, i_plint,i_pair,
			-- 		val;
			IF (val > 0 ) THEN
			BEGIN
				SET err = 0;
				SET v_return = "ERROR_FLAG_VALUE_CROSSING";
			END;
			ELSE
			BEGIN
				CALL check_crossing_flag_value(v_strafe,v_plint, v_pair,
											i_strafe,i_plint, i_pair,
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
	
	SET err = 1;

	IF (not_crossing = TRUE) THEN
	BEGIN
		OPEN cur_select_not_crossing;
		FETCH cur_select_not_crossing INTO v_flag_value;
		IF (err = 1)  THEN
		BEGIN
			IF (v_flag_value = TRUE) THEN
				SET v_return = "ERROR_FLAG_VALUE_CROSSING";
			END IF;
		END;
		END IF;
	END;
	END IF;




	SET i_return = v_return;
END$$

delimiter ;

