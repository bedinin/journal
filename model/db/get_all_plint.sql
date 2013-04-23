drop procedure get_all_plint;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_all_plint`()
    COMMENT ''
BEGIN
	SELECT plint.id, plint.name FROM plint WHERE plint.del = TRUE;
END$$

delimiter ;