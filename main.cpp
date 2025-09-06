#include <string.h>
#include "my_string_functions.h"

#define CONSOLE_RED        "\033[31m"
#define CONSOLE_GREEN      "\033[32m"
#define CONSOLE_YELLOW     "\033[33m"
#define CONSOLE_PIRPLE     "\033[35m"
#define CONSOLE_RESET      "\033[39m"

#define RESSET_DATA(x, y) memcpy(x, "123456", sizeof("123456")), memcpy(y, "123456", sizeof("123456"));

static void print_test(const char * test_name,
                       const void * correct_ans, const void * reseived_ans, 
                       const char * format_specifier);

static void printf1(const char * x, const void * ans);

static bool is_equal(const char * format_specifier, const void * correct_ans, const void * reseived_ans);

int main(){
    char test_data_1[20] = "123456";
    char test_data_2[20] = "123456";

    print_test("my_strcat",    (const void*)strcat(test_data_2,"12"),
                               (const void*)my_strcat(test_data_1,"12"),           "%s");
    RESSET_DATA(test_data_1, test_data_2);
    
    print_test("my_strcpy",    (const void*)strcpy(test_data_1, "21"),
                               (const void*)my_strcpy(test_data_2,"21"),           "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strncpy 1", (const void*)strncpy(test_data_2,"21", 2),
                               (const void*)my_strncpy(test_data_1,"21", 2),       "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strncpy 2", (const void*)strncpy(test_data_2,"21", 1),
                               (const void*)my_strncpy(test_data_1,"21", 1),       "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strncat 1", (const void*)strncat(test_data_2,"12", 1),
                               (const void*)my_strncat(test_data_1,"12", 1),       "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strncat 2", (const void*)strncat(test_data_2,"12", 5),    
                               (const void*)my_strncat(test_data_1,"12", 5),       "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strlen",    (const void *)(strlen(test_data_1)),
                               (const void *)(my_strlen(test_data_1)),             "%zu");

    int ans_atoi_1 = atoi(test_data_1), ans_atoi_2 =  my_atoi(test_data_2);
    print_test("my_atoi",      (const void*)&ans_atoi_1,
                               (const void*)&ans_atoi_2,                           "%d");
    
    print_test("my_strchr",    (const void*)((size_t)strchr(test_data_2, '2')), 
                               (const void*)((size_t)my_strchr(test_data_2, '2')), "%zu");
    RESSET_DATA(test_data_1, test_data_2);

    FILE * x = fopen("test.txt", "r");
    my_fgets(test_data_1, 7, x);
    fgetc(x);
    my_fgets(test_data_2, 7, x);
    fclose(x);

    print_test("my_fgets",     (const void*)test_data_2,    
                               (const void*)test_data_1,                           "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strdup",    (const void*)((size_t)strdup(test_data_2)), 
                               (const void*)((size_t)my_strdup(test_data_2)),      "%s");
    RESSET_DATA(test_data_1, test_data_2);

    printf("Test:" CONSOLE_PIRPLE " my_puts: \n" CONSOLE_RESET);
    printf(CONSOLE_GREEN "Expected: ");
    puts(test_data_1);
    printf(CONSOLE_RESET);

    printf(CONSOLE_YELLOW "received: ");
    my_puts(test_data_1);
    printf(CONSOLE_RESET);

    return 0;
}

void print_test(const char * test_name, 
                const void * correct_ans, const void * reseived_ans,
                const char * format_specifier){
    if (test_name == 0 || correct_ans == 0 || reseived_ans == 0 || format_specifier == 0){
        printf(CONSOLE_RED   "Test was failed!\n" CONSOLE_RESET);
        return;
    }

    printf("Test: " CONSOLE_PIRPLE "%s\n" CONSOLE_RESET, test_name);

    printf(CONSOLE_GREEN  "Expected: ");
    printf1(format_specifier, correct_ans);
    printf("\n" CONSOLE_RESET);

    printf(CONSOLE_YELLOW  "Received: ");
    printf1(format_specifier, (const void *)reseived_ans);
    printf("\n" CONSOLE_RESET);

    if (is_equal(format_specifier, correct_ans, reseived_ans)){
        printf(CONSOLE_GREEN "Test was passed!\n" CONSOLE_RESET);
    }
    else{
        printf(CONSOLE_RED   "Test was failed!\n" CONSOLE_RESET);
    } 
    printf("____________________________\n");
}


void printf1(const char * format_specifier, const void * ans){
    if (strcmp(format_specifier, "\%s") == 0){
        printf("%s", (const char *)ans);
    }
    if (strcmp(format_specifier, "\%d") == 0){
        printf("%d", *(const int *)ans);
    }
    if (strcmp(format_specifier, "\%zu") == 0 || strcmp(format_specifier, "\%llu") == 0){
        printf("%llu", (uintptr_t)ans);
    }
}

bool is_equal(const char * format_specifier, const void * correct_ans, const void * reseived_ans){
    if (strcmp(format_specifier, "\%s") == 0){
        return strcmp((const char *)correct_ans, (const char *)reseived_ans) == 0;
    }
    if (strcmp(format_specifier, "\%d") == 0){
        return *((const int *)correct_ans) == *((const int *)reseived_ans);
    }

    if (strcmp(format_specifier, "\%zu") == 0 || strcmp(format_specifier, "\%llu") == 0){
        return (uintptr_t)correct_ans == (uintptr_t)reseived_ans;
    }

    return false;
}


