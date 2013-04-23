drop procedure get_group_name;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_group_name`(IN i_id INT)
    COMMENT ''
BEGIN
	SELECT group_name.id, group_name.name, group_name.color, group_name.comment FROM group_name WHERE group_name.id = i_id AND group_name.del = TRUE;
END$$

delimiter ;