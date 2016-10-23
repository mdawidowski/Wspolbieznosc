#!/bin/bash
rm wyniki.txt
echo Podaj liczbe:
read liczba
echo $liczba > dane.txt
while [[ -e "wyniki.txt" ]]; do
  wynik=$(cat "wyniki.txt")
  echo $wynik
  break;
done
