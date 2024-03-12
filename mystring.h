#ifndef IWANTC___MYSTRING_H
#define IWANTC___MYSTRING_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
typedef struct {
    char *str;
    int length;
} String;

void printsubstring(String *s) ;
void initStringStruct(String *s, char *initialStr) ;
void freeStringStruct(String *s) ;
void printString(String *s) ;
void append_string(String *s, char *new_s) ;
void searchSubstring(String *text, String *pattern) ;
void searchSubstring_nocase(String *text, String *pattern) ;
char *createSubstring(String *str, int i, int j) ;
#endif //IWANTC___MYSTRING_H
