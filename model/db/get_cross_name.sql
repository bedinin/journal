drop procedure get_cross_name;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_cross_name`(IN i_id INT)
    COMMENT ''
BEGIN
	SELECT cross_name.id, cross_name.name FROM cross_name WHERE cross_name.id = i_id AND cross_name.del = TRUE;
END$$

delimiter ;