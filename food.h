#ifndef FOOD_H
#define FOOD_H

#include "color.h"

class food
{
public:
  food(const double x = 0.0, const double y = 0.0, const color &c = color(),const double timer=0.0);

  const color &get_color() const noexcept { return m_color; }
  double get_x() const noexcept;
  double get_y() const noexcept;
  double get_timer_regeneration() const noexcept { return m_timer;}
private:
  double m_x;
  double m_y;
  color m_color;
  double m_timer;
};

void test_food();

/// Get the blueness (from the color) of the food
int get_blueness(const food &f) noexcept;

/// Get the greenness (from the color) of the food
int get_greenness(const food &f) noexcept;

/// Get the redness (from the color) of the food
int get_redness(const food &f) noexcept;

/// Implement stream operator
std::ostream& operator << (std::ostream &out, const food food);
#endif // FOOD_H
