#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(bertomzilla, 1.0, joris.bertomeu@epitech.eu)
AC_CONFIG_SRCDIR([src/rnto.c])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_HEADERS([includes/config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([crypto], [BIO_new_mem_buf], [],[
         echo "Crypto library is required"
         exit -1])
AC_CHECK_LIB([mysqlclient], [mysql_query], [],[
         echo "Mysqlclient library is required"
         exit -1])
AC_CHECK_LIB([pthread], [pthread_create], [],[
         echo "Pthread library is required"
         exit -1])
AC_CHECK_LIB([dl], [dlopen], [],[
         echo "Dl library is required"
         exit -1])
AC_CHECK_LIB([yaml], [yaml_parser_scan], [],[
         echo "Yaml library is required"
         exit -1])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h netdb.h netinet/in.h stdlib.h string.h sys/socket.h unistd.h stdio.h errno.h signal.h netdb.h pthread.h my_global.h mysql.h openssl/pem.h openssl/ssl.h openssl/rsa.h openssl/evp.h openssl/bio.h openssl/sha.h dirent.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_CHECK_FUNCS([bzero getcwd mkdir rmdir socket strerror])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
