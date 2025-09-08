#include "my_string_functions.h"

ssize_t my_getline(char **str, size_t *n, FILE *stream){
    if (str == NULL || stream == NULL){
        return NULL;
    }

    *str = (char *)calloc(*n, sizeof(char));
    
    size_t str_position = 0;
    int new_symbol = fgetc(stream);

    for (; new_symbol != EOF && new_symbol != '\n';
         str_position++, new_symbol = fgetc(stream)){

        if (str_position == *n){
            *n += 1;
            *str = (char *)realloc(*str, (*n)*sizeof(char));
        }

        (*str)[str_position] = (char)new_symbol;
    }

    (*str)[str_position] = '\0';
    
    return *n;
}

char * my_strdup(const char *str){
    if (str == 0) return NULL;

    size_t len = my_strlen(str);
    char * new_str = (char *)calloc(len + 1, sizeof(char));

    if (new_str == NULL) return NULL;

    for (unsigned int str_position = 0; str_position < len; str_position++){
        new_str[str_position] = str[str_position];
    }

    return new_str;
}

char * my_fgets(char *str, int num_chars, FILE *stream){
    if (str == NULL || stream == NULL){
        return NULL;
    }
    
    int str_position = 0;
    for (; str_position < num_chars - 1; str_position++){
        int new_symbol = fgetc(stream);
        str[str_position] = (char)new_symbol;

        if (new_symbol == EOF || new_symbol == '\n'){
            str_position++;
            break;
        }
    }
    str[str_position] = '\0';
    
    return str;
}

int my_atoi(const char * str){
    if (str== NULL) return NULL;

    bool less_than_zero = false;
    if (str[0] == '-'){
        less_than_zero = true;
    }

    int ans = 0;
    size_t str_position = (size_t)less_than_zero;
    for (; str[str_position] != '\0'; str_position++){
        if (!('0' <= str[str_position] && str[str_position] <= '9')){
            return NULL;
        }
        ans = ans * 10 + (str[str_position] - '0');
    }

    return less_than_zero ? -ans : ans;
}

char * my_strncat(char *str_dest, const char *str_add, size_t len){
    if (str_dest == NULL || str_add == NULL) return NULL;
    if (len == 0)  return str_dest;

    size_t str_position = 0;
    for (; str_dest[str_position] != '\0'; str_position++)
        ;

    size_t str_add_position = 0; 
    for (;str_add[str_add_position] != '\0' && str_add_position < len;
         str_position++, str_add_position++){

        str_dest[str_position] = str_add[str_add_position];
    }
    str_dest[str_position] = str_add[str_add_position];

    if (str_add_position == len){
        str_dest[str_position] = '\0';
    }

    return str_dest;
}

char * my_strcat(char * str_dest, const char * str_add){
    if (str_dest == NULL || str_add == NULL) return NULL;

    size_t str_position = 0;
    for (; str_dest[str_position] != '\0'; str_position++)
        ;

    size_t str_add_position = 0;
    for (; str_add[str_add_position] != '\0'; str_add_position++, str_position++){
        str_dest[str_position] = str_add[str_add_position];
    }

    str_dest[str_position] = str_add[str_add_position];

    return str_dest;
}

char * my_strncpy(char * new_str, const char * old_str, size_t len){
    if (new_str == NULL || old_str == NULL) return NULL;
    if (len == 0) return new_str;

    size_t symbol_num = 0;
    for (; symbol_num < len; symbol_num++){
        new_str[symbol_num] = old_str[symbol_num];
        if (old_str[symbol_num] == '\0'){
            break;
        }
    }

    return new_str;
}

char * my_strcpy(char * new_str, const char * old_str){
    if (new_str == NULL || old_str == NULL) return NULL;
    
    int symbol_num = 0;
    for (; old_str[symbol_num] != '\0'; symbol_num++){
        new_str[symbol_num] = old_str[symbol_num];
    }

    new_str[symbol_num] = old_str[symbol_num];
    
    return new_str;
}

char * my_strchr(char * str, int symbol){
    if (str == NULL) return NULL;

    for (int symbol_num = 0; str[symbol_num] != '\0'; symbol_num++){
        if (str[symbol_num] == symbol){
            return (char *)(str + symbol_num);
        }
    }

    return NULL; 
}

size_t my_strlen(const char * str){
    if (str == NULL) return EOF;

    size_t len = 0;
    for (;  str[len] != '\0'; len++)
        ;

    return len;
}

int my_puts(const char* str){
    if (str == NULL) return EOF;

    for (int symbol_num = 0; str[symbol_num] != '\0'; symbol_num++){
        putchar(str[symbol_num]);
    }
    putchar('\n');

    return 1;
}