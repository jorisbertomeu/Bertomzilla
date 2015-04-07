/*
** path.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/bertomzilla_server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat Mar 28 16:38:24 2015 Joris Bertomeu
** Last update Sat Mar 28 16:52:18 2015 Joris Bertomeu
*/

#include	"server.h"

int		is_file(char *path)
{
  struct stat	buf;

  stat(path, &buf);
  return (S_ISREG(buf.st_mode));
}

int		is_dir(char *path)
{
  struct stat	buf;

  stat(path, &buf);
  return (S_ISDIR(buf.st_mode));
}

char		*get_path(char *str)
{
  int		i;
  char		*ret;

  if (is_dir(str))
    return (str);
  i = strlen(str);
  while (str[i] != '/' && i >= 0)
    i--;
  i++;
  ret = malloc((i + 1) * sizeof(char));
  bzero(ret, i + 1);
  strncpy(ret, str, i);
  return (ret);
}

int		is_authorized_path(t_client *client, char *str)
{
  char		pwd[2][512];
  char		*path;
  
  if (strlen(str) == 0)
    return (1);
  path = get_path(str);
  getcwd(pwd[0], 512);
  if (chdir(path) == 0)
    {
      getcwd(pwd[1], 512);
      if (strlen(pwd[1]) < strlen(client->home) ||
	  strncmp(pwd[1], client->home, strlen(client->home)))
	{
	  chdir(pwd[0]);
	  return (0);
	}
      chdir(pwd[0]);
    }
  return (1);
}
