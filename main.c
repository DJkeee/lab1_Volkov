#include "mystring.h"
#include "safeinput.h"
#include "test.h"
void printMenu()
{
    printf("\n 1. Add string to string(concatenation) ") ;
    printf("\n 2. find substring with case sensitive ") ;
    printf("\n 3. find substring with no case sensitive ") ;
    printf("\n 4. create substring ") ;
    printf("\n 5. EXIT\n") ;

}

    int main() {
         //3 теста
         string_test_standart(), string_test_big_data(), string_test_no_input();
         //кончились 3 теста,если вывода нет,то все ок
        int choice = 1;
        printf("\nInput your string: ");
        char* input = getInputString() ;
        String mystring;
        initStringStruct(&mystring,input) ;
        printString(&mystring) ;
        free(input) ;
        String test_string;


        do {
            printMenu();
            printf("Enter your choice: \n");
            choice = switch_input();

            switch (choice) {
                        case 1:
                            printf("\n Now add new string to your string(concatenation): ");
                            input = getInputString() ;
                            append_string(&mystring ,input ) ;
                            printString(&mystring) ;
                            free(input) ;
                    break;
                        case 2:
                             printf("\nnow enter your substring to find with case sensetive: ") ;
                            char* input_sub_str = getInputString();
                            String sub_string;
                            initStringStruct(&sub_string, input_sub_str);
                            searchSubstring(&mystring, &sub_string);
                            freeStringStruct(&sub_string);
                    break;

                        case 3:
                            printf("\nnow enter your substring to find with no case sensetive: ");
                            input_sub_str = getInputString();
                            String substring;
                            initStringStruct(&substring, input_sub_str);
                            searchSubstring_nocase(&mystring, &substring);
                            freeStringStruct(&substring);
                            free(input_sub_str) ;
                    break;
                        case 4:

                            printf("Now enter two number form [i] to [j] to create substr \n");
                              String Saved_substr ;
                              int i =  safe_positive_integer() ;
                              int j =  safe_positive_integer() ;
                              char* Save_sub = createSubstring(&mystring,i,j) ;
                              initStringStruct(&Saved_substr,Save_sub) ;
                               printsubstring(&Saved_substr ) ;

                    break;

                        case 5:
                            printf("\nEXTERMINATED CODE,KARAMBA\n");
                            freeStringStruct(&mystring) ;
                            if(Saved_substr.str != NULL) ;
                            freeStringStruct(&Saved_substr) ;
                            free(input) ;
                    break;

                    }
            } while (choice != 5);

        }