drop procedure set_group_name;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `set_group_name`(IN i_id INT, IN i_name TEXT, IN i_color TEXT, IN i_comment TEXT)
    COMMENT ''
BEGIN
	DECLARE return_text TEXT;
	DECLARE val INT;
	DECLARE flag BOOL DEFAULT TRUE;

	call check_group_name(i_id,i_name,return_text);
	SELECT COUNT(group_name.id) INTO val FROM group_name WHERE group_name.id = i_id AND group_name.del = TRUE;
	IF val = 0 AND flag THEN
	BEGIN
		SET return_text = "NOT_FOUND";
		SET flag = FALSE;
	END;
	END IF;
    	IF return_text = "NORMAL" THEN
    	BEGIN
    		UPDATE group_name SET group_name.name = i_name, group_name.color = i_color, group_name.comment = i_comment WHERE group_name.id = i_id;
    	END;
	END IF;
	SELECT return_text;
END$$

delimiter ;