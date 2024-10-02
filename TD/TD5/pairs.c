#include <stdio.h>
#include <stddef.h>


struct pair
{
    int x;
    int y;
};

struct pair three_pairs_sum(const struct pair pair_1,const struct pair pair_2,const struct pair pair_3)
{
    struct pair sum;
    sum.x = pair_1.x + pair_2.x + pair_3.x;
    sum.y = pair_1.y + pair_2.y + pair_3.y;
    return sum;
}

struct pair pairs_sum(const struct pair pairs[], size_t size)
{
    struct pair sum_arr;
    for(size_t i = 0; i < size; i++)
    {
        sum_arr.x += pairs[i].x;
        sum_arr.y += pairs[i].y;
    }
    return sum_arr;
}

int main(void)
{
    struct pair nbr1, nbr2, nbr3;
    nbr1.x = 11;
    nbr1.y = -1;
    
    nbr2.x = 11;
    nbr2.y = 6;

    nbr3.x = 100;
    nbr3.y = -5;
    
    struct pair res = three_pairs_sum(nbr1, nbr2, nbr3)

    printf("%d %d\n", res.x, res.y);

}
    

