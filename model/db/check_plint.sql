drop procedure check_plint;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `check_plint`(IN i_id INT,IN i_name TEXT, OUT o_return TEXT)
    COMMENT ''
BEGIN
	DECLARE constant_name TEXT;
	DECLARE flag BOOL DEFAULT TRUE;
	DECLARE val INT DEFAULT 0;

	IF i_name = "" AND flag THEN
	BEGIN
		SET constant_name = "NAME_NOT_NULL";
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
		SELECT COUNT(plint.id) INTO val FROM plint WHERE plint.name = i_name AND plint.del = TRUE;
	END;
	ELSE
	BEGIN
		SELECT COUNT(plint.id) INTO val FROM plint WHERE plint.name = i_name AND plint.id != i_id AND plint.del = TRUE;
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