/**
 * @file unit_test.h
 * @brief performs unit tests
 */

#ifndef UNIT_TEST_H_
#define UNIT_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_string_functions.h"

#define CONSOLE_RED        "\033[31m"
#define CONSOLE_GREEN      "\033[32m"
#define CONSOLE_YELLOW     "\033[33m"
#define CONSOLE_PIRPLE     "\033[35m"
#define CONSOLE_RESET      "\033[39m"

#define RESSET_DATA(x, y) memcpy(x, "123456", sizeof("123456")), memcpy(y, "123456", sizeof("123456"));

/**
 * @brief complit unit tests
 * 
 * @return 0
 */
int start_unit_test();

#endif