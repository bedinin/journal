DROP PROCEDURE check_null_data;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `check_null_data`(	IN i_strafe TEXT,IN i_plint TEXT,IN i_pair TEXT,
						IN i_prev_strafe TEXT,IN i_prev_plint TEXT,IN i_prev_pair TEXT,
						OUT i_return TEXT)
    COMMENT ''
BEGIN
	DECLARE flag BOOL DEFAULT TRUE;
	DECLARE prev_count,
			this_count INT;
	DECLARE constant_name TEXT DEFAULT "NORMAL";
	SELECT COUNT(data.id) INTO this_count FROM data WHERE 	data.strafe = i_strafe AND 
											data.plint = i_plint AND 
											data.pair = i_pair AND 
											data.del = TRUE;
	SELECT COUNT(data.id) INTO prev_count FROM data WHERE 	data.strafe = i_prev_strafe AND 
											data.plint = i_prev_plint AND 
											data.pair = i_prev_pair AND 
											data.del = TRUE;
	IF (this_count = 0 OR prev_count = 0) THEN 
	BEGIN
		SET constant_name = "NOT_FOUND_DATA";
	END;
	ELSE
	BEGIN
		SET constant_name = "NORMAL";
	END;
	END IF;
	SET i_return = constant_name;
END$$

delimiter ;
