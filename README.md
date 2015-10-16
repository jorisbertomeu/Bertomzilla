# Bertomzilla Project

Bertomzilla is a complete solution included a FTP Server with a web-based monitoring interface and a simple FTP client.

### Server
Server side is a full server written in C wich communicate with a MySQL Database. Server is fully able to communicate with a basic FTP client like FileZilla or other. Goal of this MySQL Communication is to manage your FTP Server only with a web interface. You can do some stuff :
* Manage Users
* Assignate home directory to an user
* Change an user's password
* View all exchange on an user with fully populated table including some stuff like size file, name file, date, client software used ...
* Get or remove files from web interface
* View graphs including stats about lot of params like data exchanged by day on a week or exchange count by user on a week
* Debuging console included to get some raw informations from Bertomzilla Server like current exchange, server state ...

This server with web interface was developed with <3 for all dev or adminsys who ever dream about a full solution able to manage completely a secure FTP Server.

### Client
Bertomzilla client is a simple FTP Client fully able to communicate with another FTP Server. This is a CLI Client including some stuff for Bertomzilla Server : 
* OpenSSL Encryption (Asymetric Encryption as RSA1024)
* Auto-completion with directory and file
* Multi-user logging to allow exchange between severals users without a directory permission

##
Do not hesitate to contribute to this project by adding some stuff into code or by send an email to joris.bertomeu@epitech.eu
