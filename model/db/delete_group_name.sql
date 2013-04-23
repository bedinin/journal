drop procedure delete_group_name;
delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `delete_group_name`(IN i_id INT)
    COMMENT ''
BEGIN
	DECLARE return_text TEXT DEFAULT "NORMAL"; 
	DECLARE val INT;
	DECLARE flag BOOL DEFAULT TRUE;

	IF return_text = "NORMAL" THEN
    BEGIN
    		UPDATE group_name SET group_name.del = FALSE WHERE group_name.id = i_id;
    END;
	END IF;    
	SELECT return_text;
END$$

delimiter ;