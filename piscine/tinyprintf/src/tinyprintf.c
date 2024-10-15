#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int result = 0;

void print(char *s)
{
    if (s == NULL)
        return;
    int i = 0;
    while (s[i] != '\0')
    {
        /*if (s[i] == '\\' && s[i + 1] != '\0')
        {
            if ((s[i + 1]) == 'n')
            {
                i++;
                i++;
                putchar('\n');
                result++;
            }
            else
            {
                putchar(s[i]);
                i++;
                result++;
            }
        }
        else*/

        putchar(s[i]);
        result++;
        i++;
    }
}

/*
static char *int_to_char(int n)
{
    int l = len_int(n);
    char s[l+1] = {0};
    int i = 0;
    while (l>0)
    {
        s[i] = n%10;
        n = n/10;
        l--;
    }
}
*/

static void my_itoa_base(int n, const char *base)
{
    int base_length = 0;

    while (base[base_length] != '\0')
    {
        base_length++;
    }

    if (n < 0 && base_length == 10)
    {
        putchar('-');
        n = -n;
        result++;
    }

    if (n == 0)
    {
        putchar(base[0]);
        result++;
        return;
    }

    char buffer[32];
    int index = 0;

    while (n > 0)
    {
        int remainder = n % base_length;
        buffer[index++] = base[remainder];
        n /= base_length;
    }
    while (index > 0)
    {
        putchar(buffer[--index]);
        result++;
    }
}

static void my_itoa_base_u(unsigned int n, const char *base)
{
    int base_length = 0;

    while (base[base_length] != '\0')
    {
        base_length++;
    }

    if (n == 0)
    {
        putchar(base[0]);
        result++;
        return;
    }

    char buffer[32];
    int index = 0;

    while (n > 0)
    {
        int remainder = n % base_length;
        buffer[index++] = base[remainder];
        n /= base_length;
    }

    while (index > 0)
    {
        putchar(buffer[--index]);
        result++;
    }
}

static void case_int(va_list args)
{
    int val = va_arg(args, int);
    my_itoa_base(val, "0123456789");
}

static void case_uint(va_list args)
{
    unsigned int val = va_arg(args, unsigned int);
    my_itoa_base_u(val, "0123456789");
}

static void case_octal(va_list args)
{
    unsigned int val = va_arg(args, unsigned int);
    my_itoa_base_u(val, "01234567");
}

static void case_hex(va_list args)
{
    unsigned int val = va_arg(args, unsigned int);
    my_itoa_base_u(val, "0123456789abcdef");
}

static void case_char(va_list args)
{
    char temp[2] = { 0 };
    temp[0] = va_arg(args, int);
    print(temp);
}

static void case_str(va_list args)
{
    char *temp = va_arg(args, char *);
    if (temp == NULL)
        print("(null)");
    else
        print(temp);
}

static void switches(const char *p, va_list args)
{
    switch (*p)
    {
    case '%':
        putchar(*p);
        (result)++;
        break;
    case 'd':
        case_int(args);
        break;
    case 'u':
        case_uint(args);
        break;
    case 's':
        case_str(args);
        break;
    case 'c':
        case_char(args);
        break;
    case 'o':
        case_octal(args);
        break;
    case 'x':
        case_hex(args);
        break;
    default:
        --p;
        putchar(*p);
        (result)++;
        ++p;
        putchar(*p);
        (result)++;
    }
}

int tinyprintf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    const char *p = format;
    if (!format)
        return 0;

    while (*p != '\0')
    {
        if (*p == '%')
        {
            p++; // move to next character
            switches(p, args);
            p++;
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
