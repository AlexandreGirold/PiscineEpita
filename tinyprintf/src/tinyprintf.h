#ifndef TINYPRINTF_H
#define TINYPRINTF_H

#include <stddef.h>

void print(char *s, int *result);

void my_itoa_base(int n, char *s, const char *base);

void switches(char *p, int *result, va_list args);

int tinyprintf(const char *format, ...);

#endif /* !TINYPRINTF_H */
