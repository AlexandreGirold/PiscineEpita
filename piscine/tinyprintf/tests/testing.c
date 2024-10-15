
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#if 1
#    include "../src/tinyprintf.h"
#endif
TestSuite(basics);

/*Test(basics, basic_str)
{
    tinyprintf("hello %s %c %o %x", "world",
               'b', 3967471, 3967471);
    fflush(stdout);

    cr_redirect_stdout();
    tinyprintf("hello %s %c %o %x", "world",
                'b', 3967471, 3967471);
    cr_assert_stdout_eq_str(
        "hello world b 17104757 3c89ef");
}*/

Test(tinyprintf, simple_string_and_number)
{
    tinyprintf("hello %d", -42);
    cr_redirect_stdout();

    cr_redirect_stdout();
    fflush(stdout);
    tinyprintf("hello %d", 0);
    fflush(stdout);
    tinyprintf("hello %u", 0);
    fflush(stdout);
    tinyprintf("hello %d", 7850);
    fflush(stdout);
    tinyprintf("hello %%", 0);
    fflush(stdout);
    tinyprintf("hello %w", 0);
    fflush(stdout);
    tinyprintf("hello %s", "\n");
    fflush(stdout);
    cr_redirect_stdout();
    fflush(stdout);
    tinyprintf("Hello [%u] world!(null)\n", 42);
    fflush(stdout);
    tinyprintf("Percent sign: %%");
    fflush(stdout);
    tinyprintf("hello %s %c %o %x", "world", 'b', 3967471, 3967471);
    fflush(stdout);
    tinyprintf("Percent sign: %s", NULL);
    fflush(stdout);
    tinyprintf(NULL);
    fflush(stdout);
    tinyprintf("\\n", NULL);
}
