#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

// Mock putchar to capture output for testing
#include <stdio.h>
#include <string.h>

static int output_len = 0;
static char output_buffer[1024];

int mock_putchar(int c) {
    if (output_len < sizeof(output_buffer) - 1) {
        output_buffer[output_len++] = c;
        return c;
    }
    return EOF; // Buffer overflow
}

void reset_output() {
    memset(output_buffer, 0, sizeof(output_buffer));
    output_len = 0;
}

Test(tinyprintf, simple_string_and_number) {
    reset_output();
    int ret = tinyprintf("Hello [%d] world!", 42);
    cr_assert_eq(ret, 19, "Expected return value 19, got %d", ret);
    cr_assert_str_eq(output_buffer, "Hello [42] world!", "Output mismatch");
}

Test(tinyprintf, hexadecimal_output) {
    reset_output();
    int ret = tinyprintf("Value: [%x]", 42);
    cr_assert_eq(ret, 12, "Expected return value 12, got %d", ret);
    cr_assert_str_eq(output_buffer, "Value: [2a]", "Output mismatch");
}

Test(tinyprintf, percent_directive) {
    reset_output();
    int ret = tinyprintf("Percent sign: %%");
    cr_assert_eq(ret, 20, "Expected return value 20, got %d", ret);
    cr_assert_str_eq(output_buffer, "Percent sign: %", "Output mismatch");
}

Test(tinyprintf, null_string) {
    reset_output();
    int ret = tinyprintf("String: %s", NULL);
    cr_assert_eq(ret, 14, "Expected return value 14, got %d", ret);
    cr_assert_str_eq(output_buffer, "String: (null)", "Output mismatch");
}

Test(tinyprintf, character_output) {
    reset_output();
    int ret = tinyprintf("Character: %c", 'A');
    cr_assert_eq(ret, 14, "Expected return value 14, got %d", ret);
    cr_assert_str_eq(output_buffer, "Character: A", "Output mismatch");
}

Test(tinyprintf, octal_output) {
    reset_output();
    int ret = tinyprintf("Octal: [%o]", 42);
    cr_assert_eq(ret, 12, "Expected return value 12, got %d", ret);
    cr_assert_str_eq(output_buffer, "Octal: [52]", "Output mismatch");
}

Test(tinyprintf, multiple_arguments) {
    reset_output();
    int ret = tinyprintf("Values: %s %d %x", "Test", 15, 15);
    cr_assert_eq(ret, 29, "Expected return value 29, got %d", ret);
    cr_assert_str_eq(output_buffer, "Values: Test 15 f", "Output mismatch");
}

// Main function for running the tests
int main(int argc, char *argv[]) {
    return criterion_run(argc, argv);
}
