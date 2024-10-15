#include "functional_programming.h"
#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main(void)
{
    int arr[] = {1, 4, 7, 3 ,20};
    int a = foldl(arr, 5, sum);
    printf("%d\n", a);

}
