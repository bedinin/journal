drop procedure get_all_group_name;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_all_group_name`()
    COMMENT ''
BEGIN
	SELECT group_name.id, group_name.name, group_name.color, group_name.comment FROM group_name WHERE group_name.del = TRUE;
END$$

delimiter ;