/*
** conf_types.c for + in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 20 11:03:19 2015 Joris Bertomeu
** Last update Sat Mar 21 16:33:42 2015 Joris Bertomeu
*/

#include	"server.h"

int		check_for_int(char *str, char *key)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (!isdigit(str[i]))
	{
	  printf("Invalid value \"%s\" for \"%s\"\n", str, key);
	  return (1);
	}
      i++;
    }
  return (0);
}

int		check_for_string(char *str, char *key)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] > 125)
	{
	  printf("Invalid value \"%s\" for \"%s\"\n", str, key);
	  return (1);
	}
      i++;
    }
  return (0);
}

int		check_for_file(t_conf *conf, char *str, char *key)
{
  FILE		*fd;

  (void) conf;
  if (!(fd = fopen(str, (!strcmp(key, "f_log_file")) ? "a+" : "r")))
    {
      printf("Unable to create or open \"%s\" file for \"%s\" : %s\n",
	     str, key, strerror(errno));
      return (1);
    }
  fclose(fd);
  return (0);
}

int		check_for_types(t_conf *conf)
{
  int		i;
  int		ret;

  i = 0;
  ret = 0;
  while (i < 14)
    {
      if (!strncmp(conf->ptr_conf_tab[i], "i_", 2))
	ret += check_for_int(*(conf->ptr_conf_tab_var[i]),
		      conf->ptr_conf_tab[i]);
      else if (!strncmp(conf->ptr_conf_tab[i], "s_", 2))
	ret += check_for_string(*(conf->ptr_conf_tab_var[i]),
			 conf->ptr_conf_tab[i]);
      else
	ret += check_for_file(conf,
		       *(conf->ptr_conf_tab_var[i]),
		       conf->ptr_conf_tab[i]);
      i++;
    }
  return (ret);
}
