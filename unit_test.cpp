#include "unit_test.h"

/**
 * @brief check if test correct
 * 
 * @param [in] format_specifier  format of answer
 * @param [in] correct_ans       correct test answer
 * @param [in] reseived_ans      reseived test answer 
 */
static bool is_equal(const char * format_specifier, const void * correct_ans, const void * reseived_ans);

/**
 * @brief print answer
 * 
 * @param [in] format_specifier  format of output 
 * @param [in] ans               reseived test answer 
 */
static void print_test_res(const char * format_specifier, const void * ans);


/**
 * @brief print result of test
 * 
 * @param [in] test_name         test name 
 * @param [in] correct_ans       correct test answer
 * @param [in] reseived_ans      reseived test answer 
 * @param [in] format_specifier  format of output 
 */
static void print_test(const char * test_name, 
                const void * correct_ans, const void * reseived_ans,
                const char * format_specifier);

int start_unit_test(){
    char test_data_1[20] = "123456";
    char test_data_2[20] = "123456";
    
    print_test("my_strcpy",    (const void*)strcpy(test_data_1, "21"),
                               (const void*)my_strcpy(test_data_2,"21"),           "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strncpy 1", (const void*)strncpy(test_data_2,"21", 5),
                               (const void*)my_strncpy(test_data_1,"21", 5),       "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strncpy 2", (const void*)strncpy(test_data_2,"21", 1),
                               (const void*)my_strncpy(test_data_1,"21", 1),       "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strcat",    (const void*)strcat(test_data_2,"12"),
                               (const void*)my_strcat(test_data_1,"12"),           "%s");
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

    FILE * file = fopen("test.txt", "r");
    my_fgets(test_data_1, 8, file);
    my_fgets(test_data_2, 8, file);
    size_t n = 6;
    char* str = (char*)calloc(n, sizeof(char));
    my_getline(&str, &n, file);
    printf("%s\n", str);
    fclose(file);

    print_test("my_fgets",     (const void*)test_data_2,    
                               (const void*)test_data_1,                           "%s");
    RESSET_DATA(test_data_1, test_data_2);

    print_test("my_strdup",    (const void*)((size_t)strdup(test_data_2)), 
                               (const void*)((size_t)my_strdup(test_data_2)),      "%s");
    
    printf("Test:" CONSOLE_PIRPLE " my_getline: \n" CONSOLE_RESET);
    printf(CONSOLE_GREEN "Getted: ");
    printf("%s\n", str);
    printf(CONSOLE_RESET);
    printf("____________________________\n");

    printf("Test:" CONSOLE_PIRPLE " my_puts: \n" CONSOLE_RESET);
    printf(CONSOLE_GREEN "Expected: ");
    puts(test_data_1);
    printf(CONSOLE_RESET);

    printf(CONSOLE_YELLOW "Received: ");
    my_puts(test_data_1);
    printf(CONSOLE_RESET);

    return 0;
}

static void print_test_res(const char * format_specifier, const void * ans){
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

static bool is_equal(const char * format_specifier, const void * correct_ans, const void * reseived_ans){
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

static void print_test(const char * test_name, 
                const void * correct_ans, const void * reseived_ans,
                const char * format_specifier){
    if (test_name == 0 || correct_ans == 0 || reseived_ans == 0 || format_specifier == 0){
        printf(CONSOLE_RED   "Test was failed!\n" CONSOLE_RESET);
        return;
    }

    printf("Test: " CONSOLE_PIRPLE "%s\n" CONSOLE_RESET, test_name);

    printf(CONSOLE_GREEN  "Expected: ");
    print_test_res(format_specifier, correct_ans);
    printf("\n" CONSOLE_RESET);

    printf(CONSOLE_YELLOW  "Received: ");
    print_test_res(format_specifier, (const void *)reseived_ans);
    printf("\n" CONSOLE_RESET);

    if (is_equal(format_specifier, correct_ans, reseived_ans)){
        printf(CONSOLE_GREEN "Test was passed!\n" CONSOLE_RESET);
    }
    else{
        printf(CONSOLE_RED   "Test was failed!\n" CONSOLE_RESET);
    } 
    printf("____________________________\n");
}