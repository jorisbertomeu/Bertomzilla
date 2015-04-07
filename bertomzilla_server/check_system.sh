#!/bin/sh
## check_system.sh for  in /home/jobertomeu/Work/my_ftp/PSU_2014_myftp/server
## 
## Made by Joris Bertomeu
## Login   <jobertomeu@epitech.net>
## 
## Started on  Thu Mar 19 09:44:56 2015 Joris Bertomeu
## Last update Fri Mar 20 10:52:54 2015 Joris Bertomeu
##

if [ `dpkg --get-selections | grep apache | wc -l` = "0" ]
then
     echo "\033[31mChecking Apache\t\t\t[KO]\033[0m"
     exit 1
else
     echo "\033[32mChecking Apache\t\t\t[OK]\033[0m"
fi

if [ `dpkg --get-selections | grep mysql-server | wc -l` = "0" ]
then
     echo "\033[31mChecking MySQL Server\t\t[KO]\033[0m"
     exit 1
else
     echo "\033[32mChecking MySQL Server\t\t[OK]\033[0m"
fi

if [ `dpkg --get-selections | grep php | wc -l` = "0" ]
then
     echo "\033[31mChecking PHP\t\t\t[KO]\033[0m"
     exit 1
else
     echo "\033[32mChecking PHP\t\t\t[OK]\033[0m"
fi

mkdir -p /etc/bertomzilla/
cp config.yaml /etc/bertomzilla/
cp banner.cnf /etc/bertomzilla
echo "\033[32mCreating BZ Folders\t\t\t[OK]\033[0m"
echo "Creating MySQL Database Structure ..."
read -p "Root user for MySQL : " rootUser
echo -n Password :
read -s rootPass
echo
command="mysql -u $rootuser root -p$rootPass"
cat bertomzilla.sql | $command
echo "\033[32mCreating MySQL User\t\t[OK]\033[0m"
echo "\033[32mCreating MySQL Database\t\t[OK]\033[0m"
echo "\033[32mCreating MySQL Tables\t\t[OK]\033[0m"
echo "" > .error
cp -fr ./BertomZilla /var/www/ 2> .error
if [ `cat .error | wc -l` = "0" ]
then
     echo "\033[32mCopying FileZilla /var/www/\t[OK]\033[0m"
     echo "You can access to BertomZilla GUI by typing http://<IPAddr>/bertomzilla"
     exit 1
else
     echo "\033[31mCopying FileZilla /var/www/\t[KO]\033[0m"
     cat .error
fi
