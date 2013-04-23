drop procedure get_plint;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_plint`(IN i_id INT)
    COMMENT ''
BEGIN
	SELECT plint.id, plint.name FROM plint WHERE plint.id = i_id AND plint.del = TRUE;
END$$

delimiter ;