#include <stdio.h>
#include <stddef.h>
#include <limits.h>

int max_array(const int array[], size_t size){
    if (size == 0)
        return INT_MIN;
    else{
        int curr_max = array[0];
        for (size_t i=0; i<size-1; i++){
            int max = array[i + 1];
            if (max > curr_max){
                curr_max = max;
            }
        }
        return curr_max;


    }
}

int main(void){
    //int arr[5] = {0, 9, -5, 4, 2};
    int arr_empty[5] = {}; 
    //int m = max_array(arr, 5);
    int nm = max_array(arr_empty,0);
    printf("%d\n",nm);

}
