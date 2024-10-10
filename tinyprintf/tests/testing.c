#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#if 1
#    include "../src/tinyprintf.h"
#endif
TestSuite(basics);

Test(basics, basic_str)
{
    tinyprintf("hello %s ", "world");
    //tinyprintf("hello %s %d %d %u %c %% %o %x ", "world", 123, -150,
    //           80, 'b', 3967471, 3967471);
    cr_redirect_stdout();
    fflush(stdout);

    //tinyprintf("hello %s %d %d %u %c %% %o %x ", "world", 123, -150,
    //           -80, 'b', 3967471, 3967471);
    tinyprintf("hello %s", "world");
    fflush(stdout);
    //cr_assert_stdout_eq_str(
    //    "hello world 123 -150 80 b % 17104757 3c89ef ");
    cr_assert_stdout_eq_str("hello world");
}
