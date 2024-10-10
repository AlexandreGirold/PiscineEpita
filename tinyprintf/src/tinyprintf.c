#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int result = 0;
/*
static int reverse(int num)
{
    int rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

static int len(const char *base)
{
    int len = 0;
    while (base[len] != '\0')
    {
        len++;
    }
    return len;
}


static int len_int(int n)
{
    int len = 0;
    while (n > 0)
    {
        len++;
        n/10;
    }
    return len;
}
*/
void print(char *s)
{
    if (s == NULL)
        return;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\\' && s[i + 1] != '\0')
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
        else
        {
            putchar(s[i]);
            result++;
            i++;
        }
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

/*
void my_itoa_base(int n, const char *base)
{
    int isneg = (n < 0) ? 1 : 0; // is not neg
    int i = 0;
    if(isneg)
        n = reverse(-n);
    else
        n = reverse(n);
    if (isneg)
    {
        putchar('-');
        (result)++;
        // s[i++] = '-';
    }
    if (n == 0)
    {
        // s[i] = base[i];
        putchar(base[i]);
        i++;
        (result)++;
        // s[i] = '\0';
    }
    while (n > 0 && isneg)
    {
        int rest = n % 10;
        putchar('0' + rest);
        (result)++;
        // s[i++] = '0' + rest;
        n = n / 10;
    }
    int l = len(base); // here ? Not null terminated??
    while (n > 0 && !isneg)
    {
        int rest = n % l;
        // s[i++] = base[rest];
        putchar(base[rest]);
        result++;
        n = n / l;
    }

    // reverse(s, i - 1);
    //  s[i] = '\0';
}
*/
void my_itoa_base(int n, const char *base)
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
    }

    if (n == 0)
    {
        putchar(base[0]);
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
    }
}

void my_itoa_base_u(unsigned int n, const char *base)
{
    int base_length = 0;

    while (base[base_length] != '\0')
    {
        base_length++;
    }

    if (n == 0)
    {
        putchar(base[0]);
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

void switches(const char *p, va_list args)
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
            ++p; // move to next character
            switches(p, args);
            ++p;
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
