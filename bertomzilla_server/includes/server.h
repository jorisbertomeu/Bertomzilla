/*
** server.h for  in /home/jobertomeu/Work/my_ftp/server
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Fri Mar  6 18:40:22 2015 Joris Bertomeu
** Last update Sat Mar 28 16:56:09 2015 Joris Bertomeu
*/

#ifndef			_SERVER_H_
# define		_SERVER_H_
# define SHM_KEY_PATH	"/etc/bertomzilla"
# define NBR_FUNC_CONF	18

# include		"config.h"
# include		<stdio.h>
# include		<unistd.h>
# include		<stdlib.h>
# include		<errno.h>
# include		<signal.h>
# include		<netdb.h>
# include		<string.h>
# include		<sys/socket.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<sys/types.h>
# include		<sys/stat.h>
# include		<fcntl.h>
# include		<pthread.h>
# include		<mysql.h>
# include		<openssl/pem.h>
# include		<openssl/ssl.h>
# include		<openssl/rsa.h>
# include		<openssl/evp.h>
# include		<openssl/bio.h>
# include		<openssl/err.h>
# include		<openssl/sha.h>
# include		<dirent.h>
# include		<stropts.h>
# include		<sys/ioctl.h>
# include		<linux/netdevice.h>
# include		<netinet/in.h>
# include		<yaml.h>
# include		<ctype.h>
# include		<sys/ipc.h>
# include		<sys/shm.h>

typedef	struct		s_sck_srv
{
  struct sockaddr_in	server;
}			t_sck_srv;

typedef struct		s_conf
{
  FILE			*log_fd;
  char			ptr_conf_tab[20][32];
  char			**ptr_conf_tab_var[20];
  char			*net_iface;
  char			*srv_banner;
  char			*mysql_server;
  char			*mysql_user;
  char			*mysql_pass;
  char			*mysql_db;
  char			*log_file;
  char			*net_port;
  char			*mysql_enabled;
  char			*mysql_users;
  char			*ssl_enabled;
  char			*ssl_fconnect;
  char			*log_enabled;
  char			*log_level;
  char			*log_max_size;
  char			*monit_enabled;
  char			*monit_port;
  char			*monit_log;
}			t_conf;


typedef	struct		s_monit
{
  int			fd_monit;
  struct sockaddr_in	server_monit;
  fd_set		active_fd_set;
  fd_set		read_fd_set;
}			t_monit;

typedef struct		s_infos
{
  char			*ip;
  int			pid;
  int			fd;
  char			username[4096];
}			t_infos;

typedef	struct		s_shared
{
  int			shm_id;
  int			key_id;
}			t_shared;

typedef struct s_client	t_client;
typedef	struct s_server	t_server;
struct			s_server
{
  t_shared		shared;
  t_infos		clients[50];
  t_monit		monit;
  t_conf		*conf;
  t_sck_srv		srv_sck;
  int			clients_nbr;
  int			fd_cl;
  int			uptime;
  int			port;
  int			mysql;
  int			fd_srv;
  char			tab_func_name[24][128];
  char			*banned[50];
  void			(*tab_func_ptr[24])(t_client *, char *);
};

typedef enum		E_TYPE
  {
    ASCII,
    IMAGE
  }			T_TYPE;

typedef	struct		s_rights
{
  int			read;
  int			write;
  int			mkdir;
  int			rmdir;
}			t_rights;

struct			s_client
{
  t_rights		rights;
  t_server		*server;
  char			*username;
  char			*password;
  char			home[1024];
  char			perms[5];
  int			fd;
  int			rsa;
  int			logged;
  T_TYPE		type;
  int			pasv_sck;
  int			passive;
  char			rndst[4096];
  int			rnfr;
  MYSQL			mysql;
  int			mysql_flg;
  unsigned char		publicKeyRSA[4096];
};

typedef struct		s_file 
{
  char			filename[4096];
  int			size;
  int			time;
}			t_file;

void			ftp_retr(t_client *client, char *str);
char			*get_cmd(char *str, int len);
int			is_passive(t_client *client);
int			file_exists(char *filename);
FILE			*open_file(t_client *client, char *filename, int flg, int mode);
void			mysql_add_down_up(t_client *client, int type, t_file *file);
void			mysql_notif(t_client *client, char *icon, char *label);
void			send_error(t_client *client);
void			ftp_syst(t_client *client, char *str);
void			ftp_feat(t_client *client, char *str);
void			ftp_opts(t_client *client, char *str);
void			ftp_pwd(t_client *client, char *str);
void			ftp_type(t_client *client, char *str);
int			set_pasv(t_client *client, int p1, int p2);
void			ftp_pasv(t_client *client, char *str);
void			ftp_list(t_client *client, char *str);
void			ftp_cwd(t_client *client, char *str);
void			ftp_cdup(t_client *client, char *str);
void			ftp_mkd(t_client *client, char *str);
void			ftp_user(t_client *client, char *str);
void			ftp_pass(t_client *client, char *str);
void			ftp_rnfr(t_client *client, char *str);
void			ftp_rnto(t_client *client, char *str);
void			ftp_dele(t_client *client, char *str);
int			check_mysql(t_client *client, char *password);
void			ftp_rmd(t_client *client, char *str);
int			remove_directory(char *path);
void			ftp_stor(t_client *client, char *str);
void			ftp_rsaupld(t_client *client, char *str);
void			ftp_rsa(t_client *client, char *str);
void			ftp_size(t_client *client, char *str);
void			ftp_rsauser(t_client *client, char *str);
RSA			*createRSA(unsigned char * key,int public);
int			public_encrypt(unsigned char * data, int data_len,
				       unsigned char * key, unsigned char *encrypted);
void			ftp_quit(t_client *client, char *str);
void			show_error(char *str);
void			mysql_add_down_up(t_client *client, int type, t_file *file);
int			check_mysql(t_client *client, char *password);
void			mysql_notif(t_client *client, char *icon, char *label);
void			init_new_connection(t_client *client);
void			init_tab_func_ptr(t_server *server);
void			init_tab_func_names(t_server *server);
void			create_socket(t_server *server);
void			init_server(t_server *server);
void			send_banner(t_server *server, int fd);
int			check_auth(t_client *client, char *str);
int			check_arg(t_server *server, int ac, char **argv);
void			init_struct(t_client *client, int sock);
void			init_ptr_func(t_server *server);
void			show_error(char *str);
char			*get_first(char *str);
void			parse_me_conf_file(t_server *server);
void			check_parsing(t_conf *conf);
int			check_for_types(t_conf *conf);
int			check_for_file(t_conf *conf, char *str, char *key);
int			check_for_string(char *str, char *key);
int			check_for_int(char *str, char *key);
t_conf			*readConf(char* filename);
FILE			*init_parser(t_conf *conf, yaml_parser_t *parser,
				     char *filename);
t_conf			*end_reading(yaml_token_t *token,
				     yaml_parser_t *parser, FILE *fh,
				     t_conf *conf);
char			**save_info(t_conf *conf, char **datap,
				    yaml_token_t token, int *state);
void			init_conf(t_conf *conf);
void			init_conf_keywords(t_conf *conf);
void			init_label_txt(t_conf *conf);
void			process_ok(t_client *client, char *arg);
void			post(char *trame, int len, t_client *client,
			     unsigned char *encrypted);
int			recover_from_mysql_without_pswd(t_client *client);
int			is_authorized(t_client *client, int type);
void			do_end_retr(t_client *client, t_file *file);
void			check_log_file(t_client *client);
void			move_log_file(t_client *client);
int			get_next_nbr(t_client *client);
void			sigint_handler(int sig);
void			create_monit_socket(t_server *server);
void			*monit_managing(void *ptr);
int			read_for_monit(t_server *server, int fd);
void			server_cmd(t_server *server, char *str, int fd);
void			client_cmd(t_server *server, char *str, int fd);
void			add_new_client(t_server *server,
				       struct sockaddr_in client, int fd, int pid);
void			init_clients_tab(t_server *server);
t_server		*init_shared_memory(t_server *server);
t_server		*get_from_shared(int *key_id);
void			delete_client_from_list(t_client *client, int fd);
void			shut_server(t_server *server);
void			sigint_handler_client(int sig);
void			sigusr2_handler_client(int sig);
void			delete_client_from_list_with_pid(t_server *server, int pid);
void			sigusr1_handler_client(int sig);
void			delete_client_from_list_with_pid_and_ban(t_server *server, int pid);
void			add_user_to_client_list(t_client *client);
int			get_fd_with_pid(t_server *server, int pid);
void			add_ban(t_server *server, char *ip);
int			is_banned(t_server *server, struct sockaddr_in client, int fd);
void			add_new_client_monit(t_server *server,
					     struct sockaddr_in *clientname);
void			ban_clients(t_server *server, int fd, char *str);
char			*show_help();
void			list_clients(t_server *server, int fd);
void			kick_clients(t_server *server, int fd, char *str);
int			get_good_pos_for_ban(int pos, char *str);
void			choose_select_fd(t_server *server, struct sockaddr_in *clientname);
void			parse_monit_cmd(t_server *server, char *str, int fd);
int			get_number_clients_connected(t_server *server);
void			monit_info(t_server *server, int fd);
void			check_log_file_monit(t_server *server);
void			mysql_notif_monit(t_server *server, char *icon, char *label);
void			send_unknown(t_client *client, char *str);
void			cond_is_ok(t_client *client, int client_fd);
void			bad_path(t_client *client);
int			is_authorized_path(t_client *client, char *path);
int			is_file(char *path);
int			is_dir(char *path);
char			*get_path(char *str);
int			preli_test_retr(t_client *client);

#endif			/* _SERVER_H_ */
