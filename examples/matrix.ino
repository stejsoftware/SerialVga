#include <Arduino.h>
#include <SerialVga.h>
#include <Color.h>

char charSet[] = "0123456789abcdefghijklmnopqrstuvwxyz";

void drawChar(int x, int y, char c)
{
    SerialVga.position(x, y);
    SerialVga.print(c);
    delay(2);
}

char randChar()
{
    return charSet[rand() % sizeof(charSet)];
}

void drop(int c)
{
    SerialVga.clear();

    int len = (rand() % 10) + 5;

    for (int y = 0; y < SerialVga.HEIGHT + len; y++)
    {
        if (y < SerialVga.HEIGHT)
        {
            SerialVga.lineColor(y, Color::White, Color::Black);
            drawChar(c, y, randChar());
        }

        for (int x = 1; x <= min(y, len); x++)
        {
            SerialVga.lineColor(y - x, Color(0, map(x, 0, min(y, len), 255, 0), 0), Color::Black);
        }
    }
}

void setup()
{
    SerialVga.begin(9600);
    SerialVga.reboot();

    // draw a window around the whole screen to all new monitors to auto adjust.
    SerialVga.window(1, 0, 0, SerialVga.WIDTH, SerialVga.HEIGHT, true);
    delay(5000);

    // remove the borders
    SerialVga.window(1, 0, 0, SerialVga.WIDTH, SerialVga.HEIGHT, false);
    delay(1000);
}

void loop()
{
    drop(rand() % 100);
}