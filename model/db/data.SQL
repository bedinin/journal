
delimiter $$

CREATE TABLE `data` (
  `id` int(11) NOT NULL auto_increment,
  `strafe` text,
  `plint` text,
  `pair` text,
  `flag_value` tinyint(1) NOT NULL default '1',
  `value` text,
  `ext_id` int(11) default NULL,
  `journal` tinyint(1) default NULL,
  `post_id` int(11) default NULL,
  `department_id` int(11) default NULL,
  `address_id` int(11) default NULL,
  `plint_name_id` int(11) default NULL,
  `cross_id` int(11) default NULL,
  `group_id` int(11) default NULL,
  `comment` text,
  `del` tinyint(1) NOT NULL default '1',
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8$$

delimiter ;