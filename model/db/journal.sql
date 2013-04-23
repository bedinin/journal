SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `data`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `data` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `data` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `strafe` TEXT NULL ,
  PRIMARY KEY (`id`) )
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- procedure add_data
-- -----------------------------------------------------
DROP procedure IF EXISTS `add_data`;
SHOW WARNINGS;

DELIMITER $$
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_data`(	IN i_strafe TEXT,
														IN i_plint TEXT,
														IN i_pair TEXT,
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

	call check_data(-1,i_strafe,i_plint,i_pair,return_text);

    IF return_text = "NORMAL" THEN
    BEGIN
    	INSERT INTO data VALUES(NULL,
    							i_strafe,
								i_plint,
								i_pair,
								i_flag_value,
								i_value,
								i_ext_id,
								i_journal,
								i_post_id,
								i_department_id,
								i_address_id,
								i_plint_name_id,
								i_group_id,
								i_comment,
    							TRUE);
    	SET return_id = LAST_INSERT_ID();
      	-- SELECT return_text, return_id;
    END;
    ELSE
	BEGIN
		-- SELECT return_text;
	END;
	END IF;
END$$
SHOW WARNINGS;

-- -----------------------------------------------------
--  routine1
-- -----------------------------------------------------
DROP  IF EXISTS `routine1`;
SHOW WARNINGS;

DELIMITER $$
CREATE PROCEDURE `routine1` ()
BEGIN

END$$
SHOW WARNINGS;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
