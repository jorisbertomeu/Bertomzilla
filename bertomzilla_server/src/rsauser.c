/*
** rsauser.c for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Thu Mar 12 17:07:32 2015 Joris Bertomeu
** Last update Sat Mar 21 17:01:15 2015 Joris Bertomeu
*/

#include	"server.h"

unsigned char	*randstring(int length)
{
  char		string[4096];
  size_t	stringLen;
  char		*randomString;
  unsigned int	key;
  int		n;

  key = 0;
  stringLen = 26*2+10+7;
  bzero(string, 4096);
  strcpy(string,
	 "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!");
  if (!(randomString = malloc(sizeof(char) * (length + 1))))
    show_error("Error while mallocing !");
  if (!randomString)
    return (NULL);
  n = 0;
  while (n < length)
    {
      srand(n);
      key = rand() % stringLen;
      randomString[n] = string[key];
      n++;
    }
  randomString[length] = '\0';
  return ((unsigned char*) randomString);
}

int		fill_publicKeyFromScratch(t_client *client, char *filename)
{
  FILE		*fd;

  if (!file_exists(filename))
    {
      printf("File %s not exists\n", filename);
      send_error(client);
      return (0);
    }
  if (!(fd = open_file(client, filename, 0, 1)))
    {

      send_error(client);
      return (0);
    }
  bzero(client->publicKeyRSA, 4096);
  fread(client->publicKeyRSA, 1, 4096, fd);
  fclose(fd);
  return (1);
}

int		recover_from_mysql_without_pswd(t_client *client)
{
  MYSQL_RES	*result;
  MYSQL_ROW	row;

  if (client->mysql_flg)
    {
      mysql_query(&(client->mysql), "SELECT * FROM users");
      result = mysql_store_result(&(client->mysql));
      while ((row = mysql_fetch_row(result)))
	if (!strcmp(row[1], client->username))
	  {
	    bzero(client->home, 1024);
	    strcpy(client->home, row[4]);
	    strcpy(client->perms, row[7]);
	    free(result);
	    return (1);
	  }
      free(result);
    }
  return (0);
}

void		ssl_not_actived(t_client *client)
{
  write(client->fd, "550 - SSL Not activated !\r\n",
	strlen("550 - SSL Not activated !\r\n"));
}

void		ftp_rsauser(t_client *client, char *str)
{
  char		*arg;
  char		filename[4096];
  char		trame[4096];
  unsigned char	encrypted[4096];
  unsigned char	*randstr;
  int		len;

  arg = get_cmd(str, 7);
  if (atoi(client->server->conf->ssl_enabled) == 0 ||
      atoi(client->server->conf->ssl_fconnect) == 0)
    return (ssl_not_actived(client));
  sprintf(filename, "/etc/bertomzilla/.rsa/%s.pub", arg);
  if (!fill_publicKeyFromScratch(client, filename))
    return (show_error("Error while filling RSA File"));
  randstr = randstring(16);
  len = public_encrypt(randstr, 16, client->publicKeyRSA, encrypted);
  post(trame, len, client, encrypted);
  if (!strncmp(trame, (const char*) randstr, 16))
    process_ok(client, arg);
  else
    write(client->fd, "KO\r\n", 4);
}
