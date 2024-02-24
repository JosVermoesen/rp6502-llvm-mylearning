/*
    Experimenting ASCII values and escape codes in C.
 */
#define IS_RP6502
// #define IS_DOSWIN

#include <stdio.h>
#include "kc-functions.c"

void charset(int aFrom, int aTo)
{
    int i;

    /* Print ASCII values from 0 to 255 */
    for (i = aFrom; i <= aTo; i++)
    {
        printf("%c: %d", i, i);
        printf(" ");
    }
}

int main()
{
    int a_ulc = 201; // double upper left corner
    int a_urc = 187; // double upper right corner
    int a_llc = 200; // double lower left corner
    int a_lrc = 188; // double lower right corner
    int a_h = 205;   // double horizontal
    int a_v = 186;   // double vertical

    int iChoise, iFlag;
    char cChoise;

    clear();
    setColor(green);
    charset(32, 221);

    setColor(white);

    printf("\n\nPress any key to continue.\n");
    cChoise = anyKey(0, 0);
    clear();

    printf("Upper left %c = %d\n", a_ulc, a_ulc);
    printf("Upper right %c = %d\n", a_urc, a_urc);
    printf("Lower left %c = %d\n", a_llc, a_llc);
    printf("Lower right %c = %d\n", a_lrc, a_lrc);
    printf("Horizontal %c = %d\n", a_h, a_h);
    printf("Vertical %c = %d\n", a_v, a_v);

    cChoise = anyKey(0, 0);
    iChoise = (int)(cChoise)-48;
    printf("%d\n", iChoise);

    printf("Char: %c %d\n", cChoise, iChoise);

    iFlag = -1;
    while (iFlag == -1)
    {
        cChoise = anyKey(0, 254);
        iChoise = (int)(cChoise);

        printf("pressed: %c %d (Press Q or q to quit)\n", cChoise, iChoise);
        if ((iChoise == 113) || (iChoise == 81))
        {
            iFlag = 0;
        }
    }
    return 0;
}