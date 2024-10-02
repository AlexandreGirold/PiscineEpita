#include <stdio.h>


void put3(int nbr, char **val)
{
    for (int i = 0; i < nbr; i++)
    {
        puts(val[i]);
    }
    return;
}


int main(int argc, char *argv[])
{
    put3(argc, argv);    

}


