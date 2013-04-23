drop procedure set_data;
delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `set_data`(	IN i_id INT,
														IN i_strafe INT,
														IN i_plint INT,
														IN i_pair INT,
														IN i_flag_value BOOL,
														IN i_value TEXT,
														IN i_ext_id INT,
														IN i_journal BOOL,
														IN i_post_id INT,
														IN i_department_id INT,
														IN i_address_id INT,
														IN i_plint_name_id INT,
														IN i_group_id INT,
														IN i_comment TEXT)
    COMMENT ''
BEGIN
	DECLARE return_text TEXT;
	DECLARE value TEXT;
	DECLARE return_id INT;

	call check_data(i_id,i_strafe,i_plint,i_pair,return_text);

    IF return_text = "NORMAL" THEN
    BEGIN
    	UPDATE data 
		SET data.strafe = i_strafe,
			data.plint = i_plint,
			data.pair = i_pair,
			data.flag_value = i_flag_value,
			data.value = i_value,
			data.ext_id = i_ext_id,
			data.journal = i_journal,
			data.post_id = i_post_id,
			data.department_id = i_department_id,
			data.address_id = i_address_id,
			data.plint_name_id = i_plint_name_id,
			data.group_id = i_group_id,
			data.comment = i_comment,
			data.del = TRUE
		WHERE data.id = i_id;

    	SET return_id = i_id;
      	SELECT return_text, return_id;
    END;
    ELSE
	BEGIN
		SELECT return_text, -1;
	END;
	END IF;
END$$

delimiter ;
