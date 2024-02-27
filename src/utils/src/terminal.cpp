#include <utils/terminal.h>
// #include <fmt/core.h>
#include <string_view>
#include <iostream>

namespace tetriz
{
inline constexpr std::string_view CSI = "\033[";

void move_to(size_t row, size_t col)
{
	// fmt::print("{}{};{}H", CSI, row, col);
	std::cout << CSI << row << ';' << col << 'H';
}

void set_fore_color(size_t color_id)
{
	// fmt::print("{}38;5;{}m", CSI, color_id);
	std::cout << CSI << "38;5;" << color_id << 'm';
}

void set_back_color(size_t color_id)
{
	// fmt::print("{}48;5;{}m", CSI, color_id);
	std::cout << CSI << "48;5;" << color_id << 'm';
}

void clean_screen()
{
	// fmt::print("{}2J", CSI);
	std::cout << CSI << "2J";
}

void reset_color()
{
	// fmt::print("{}0m", CSI);
	std::cout << CSI << "0m";
}

void hide_cursor()
{
	// fmt::print("{}?25l", CSI);
	std::cout << CSI << "?25l";
}

void show_cursor()
{
	// fmt::print("{}?25h", CSI);
	std::cout << CSI << "?25h";
}

} // namespace tetriz