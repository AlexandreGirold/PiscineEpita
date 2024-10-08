#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#if 1
#include "../src/tinyprintf.h"
#endif
TestSuite(basics);

Test(basics, basic_str) 
{

    tinyprintf("hello %s %d %d %u %c %% %o %x", "world", -123, -150, 100,'b', 62, 50);
    putchar('\0');
    cr_redirect_stdout();

    tinyprintf("hello %s %d %d %u %c %% %o %x", "world", 123, -15, -100,'b', 62, 50 );
    fflush(stdout);
    cr_assert_stdout_eq_str("hello world 123 -15 100 b % 50 80");
}
