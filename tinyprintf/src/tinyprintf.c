#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int len(const char *base)
{
    int len = 0;
    while (base[len] != '\0')
    {
        len++;
    }
    return len;
}

void print(char *s, int *result)
{
    int i = 0;
    while (s[i] != '\0')
    {
        putchar(s[i]);
        (*result)++;
        i++;
    }
}

void my_itoa_base(int n, const char *base, int *result)
{
    int isneg = (n < 0) ? 1 : 0; // is not neg
    int i = 0;
    if (isneg)
    {
        n = -n; // abs
        putchar('-');
        (*result)++;
        // s[i++] = '-';
    }
    if (n == 0)
    {
        // s[i] = base[i];
        putchar(base[i]);
        i++;
        (*result)++;
        // s[i] = '\0';
    }
    while (n > 0 && isneg)
    {
        int rest = n % 10;
        putchar('0' + rest);
        (*result)++;
        // s[i++] = '0' + rest;
        n = n / 10;
    }
    int l = len(base); // here ? Not null terminated??
    while (n > 0 && !isneg)
    {
        int rest = n % l;
        // s[i++] = base[rest];
        putchar(base[rest]);
        (*result)++;
        n = n / l;
    }

    // s[i] = '\0';
}

static void case_int(const char *p, va_list args, int *result)
{
    int val = va_arg(args, int);
    my_itoa_base(val, "0123456789", result);
    ++p;
}

static void case_uint(const char *p, va_list args, int *result)
{
    unsigned int val = va_arg(args, unsigned int);
    my_itoa_base(val, "0123456789", result);
    ++p;
}

static void case_octal(const char *p, va_list args, int *result)
{
    unsigned int val = va_arg(args, unsigned int);
    my_itoa_base(val, "01234567", result);
    ++p;
}

static void case_hex(const char *p, va_list args, int *result)
{
    unsigned int val = va_arg(args, unsigned int);
    my_itoa_base(val, "0123456789abcdef", result);
    ++p;
}

static void case_char(const char *p, va_list args, int *result)
{
    char temp[2] = { 0 };
    temp[0] = va_arg(args, int);
    print(temp, result);
    ++p;
}

static void case_str(const char *p, va_list args, int *result)
{
    char *temp = va_arg(args, char *);
    print(temp, result);
    ++p;
}

void switches(const char *p, int *result, va_list args)
{
    switch (*p)
    {
    case '%':
        putchar(*p);
        (*result)++;
        ++p;
        break;
    case 'd':
        case_int(p, args, result);
        break;
    case 'u':
        case_uint(p, args, result);
        break;
    case 's':
        case_str(p, args, result);
        break;
    case 'c':
        case_char(p, args, result);
        break;
    case 'o':
        case_octal(p, args, result);
        break;
    case 'x':
        case_hex(p, args, result);
        break;
    default:
        (*result)++;
        ++p;
    }
}

int tinyprintf(const char *format, ...)
{
    va_list args;
    int result = 0; // pointer
    va_start(args, format);

    const char *p = format;

    while (*p != '\0')
    {
        if (*p == '%')
        {
            ++p; // move to next character
            switches(p, &result, args);
        }
        else
        {
            putchar(*p);
            ++p;
            (result)++;
        }
    }
    return result;
}
