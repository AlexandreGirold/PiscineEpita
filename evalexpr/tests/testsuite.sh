#!/bin/sh

REF_OUT=".echo.out"
TEST_OUT=".my_echo.out"
EXEC="./evalexpr"

test_class()
{
    echo "$1" | "$EXEC" > TEST_OUT
    echo "$1" | bc > REF_OUT
    #Comment savoir si bc(classique) ou dc (rpn)

    diff "$REF_OUT" "$TEST_OUT"
}

tests_rpn()
{
    echo "$1" | "$EXEC" > TEST_OUT
    echo "$1" | dc > REF_OUT
    #Comment savoir si bc(classique) ou dc (rpn)

    diff "$REF_OUT" "$TEST_OUT"
}


#faire test
