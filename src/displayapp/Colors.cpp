#include "displayapp/Colors.h"

using namespace Pinetime::Applications;
using namespace Pinetime::Controllers;

lv_color_t Pinetime::Applications::Convert(Pinetime::Controllers::Settings::Colors color) {
  switch (color) {
    case Pinetime::Controllers::Settings::Colors::White:
      return LV_COLOR_WHITE;
    case Pinetime::Controllers::Settings::Colors::Silver:
      return LV_COLOR_SILVER;
    case Pinetime::Controllers::Settings::Colors::Gray:
      return LV_COLOR_GRAY;
    case Pinetime::Controllers::Settings::Colors::Black:
      return LV_COLOR_BLACK;
    case Pinetime::Controllers::Settings::Colors::Red:
      return LV_COLOR_RED;
    case Pinetime::Controllers::Settings::Colors::Maroon:
      return LV_COLOR_MAKE(0xeb, 0x6f, 0x92);
    case Pinetime::Controllers::Settings::Colors::Yellow:
      return LV_COLOR_YELLOW;
    case Pinetime::Controllers::Settings::Colors::Olive:
      return LV_COLOR_MAKE(0xf6, 0xc1, 0x77);
    case Pinetime::Controllers::Settings::Colors::Lime:
      return LV_COLOR_LIME;
    case Pinetime::Controllers::Settings::Colors::Green:
      return LV_COLOR_MAKE(0x19, 0x17, 0x24);
    case Pinetime::Controllers::Settings::Colors::Cyan:
      return LV_COLOR_CYAN;
    case Pinetime::Controllers::Settings::Colors::Teal:
      return LV_COLOR_MAKE(0x9c, 0xcf, 0xd8);
    case Pinetime::Controllers::Settings::Colors::Blue:
      return LV_COLOR_BLUE;
    case Pinetime::Controllers::Settings::Colors::Navy:
      return LV_COLOR_MAKE(0xeb, 0xbc, 0xba);
    case Pinetime::Controllers::Settings::Colors::Magenta:
      return LV_COLOR_MAGENTA;
    case Pinetime::Controllers::Settings::Colors::Purple:
      return LV_COLOR_MAKE(0xc4, 0xa7, 0xe7);
    case Pinetime::Controllers::Settings::Colors::Orange:
      return LV_COLOR_ORANGE;
    case Pinetime::Controllers::Settings::Colors::Pink:
      return LV_COLOR_MAKE(0xeb, 0xbc, 0xba);
    default:
      return LV_COLOR_WHITE;
  }
}
