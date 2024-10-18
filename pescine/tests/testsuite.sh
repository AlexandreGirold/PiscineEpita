#!/bin/sh

REF_OUT=".echo.out"
TEST_OUT=".my_echo.out"
EXEC="./evalexpr"

test_class()
{
    echo "$1" | "$EXEC" > "$TEST_OUT"
    echo "$1" | bc > "$REF_OUT"
    #Comment savoir si bc(classique) ou dc (rpn)

    diff "$REF_OUT" "$TEST_OUT" && echo "test passed" || echo "test failed"

}

tests_rpn()
{
    echo "$1" | "$EXEC" > "$TEST_OUT"
    echo "$1"" p" | dc > "$REF_OUT"
    #Comment savoir si bc(classique) ou dc (rpn)
    #content=$(cat "$REF_OUT")
    #echo "$content"
    diff "$REF_OUT" "$TEST_OUT" && echo "test passed" || echo "test failed"

}


#faire test

tests_rpn '1 1 +' 
tests_rpn '16 2 /'
tests_rpn '48 2 / 2-' 
tests_rpn '5 9 8 * 2 / 3 * +' 
tests_rpn '2 3 ^' 
tests_rpn '9 10 %'
tests_rpn " "
tests_rpn ' 1 1-'
tests_rpn '45 0 /'
tests_rpn '0 45 /'

test_class '1+1'
test_class '1^1'
test_class '(1+1)*3'
test_class '2^5'
test_class '2/0'
test_class '2-7'
test_class '10%3'
test_class '9/3'
test_class '(4/(2+2))'
test_class " " 

