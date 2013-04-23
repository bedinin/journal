drop procedure creater;

delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `creater`(IN i_strafe_count INT,IN i_plint_count INT,IN i_pair_count INT,IN i_cross_name TEXT)
    COMMENT ''
BEGIN
	DECLARE x INT DEFAULT 0;	
	DECLARE y INT DEFAULT 0;
	DECLARE z INT DEFAULT 0;

	-- DELETE FROM data WHERE id >=  0;
-- 	DELETE FROM crossing WHERE id >=  0;
-- 	DELETE FROM cross_name WHERE id >=  0;
-- 	DELETE FROM options WHERE id >=  0;
-- 	DELETE FROM plint WHERE id >=  0;

	TRUNCATE TABLE data;
	TRUNCATE TABLE crossing;
	TRUNCATE TABLE cross_name;
	TRUNCATE TABLE options;
	TRUNCATE TABLE plint;

	INSERT INTO options VALUES(NULL,"strafe_count", i_strafe_count);
	INSERT INTO options VALUES(NULL,"plint_count", i_plint_count);
	INSERT INTO options VALUES(NULL,"pair_count", i_pair_count);
	INSERT INTO options VALUES(NULL,"cross_name", i_cross_name);
	SET x = 0;
	SET y = 0;
	SET z = 0;
	-- SELECT i_strafe_count,i_plint_count,i_pair_count;
	labelX: LOOP
		IF (x >= i_strafe_count) THEN
		BEGIN
			LEAVE labelX;
		END;
		ELSE
		BEGIN
			SET y = 0;
			labelY: LOOP
				IF (y >= i_plint_count) THEN
				BEGIN
					LEAVE labelY;
				END;
				ELSE
				BEGIN
					SET z = 0;
					labelZ: LOOP
						IF (z >= i_pair_count) THEN
						BEGIN
							LEAVE labelZ;
						END;
						ELSE
						BEGIN
							CALL add_data(x,y,z,FALSE,"",-1,FALSE,-1,-1,-1,-1,-1,"");
							SET z=z+1;
						END;
						END IF;
					END LOOP labelZ;					
					
					SET y=y+1;			
				END;
				END IF;
			END LOOP labelY;
			SET x=x+1;						
		END;
		END IF;
	END	LOOP labelX;
			
END$$

delimiter ;
