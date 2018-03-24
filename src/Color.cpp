
#include "Color.h"

const Color Color::White(255, 255, 255);
const Color Color::Black(0, 0, 0);
const Color Color::Blue(0, 0, 255);
const Color Color::Green(0, 255, 0);
const Color Color::Red(255, 0, 0);

Color::Color(uint8_t red, uint8_t green, uint8_t blue) : m_red(red), m_green(green), m_blue(blue)
{
}

Color::~Color()
{
}

size_t Color::printTo(Print &p) const
{
    size_t len = 0;

    len += p.write((char)map(m_red, 0, 254, '0', '3'));
    len += p.write((char)map(m_green, 0, 254, '0', '3'));
    len += p.write((char)map(m_blue, 0, 254, '0', '3'));

    return len;
}
