#include <stddef.h>
#include <stdio.h>

void map(int *array, size_t len, void (*func)(int *))
{
    size_t i = 0;
    while(i < len)
    {
        func(&array[i]);
        i++;
    }
}

void times_two(int *a)
{
    *a *= 2;
}
int main(void)
{
    int arr[] = {1, 4, 7};
    int i = 0;
    while(i < 3)
    {
        printf("%d\n",arr[i]);
        i++;
    }
    
    map(arr, 3, times_two);
    i = 0;
    while(i < 3)
    {
        printf("%d\n",arr[i]);
        i++;
    }

}
