drop procedure delete_plint;
delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `delete_plint`(IN i_id INT)
    COMMENT ''
BEGIN
	DECLARE return_text TEXT DEFAULT "NORMAL"; 
	DECLARE val INT;
	DECLARE flag BOOL DEFAULT TRUE;

	IF return_text = "NORMAL" THEN
    BEGIN
    		UPDATE plint SET plint.del = FALSE WHERE plint.id = i_id;
    END;
	END IF;    
	SELECT return_text;
END$$

delimiter ;