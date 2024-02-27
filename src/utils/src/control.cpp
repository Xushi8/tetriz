#include <utils/control.h>
#include <utils/utils.h>
#include <utils/terminal.h>
#include <utils/draw.h>
#include <termios.h>
#include <cstdio>
#include <thread>
// #include <fmt/core.h>
#include <iostream>

namespace tetriz
{
char getch()
{
	static struct termios old, cur;
	tcgetattr(0, &cur);
	old = cur;
	cfmakeraw(&cur);
	tcsetattr(0, 0, &cur);
	char ch = static_cast<char>(getchar());
	tcsetattr(0, 0, &old);
	return ch;
}
static bool game_running;
static size_t row, col;
static char command;
void key_event()
{
	while (game_running)
	{
		command = static_cast<char>(getch());
		if (command == 'q')
		{
			command_q();
		}
		else if (command == 'a')
		{
			command_a();
		}
		else if (command == 'd')
		{
			command_d();
		}
		else if (command == 'w')
		{
			command_rotate();
		}
		else if (command == 's')
		{
			command_s();
		}
	}
}

inline void key_listener()
{
	std::jthread t(key_event);
	t.detach();
}

void init()
{
	game_running = true;
	row = 2;
	col = 15;
	hide_cursor();
	key_listener();
}

void loop()
{
	while (game_running)
	{
		clean_screen();

		draw_window(1, 1, 9, 6, "Hold");
		draw_window(1, 10, 12, 22, "Tetriz");
		draw_window(7, 1, 9, 16, "Status");
		draw_window(19, 22, 8, 4, "Hold");
		draw_window(1, 22, 8, 18, "Hold");

		move_to(10, 4);
		// fmt::print("FPS: {}", fps());
		std::cout << "FPS: " << fps();

		move_to(row, col);
		set_back_color(123);
		// fmt::print("  ");
		std::cout << "  ";
		reset_color();
		fflush(stdout);

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(100ms);
	}
}

void command_q()
{
	game_running = false;
}

void command_a()
{
	col--;
}

void command_d()
{
	col++;
}

void command_rotate()
{
	row--;
}

void command_s()
{
	row++;
}

void exit()
{
	show_cursor();
	reset_color();
	clean_screen();
	move_to(1, 1);
	set_fore_color(9);
	// fmt::print("Bye!\n");
	std::cout << "Bye!" << std::endl;
}

} // namespace tetriz