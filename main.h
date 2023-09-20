#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct format - Struct operator
 *
 * @fmt: The format.
 * @func: The function associated.
 */
struct format {
  char fmt;
  int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct format fmt_t;

int _printf(const char *format, ...);
int _handlePrint(const char *format, int *i, va_list list, char buffer[],
                 int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int _printChar(va_list types, char buffer[], int flags, int width,
               int precision, int size);
int _printString(va_list types, char buffer[], int flags, int width,
                 int precision, int size);
int _printPercent(va_list types, char buffer[], int flags, int width,
                  int precision, int size);

/* Functions to print numbers */
int _printInt(va_list types, char buffer[], int flags, int width, int precision,
              int size);
int _printBinary(va_list types, char buffer[], int flags, int width,
                 int precision, int size);
int _printUnsigned(va_list types, char buffer[], int flags, int width,
                   int precision, int size);
int _printOctal(va_list types, char buffer[], int flags, int width,
                int precision, int size);
int _printHexadecimal(va_list types, char buffer[], int flags, int width,
                      int precision, int size);
int _printHexUpper(va_list types, char buffer[], int flags, int width,
                   int precision, int size);

int _printHex(va_list types, char map_to[], char buffer[], int flags,
              char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int _printNonPrintable(va_list types, char buffer[], int flags, int width,
                       int precision, int size);

/* Functions to handle other specifiers */
int _getFlags(const char *format, int *i);
int _getWidth(const char *format, int *i, va_list list);
int _getPrecision(const char *format, int *i, va_list list);
int _getSize(const char *format, int *i);

/* Functions to print memory address */
int _printPointer(va_list types, char buffer[], int flags, int width,
                  int precision, int size);

/*Function to print string in reverse*/
int _printReverse(va_list types, char buffer[], int flags, int width,
                  int precision, int size);

int _handleWriteChar(char c, char buffer[], int flags, int width, int precision,
                     int size);
int _writeNumber(int positive, int ind, char buffer[], int flags, int width,
                 int precision, int size);
int _writeNum(int indent, char buff[], int flags, int width, int precision,
              int length, char padd, char extra_c);
int _writePointer(char buffer[], int ind, int length, int width, int flags,
                  char padd, char extra_chars, int padding_start);
int _writeUnsigned(int negative, int ind, char buffer[], int flags, int width,
                   int precision, int size);

/*Function to print a string in rot 13*/
int _printRot13String(va_list types, char buffer[], int flags, int width,
                      int precision, int size);

/* Utils */
int _isPrintable(char);
int _appendHexaCode(char, char[], int);
int _isDigit(char);

/* width handler */

long int _convertSizeNumber(long int number, int size);
long int _convertSizeUnsigned(unsigned long int number, int size);

#endif
