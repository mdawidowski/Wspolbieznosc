#!/bin/bash
user=$(whoami)
klient=klientfifo
if [[ -e $klient ]]; then
  rm $klient
  mkfifo $klient
  chmod 777 $klient
else
  mkfifo $klient
  chmod 777 $klient
fi

echo $user $1 > serwerfifo
while [[ $line -le 0 ]]; do
  read line < $klient
  echo $line
done
exit 0
