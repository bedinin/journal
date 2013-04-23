drop procedure set_plint;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `set_plint`(IN i_id INT, IN i_name TEXT)
    COMMENT ''
BEGIN
	DECLARE return_text TEXT;
	DECLARE val INT;
	DECLARE flag BOOL DEFAULT TRUE;

	call check_plint(i_id,i_name,return_text);
	SELECT COUNT(plint.id) INTO val FROM plint WHERE plint.id = i_id AND plint.del = TRUE;
	IF val = 0 AND flag THEN
	BEGIN
		SET return_text = "NOT_FOUND";
		SET flag = FALSE;
	END;
	END IF;
    	IF return_text = "NORMAL" THEN
    	BEGIN
    		UPDATE plint SET plint.name = i_name WHERE plint.id = i_id;
    	END;
	END IF;
	SELECT return_text;
END$$

delimiter ;