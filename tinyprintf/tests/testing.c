#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>

include "../src/tinyprint.h"


Test(basics, basic_str) 
{
    cr_redirect_stdout();
    tinyprintf("hello %s", "world");
    fflush(stdout);
    cr_assert_stdout_eq_str("hello world")
}
