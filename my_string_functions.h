#ifndef my_string_functions_h_
#define my_string_functions_h_

#include <stdio.h>
#include <stdlib.h>

//TODO documentation

char * my_getline(char *str, int num_chars, FILE *stream);

char * my_strdup(const char *str);

char * my_fgets(char *str, int numChars, FILE *stream);

int my_atoi(const char * str);

char * my_strncat(char * str_dest, const char * str_add, size_t len);

char * my_strcat(char * str_dest, const char * str_add);

char * my_strncpy(char * new_str, const char * old_str, size_t len);

char * my_strcpy(char * new_str, const char * old_str);

size_t my_strlen(const char * str);

char * my_strchr(char * str, int symbol);

int my_puts(const char* str);

#endif