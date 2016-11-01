#!/bin/bash

while [ 1 ]
do
  if [ -e "dane.txt" ]
  then
    liczba=$(cat "dane.txt")
  fi

  if [ -e "dane.txt" ]
    then
        rm dane.txt
  fi
  let wynik=liczba*5;
  echo $wynik > wyniki.txt

  if [[ -e "tworek.txt" ]]; then
  rm tworek.txt
  fi
done
