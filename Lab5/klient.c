#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <linux/stat.h>
#include <fcntl.h>
#include <string.h>
#define SERWERFIFO "serwerfifo"
#define KLIENTFIFO "klientfifo"
#define PERM 0777
int main(int argc, char const *argv[]) {
  FILE *input;
  int output, licz=20;
  char liczba[70];
  char *home = getenv("HOME"),tekst[100], bufor[70];
  int i=0;

  if(argc != 2){
    printf("Brak parametru!\n");
    exit(1); }

  strcat(tekst, argv[1]);
  strcat(tekst, home);
  while (tekst[i]!='\0') {
    i+=1;
  }
  if((output = open(SERWERFIFO, O_WRONLY|O_CREAT|O_TRUNC, PERM)) == -1)
   {
   return(-2);
 }
  sprintf(liczba, "%d%s", i, tekst);

  write(output, liczba, licz);
  close(output);

  input = fopen(KLIENTFIFO, "r");
  fgets(bufor, 70, input);
  fclose(input);
  printf("%s\n", bufor);

  return 0;
}
