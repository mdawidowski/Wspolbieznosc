#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
  char tekst[1000] = "";
  int bufor = open("bufor.txt", O_RDWR);
   FILE *buforek = fopen("bufor.txt", "w");
  if(buforek){
    char cz[1] = "";
    write(bufor, "Klient pisze: ", 14);
    fprintf(buforek, "%s", cz);
    fclose(buforek); }

  printf("Podaj tresc wiadomosci:\n");
  gets(tekst);
  write(bufor, tekst, 1000);

  close(bufor);
  while(open("lockfile", O_CREAT|O_EXCL, 0) == -1){
    printf("Serwer zajety, prosze czekac\n");
    sleep(5); }

    FILE *buforek2  = fopen("bufor.txt", "r");
    if(buforek2){
      char slowo[100];
      char c;
      while((c = fscanf(buforek2, "%s", slowo)) != EOF){
        printf("%s " , slowo); }
      printf("\n");
      fclose(buforek2); }
    else printf("Nie mozna odczytac zawartosci bufora.\n");

  return 0;
}
