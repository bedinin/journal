drop procedure add_group_name;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `add_group_name`(IN i_name TEXT, IN i_color TEXT, IN i_comment TEXT)
    COMMENT ''
BEGIN
	DECLARE return_text TEXT;
	DECLARE return_id INT;

	call check_group_name(-1,i_name,return_text);
    IF return_text = "NORMAL" THEN
    BEGIN
    	INSERT INTO group_name VALUES(NULL,i_name,i_color,i_comment,TRUE);
    	SET return_id = LAST_INSERT_ID();
        SELECT return_text, return_id;
    END;
    ELSE
	BEGIN
		SET return_id = -1;
		SELECT return_text, return_id;
	END;
	END IF;
END$$

delimiter ;
