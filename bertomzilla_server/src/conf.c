/*
** conf.c for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar 20 11:02:16 2015 Joris Bertomeu
** Last update Fri Mar 27 19:55:10 2015 Joris Bertomeu
*/

#include	"server.h"

char		**save_info(t_conf *conf, char **datap,
			    yaml_token_t token, int *state)
{
  int		i;
  unsigned char	*tk;

  i = 0;
  tk = token.data.scalar.value;
  if (*state == 0)
    {
      datap = NULL;
      while (i < NBR_FUNC_CONF)
	{
	  if (!strcmp((char*) tk, conf->ptr_conf_tab[i]))
	    {
	      datap = conf->ptr_conf_tab_var[i];
	      break;
	    }
	  i++;
	}
    }
  else
    {
      *state = 0;
      if (datap)
	*datap = strdup((char*) tk);
    }
  return (datap);
}

t_conf		*end_reading(yaml_token_t *token,
			  yaml_parser_t *parser, FILE *fh,
			  t_conf *conf)
{
  yaml_token_delete(token);
  yaml_parser_delete(parser);
  fclose(fh);
  return (conf);
}

t_conf		*readConf(char* filename)
{
  FILE		*fh;
  yaml_parser_t	parser;
  yaml_token_t	token;
  t_conf	*conf;
  int		state;
  char**	datap;

  state = 0;
  conf = malloc(sizeof(*conf));
  fh = init_parser(conf, &parser, filename);
  do
    {
      yaml_parser_scan(&parser, &token);
      if (token.type == YAML_KEY_TOKEN)
	state = 0;
      else if (token.type == YAML_VALUE_TOKEN)
	state = 1;
      else if (token.type == YAML_SCALAR_TOKEN)
	datap = save_info(conf, datap, token, &state);
      else if (token.type != YAML_STREAM_END_TOKEN)
	yaml_token_delete(&token);

    }
  while (token.type != YAML_STREAM_END_TOKEN);
  return (end_reading(&token, &parser, fh, conf));
}

void		check_parsing(t_conf *conf)
{
  int		i;
  int		ret;

  i = 0;
  ret = 0;
  while (i < NBR_FUNC_CONF)
    {
      if (!*(conf->ptr_conf_tab_var[i]))
	{
	  printf("Error, %s not found or bad value ..",
		 conf->ptr_conf_tab[i]);
	  ret += 1;
	}
      i++;
    }
  ret += check_for_types(conf);
  if (ret != 0)
    show_error("Configuration Error, exiting ..");
}

void		parse_me_conf_file(t_server *server)
{
  if (!file_exists("/etc/bertomzilla/config.yaml"))
    show_error("Unable to read BertomZilla Configuration File .. Exiting !");
  server->conf = readConf("/etc/bertomzilla/config.yaml");
  check_parsing(server->conf);
}
