#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <linux/stat.h>
#include <string.h>
#define SERWERFIFO "serwerfifo"
#define KLIENTFIFO "klientfifo"

int main(int argc, char const *argv[]) {
  FILE *input,*output;
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
  output = fopen(SERWERFIFO, "w");
  fprintf(output, "%d%s",i,tekst);
  fclose(output);

  input = fopen(KLIENTFIFO, "r");
  fgets(bufor, 70, input);
  fclose(input);
  printf("%s\n", bufor);

  return 0;
}
