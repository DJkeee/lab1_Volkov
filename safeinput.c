#include <string.h>
#include "safeinput.h"
#include "mystring.h"
int IntInput() {
    int num;
    while (1) {
        if (scanf("%d", &num) != 1) {
            printf("Please, enter correct int input : ");
            while (getchar() != '\n'); // очистка буфера
        } else {
            while (getchar() != '\n'); // очистка буфера
            return num;
        }
    }
}
#include <stdio.h>

int positiveInput() {
    int num;
    while (1) {
        if (scanf("%d", &num) != 1 || num <= 0) {
            printf("Please,enter correct POSITIVE input : ");
            while (getchar() != '\n'); // очистка буфера
        } else {
            while (getchar() != '\n'); // очистка буфера
            return num;
        }
    }
}
int switch_input() {
    int num;
    while (1) {
        if (scanf("%d", &num) != 1 || num <= 0 || num > 5) {
            printf("Please,enter correct input from 1 to 5: ");
            while (getchar() != '\n'); // очистка буфера
        } else {
            while (getchar() != '\n'); // очистка буфера
            return num;
        }
    }
}

char* getInputString() {
    int bufferSize = 20;
    char *input = (char*)malloc(bufferSize);
    int index = 0;
    int c;

    if (input == NULL) {
        printf("input string error!!!\n");
        exit(1);
    }

    while (1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            input[index] = '\0'; // Добавляем нуль-терминатор
            break;
        }
//если вводить текст книги в несколько строк ,то \n будет и я засру буффер
        input[index] = c;
        index++;

        if (index >= bufferSize - 1) {
            bufferSize *= 2;
            input = (char*)realloc(input, bufferSize);
            if (input == NULL) {
                printf("STRING MEMORY ALLOCATION ERROR\n");
                exit(1);
            }
        }
    }

    return input;


}

int safe_positive_integer() {
    int number;
    while (1) {
        printf("Enter Positive value \n");
        if (scanf("%d", &number) != 1) {
            printf("Uncorrect\n");
            // Очищаем буфер
            while (getchar() != '\n');
            continue;
        }

        if (number <= 0) {
            printf("Enter POSITIVE value\n");
            continue;
        }

        break;
    }

    return number;
}

