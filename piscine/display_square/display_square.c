#include <stddef.h>
#include <stdio.h>

void display_square(int width)
{
    int odd = 0;
    int even = 0;
<<<<<<< Updated upstream
    if (width <= 0)
=======
    if (width < 0)
>>>>>>> Stashed changes
        return;
    int row = width / 2 + 1;
    if (width % 2 == 0)
        odd = 1;
    else
        even = 1;
    for (int i = 0; i < row; i++)
<<<<<<< Updated upstream
    {
        if (i == 0 || i == row - 1)
=======
#include <stddef.h>
#include <stdio.h>

        void display_square(int width)
>>>>>>> Stashed changes
        {
            int odd = 0;
            int even = 0;
            if (width <= 0)
                return;
            int row = width / 2 + 1;
            if (width % 2 == 0)
                odd = 1;
            else
                even = 1;
            for (int i = 0; i < row; i++)
            {
                if (i == 0 || i == row - 1)
                {
                    for (int j = 0; j < width + odd; j++)
                    {
                        putchar('*');
                    }
                }
                else
                {
                    putchar('*');
                    for (int j = 0; j < width - 1 - even; j++)
                    {
                        putchar(' ');
                    }
                    putchar('*');
                }

                putchar('\n');
            }
        }
