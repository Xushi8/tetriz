#include <fmt/core.h>
#include <terminal/terminal.h>
#include <thread>


int main()
{
	// print("{}{}{}{}\n", "\033[5;10H", "\033[38;5;214m", "Hello world", "\033[10;1H");

	// tetriz::move_to(5, 10);
	// tetriz::set_fore_color(214);
	// fmt::print("Hello World");
	// tetriz::move_to(10, 1);

	tetriz::hide_cursor();

	int row = 1;
	while (1)
	{
		tetriz::clean_screen();
		tetriz::move_to(row++, 10);
		tetriz::set_back_color(123);
		fmt::print("  ");
		tetriz::reset_color();
		fflush(stdout);

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(500ms);
	}


	return 0;
}