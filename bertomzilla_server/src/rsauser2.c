/*
** rsauser2.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat Mar 21 17:01:04 2015 Joris Bertomeu
** Last update Sat Mar 21 17:01:17 2015 Joris Bertomeu
*/

#include	"server.h"

void		post(char *trame, int len, t_client *client,
		     unsigned char *encrypted)
{
  bzero(trame, 4096);
  sprintf(trame, "331 %d\r\n", len);
  write(client->fd, trame, strlen(trame));
  write(client->fd, encrypted, len);
  bzero(trame, 4096);
  read(client->fd, trame, 4096);
}

void		process_ok(t_client *client, char *arg)
{
  write(client->fd, "OK\r\n", 4);
  client->username = malloc((strlen(arg) + 1) * sizeof(char));
  strcpy(client->username, arg);
  recover_from_mysql_without_pswd(client);
  mysql_notif(client, "sign-in", "Successfully Connected with RSA Mode");
  client->logged = 1;
}
