#include  "TXlib.h"

void TankDraw(int x, int y, int muzzleUp, int muzzleLenght, int trackUp, double dir);
void RocketDraw(int x, int y);
void StoneDraw (int x, int y);  // StoneDraw function prototype
void HumanJohnDraw(int x, int y, int handRight, int legs, int headUp, int headRightLeft, int handUp,
                   COLORREF color, int legDown, COLORREF colorHands);
void TankMove();
void HumanJohnMove();
void TankandJohnMove ();
void TankAttack ();
void TankArmy ();
void RocketMove ();
void CarDraw ();

int main()
    {
    txCreateWindow (1024, 768);

    //RocketDraw(491, 499);
    //HumanJohnDraw (96, 491, 40, 55, 70, 85, 100, TX_GREEN, 0);
    //HumanJohnDraw (700, 700, 0, 0, 0, 0, 0, TX_RED, 0);
    //HumanJohnDraw (400, 400, 0, 0, 0, 0, 0, TX_YELLOW, 35);
    //StoneDraw (230, 498);  // StoneDraw function call
    //StoneDraw (334, 611);
    //StoneDraw (300, 300);
    //StoneDraw (200, 200);
    //TankDraw (635, 354, 0, 25, 0);
    //TankDraw (400, 400, 39, 0, 37);
    //TankDraw (300, 300, -46, 84, 45);
    //TankMove ();
    //HumanJohnMove ();
    //TankandJohnMove ();
    //TankAttack ();
    //TankArmy ();
    //RocketMove ();
    CarDraw ();
    }

void StoneDraw (int x, int y)                       //
    {                                  //
    txSetColor (TX_GREEN);             //
    txLine (x, y, x+31, y-132);       //  StoneDraw function definition
    txLine (x+49, y-121, x+195, y-17);       //
    txLine (x+5, y, x+200, y-17);
    txCircle (x, y, 5);   //230, 498
    }

void HumanJohnDraw(int x, int y, int handRight, int legs, int headUp, int headRightLeft, int handUp,
                   COLORREF color, int legDown, COLORREF colorHands)
    {
    txSetFillColor (color);
    txSetColor (colorHands);
    txLine (x-13, y-104, x+legs, y+legDown);
    txLine (x-54-legs, y-2-legDown, x-51, y-104);
    txLine (x-49, y-223, x-77+handUp, y-301);
    txLine (x-8, y-221, x+24, y-144-handUp);
    txEllipse (x-34+headRightLeft, y-261-headUp, x-5+headRightLeft, y-320-headUp);
    txEllipse (x-11, y-114, x-50, y-255);
    txCircle (x, y, 5);  //96, 491
    }

void RocketDraw (int x, int y)
    {
    txSetColor (TX_LIGHTBLUE);
    txLine (x, y, x+290, y+108);
    txLine (x+2, y-4, x+309, y-62);
    txLine (x+314, y-54, x+300, y+110);
    txLine (x+318, y+112, x+530, y+114);
    txLine (x+530, y+112, x+526, y-66);
    txLine (x+526, y-66, x+343, y-62);
    txSelectFont ("Arial", 36);
    txTextOut (x+340, y+21, "Rocket");
    txCircle (x, y, 5);
    //491, 499
    }

void TankDraw (int x, int y, int muzzleUp, int muzzleLenght, int trackUp, double dir)
    {
    txSetColor (TX_RED, 50);
    txLine (x-30*dir, y+67-trackUp, x-350*dir, y+67+trackUp);
    txSetFillColor (TX_RED);
    txSetColor (TX_ORANGE);
    txRectangle (x-170*dir, y-17, x-276*dir, y+31);

    POINT rectangle [4] = {{x-muzzleLenght*dir, y-15-muzzleUp}, {x-164*dir, y-15},
                           {x-164*dir, y-1}, {x-muzzleLenght*dir, y-1-muzzleUp}};
    txPolygon (rectangle, 4);

    //txEllipse (x+30, y+29, x+350, y+67); //635, 354
    txSelectFont ("Arial", 28);
    //txTextOut (817, 351, "Tank");
    }

void TankMove()
    {
    int x = 600, y = 300;
    while (x > 100)
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        RocketDraw(0, 0);
        //HumanJohnDraw (96, 491, 40, 55, 70, 85, 100, TX_GREEN, 0);
        HumanJohnDraw (700, 700, 0, 0, 0, 0, 0, TX_RED, 0, 0);
        HumanJohnDraw (400, 400, 0, 0, 0, 0, 0, TX_YELLOW, 35, 0);
        StoneDraw (230, 498);  // StoneDraw function call
        //StoneDraw (334, 611);
        //StoneDraw (300, 300);
        //StoneDraw (200, 200);


        TankDraw (x, y, 0, 0, 0, 0);
        x -= 5;
        y -= 2;
        txSleep (100);
        }
    }

void TankandJohnMove()
    {
    int t = 0;
    while (t < 222)
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        HumanJohnDraw (-3*t + 400, 400, 0, 0, 0, 0, 0, TX_YELLOW, 35, 0);
        HumanJohnDraw (-2*t + 700, -2*t + 700, 0, 0, 0, 0, 0, TX_RED, 0, 0);
        HumanJohnDraw (1*t + 96, 491, 40, 55, 70, 85, 100, TX_GREEN, 0, 0);
        RocketDraw(0, 0);
        StoneDraw (230, 498);  // StoneDraw function call
        //StoneDraw (334, 611);
        //StoneDraw (300, 300);
        //StoneDraw (200, 200);

        TankDraw (-10*t + 600, -5*t + 600, 0, 0, 0, 0);  //t = 5    6    7       8      9
        //////////////////////                  100  120  140     160    180
        /////                 t= 5   6   7    8    9
        ///
        t ++;
        txSleep (100);

        }


    }

void HumanJohnMove()
    {
    int x = 96, y = 491;
    while (x < 600)
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        RocketDraw(0, 0);
        //HumanJohnDraw (96, 491, 40, 55, 70, 85, 100, TX_GREEN, 0);
        HumanJohnDraw (700, 700, 0, 0, 0, 0, 0, TX_RED, 0, 0);
        HumanJohnDraw (400, 400, 0, 0, 0, 0, 0, TX_YELLOW, 35, 0);
        StoneDraw (230, 498);  // StoneDraw function call
        //StoneDraw (334, 611);
        //StoneDraw (300, 300);
        //StoneDraw (200, 200);


        HumanJohnDraw (x, y, 0, 0, 0, 0, 0, TX_GREEN, 0, 0);
        x += 4;
        y -= 1;
        txSleep (100);
        }
    }

void TankAttack()
    {
    int t = 0;
    while (t < 100)
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        TankDraw (-10*t + 600, 354, 0, 0, 0, 0);
        t ++;
        txSleep (100);
        }
    }

void TankArmy ()
    {
    int t = 0;
    while (t < 612)
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        TankDraw (-7*t + 700, 480, t, 0, 0, -1);
        TankDraw (4*t + 0, 200, 50, 0, 0, 1-t*0.009);

        HumanJohnDraw (-7*t + 800, 470, 0, 0, 0, -15, 100, TX_GREEN, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-7*t + 950, 460, 0, 28, 0, 0, 0, TX_YELLOW, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-7*t + 1050, 525, 0, 0, 10, -15, 0, TX_ORANGE, 20, TX_LIGHTCYAN);

        HumanJohnDraw (-5*t + 1330, 600 + t%5*4, 0, t%10*3, 0, 0, 0, TX_GREEN, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1360, 600 + t%5*5, 0, t%10*3, 0, 0, 0, TX_GREEN, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1390, 600 + t%3*3, 0, t%10*3, 0, 0, 0, TX_GREEN, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1420, 600 + t%3*6, 0, t%10*3, 0, 0, 0, TX_GREEN, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1450, 600, 0, t%10*3, 0, 0, 0, TX_GREEN, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1480, 600, 0, t%10*3, 0, 0, 0, TX_GREEN, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1510, 600, 0, t%10*3, 0, 0, 0, TX_GREEN, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1540, 600, 0, t%10*3, 0, 0, 0, TX_GREEN, 0, TX_LIGHTCYAN);

        HumanJohnDraw (-5*t + 1830, 600, 0, 28, 0, 0, t%10, TX_YELLOW, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1860, 600, 0, 28, 0, 0, t%10, TX_YELLOW, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1890, 600, 0, 28, 0, 0, t%10, TX_YELLOW, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1920, 600, 0, 28, 0, 0, t%10, TX_YELLOW, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1950, 600, 0, 28, 0, 0, t%10, TX_YELLOW, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 1980, 600, 0, 28, 0, 0, t%10, TX_YELLOW, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 2010, 600, 0, 28, 0, 0, t%10, TX_YELLOW, 0, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 2040, 600, 0, 28, 0, 0, t%10, TX_YELLOW, 0, TX_LIGHTCYAN);

        HumanJohnDraw (-5*t + 2230, 600 + t%5*4, 0, 0, 10, -15, t%5*50, TX_ORANGE, 20, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 2260, 600 + t%3*4, 0, 0, 10, -15, t%2*50, TX_ORANGE, 20, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 2290, 600 + t%5*4, 0, 0, 10, -15, t%5*50, TX_ORANGE, 20, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 2320, 600 + t%3*4, 0, 0, 10, -15, t%2*50, TX_ORANGE, 20, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 2350, 600 + t%5*4, 0, 0, 10, -15, t%5*50, TX_ORANGE, 20, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 2380, 600 + t%3*4, 0, 0, 10, -15, t%2*50, TX_ORANGE, 20, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 2410, 600 + t%5*4, 0, 0, 10, -15, t%5*50, TX_ORANGE, 20, TX_LIGHTCYAN);
        HumanJohnDraw (-5*t + 2440, 600 + t%3*4, 0, 0, 10, -15, t%2*50, TX_ORANGE, 20, TX_LIGHTCYAN);

        TankDraw (-5*t + 2700, 480 + t*20, t%20, 0, t%20, 0);
        //t = 0  1  2  3  4  5  6  7  8
        //    0  1  0  1  0  1  0  1  0 = t%2
        //    0  20 0  20 0  20 0  20 0 = t%2 * 20

        if (GetAsyncKeyState (MK_LBUTTON)) break;

        t ++;
        txSleep (100);
        //printf ("ÿ óáèë êàñóëþ %d ", t);
        }
    }

void RocketMove ()
    {
    int t = 0;
    while (t < 601)
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        RocketDraw(-4*t+700, 300);

        txSleep (100);
        t ++;
        }
    }

void CarDraw ()
    {
    txLine (495, 366, 563, 306);
    txLine (563, 306, 733, 359);
    txLine (733, 359, 738, 493);
    txLine (738, 440, 704, 440);
    txCircle (678, 440, 22);
    txLine (656, 440, 476, 440);
    txCircle (445, 440, 28);
    txLine (412, 440, 372, 440);
    txLine (372, 440, 387, 369);
    txLine (387, 369, 497, 363);
    }



