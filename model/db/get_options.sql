drop procedure get_options;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_options`()
    COMMENT ''
BEGIN
	SELECT options.nameOptions, options.value FROM options;
END$$

delimiter ;