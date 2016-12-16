#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <linux/stat.h>
#include <string.h>
#include <ctype.h>

#define SERWERFIFO "serwerfifo"
#define KLIENTFIFO "klientfifo"

struct names{
  int ID;
  char *name;
};

int main() {
  FILE *input, *output;
  int digit=0, length = 0, numer, j=0;
  char bufor[70] = "", indeks[0] = "";
  struct names spis[20];
  spis[0].name = "Fabianski";
  spis[1].name = "Wasilewski";
  spis[2].name = "Pazdan";
  spis[3].name = "Jodlowiec";
  spis[4].name = "Piszczek";
  spis[5].name = "Formela";
  spis[6].name = "Lewandowski";
  spis[7].name = "Boruc";
  spis[8].name = "Milik";
  spis[9].name = "Zielinski";
  spis[10].name = "Teodorczyk";
  spis[11].name = "Krychowiak";
  spis[12].name = "Blaszczykowski";
  spis[13].name = "Glik";
  spis[14].name = "Grosicki";
  spis[15].name = "Kapustka";
  spis[16].name = "Peszko";
  spis[17].name = "Kucharczyk";
  spis[18].name = "Szczesny";
  spis[19].name = "Robak";
  char user[15] = "";
  char answer[70] = "";
  while (1) {
    int i=0,length = 0;
    numer = 0;
    for(int z = 0; z < sizeof(bufor); z++) bufor[z] = '\0';
    for(int z = 0; z < sizeof(answer); z++) answer[z] = '\0';
    input = fopen(SERWERFIFO, "r");
    fgets(bufor, 70, input);
    fclose(input);
    while (isdigit(bufor[digit])) {
      digit+=1;
    }
    while (bufor[length]!='\0') {
      length+=1;
    }
    if (length>=10) {
      indeks[0] = bufor[2];
      indeks[1] = bufor[3];
    } else {
      indeks[0] = bufor[2];
    }
    for (i=2;i<=10;i++){
      indeks[i]='\0';
    }
    for(int i=digit+6;i<length;i++){
        user[j] = bufor[i];
        j++;
    }
    numer = atoi(indeks);
    if (numer>=20) {
      strcpy(answer, "nie ma");
    } else {
      sscanf(spis[numer].name, "%s", answer);
    }
    if (digit>=5) {
      strcpy(answer, "nie ma");
    }
    output = fopen(KLIENTFIFO,"w");
    fprintf(output, "%s", answer);
    fclose(output);
  }
  return 0;
}
