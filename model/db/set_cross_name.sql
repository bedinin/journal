drop procedure set_cross_name;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `set_cross_name`(IN i_id INT, IN i_name TEXT)
    COMMENT ''
BEGIN
	DECLARE return_text TEXT;
	DECLARE val INT;
	DECLARE flag BOOL DEFAULT TRUE;

	call check_plint(i_id,i_name,return_text);
	SELECT COUNT(cross_name.id) INTO val FROM cross_name WHERE cross_name.id = i_id AND cross_name.del = TRUE;
	IF val = 0 AND flag THEN
	BEGIN
		SET return_text = "NOT_FOUND";
		SET flag = FALSE;
	END;
	END IF;
    	IF return_text = "NORMAL" THEN
    	BEGIN
    		UPDATE cross_name SET cross_name.name = i_name WHERE cross_name.id = i_id;
    	END;
	END IF;
	SELECT return_text;
END$$

delimiter ;