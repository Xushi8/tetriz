#include <utils/draw.h>
#include <array>
#include <utils/terminal.h>
// #include <fmt/core.h>
#include <iostream>

namespace
{
constexpr size_t block2col(size_t b)
{
	return b * 2 - 1;
}
} // namespace

namespace tetriz
{
constexpr std::array<std::string_view, 6> style1 = {"┌", "┐", "└", "┘", "│", "─"};
constexpr std::array<std::string_view, 6> style2 = {"┏", "┓", "┗", "┛", "┃", "━"};
constexpr std::array<std::string_view, 6> style3 = {"╔", "╗", "╚", "╝", "║", "═"};
constexpr std::array<std::string_view, 6> style4 = {"╭", "╮", "╰", "╯", "│", "─"};
std::array<std::string_view, 6> current_style = style4;

void draw_window(size_t top, size_t left, size_t width, size_t height, std::string_view title)
{
	tetriz::move_to(top, block2col(left));
	for (size_t i = 0; i < height; i++)
	{
		tetriz::move_to(top + i, block2col(left));
		for (size_t j = 0; j < width; j++)
		{
			if (i == 0) // 第一行
			{
				if (j == 0) // 第一列
				{
					// fmt::print(" ┌");
					// fmt::print(" {}", current_style[0]);
					std::cout << ' ' << current_style[0];
				}
				else if (j + 1 == width) // 最后一列
				{
					// fmt::print("┐");
					// fmt::print("{}", current_style[1]);
					std::cout << current_style[1];
				}
				else
				{
					// fmt::print("──");
					// fmt::print("{0}{0}", current_style[5]);
					std::cout << current_style[5] << current_style[5];
				}
			}
			else if (i + 1 == height) // 最后一行
			{
				if (j == 0) // 第一列
				{
					// fmt::print(" └");
					// fmt::print(" {}", current_style[2]);
					std::cout << ' ' << current_style[2];
				}
				else if (j + 1 == width) // 最后一列
				{
					// fmt::print("┘");
					// fmt::print("{}", current_style[3]);
					std::cout << current_style[3];
				}
				else
				{
					// fmt::print("──");
					// fmt::print("{0}{0}", current_style[5]);
					std::cout << current_style[5] << current_style[5];
				}
			}
			else
			{
				if (j == 0) // 第一列
				{
					// fmt::print(" │");
					// fmt::print(" {}", current_style[4]);
					std::cout << ' ' << current_style[4];
				}
				else if (j + 1 == width) // 最后一列
				{
					// fmt::print("│");
					// fmt::print("{}", current_style[4]);
					std::cout << current_style[4];
				}
				else
				{
					// fmt::print("  ");
					std::cout << "  ";
				}
			}
		}
	}
	// title
	tetriz::move_to(top, block2col(left) + (width * 2 - title.size()) / 2);
	// fmt::print("{}", title);
	std::cout << title;
}

} // namespace tetriz