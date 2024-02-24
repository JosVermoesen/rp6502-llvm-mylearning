#include <stdio.h>
#define IS_RP6502
// #define IS_DOSWIN

#ifdef IS_RP6502
#include <rp6502.h>
#else
#include <conio.h>
#endif

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
#ifdef IS_RP6502
    // puts("\30\f"); // rp6502 and others
    printf("\f"); // form feed
#else
    printf("\e[1;1H\e[2J"); // DOS/WINDOWS
#endif
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

char anyCtrl()
{
    char c;
    printf("Press any key\n");

#ifdef IS_RP6502
    while (!(RIA.ready & RIA_READY_RX_BIT))
        ;
    c = RIA.rx;
#else
    c = getch();
#endif

    switch (c)
    {
    case 1: // ASCII code for ctrl+A
        printf("You pressed ctrl+A\n");
        break;
    case 2: // ASCII code for ctrl+B
        printf("You pressed ctrl+B\n");
        break;
    case 26: // ASCII code for ctrl+Z
        printf("You pressed ctrl+Z\n");
        break;
    default:
        printf("You pressed something else\n");
    }
    return 0;
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
#ifdef IS_RP6502
        while (!(RIA.ready & RIA_READY_RX_BIT))
            ;
        c = RIA.rx;
#else
        c = getch();
#endif
        choise = (int)(c);
    }
    // printf("%c pressed (ascii: %d)\n", c, c);
    return c;
}

void printAt(int row, int col)
{
#ifdef IS_RP6502
    printf("%s%d;%dH", CSI, row + 1, col + 1);
#else
    printf("%s%d;%dH", CSI, row + 1, col + 1);
#endif
}

void eraseLine(int row)
{
    printAt(row, 0);

#ifdef IS_RP6502
    printf("%s2K", CSI);
#else
    printf("%sK", CSI);
#endif
}

void clearLines(int from, int to, int waitKey)
{
    int i;
    char cChoise;

    if (waitKey)
    {
        printf("\nAny key to continue ");
        cChoise = anyKey(0, 254);
    }

    for (i = from; i <= to; i++)
    {
        eraseLine(i);
    }
}
