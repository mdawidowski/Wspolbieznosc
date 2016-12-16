#!/bin/bash

trap "" SIGHUP SIGTERM SIGCHLD
trap "exit 0" SIGUSR1

klient=klientfifo
serwer=serwerfifo

if [[ -e $serwer ]]; then
  rm $serwer
  mkfifo $serwer
  chmod 777 $serwer
else
  mkfifo $serwer
  chmod 777 $serwer
fi
while [[ true ]]; do
  if [[ -z $1 ]]; then
    read line < $serwer
    echo $line
    line=$(sed 's/[^0-9]//g' <<< $line)
    x=$line
    /bin/bash $0 $x
  else
    x=$1
    let $[x=x+1]
    echo $x > klientfifo
    exit 0
  fi
done
