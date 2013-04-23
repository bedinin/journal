DROP PROCEDURE set_crossing;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `set_crossing`(	IN i_strafe TEXT,IN i_plint TEXT,IN i_pair TEXT,
						IN i_prev_strafe TEXT,IN i_prev_plint TEXT,IN i_prev_pair TEXT)
    COMMENT 'Šà®áá¨à®¢ª '
BEGIN
	DECLARE flag BOOL DEFAULT TRUE;
	DECLARE constant_name, prev_constant_name TEXT;
	DECLARE return_text  TEXT DEFAULT "ERROR_SET_CROSSING";
	DECLARE val TEXT;
	DECLARE v_strafe, 
			v_plint, 
			v_pair TEXT;
	
	CALL check_null_data(i_strafe,i_plint,i_pair,i_prev_strafe,i_prev_plint,i_prev_pair,constant_name);
	IF (constant_name != "NORMAL" AND 
		flag = TRUE) THEN
	BEGIN
		SET flag = FALSE;
		SET return_text = constant_name;
	END;
	END IF;
	IF (flag = TRUE) THEN
		CALL check_crossing_connect(i_strafe,
									i_plint,
									i_pair,
									i_strafe,
									i_plint,
									i_pair,
									i_prev_strafe,
									i_prev_plint,
									i_prev_pair,
									constant_name);
	END IF;
	IF (constant_name != "NORMAL" AND 
		flag = TRUE) THEN
	BEGIN
		SET flag = FALSE;
		SET return_text = constant_name;
	END;
	END IF;
	IF (flag = TRUE) THEN
	BEGIN
		CALL check_crossing_flag_value(	i_strafe,
										i_plint,
										i_pair,
										i_strafe,
										i_plint,
										i_pair,
										constant_name);

		CALL check_crossing_flag_value(	i_prev_strafe,
										i_prev_plint,
										i_prev_pair,
										i_prev_strafe,
										i_prev_plint,
										i_prev_pair,
										prev_constant_name);
	END;
	END IF;
	-- SELECT constant_name,prev_constant_name;
	IF ((constant_name = "ERROR_FLAG_VALUE_CROSSING" AND 
		prev_constant_name = "ERROR_FLAG_VALUE_CROSSING") AND 
		flag = TRUE) THEN
	BEGIN
		-- SELECT 1;
		SET flag = FALSE;
		SET return_text = "ERROR_FLAG_VALUE_CROSSING";
	END;
	END IF;
	
	IF (((constant_name = "NORMAL" AND 
		prev_constant_name = "NORMAL") OR 
		(constant_name = "ERROR_FLAG_VALUE_CROSSING" AND 
		prev_constant_name = "NORMAL")) AND 
		flag = TRUE) THEN 
	BEGIN
		-- SELECT 2;
		SELECT 	data.value INTO val 
		FROM 	data 
		WHERE 	data.strafe=i_strafe AND 
    			data.plint = i_plint AND 
    			data.pair = i_pair;
		-- SELECT i_strafe,i_plint,i_pair,val;
		CALL update_crossing(	i_prev_strafe,
								i_prev_plint,
								i_prev_pair,
								i_prev_strafe,
								i_prev_plint,
								i_prev_pair,
								val);
		INSERT INTO crossing VALUES(NULL,i_strafe,i_plint,i_pair,i_prev_strafe,i_prev_plint,i_prev_pair);
		SET return_text = "NORMAL";
	END;
	END IF;

	IF ((constant_name = "NORMAL" AND 
		prev_constant_name = "ERROR_FLAG_VALUE_CROSSING") AND 
		flag = TRUE) THEN 
	BEGIN
		-- SELECT 3;
		SELECT 	data.value INTO val 
		FROM 	data 
		WHERE 	data.strafe=i_prev_strafe AND 
    			data.plint = i_prev_plint AND 
    			data.pair = i_prev_pair;
		CALL update_crossing(i_strafe,
								i_plint,
								i_pair,
								i_strafe,
								i_plint,
								i_pair,
								val);
		INSERT INTO crossing VALUES(NULL,i_strafe,i_plint,i_pair,i_prev_strafe,i_prev_plint,i_prev_pair);
		SET return_text = "NORMAL";
	END;
	END IF;

	-- SET constant_name = return_text;
	SELECT return_text;
	
END$$

delimiter ;