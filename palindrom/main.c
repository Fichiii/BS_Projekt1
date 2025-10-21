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

    //Pointer die auf den Anfang und auf das Ende des Intervalls zeigen
    char *start_str = strtok(argv[2], ":");
    char *end_str = strtok(NULL, ":");

    //Umwandlung in int
    int start = atoi(start_str);
    int end = atoi(end_str);

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
                printf("Palindrom!\n");
                ++counter;
            }  
            else
            {
                printf("Kein Palindrom!\n");
            }
        }
            iter = strtok(NULL,",");
            ++current_word_index;
    }

    return counter;
}

int main(int argc, char *argv[]) {
    //Wenn zu viele oder zu wenig Argumente ERROR
    if(argc < 3 || argc > 3)
    { 
        if(argc < 3) { perror("Zu wenig Argumente!\n"); }
        else { perror("Zu viele Argumente!\n"); }
        exit(EXIT_FAILURE);
    }

    int palindrom_counter = search_palindrom(argv);
    printf("Anzahl Palindrome: %d\n", palindrom_counter);
    return 0;
}