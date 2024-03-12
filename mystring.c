#include "mystring.h"
#include "safeinput.h"


// Функция инициализации строки в структуре
void initStringStruct(String *s, char *initialStr) {
    s->length = strlen(initialStr);
    s->str = (char *)malloc((s->length + 1) * sizeof(char));
    if (s->str == NULL) {
        // Обработка ошибки - например, вывод сообщения об ошибке и выход из функции
        printf("CANNOT ALLOCATE MEMORY FOR STRUCT\n");
        return ;
    }
    strcpy(s->str, initialStr);
}

// Функция освобождения памяти, занятой под строку в структуре
void freeStringStruct(String *s) {
    free(s->str);
    s->length = 0;
}

void printString(String *s) {
    if (s->str != NULL) {
        printf("\nYour string: ") ;
        printf("%s\n", s->str);
    }
    else printf ("Your string is NULL") ;
}
void printsubstring(String *s) {
    if (s->str != NULL) {
        printf("\nYour substring: ") ;
        printf("%s\n", s->str);
    }
    else printf("Your substring is NULL") ;
}

void append_string(String *s, char *added_s) {
    int newLength = s->length + strlen(added_s);
    char *newStr = malloc(newLength + 1); // +1 для нуль-терминатора
    if (newStr == NULL) {
        printf("Memory error in malloc,NULL returned\n");
        return ;
    }

    strcpy(newStr, s->str);
    strcat(newStr, added_s); //все хорошо,потому что каждая строка имеет /0 и все функции с ними пашут

    free(s->str);
    s->str = newStr;
    s->length = newLength;

    s->str[newLength] = '\0'; // Добавляем нуль-терминатор в конец новой строки,чтоб было в кайф
}

char *createSubstring(String *str, int i, int j) {
    // Уменьшаем индексы на 1, чтобы они соответствовали индексам в си
    i = i - 1;
    j = j - 1;

    if (i < 0 || j < 0 || i > j || i >= str->length || j >= str->length) {
        printf("Invalid indices. Returning NULL.\n");
        return NULL;
    }

    int length = j - i + 1;
    char *substr = malloc(length + 1);
    strncpy(substr, str->str + i, length);
    substr[length] = '\0';

    return substr;
}
//больно
void searchSubstring(String *text, String *pattern) {
    int n = text->length;
    int m = pattern->length;
//на случай ввода пустого паттерна поиска
    if (m == 0 || n == 0) {
        printf("The substring starts with index 1\n");
        return ;
    }

    if (n < m) {
        printf("Your substring is bigger than string\n");
        return;
    }

    int next[m + 1];
    next[0] = -1;

    for (int i = 0, j = -1; i < m;) {
        while (j >= 0 && pattern->str[i] != pattern->str[j]) {
            j = next[j];
        }
        next[++i] = ++j;
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j >= 0 && text->str[i] != pattern->str[j]) {
            j = next[j];
        }

        j++;
        if (j == m) {
            printf("Your substring starting with index: %d\n", i - j + 1);
            j = next[j];
        }
    }
}



void searchSubstring_nocase(String *text, String *pattern) {
    int n = text->length;
    int m = pattern->length;

    if (m == 0 || n == 0) {
        printf("The substring starts with index 1\n");
        return;
    }

    if (n < m) {
        printf("Your substring is bigger than string \n");
        return;
    }

    char *textCopy = strdup(text->str);
    char *patternCopy = strdup(pattern->str);


    for (int i = 0; i < m; i++) {
        patternCopy[i] = tolower(patternCopy[i]);
    }

    for (int i = 0; i < n; i++) {
        textCopy[i] = tolower(textCopy[i]);
    }

    int next[m + 1];
    next[0] = -1; //-1 для сдвига на 1 эллемент,если мы не нашли совпадений для сдвига
    //
    for (int i = 0, j = -1; i < m;) {
        while (j >= 0 && patternCopy[i] != patternCopy[j]) { //j обновляется, используя значение из массива next==
            // сдвиг паттерна на правильные позиции при несовпадении
            j = next[j];
        }
        next[++i] = ++j;
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j >= 0 && textCopy[i] != patternCopy[j]) {
            j = next[j];
        }

        j++;
        if (j == m) {
            printf("Your substring starting with index: %d\n", i - j + 1);
            j = next[j];
            i -= m - 1;
        }
    }

    free(textCopy);
    free(patternCopy);
}



