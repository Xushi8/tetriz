#include <fmt/core.h>
#include <utils/terminal.h>
#include <utils/utils.h>
#include <utils/draw.h>
#include <thread>

namespace tetriz
{
void init()
{
	tetriz::clean_screen();
	hide_cursor();
	draw_window(1, 1, 9, 6, "Hold");
	draw_window(1, 10, 12, 22, "Tetriz");
	draw_window(7, 1, 9, 16, "Status");
	draw_window(19, 22, 8, 4, "Hold");
	draw_window(1, 22, 8, 18, "Hold");
}

void loop()
{
	int row = 1;
	while (1)
	{
		tetriz::move_to(10, 4);
		fmt::print("FPS: {}", tetriz::fps());

		tetriz::move_to(5, 10);
		tetriz::set_back_color(123);
		fmt::print("  ");
		tetriz::reset_color();
		fflush(stdout);

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(100ms);
	}
}

void exit()
{
	show_cursor();
	reset_color();
}

} // namespace tetriz

int main()
{
	tetriz::init();
	tetriz::loop();
	tetriz::exit();
	return 0;
}
