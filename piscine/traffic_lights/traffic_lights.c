#include <stddef.h>
#include <stdio.h>

void init(unsigned char *lights)
{
    if (lights != NULL)
        *lights = 0;
    return;
}

void turn_on(unsigned char *lights, unsigned char light_num)
{
    *lights |= (1 << (light_num - 1));
}

void turn_off(unsigned char *lights, unsigned char light_num)
{
    *lights &= ~(1 << (light_num - 1));
}

void next_step(unsigned char *lights)
{
    *lights = (*lights << 1) | (*lights >> 3);
}

void reverse(unsigned char *lights)
{
    *lights = ~(*lights);
}
void swap(unsigned char *lights_1, unsigned char *lights_2)
{
    if (*lights_1 == *lights_2)
        return;

    *lights_1 ^= *lights_2;
    *lights_2 ^= *lights_1;
    *lights_1 ^= *lights_2;
}
