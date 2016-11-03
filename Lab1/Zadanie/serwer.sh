#!/bin/bash

while [ 1 ]
do
  if [ -e "dane.txt" ]
  then
    liczba=$(cat "dane.txt")
    let wynik=liczba*5;
    echo $wynik > wyniki.txt
    echo > tworek.txt
  fi

  if [[ -e "tworek.txt" ]]; then
    rm tworek.txt
  fi
done
