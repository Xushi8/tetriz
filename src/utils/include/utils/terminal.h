#pragma once
#include <fmt/core.h>

namespace tetriz
{
void move_to(size_t row, size_t col);
void set_fore_color(size_t color_id);
void set_back_color(size_t color_id);
void clean_screen();
void reset_color();
void hide_cursor();
void show_cursor();
} // namespace tetriz