#include <terminal/terminal.h>

namespace tetriz
{
inline constexpr std::string_view CSI = "\033[";

void move_to(int row, int col)
{
	fmt::print("{}{};{}H", CSI, row, col);
}

void set_fore_color(int color_id)
{
	fmt::print("{}38;5;{}m", CSI, color_id);
}

void set_back_color(int color_id)
{
	fmt::print("{}48;5;{}m", CSI, color_id);
}

void clean_screen()
{
	fmt::print("{}2J", CSI);
}

void reset_color()
{
	fmt::print("{}0m", CSI);
}

void hide_cursor()
{
	fmt::print("{}?25l", CSI);
}

void show_cursor()
{
	fmt::print("{}?25h", CSI);
}

} // namespace tetriz