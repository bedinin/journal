drop procedure get_data;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_data`(IN i_strafe INT)
    COMMENT ''
BEGIN
	DECLARE plint_count,pair_count;
	SELECT 	data.id,
		   	data.strafe,
			data.plint,
			data.pair,
			data.flag_value,
			data.value,
			data.ext_id,
			data.plint_name_id,
			data.group_id,
			data.comment
	FROM data
	WHERE data.strafe = i_strafe AND data.del = TRUE ORDER BY 	data.strafe ASC,
																data.plint ASC,
																data.pair ASC;
			
END$$

delimiter ;
