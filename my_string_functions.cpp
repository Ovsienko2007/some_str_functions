#include "my_string_functions.h"

char * my_strncpy(char * new_str, const char * old_str, size_t len){
    if (len == 0){
        return new_str;
    }

    size_t symbol_num = 0;
    char current_character = NULL;
    do{
        current_character = old_str[symbol_num];
        new_str[symbol_num] = current_character;

        symbol_num++;
    } while (current_character != '\0' && symbol_num < len);
    if (symbol_num == len){
        new_str[len] = '\0';
    }
    
    return new_str;
}


char * my_strcpy(char * new_str, const char * old_str){
    int symbol_num = 0;
    char current_character = NULL;
    do{
        current_character = old_str[symbol_num];
        new_str[symbol_num] = current_character;

        symbol_num++;
    } while (current_character != '\0');
    
    return new_str;
}

char * my_strchr(char * str, int symbol){
    if (str == NULL){
        return NULL;
    }

    int symbol_num = 0;
    char current_character = NULL;

    do{
        current_character = str[symbol_num];
        
        if (current_character == symbol){
            return (char *)(str + symbol_num);
        }

        symbol_num++;
    } while (current_character != '\0');

    return NULL; 
}

size_t my_strlen(const char * str){
    if (str == NULL){
        return EOF;
    }

    char current_character = NULL;
    unsigned long long len = 0;
    do{
        current_character = str[len];
        len++;
    } while (current_character != '\0');

    return (len - 1) * sizeof(str[0]);
}


int my_puts(const char* str){
    if (str == NULL){
        return EOF;
    }

    int symbol_num = 0;
    char current_character = str[symbol_num];

    while (current_character != '\0'){
        putchar(current_character);
        symbol_num++;
        current_character = str[symbol_num];
    }

    if (current_character == '\0'){
        putchar('\0');
    }

    return 1;
}