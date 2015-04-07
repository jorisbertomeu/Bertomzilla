AUTOMAKE_OPTIONS = foreign

CFLAGS = -W -Wall -Werror -lyaml `mysql_config --cflags` -Iincludes
LDFLAGS = -lcrypto -lpthread -lyaml `mysql_config --libs`

bin_PROGRAMS = serveur
serveur_SOURCES = src/main.c src/retr.c src/pasv.c src/feat.c src/opts.c src/pwd.c src/type.c src/syst.c src/list.c src/cwd.c src/user.c src/cdup.c src/mkd.c src/pass.c src/rnfr.c src/rnto.c src/dele.c src/rmd.c src/stor.c src/rsaupld.c src/rsa.c src/size.c src/rsauser.c src/quit.c src/network.c src/mysql.c src/ptr.c src/utils.c src/init.c src/conf.c src/conf_init.c src/conf_types.c src/rsauser2.c src/retr2.c src/log.c src/signal.c src/monit_sock.c src/monit_init.c src/monit_operations.c src/monit_kick.c src/monit_ban.c src/monit_help.c src/monit_list.c src/shared.c src/monit_listener.c src/monit_server.c src/monit_client.c src/monit_info.c src/mysql_monit.c src/checking.c src/path.c
