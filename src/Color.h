#ifndef __COLOR_
#define __COLOR_

#include <Arduino.h>
#include <Printable.h>

class Color : public Printable
{
public:
  Color(uint8_t r, uint8_t g, uint8_t b);
  ~Color();

  size_t printTo(Print &p) const;

  static const Color White;
  static const Color Black;
  static const Color Blue;
  static const Color Green;
  static const Color Red;
  static const Color Purple;
  static const Color Gray;

private:
  uint8_t m_red;
  uint8_t m_green;
  uint8_t m_blue;
};

#endif //__COLOR_
