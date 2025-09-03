#include "my_string_functions.h"

char * my_getline(char *str, int num_chars, FILE *stream){
    return my_strdup(my_fgets(str, num_chars, stream));   
}

char * my_strdup(const char *str){
    if (str == 0){
        return 0;
    }
    size_t len = my_strlen(str);
    char * new_str = (char *)calloc(len + 1, sizeof(char));

    for (unsigned int str_position = 0; str_position < len; str_position++){
        new_str[str_position] = str[str_position];
    }

    return new_str;
}

char * my_fgets(char *str, int num_chars, FILE *stream){
    if (str == NULL && stream == NULL){
        return NULL;
    }

    int new_symbol = 0;
    int str_position = 0;
    while (str_position < num_chars){
        new_symbol = fgetc(stream);
        if (new_symbol == EOF){
            return str;
        }
        str[str_position] = (char)new_symbol;
        str_position++;
    }
    
    return str;
}

int my_atoi(const char * str){
    if (str== NULL){
        return NULL;
    }

    int ans = 0;
    unsigned int str_position = 0;
    do {
        if (!('0' <= str[str_position] && str[str_position] <= '9')){
            return NULL;
        }
        ans = ans * 10 + (str[str_position] - '0');
        str_position++;

    } while(str[str_position] != '\0');

    return ans;
}

char * my_strncat(char *str_dest, const char *str_add, size_t len){
    if (str_dest == NULL || str_add == NULL){
        return NULL;
    }

    if (len == 0){
        return str_dest;
    }

    unsigned int str_position = 0;
    do {
        str_position++;

    } while(str_dest[str_position] != '\0');

    unsigned int str_add_position = 0; 
    while (str_add[str_add_position] != '\0' && str_add_position < len){
        str_dest[str_position] = str_add[str_add_position];
        str_position++;
        str_add_position++;
    }
    str_dest[str_position] = str_add[str_add_position];

    if (str_add_position == len){
        str_dest[str_position] = '\0';
    } else{
        str_dest[str_position] = str_add[str_add_position];
    }

    return str_dest;
}

char * my_strcat(char * str_dest, const char * str_add){
    if (str_dest == NULL || str_add == NULL){
        return NULL;
    }

    unsigned int  str_position = 0;
    do {
        str_position++;

    } while(str_dest[str_position] != '\0');

    unsigned int  str_add_position = 0; 
    while (str_add[str_add_position] != '\0'){
        str_dest[str_position] = str_add[str_add_position];
        str_position++;
        str_add_position++;
    }
    str_dest[str_position] = str_add[str_add_position];

    return str_dest;
}

char * my_strncpy(char * new_str, const char * old_str, size_t len){
    if (len == 0){
        return new_str;
    }

    if (new_str == NULL || old_str == NULL){
        return NULL;
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
    if (new_str == NULL || old_str == NULL){
        return NULL;
    }

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

    return len - 1;
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