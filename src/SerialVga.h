#ifndef __SERIAL_VGA_
#define __SERIAL_VGA_

#include <Arduino.h>

class Color;

class SerialVgaClass : public Print
{
public:
  static const uint8_t WIDTH = 100;
  static const uint8_t HEIGHT = 50;

  SerialVgaClass();
  ~SerialVgaClass();

  void begin(uint32_t baud);
  void end();

  // Print functions
  size_t write(uint8_t);

  // Serial VGA comands
  void window(uint16_t win, uint16_t left, uint16_t top, uint16_t width, uint16_t height, bool border, const char *title);
  void window(uint16_t win, uint16_t left, uint16_t top, uint16_t width, uint16_t height, bool border);
  void focus(uint16_t win);
  void clear();
  void position(uint16_t x, uint16_t y);
  void cursor(uint16_t win, bool on);
  void setBaud(uint16_t baud);
  void reboot();
  void lineColor(uint16_t start, uint16_t end, const Color &foreground, const Color &background);
  void lineColor(uint16_t line, const Color &foreground, const Color &background);
  void inverse(const char *text_str);
};

extern SerialVgaClass SerialVga;

#endif // __SERIAL_VGA_