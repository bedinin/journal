delimiter $$

CREATE TABLE `group_name` (
  `id` int(11) NOT NULL auto_increment,
  `name` text NOT NULL,
  `color` text NOT NULL,
  `comment` text NOT NULL,
  `del` tinyint(1) default '1',
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8$$

delimiter ;
