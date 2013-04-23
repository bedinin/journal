drop procedure update_crossing;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `update_crossing`(	IN i_strafe TEXT,
																IN i_plint TEXT,
																IN i_pair TEXT,
																IN i_strafe_prev TEXT,
																IN i_plint_prev TEXT,
																IN i_pair_prev TEXT,
																IN i_value TEXT)
BEGIN
	DECLARE err INT DEFAULT 1;
	DECLARE v_strafe, 
			v_plint, 
			v_pair TEXT;

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
	
	UPDATE 	data 
	SET 	data.value = i_value
	WHERE 	data.strafe=i_strafe AND 
			data.plint = i_plint AND 
			data.pair = i_pair; 
	OPEN cur_select_this;
	REPEAT
		FETCH cur_select_this INTO 	v_strafe, 
									v_plint, 
									v_pair;
		IF (err = 1)  THEN
		BEGIN
			CALL update_crossing(	v_strafe,v_plint, v_pair,
									i_strafe,i_plint, i_pair,
									i_value);
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
		IF (err = 1)  THEN
		BEGIN
			CALL update_crossing(	v_strafe,v_plint, v_pair,
									i_strafe,i_plint, i_pair,
									i_value);
		END;
		END IF;
	
	UNTIL err = 0 END REPEAT;
	CLOSE cur_select_prev;

END$$

delimiter ;

