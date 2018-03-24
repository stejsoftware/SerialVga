
#include "Color.h"
#include "SerialVga.h"

#define STARTCMD F("^[")

SerialVgaClass::SerialVgaClass()
{
}

SerialVgaClass::~SerialVgaClass()
{
}

void SerialVgaClass::begin(uint32_t baud)
{
    Serial.begin(baud);
}

void SerialVgaClass::end()
{
    Serial.end();
}

size_t SerialVgaClass::write(uint8_t c)
{
    return Serial.print((char)c);
}

void SerialVgaClass::window(uint16_t win, uint16_t left, uint16_t top, uint16_t width, uint16_t height, bool border)
{
    window(win, left, top, width, height, border, "");
}

void SerialVgaClass::window(uint16_t win, uint16_t left, uint16_t top, uint16_t width, uint16_t height, bool border, const char *title)
{
    Serial.print(STARTCMD);
    Serial.print(F("w,"));
    Serial.print(win);
    Serial.print(F(","));
    Serial.print(left);
    Serial.print(F(","));
    Serial.print(top);
    Serial.print(F(","));
    Serial.print(width);
    Serial.print(F(","));
    Serial.print(height);
    Serial.print(F(","));
    Serial.print(border ? 1 : 0);
    Serial.print(F(","));
    Serial.println(title);

    delay(20);
}

void SerialVgaClass::focus(uint16_t win)
{
    Serial.print(STARTCMD);
    Serial.print(F("f,"));
    Serial.println(win);

    delay(2);
}

void SerialVgaClass::clear()
{
    Serial.print(STARTCMD);
    Serial.println(F("e"));

    delay(2);
}

void SerialVgaClass::position(uint16_t left, uint16_t top)
{
    Serial.print(STARTCMD);
    Serial.print(F("p,"));
    Serial.print(left);
    Serial.print(F(","));
    Serial.println(top);

    delay(20);
}

void SerialVgaClass::cursor(uint16_t win, bool on)
{
    Serial.print(STARTCMD);
    Serial.print(F("c,"));
    Serial.print(win);
    Serial.print(F(","));
    Serial.println(win, on ? 1 : 0);

    delay(2);
}

void SerialVgaClass::setBaud(uint16_t baud)
{
    Serial.print(STARTCMD);
    Serial.print(F("b,"));
    Serial.println(baud);

    delay(2);
}

void SerialVgaClass::reboot()
{
    Serial.print(STARTCMD);
    Serial.println(F("r"));

    delay(2000);
}

void SerialVgaClass::lineColor(uint16_t start, uint16_t end, const Color &foreground, const Color &background)
{
    Serial.print(STARTCMD);
    Serial.print(F("l,"));
    Serial.print(start);
    Serial.print(F(","));
    Serial.print(end);
    Serial.print(F(","));
    Serial.print(foreground);
    Serial.print(F(","));
    Serial.println(background);

    delay(22);
}

void SerialVgaClass::lineColor(uint16_t line, const Color &foreground, const Color &background)
{
    lineColor(line, line, foreground, background);
}

SerialVgaClass SerialVga;
