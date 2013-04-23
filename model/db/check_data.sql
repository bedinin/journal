drop procedure check_data;
delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `check_data`(IN i_id INT,
						IN i_strafe TEXT,						
						IN i_plint TEXT,						
						IN i_pair TEXT,
 						OUT o_return TEXT)
    COMMENT ''
BEGIN
	DECLARE constant_name TEXT;
	DECLARE flag BOOL DEFAULT TRUE;
	DECLARE val INT DEFAULT 0;

	IF (i_strafe = ""  OR i_plint = ""  OR i_pair = "") AND flag THEN
	BEGIN
		SET constant_name = "NOT_NULL";
		SET flag = FALSE;
	END;
	ELSE
	BEGIN
		IF flag THEN
			SET constant_name = "NORMAL";
		END IF;
	END;
	END IF;	
	

	IF i_id = -1 THEN
	BEGIN
		SELECT COUNT(data.id) INTO val FROM data WHERE data.pair = i_pair AND data.plint = i_plint AND data.strafe = i_strafe AND data.del = TRUE;
	END;
	ELSE
	BEGIN
		SELECT COUNT(data.id) INTO val FROM data WHERE data.pair = i_pair AND data.plint = i_plint AND data.strafe = i_strafe AND data.id != i_id AND data.del = TRUE;
	END;
	END IF;
	IF val > 0 AND flag THEN
	BEGIN
		SET constant_name = "NOT_REPEAT";
		SET flag = FALSE;
	END;
	ELSE
	BEGIN
		IF flag THEN
			SET constant_name = "NORMAL";
		END IF;
	END;
	END IF;
	SET o_return = constant_name;
END$$

delimiter ;
