#include <string.h>
#include "my_string_functions.h"

int main(){
    char x[10] = "12345";
    char y[10];
    int l = 0;
    scanf("%s", y);
    scanf("%d", &l);

    printf("%s", x);
    my_strncpy(x, y, l);
    printf("%s", x);

}