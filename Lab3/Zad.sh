#!/bin/bash

declare -i x

dir=$(pwd)

if [ -d "$1" ]; then
  sciezka="$dir/$1"
  cd $sciezka
  for i in $( ls ); do
    if [ "$i" == "$2" ] ; then
      let "x += 1"
    else
      while [[ -d $i ]]; do
        if [[ -d $i ]]; then
          cd $i
        fi
        for z in $( ls ); do
          if [[ "$z" == "$2" ]]; then
            let "x += 1"
          fi
          for i in $( ls ); do
            sleep 0
          done
         if [[ $i == $2 ]]; then
           let "x += 1"
         fi
      done
      done
    fi
  done
else
  echo "podaj prawidlowy parametr"
fi

if [ -z $3] ; then
  if [ -z $x ] ; then
    echo "Niestety niczego nie znaleziono"
  else
    echo "Plik/katalog zostal znaleziony"
  fi
fi
