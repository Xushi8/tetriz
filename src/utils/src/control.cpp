#include <utils/control.h>
#include <utils/utils.h>
#include <utils/terminal.h>
#include <utils/draw.h>
#include <termios.h>
#include <cstdio>
#include <thread>

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

static char command = '\0';
void key_event()
{
	while (1)
	{
		command = static_cast<char>(getch());
		if (command == 'q')
		{
			break;
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
	hide_cursor();
	key_listener();
}

void loop()
{
	size_t row = 1;
	while (1)
	{
		clean_screen();

		draw_window(1, 1, 9, 6, "Hold");
		draw_window(1, 10, 12, 22, "Tetriz");
		draw_window(7, 1, 9, 16, "Status");
		draw_window(19, 22, 8, 4, "Hold");
		draw_window(1, 22, 8, 18, "Hold");

		move_to(10, 4);
		fmt::print("FPS: {}", fps());

		move_to(row++ % 20, 10);
		set_back_color(123);
		fmt::print("  ");
		reset_color();
		fflush(stdout);

		if (command == 'q')
		{
			break;
		}

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(100ms);
	}
}

void exit()
{
	show_cursor();
	reset_color();
	clean_screen();
	move_to(1, 1);
	set_fore_color(9);
	fmt::print("Bye!\n");
}

} // namespace tetriz