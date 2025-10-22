#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//Überprüfe auf Palindrom
bool check_palindrom(char *iter)
{
    int länge = strlen(iter);

    int links = 0;
    int rechts = länge - 1;

    while(links < rechts)
    {
        if(iter[links] != iter[rechts]) { return false; }

        ++links;
        --rechts;
    }
    return true;
}


int search_palindrom(char* argv[])
{
    //counter für Anzahl palindrome
    static int counter = 0;

    //Lese das Intervall und speicher die Werte in start und end
    int start = 0;
    int end = 0;
    
    //Fehlerbehandlung, falls keine Zahl eingegeben wird
    if(sscanf(argv[2],"%d:%d",&start,&end) < 2)
    {
        perror("Gib normale Integer als Intervall an!\n");
        exit(EXIT_FAILURE);
    }

    //Fehlerbehandlung
    if(start > end) 
    { 
        perror("Der Start vom Intervall darf nicht größer als das Ende sein !\n");
        exit(EXIT_FAILURE);
    }

    if(start < 0 || end < 0)
    {
        perror("Intervall darf nicht negativ sein!\n");
        exit(EXIT_FAILURE);
    }

    //Index des momentanen Wortes
    int current_word_index = 0;

    //Pointer auf den Anfang des ersten Wortes
    char *iter = strtok(argv[1], ",");
    while(iter != NULL)
    {
    //Nur wenn Wort im Intervall liegt wird dieses überprüft
    if(current_word_index >= start && current_word_index <= end)
        {
            if(check_palindrom(iter))
            {
                ++counter;
            }  
        }
            iter = strtok(NULL,",");
            ++current_word_index;
    }

    return counter;
}

int main(int argc, char *argv[]) {
    //Wenn zu viele oder zu wenig Argumente ERROR
    if(argc !=3)
    { 
        if(argc < 3) { perror("Zu wenig Argumente!\n"); }
        else { perror("Zu viele Argumente!\n"); }
        exit(EXIT_FAILURE);
    }

    int palindrom_counter = search_palindrom(argv);
    printf("Anzahl Palindrome: %d\n", palindrom_counter);
    return 0;
}