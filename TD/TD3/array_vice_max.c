#include <stdio.h>
#include <stddef.h>

int vice_max_array(const int array[], size_t size)
{
    int curr_max;
    int second_max;
    if (array[0] >= array[1])
    {
        curr_max = array[0];
        second_max= array[1];
    }
    else
    {
        curr_max = array[1];
        second_max = array[0];
    }
    for (size_t i=0; i < size; i++)
    {
        if(curr_max < array[i])
        {
            second_max = curr_max;
            curr_max = array[i];
        }
        else if (curr_max > array[i] && second_max <= array[i])
        {
            second_max = array[i];
        }
    }
    return second_max;
}

int main(void)
{
    int arr[6] = {0, 9, -5, 4, 2, 5};
    //int arr_empty[5] = {};
    int n = vice_max_array(arr, 6);
   // int nm = max_array(arr_empty,0);
    printf("%d\n",n);
}
