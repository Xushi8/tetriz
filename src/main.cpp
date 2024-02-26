#include <fmt/core.h>
#include <utils/terminal.h>
#include <utils/utils.h>
#include <utils/draw.h>
#include <utils/control.h>

int main()
{
	tetriz::init();
	tetriz::loop();
	tetriz::exit();
	return 0;
}
