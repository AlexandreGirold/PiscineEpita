#include <stddef.h>
#include <stdio.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    if (roll > 7)
        roll = roll % 8;
    return (value << roll)
        | (value >> (8 - roll)); // on a perdu les shift du rol
                                 // et on veut les recuperer donc
                                 // on shift de 8(max) - roll
}
