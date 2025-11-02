#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool check_palindrom(char *word){
    unsigned int left = 0;
    unsigned int right = strlen(word) - 1;

    while(left <= right){
        if(word[left] != word[right]){
            return false;
        }
        ++left;
        --right;
    }
    return true;
}




int main (int argc, char *argv[]){
    if(argc != 3){
        puts("Zu viele zu wenig Eingaben!");
        exit(EXIT_FAILURE);
    }

    int current_word = 0;

    int left,right = 0;

    if(sscanf(argv[2], "%d:%d", &left, &right) < 2){
        puts("Eingabeformat des Intervalls falsch!");
        exit(EXIT_FAILURE);
    }

    if(left > right){
        puts("Anfang des Intervalls kann nicht größer als das Ende sein!");
        exit(EXIT_FAILURE);
    }

    if(left < 0 || right < 0){
        puts("Intervall kann nicht negativ sein!");
        exit(EXIT_FAILURE);
    }

    int counter = 0;
    char* iter = strtok(argv[1], ",");

    while(iter != NULL && current_word <= right){
        if(current_word >= left && current_word <= right){
            if(check_palindrom(iter)) { ++counter; } 
        }

        iter = strtok(NULL, ",");

        ++current_word;
    }

    printf("Anzahl Palindrome: %d \n", counter);

    return 0;
}