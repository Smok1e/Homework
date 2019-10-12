#include "TXLib.h"

//----------------------------------------------------------------------------

void drawMan (int x, int y, double scale, int hands, int legs, COLORREF color);

void moveMan (int x00, int y00, double vx0, double vy0,
              double scale00, double scale10,
              int time0, COLORREF color0,
              int x01, int y01, double vx1, double vy1,
              double scale01, double scale11,
              int time1, int delay, COLORREF color1,
              COLORREF bkcolor);

void Clear (COLORREF color);

void drawBackground (COLORREF color);

//----------------------------------------------------------------------------

int main()
{

    txCreateWindow (800, 600);

    moveMan (50, 300, 1, 0, 2, 2, 350, TX_GREEN, 750, 300, -1, 0, 2, 2, 350, 3, TX_LIGHTCYAN, TX_BLACK);

    //drawBackground (TX_WHITE);

    return 0;

}

//----------------------------------------------------------------------------

void drawMan (int x, int y, double scale, int hands, int legs, COLORREF color)
{

    txSetColor (color, scale);
    txSetFillColor(TX_BLACK);

    txLine (x, y, x, y + scale * 40);

    txLine (x, y + scale * 5, x + scale * 7, y + scale * 25 + hands);
    txLine (x, y + scale * 5, x - scale * 7, y + scale * 25 + hands);

    txLine (x, y + scale * 40, x + scale * 10, y + scale * 40 + scale * 20 + legs);
    txLine (x, y + scale * 40, x - scale * 10, y + scale * 40 + scale * 20 + legs);

    txCircle (x, y - scale * 5, scale * 10);

}

//----------------------------------------------------------------------------

void moveMan (int x00, int y00, double vx0, double vy0,
              double scale00, double scale10,
              int time0, COLORREF color0,
              int x01, int y01, double vx1, double vy1,
              double scale01, double scale11,
              int time1, int delay, COLORREF color1,
              COLORREF bkcolor)
{

    drawMan (x00, y00, scale00, 0, 0, color0);
    drawMan (x01, y01, scale01, 0, 0, color1);

    double vScale0 = (scale10 - scale00) / time0;
    double vScale1 = (scale11 - scale01) / time1;

    int x10 = x00;
    int y10 = y00;

    int x11 = x01;
    int y11 = y01;

    double scale0 = scale00;
    double scale1 = scale01;

    int time = 0;

    if (time0 > time1)

    {

        time = time0;

    }

    else

    {

        time = time1;

    }


    for (int t = 0; t <= time; t++)

    {

        drawMan (x10, y10, scale0, 0, 0, color0);
        drawMan (x11, y11, scale1, 0, 0, color1);

        txSleep (delay);

        Clear (bkcolor);

        if (t <= time0)

        {

            x10 = x00 + vx0 * t;
            y10 = y00 + vy0 * t;
            scale0 = scale00 + vScale0 * t;
            drawMan (x10, y10, scale0, 0, 0, color0);

        }

        if (t <= time1)

        {

            x11 = x01 + vx1 * t;
            y11 = y01 + vy1 * t;
            scale1 = scale01 + vScale1 * t;
            drawMan (x11, y11, scale1, 0, 0, color1);

        }


    }

    drawMan (x10, y10, scale10, 0, 0, color0);
    drawMan (x11, y11, scale11, 0, 0, color1);

}

void Clear (COLORREF color)

{

    txSetColor (color);
    txSetFillColor (color);

    txRectangle (1, 1, 800, 600);

}

void drawBackground (COLORREF color)

{

}

//----------------------------------------------------------------------------
