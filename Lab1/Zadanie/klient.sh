#!/bin/bash
echo Podaj liczbe:
read liczba
echo $liczba > dane.txt

until [[ -e "tworek.txt" ]]; do
  if [[ -e "tworek.txt" ]]; then
    echo 1 > tworek.txt
  fi
done
if [[ -e "wyniki.txt" ]]; then
    wynik=$(cat "wyniki.txt")
fi

echo "Wynik to: "
echo $wynik
rm dane.txt

exit
