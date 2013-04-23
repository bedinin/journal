drop procedure get_all_cross_name;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_all_cross_name`()
    COMMENT ''
BEGIN
	SELECT cross_name.id, cross_name.name FROM cross_name WHERE cross_name.del = TRUE;
END$$

delimiter ;