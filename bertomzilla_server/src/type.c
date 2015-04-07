/*
** type.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 11 16:44:45 2015 Joris Bertomeu
** Last update Sat Mar 21 16:12:47 2015 Joris Bertomeu
*/

#include	"server.h"

void		ftp_type(t_client *client, char *str)
{
  char		*arg;

  arg = get_cmd(str, 4);
  if (!strcmp(arg, "I"))
    {
      client->type = IMAGE;
      write(client->fd, "200 TYPE is now 8-bit binary\r\n",
	    strlen("200 TYPE is now 8-bit binary\r\n"));
      return;
    }
  else if (!strcmp(arg, "A"))
    {
      client->type = ASCII;
      write(client->fd, "200 TYPE is now ASCII\r\n",
	    strlen("200 TYPE is now ASCII\r\n"));
      return;
    }
  client->type = ASCII;
  write(client->fd, "504-Unknown TYPE\n200 TYPE is now ASCII\r\n",
	strlen("504-Unknown TYPE\n200 TYPE is now ASCII\r\n"));
}

