#include <stdio.h>
#ifndef my_string_functions_h_
#define my_string_functions_h_

char * my_strncpy(char * new_str, const char * old_str, size_t len);

char * my_strcpy(char * new_str, const char * old_str);

size_t my_strlen(const char * str);

char * my_strchr(char * str, int symbol);

int my_puts(const char* str);

#endif