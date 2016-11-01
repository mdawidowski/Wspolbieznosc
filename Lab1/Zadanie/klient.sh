#!/bin/bash

echo Podaj liczbe:

read liczba

echo $liczba > dane.txt

pomoc=$(cat "wyniki.txt")

wynik=$(cat "wyniki.txt")

while [[ wynik = pomoc ]]; do
  wynik=$(cat "wyniki.txt")
done
  echo $wynik

exit
