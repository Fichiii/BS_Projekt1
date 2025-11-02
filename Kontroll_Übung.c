#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int alter;
    int matrikelnummer;
    char name[64];
};

enum Farben{
    rot,
    blau,
    grün,
    lila
};

int main(void){
    //printf, putchar, puts
    int a = 42;
    printf("Best number: %d\n", a);

    char ch = 'c';
    putchar(ch);
    putchar('\n');

    char str[42] = "Was geht Yallah";
    puts(str);

    char* str_p = "Tobi riecht nach Kutschi!";
    puts(str_p); 

    //scanf, sscanf
    int c,d = 0;

    if(scanf("%d %d", &c,&d) < 2){
        puts("Fehler bei scanf!\n");
        exit(EXIT_FAILURE);
    }
    printf("%d %d\n",c,d);

    char out[42] = "67:99";
    int e,f = 0;
    if(sscanf(out,"%d:%d", &e,&f) < 2){
        puts("Fehler bei sscanf!\n");
        exit(EXIT_FAILURE);
    }

    printf("%d %d\n", e,f);

    //sprintf

    char string[64] = "Hallo";
    int h = 42;
    int i = 67;

    if(sprintf(string,"%d...%d", h, i) < 2){
        puts("Fehler bei sprintf!\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", string);

    printf("%ld\n",strlen(string));
    
    //strncpy

    char *string_p = "Dies ist ein Satz";
    char  string_cpy[18];

    strncpy(string_cpy, string_p, strlen(string_p));

    puts(string_cpy);

    //strncat
    char concatenate[64] = "Tobi mag";

    strncat(concatenate, " Füße!\n", strlen(concatenate));

    puts(concatenate);

    //strncmp

    char *tier = "Pferd";

    if(strncmp("Pferd", tier, strlen(tier)) != 0){
        puts("Fehler bei strncmp!\n");
        exit(EXIT_FAILURE);
    }

    puts("Compare kloppt\n");

    //strtok

    char tok[64] = "anna,otto,paul,gerold";

    char *iter = strtok(tok, ",");

    while(iter != NULL){
        puts(iter);

        iter = strtok(NULL, ",");
    }


    //structs
    struct student s1;
    s1.alter = 20;
    s1.matrikelnummer = 23452;

    //Strings kannst du nicht neu zuweisen, man muss es mit strncpy machen
    strncpy(s1.name, "Kevo", 64);

    puts(s1.name);

    //Enums
    enum Farben c1 = rot;
    enum Farben c2 = blau;
    if(c1 == rot) { puts("rot"); }    
    if(c2 == blau) { puts("blau"); }
return 0;
}
