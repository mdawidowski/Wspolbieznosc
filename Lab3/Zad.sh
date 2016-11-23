#!/bin/bash

declare -i licznik

dir=$(pwd)

if [ -d "$1" ]; then
  sciezka="$dir/$1"
  cd $sciezka
  for i in $( tree ); do
    if [ "$i" == "$2" ] ; then
      let "licznik += 1"
    fi
  done
else
  echo "Podany parametr jest niepoprawny"
fi

if [ -z $3] ; then
  if [ -z $licznik ] ; then
    echo "Niestety nie znaleziono"
  else
    echo "Plik zostal znaleziony"
  fi
fi
