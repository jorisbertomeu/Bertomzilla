/*
** retr2.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat Mar 21 17:23:53 2015 Joris Bertomeu
** Last update Sat Mar 21 18:21:11 2015 Joris Bertomeu
*/

#include	"server.h"

void		do_end_retr(t_client *client, t_file *file)
{
  mysql_add_down_up(client, 0, file);
  mysql_notif(client, "download", "File downloaded successfully");
  write(client->fd, "226 File successfully transfered\r\n",
	strlen("226 File successfully transfered\r\n"));
}

int		is_authorized(t_client *client, int type)
{
  int		ret;

  ret = (client->perms[type] == '0') ? 0 : 1;
  if (!ret)
    write(client->fd, "550 Unauthorized action !\r\n",
	  strlen("550 Unauthorized action !\r\n"));
  return (ret);
}
