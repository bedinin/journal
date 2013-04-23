drop procedure add_plint;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `add_plint`(IN i_name TEXT)
    COMMENT ''
BEGIN
	DECLARE return_text TEXT;
	DECLARE return_id INT;

	call check_plint(-1,i_name,return_text);
    IF return_text = "NORMAL" THEN
    BEGIN
    	INSERT INTO plint VALUES(NULL,i_name,TRUE);
    	SET return_id = LAST_INSERT_ID();
        SELECT return_text, return_id;
    END;
    ELSE
	BEGIN
		SELECT return_text;
	END;
	END IF;
END$$

delimiter ;