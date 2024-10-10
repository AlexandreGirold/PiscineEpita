#include <stdio.h>
#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    //size_t i = 0;
    if(0 < len)
    {
        len--;
        printf("%d\n", array[0]);
        return func(array[0], foldr(array+1, len , func));
    }
    return 0;
}

int foldl(int *array, size_t len, int (*func)(int, int))
{
    if(0 < len)
    {
        len--;
        printf("%d\n", array[len]);
        return func(array[len], foldl(array, len, func));
    }
    return 0;

}

int sum(int a, int b)
{
    return a + b;
}


int main(void)
{
    int arr[] = {1, 4, 7, 3, 20};
    
    int a = foldl(arr, 5, sum);
    printf("--------------\n");
    int b = foldr(arr, 5, sum);
    printf("foldl = %d\n", a);
    printf("foldr = %d\n", b);
    
   
}
