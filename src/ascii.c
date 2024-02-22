/*
    Experimenting ASCII values and escape codes in C.
 */

#include <stdio.h>
// #include "kc-functions.c"

static const char *CSI = "\x1b["; // Escape

const int black = 0;
const int red = 1;
const int green = 2;
const int yellow = 3;
const int blue = 4;
const int magenta = 5;
const int cyan = 6;
const int white = 7;

void clear()
{
    puts("\30\f"); // rp6502 and others
    // printf("\f"); // form feed
}

void setColor(int colorCode)
{
    switch (colorCode)
    {
    case 0: // BLACK
        printf("%s%s", CSI, "30m");
        break;
    case 1: // RED
        printf("%s%s", CSI, "31m");
        break;
    case 2: // GREEN
        printf("%s%s", CSI, "32m");
        break;
    case 3: // YELLOW
        printf("%s%s", CSI, "93m");
        break;
    case 4: // BLUE
        printf("%s%s", CSI, "34m");
        break;
    case 5: // MAGENTA
        printf("%s%s", CSI, "35m");
        break;
    case 6: // CYAN
        printf("%s%s", CSI, "36m");
        break;
    case 7: // WHITE
        printf("%s%s", CSI, "37m");
        break;

    // operator doesn't match any case constant +, -, *, /
    default:
        printf("Error! operator is not correct. Switching to white");
        printf("%s%s", CSI, "37m");    
    }

    /*
        static const char *BLACK = "30m"; // color codes
        static const char *RED = "31m";
        static const char *YELLOW = "93m";
        static const char *GREEN = "32m";
        static const char *BLUE = "34m";
        static const char *MAGENTA = "35m";
        static const char *CYAN = "36m";
        static const char *WHITE = "37m";
        static const char *UNDEFINED = "37m";
     */
}

// ABCDEFGHIJKLMNOPQRSTUVWXYZ
char anyKey(int kFrom, int kTo)
{
    char c;
    int choise = -1;

    if (kTo == 0)
    {
        kFrom = 32;
        kTo = 254;
    }

    while ((choise < kFrom) || (choise > kTo))
    {
        c = getchar();
        choise = (int)(c);
    }
    // printf("%c pressed (ascii: %d)\n", c, c);
    return c;
}

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
    while ((iFlag == -1))
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