DROP PROCEDURE check_crossing;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `check_crossing`(	IN i_strafe TEXT,						
																IN i_plint TEXT,						
																IN i_pair TEXT,
																IN i_cross_strafe TEXT,
																IN i_cross_plint TEXT,
																IN i_cross_pair TEXT,
																OUT i_return TEXT)
    COMMENT '®¨áª flag_value ¢ á¢ï§ïå, ¢®§¢à®é ¥â "NORMAL" - flag_value=fals'
BEGIN
	DECLARE constant_name TEXT;
	DECLARE err INT DEFAULT 0;
	DECLARE v_strafe, 
			v_plint, 
			v_pair TEXT;
	DECLARE v_return TEXT DEFAULT "NORMAL";
	DECLARE v_flag_value BOOL;
	DECLARE flag BOOL DEFAULT TRUE;
	
END$$

delimiter ;