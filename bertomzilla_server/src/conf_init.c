/*
** conf_init.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 20 11:11:28 2015 Joris Bertomeu
** Last update Fri Mar 27 19:33:17 2015 Joris Bertomeu
*/

#include	"server.h"

void		init_label_txt(t_conf *conf)
{
  int		i;

  i = 0;
  strcpy(conf->ptr_conf_tab[i++], "i_net_port");
  strcpy(conf->ptr_conf_tab[i++], "s_net_iface");
  strcpy(conf->ptr_conf_tab[i++], "f_srv_banner");
  strcpy(conf->ptr_conf_tab[i++], "i_mysql_enabled");
  strcpy(conf->ptr_conf_tab[i++], "s_mysql_server");
  strcpy(conf->ptr_conf_tab[i++], "s_mysql_user");
  strcpy(conf->ptr_conf_tab[i++], "s_mysql_pass");
  strcpy(conf->ptr_conf_tab[i++], "s_mysql_db");
  strcpy(conf->ptr_conf_tab[i++], "i_mysql_users");
  strcpy(conf->ptr_conf_tab[i++], "i_ssl_enabled");
  strcpy(conf->ptr_conf_tab[i++], "i_ssl_fconnect");
  strcpy(conf->ptr_conf_tab[i++], "i_log_enabled");
  strcpy(conf->ptr_conf_tab[i++], "f_log_file");
  strcpy(conf->ptr_conf_tab[i++], "i_log_level");
  strcpy(conf->ptr_conf_tab[i++], "i_log_max_size");
  strcpy(conf->ptr_conf_tab[i++], "i_monit_enabled");
  strcpy(conf->ptr_conf_tab[i++], "i_monit_port");
  strcpy(conf->ptr_conf_tab[i++], "i_monit_log");
}

void		init_conf_keywords(t_conf *conf)
{
  conf->net_port = NULL;
  conf->net_iface = NULL;
  conf->srv_banner = NULL;
  conf->mysql_enabled = NULL;
  conf->mysql_server = NULL;
  conf->mysql_user = NULL;
  conf->mysql_pass = NULL;
  conf->mysql_db = NULL;
  conf->mysql_users = NULL;
  conf->ssl_enabled = NULL;
  conf->ssl_fconnect = NULL;
  conf->log_enabled = NULL;
  conf->log_file = NULL;
  conf->log_level = NULL;
  conf->log_max_size = NULL;
  conf->monit_enabled = NULL;
  conf->monit_port = NULL;
  conf->monit_log = NULL;
}

void		init_conf(t_conf *conf)
{
  int		i;

  i = 0;
  conf->ptr_conf_tab_var[i++] = &(conf->net_port);
  conf->ptr_conf_tab_var[i++] = &(conf->net_iface);
  conf->ptr_conf_tab_var[i++] = &(conf->srv_banner);
  conf->ptr_conf_tab_var[i++] = &(conf->mysql_enabled);
  conf->ptr_conf_tab_var[i++] = &(conf->mysql_server);
  conf->ptr_conf_tab_var[i++] = &(conf->mysql_user);
  conf->ptr_conf_tab_var[i++] = &(conf->mysql_pass);
  conf->ptr_conf_tab_var[i++] = &(conf->mysql_db);
  conf->ptr_conf_tab_var[i++] = &(conf->mysql_users);
  conf->ptr_conf_tab_var[i++] = &(conf->ssl_enabled);
  conf->ptr_conf_tab_var[i++] = &(conf->ssl_fconnect);
  conf->ptr_conf_tab_var[i++] = &(conf->log_enabled);
  conf->ptr_conf_tab_var[i++] = &(conf->log_file);
  conf->ptr_conf_tab_var[i++] = &(conf->log_level);
  conf->ptr_conf_tab_var[i++] = &(conf->log_max_size);
  conf->ptr_conf_tab_var[i++] = &(conf->monit_enabled);
  conf->ptr_conf_tab_var[i++] = &(conf->monit_port);
  conf->ptr_conf_tab_var[i++] = &(conf->monit_log);
  init_label_txt(conf);
  init_conf_keywords(conf);
}

FILE		*init_parser(t_conf *conf, yaml_parser_t *parser,
			     char *filename)
{
  FILE		*fd;

  fd = fopen(filename, "r");
  init_conf(conf);
  if (!yaml_parser_initialize(parser))
    fputs("Failed to initialize parser!\n", stderr);
  if (fd == NULL)
    fputs("Failed to open file!\n", stderr);
  yaml_parser_set_input_file(parser, fd);
  return (fd);
}
