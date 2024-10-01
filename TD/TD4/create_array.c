#include <stdio.h>
#include <stdlib.h>

int *create_array(size_t size)
{
        int *arr = malloc(sizeof(int) * size);
        if (!arr)
        {
            printf("error here memory");
            return NULL;//pensez a retirer ce qui a ete aloue avant
        }
        return arr;
}


void free_array(int *arr)
{
    if (!arr)
        return;
    free(arr);

}


void read_and_inc(int *v)
{
    if (!v)
        return;
    printf("%d\n", *v);
    *v = *v + 1;
    printf("%d\n", *v);
}


char *my_strdup(const char *str)
{
    if(!str)
        return NULL;
    size_t i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    char *string = malloc(sizeof(char) * (i+2)); // size of char is i
    if(!string)
        return NULL;
    for(size_t j = 0; j<i+1; j++)
    {
        string[j] = str[j];
    }
    return string; 
}



char *my_strndup(const char *str, size_t n)
{
    size_t i = 0;
    while (str[i] != '\0' && i < n)
    {
        i++;
    }
    char *string = malloc(sizeof(char) * (i+2)); // size of char is 1
    if(!string)
        return NULL;
    for(size_t j = 0; j<i+1; j++)
    {
        string[j] = str[j];
    }
    return string; 
}


int main(void)
{
    int nbr = 5;
    int *create_arr = create_array(nbr);

    printf("%p\n",(void*) create_arr);
    free_array(create_arr);

    int *val = malloc(sizeof(int));
    *val = 16;
    read_and_inc(val);
    free(val);

    const char chello[] = "hello how 1";
    char *my_str = my_strndup(chello, 4);
    int i=0;
    while(i < 4)
    {
        printf("%c", my_str[i]);

        i++;
    }
    printf("\n");
    free(my_str);
    
    return 0;
}

    

