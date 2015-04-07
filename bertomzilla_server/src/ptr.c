/*
** ptr.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/server/src
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 18 13:22:40 2015 Joris Bertomeu
** Last update Sat Mar 21 16:31:31 2015 Joris Bertomeu
*/

#include	"server.h"

void		step_2_1(t_server *server, int i)
{
  server->tab_func_ptr[i++] = &ftp_rsa;
  server->tab_func_ptr[i++] = &ftp_size;
  server->tab_func_ptr[i++] = &ftp_rsauser;
  server->tab_func_ptr[i++] = &ftp_quit;
  server->tab_func_ptr[i++] = NULL;
}

void		init_tab_func_ptr(t_server *server)
{
  int		i;

  i = 0;
  server->tab_func_ptr[i++] = &ftp_user;
  server->tab_func_ptr[i++] = &ftp_pass;
  server->tab_func_ptr[i++] = &ftp_syst;
  server->tab_func_ptr[i++] = &ftp_feat;
  server->tab_func_ptr[i++] = &ftp_opts;
  server->tab_func_ptr[i++] = &ftp_pwd;
  server->tab_func_ptr[i++] = &ftp_type;
  server->tab_func_ptr[i++] = &ftp_pasv;
  server->tab_func_ptr[i++] = &ftp_list;
  server->tab_func_ptr[i++] = &ftp_cwd;
  server->tab_func_ptr[i++] = &ftp_cdup;
  server->tab_func_ptr[i++] = &ftp_stor;
  server->tab_func_ptr[i++] = &ftp_retr;
  server->tab_func_ptr[i++] = &ftp_mkd;
  server->tab_func_ptr[i++] = &ftp_rnfr;
  server->tab_func_ptr[i++] = &ftp_rnto;
  server->tab_func_ptr[i++] = &ftp_dele;
  server->tab_func_ptr[i++] = &ftp_rmd;
  server->tab_func_ptr[i++] = &ftp_rsaupld;
  step_2_1(server, i);
}

void		step_2_2(t_server *server, int i)
{
  strcpy(server->tab_func_name[i++], "RSA");
  strcpy(server->tab_func_name[i++], "SIZE");
  strcpy(server->tab_func_name[i++], "USERRSA");
  strcpy(server->tab_func_name[i++], "QUIT");
  server->tab_func_name[i++][0] = 0x00;
}

void		init_tab_func_names(t_server *server)
{
  int		i;

  i = 0;
  strcpy(server->tab_func_name[i++], "USER");
  strcpy(server->tab_func_name[i++], "PASS");
  strcpy(server->tab_func_name[i++], "SYST");
  strcpy(server->tab_func_name[i++], "FEAT");
  strcpy(server->tab_func_name[i++], "OPTS");
  strcpy(server->tab_func_name[i++], "PWD");
  strcpy(server->tab_func_name[i++], "TYPE");
  strcpy(server->tab_func_name[i++], "PASV");
  strcpy(server->tab_func_name[i++], "LIST");
  strcpy(server->tab_func_name[i++], "CWD");
  strcpy(server->tab_func_name[i++], "CDUP");
  strcpy(server->tab_func_name[i++], "STOR");
  strcpy(server->tab_func_name[i++], "RETR");
  strcpy(server->tab_func_name[i++], "MKD");
  strcpy(server->tab_func_name[i++], "RNFR");
  strcpy(server->tab_func_name[i++], "RNTO");
  strcpy(server->tab_func_name[i++], "DELE");
  strcpy(server->tab_func_name[i++], "RMD");
  strcpy(server->tab_func_name[i++], "RSAUPLD");
  step_2_2(server, i);
}
