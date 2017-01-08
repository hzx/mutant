#pragma once


/*
 * If method return number < 0 is error
 * If method return number >= 0 is result
 * Error groups:
 * 1000 - loader
 * 2000 - preprocessor
 * 3000 - lexer
 * 4000 - parser
 * 5000 - analyzer
 * 6000 - formatter
 */


int const ERROR_OK = 0;
int const ERROR_NOT_IMPLEMENTED = -1;
int const ERROR_INI_NO_CLOSE_BRACKET = -101;
int const ERROR_INI_NO_GROUP_FOR_VALUE = -102;

/* 1000 - app */

int const APP_CONFIG_NOT_EXISTS = -1001;

/* 2000 - compiler */

/* 3000 - loader */

/* 4000 - preprocessor */

/* 5000 - lexer */

/* 6000 - parser */

/* 7000 - analyzer */

/* 8000 - formatter */


inline bool isError(int error) {
  return error < ERROR_OK;
}
