#include "test.h"

/*void printsubstring(String *s) ;
void initStringStruct(String *s, char *initialStr) ;
void freeStringStruct(String *s) ;
void printString(String *s) ;
void append_string(String *s, char *new_s) ;
void searchSubstring(String *text, String *pattern) ;
void searchSubstring_nocase(String *text, String *pattern) ;
char *createSubstring(String *str, int i, int j) ; */

void string_test_standart(){
    String test_str ;
    char* test_input = "DOCTOR" ;
    //тест инициализации
    initStringStruct(&test_str, test_input) ;
    if (test_str.length != 6 ) printf("SIZE ISNT CORRECT , ALLOCATE ERROR\n") ;
    append_string(&test_str, " Who") ;
    //тест добавления строки к строке
    if (strcmp(test_str.str, "DOCTOR Who") != 0) printf("STRING CUMCOTENNATION ERROR\n");
    //тест на создание подстроки и ее поиск
    char* test_substring =createSubstring(&test_str, 1, 8 ) ;
    if ( strcmp(test_substring,"DOCTOR W") != 0) printf("SUBSTRING CREATE ERROR\n") ;
    freeStringStruct(&test_str) ;
    free(test_substring) ;
}

void string_test_big_data(){
    String test_str ;
    char* test_input ="Mr and Mrs Dursley, of number four, Privet Drive, were proud tosay that they were perfectly normal, thank you very much. Theywere the last people you’d expect to be involved in anythingstrange or mysterious, because they just didn’t hold with suchnonsense.Mr Dursley was the director of a firm called Grunnings, whichmade drills. He was a big, beefy man with hardly any neck,although he did have a very large moustache. Mrs Dursley wasthin and blonde and had nearly twice the usual amount of neck,which came in very useful as she spent so much of her time craningover garden fences, spying on the neighbours. The Dursleys had asmall son called Dudley and in their opinion there was no finerboy anywhere.The Dursleys had everything they wanted, but they also had asecret, and their greatest fear was that somebody would discoverit. They didn’t think they could bear it if anyone found out aboutthe Potters. Mrs Potter was Mrs Dursley’s sister, but they hadn’tmet for several years; in fact, Mrs Dursley pretended she didn’thave a sister, because her sister and her good-for-nothing husbandwere as unDursleyish as it was possible to be. The Dursleysshuddered to think what the neighbours would say if the Pottersarrived in the street. The Dursleys knew that the Potters had asmall son, too, but they had never even seen him. This boy wasanother good reason for keeping the Potters away; they didn’twant Dudley mixing with a child like that.";
    initStringStruct(&test_str, test_input) ;
    if (test_str.length != strlen(test_input) ) printf("SIZE ISNT CORRECT , SIZE COUNT ERROR\n") ;
    append_string(&test_str,test_input) ;
    if (strcmp(test_str.str,"Mr and Mrs Dursley, of number four, Privet Drive, were proud tosay that they were perfectly normal, thank you very much. Theywere the last people you’d expect to be involved in anythingstrange or mysterious, because they just didn’t hold with suchnonsense.Mr Dursley was the director of a firm called Grunnings, whichmade drills. He was a big, beefy man with hardly any neck,although he did have a very large moustache. Mrs Dursley wasthin and blonde and had nearly twice the usual amount of neck,which came in very useful as she spent so much of her time craningover garden fences, spying on the neighbours. The Dursleys had asmall son called Dudley and in their opinion there was no finerboy anywhere.The Dursleys had everything they wanted, but they also had asecret, and their greatest fear was that somebody would discoverit. They didn’t think they could bear it if anyone found out aboutthe Potters. Mrs Potter was Mrs Dursley’s sister, but they hadn’tmet for several years; in fact, Mrs Dursley pretended she didn’thave a sister, because her sister and her good-for-nothing husbandwere as unDursleyish as it was possible to be. The Dursleysshuddered to think what the neighbours would say if the Pottersarrived in the street. The Dursleys knew that the Potters had asmall son, too, but they had never even seen him. This boy wasanother good reason for keeping the Potters away; they didn’twant Dudley mixing with a child like that.Mr and Mrs Dursley, of number four, Privet Drive, were proud tosay that they were perfectly normal, thank you very much. Theywere the last people you’d expect to be involved in anythingstrange or mysterious, because they just didn’t hold with suchnonsense.Mr Dursley was the director of a firm called Grunnings, whichmade drills. He was a big, beefy man with hardly any neck,although he did have a very large moustache. Mrs Dursley wasthin and blonde and had nearly twice the usual amount of neck,which came in very useful as she spent so much of her time craningover garden fences, spying on the neighbours. The Dursleys had asmall son called Dudley and in their opinion there was no finerboy anywhere.The Dursleys had everything they wanted, but they also had asecret, and their greatest fear was that somebody would discoverit. They didn’t think they could bear it if anyone found out aboutthe Potters. Mrs Potter was Mrs Dursley’s sister, but they hadn’tmet for several years; in fact, Mrs Dursley pretended she didn’thave a sister, because her sister and her good-for-nothing husbandwere as unDursleyish as it was possible to be. The Dursleysshuddered to think what the neighbours would say if the Pottersarrived in the street. The Dursleys knew that the Potters had asmall son, too, but they had never even seen him. This boy wasanother good reason for keeping the Potters away; they didn’twant Dudley mixing with a child like that."));
    char* test_substring =createSubstring(&test_str, 1, 2 ) ;
    if ( strcmp(test_substring,"Mr") != 0) printf("SUBSTRING CREATE ERROR\n") ;
    //тест поиска подстроки
    freeStringStruct(&test_str) ;
    free(test_substring) ;
}

void string_test_no_input(){
    String test_str ;
    char* test_input = "" ;
    //тест инициализации
    initStringStruct(&test_str, test_input) ;
    if (test_str.length != 0 ) printf("SIZE ISNT CORRECT , ALLOCATE ERROR\n") ;
    append_string(&test_str, "") ;
    //тест добавления строки к строке
    if (strcmp(test_str.str, "") != 0) printf("STRING CUMCOTENNATION ERROR\n");
    freeStringStruct(&test_str) ;
}