/*
** mysql.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/server/src
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Mar 18 13:14:36 2015 Joris Bertomeu
** Last update Fri Mar 27 14:37:44 2015 Joris Bertomeu
*/

#include	"server.h"

void		mysql_add_down_up(t_client *client, int type, t_file *file)
{
  char	requete[4096];

  if (client->mysql_flg)
    {
      sprintf(requete, "INSERT INTO `%s`.`operations` (`id`, `filename`,\
 `time`, `size`, `date`, `username`, `type`) VALUES (NULL, '%s', '%d', '%d',\
 CURRENT_TIMESTAMP, '%s', '%d');",
	      client->server->conf->mysql_db,
	      file->filename, file->time, file->size, client->username, type);
      mysql_query(&(client->mysql), requete);
    }
}

void		get_rights(t_client *client)
{
  client->rights.read = (client->perms[0] == '1') ? 1: 0;
  client->rights.write = (client->perms[1] == '1') ? 1: 0;
  client->rights.mkdir = (client->perms[2] == '1') ? 1: 0;
  client->rights.rmdir = (client->perms[3] == '1') ? 1: 0;
}

int		check_mysql(t_client *client, char *password)
{
  MYSQL_RES	*result;
  MYSQL_ROW	row;

  bzero(client->home, 1024);
  bzero(client->perms, 4);
  getcwd(client->home, 1024);
  if (client->mysql_flg && client->server->conf->mysql_users)
    {
      mysql_query(&(client->mysql), "SELECT * FROM users");
      result = mysql_store_result(&(client->mysql));
      while ((row = mysql_fetch_row(result)))
	if (!strcmp(row[1], client->username) && !strcmp(row[2], password))
	  {
	    bzero(client->home, 1024);
	    strcpy(client->home, row[4]);
	    strcpy(client->perms, row[7]);
	    add_user_to_client_list(client);
	    get_rights(client);
	    free(result);
	    return (1);
	  }
      free(result);
    }
  return (0);
}

void		mysql_notif(t_client *client, char *icon, char *label)
{
  char	requete[4096];

  bzero(requete, 4096);
  if (client->server->conf->log_enabled)
    {
      check_log_file(client);
      client->server->conf->log_fd = fopen(client->server->conf->log_file,
					   "a+");
      sprintf(requete,
	      "[%d][%s]\t%s\n", (int) time(NULL), icon, label);
      fwrite(requete, 1, strlen(requete), client->server->conf->log_fd);
      fclose(client->server->conf->log_fd);
    }
  bzero(requete, 4096);
  if (client->mysql_flg)
    {
      sprintf(requete, "INSERT INTO `%s`.`notifications`\
 (`id`, `icon`, `label`, `date`, `username`)		\
 VALUES (NULL, '%s', '%s', CURRENT_TIMESTAMP, '%s');",
	      client->server->conf->mysql_db, icon, label, client->username);
      mysql_query(&(client->mysql), requete);
    }
}

void		init_new_connection(t_client *client)
{
  client->username = NULL;
  client->mysql_flg = 0;
  client->password = NULL;
  if (client->server->mysql)
    {
      mysql_init(&(client->mysql));
      mysql_options(&(client->mysql), MYSQL_READ_DEFAULT_GROUP, "option");
      if (mysql_real_connect(&(client->mysql),
			     client->server->conf->mysql_server,
			     client->server->conf->mysql_user,
			     client->server->conf->mysql_pass,
			     client->server->conf->mysql_db, 0, NULL, 0))
	client->mysql_flg = 1;
    }
}
