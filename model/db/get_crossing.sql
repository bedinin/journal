drop procedure get_crossing;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_crossing`(IN i_strafe INT,IN i_plint INT,IN i_pair INT)
    COMMENT ''
BEGIN
	SELECT crossing.this_strafe,crossing.this_plint,crossing.this_pair,
			crossing.prev_strafe,crossing.prev_plint,crossing.prev_pair 
	FROM crossing WHERE (crossing.this_strafe = i_strafe AND 
						crossing.this_plint = i_plint AND 
						crossing.this_pair = i_pair) OR 
						(crossing.prev_strafe = i_strafe AND 
						crossing.prev_plint = i_plint AND 
						crossing.prev_pair = i_pair);
	
END$$

delimiter ;