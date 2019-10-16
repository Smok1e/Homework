#include "TXLib.h"

//----------------------------------------------------------------------------

void drawMan (int x, int y, int lhx, int lhy, int rhx, int rhy, double scale, COLORREF color);

void Clear (COLORREF color);

void drawBackground (COLORREF color);

void drawHouse (int x, int y, COLORREF color, COLORREF bkcolor);

void drawHouse (int x, int y, int scale, COLORREF color, COLORREF bkcolor);

int Max (int num1, int num2);

void drawUfo (int x, int y);

void Scene1 ();

void Scene2 ();

void Scene3 ();

void Scene4 ();

void Scene5 ();

void Scene6 ();

void Scene7 ();

void Scene8 ();

void Scene9 ();


//----------------------------------------------------------------------------

int main()
{

    txCreateWindow (800, 600);

    Scene1 ();

    txSleep (500);

    Scene2 ();

    txSleep (500);

    Scene3 ();

    txSleep (300);

    Scene4 ();

    txSleep (500);

    Scene5 ();

    txSleep (500);

    Scene6 ();

    Scene7 ();

    Scene8 ();

    Scene9 ();

    return 0;

}

//-----------------------------------------------------------------------------

void Scene1 ()

{

    for (int t = 0; t <= 100; t++)

    {

        drawBackground (TX_WHITE);

        drawMan (400 + 3.75 * t, 338 + t % 10 - 5, 0, 0, 0, 0, 1, TX_GREEN);

        txSleep (10);

    }

}

//-----------------------------------------------------------------------------


void Scene2 ()

{

    for (int t = 0; t <= 100; t++)

    {

        drawBackground (TX_WHITE);

        drawMan   (775 + -2 * t, 338, 0, 0, 0, 0, 1, TX_GREEN);
        drawMan   (850 + -2 * t, 338, 0, 0, 0, 0, 1, TX_LIGHTCYAN);
        drawHouse (835 + -2 * t, 400, TX_WHITE, TX_BLACK);

        txSleep (10);

    }

}

//-----------------------------------------------------------------------------


void Scene3 ()

{

    for (int t = 0; t <= 100; t++)

    {

        drawBackground (TX_WHITE);

        drawMan   (575 +     0 * t, 338, 0, 0, 0, 0, 1, TX_GREEN);
        drawMan   (650 + -0.35 * t, 338, 0, 0, 0, 0, 1, TX_LIGHTCYAN);
        drawHouse (635 +     0 * t, 400, TX_WHITE, TX_BLACK);

        txSleep (0);

    }

}

//-----------------------------------------------------------------------------

void Scene4 ()

{

    for (int t = 0; t <= 20; t++)

    {

        drawBackground (TX_WHITE);
        drawMan (575, 338,    0 * t,    0 * t, -1.3 * t, 0.7 * t, 1, TX_GREEN);
        drawMan (615, 338, -1.3 * t, -0.7 * t,    0 * t,   0 * t, 1, TX_LIGHTCYAN);

        drawHouse (635, 400, TX_WHITE, TX_BLACK);

        txSleep (30);

    }

    txSleep (300);

    for (int t = 20; t >= 0; t--)

    {

        Clear (TX_BLACK);

        drawBackground (TX_WHITE);

        drawMan (575, 338,    0 * t,    0 * t, -1.3 * t, 0.7 * t, 1, TX_GREEN);
        drawMan (615, 338, -1.3 * t, -0.7 * t,    0 * t,   0 * t, 1, TX_LIGHTCYAN);

        drawHouse (635, 400, TX_WHITE, TX_BLACK);

        txSleep (30);


    }

}

//-----------------------------------------------------------------------------

void Scene5 ()

{

    for (int t = 0; t <= 100; t++)

    {

        drawBackground (TX_WHITE);

        drawMan   (575 + -6.5 * t, 338 + t % 10 - 5, 0, 0, 0, 0, 1, TX_GREEN);
        drawMan   (615 + -6.5 * t, 338 - t % 10 + 5, 0, 0, 0, 0, 1, TX_LIGHTCYAN);
        drawHouse (635, 400, TX_WHITE, TX_BLACK);

        txSleep (10);

    }

}


//-----------------------------------------------------------------------------

void Scene6 ()

{

    for (int t = 0; t <= 300; t++)

    {

        drawBackground (TX_WHITE);

        drawHouse (-500 + 10 * t, 400, 20, TX_WHITE, TX_BLACK);
        drawHouse (-1300 + 10 * t, 400, 100, TX_WHITE, TX_BLACK);
        drawHouse (-2000 + 10 * t, 400, 50, TX_WHITE, TX_BLACK);

        drawMan (375, 338 + t % 10 - 5, 0, 0, 0, 0, 1, TX_GREEN);
        drawMan (425, 338 - t % 10 + 5, 0, 0, 0, 0, 1, TX_LIGHTCYAN);

        txSleep (10);

    }

}


//-----------------------------------------------------------------------------

void Scene7 ()

{

   for (int t = 0; t <= 100; t++)

    {

        drawBackground (TX_WHITE);

        drawMan (375, 338 + t % 10 - 5, 0, 0, 0, 0, 1, TX_GREEN);
        drawMan (425, 338 - t % 10 + 5, 0, 0, 0, 0, 1, TX_LIGHTCYAN);

        drawUfo (810 - 5.1 * t, 100);

        txSleep (10);

    }

}

//-----------------------------------------------------------------------------

void Scene8 ()

{

    for (int t = 0; t <= 100; t++)

    {

        drawBackground (TX_WHITE);

        drawMan (375, 338 + t % 10 - 5 - 3 * t, 0, 0, 0, 0, 1, TX_GREEN);
        drawMan (425, 338 - t % 10 + 5 - 3 * t, 0, 0, 0, 0, 1, TX_LIGHTCYAN);

        drawUfo (310, 100);

        txSleep (10);

    }

}

//-----------------------------------------------------------------------------

void Scene9 ()

{

    for (int t = 0; t <= 100; t++)

    {

        drawBackground (TX_WHITE);

        drawUfo (310, 100 - 5 * t);

        txSleep (10);

    }

}

//----------------------------------------------------------------------------

void drawMan (int x, int y, int lhx, int lhy, int rhx, int rhy, double scale, COLORREF color)
{

    txSetColor (color, scale * 2);
    txSetFillColor(TX_BLACK);

    txLine (x, y, x, y + scale * 40);

    txLine (x, y + scale * 5, x + scale * 7 + rhy, y + scale * 25 + rhx);
    txLine (x, y + scale * 5, x - scale * 7 + lhy, y + scale * 25 + lhx);

    txLine (x, y + scale * 40, x + scale * 10, y + scale * 40 + scale * 20);
    txLine (x, y + scale * 40, x - scale * 10, y + scale * 40 + scale * 20);

    txCircle (x, y - scale * 5, scale * 10);

}

//----------------------------------------------------------------------------

void Clear (COLORREF color)

{

    txSetColor (color);
    txSetFillColor (color);

    txRectangle (0, 0, 800, 600);

}

//----------------------------------------------------------------------------

void drawBackground (COLORREF color)

{

    Clear (TX_BLACK);

    txSetColor (color, 3);

    txLine (1, 400, 800, 400);

}

//----------------------------------------------------------------------------

void drawHouse (int x, int y, COLORREF color, COLORREF bkcolor)

{

    txSetFillColor (bkcolor);
    txSetColor (bkcolor);

    txRectangle (x, y - 110, x + 100, y);

    txSetColor (color, 3);

    txLine (x, y, x, y - 75);
    txLine (x, y, x + 100, y);
    txLine (x + 100, y - 75, x + 100, y);
    txLine (x, y - 75, x + 50, y - 110);
    txLine (x + 100, y - 75, x + 50, y - 110);

}

//-----------------------------------------------------------------------------

int Max (int num1, int num2)

{

    if (num1 > num2)
    {

        return num1;

    }

    else

    {

        return num2;

    }

}

//-----------------------------------------------------------------------------

void drawUfo (int x, int y)

{

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);

    txRectangle (x, y + 74, x + 200, y - 200);

    txSetColor (TX_GRAY);
    txSetFillColor (TX_GRAY);

    txEllipse (x, y + 75, x + 200, y);
    txEllipse (x + 80, y + 20, x + 120, y - 25);


}

void drawHouse (int x, int y, int scale, COLORREF color, COLORREF bkcolor)

{

    txSetFillColor (bkcolor);
    txSetColor (bkcolor);

    txRectangle (x, y - 110 - scale, x + 100 + scale, y + scale);

    txSetColor (color, 3);

    txLine (x, y, x, y - 75 - scale);
    txLine (x, y, x + 100 + scale, y);
    txLine (x + 100 + scale, y - 75 - scale, x + 100 + scale, y);
    txLine (x, y - 75 - scale, x + 50 + scale / 2, y - 110 - scale - scale / 4);
    txLine (x + 100 + scale, y - 75 - scale, x + 50 + scale / 2, y - 110 - scale - scale / 4);

}
