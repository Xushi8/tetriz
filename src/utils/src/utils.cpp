#include <utils/utils.h>
#include <chrono>

namespace tetriz
{
size_t fps()
{
	using namespace std::chrono_literals;
	static auto t_start = std::chrono::steady_clock::now();
	static size_t frame_count = 0;
	static size_t res = 0;

	auto t_end = std::chrono::steady_clock::now();
	frame_count++;
	if (t_end - t_start > 1s)
	{
		res = frame_count;

		frame_count = 0;
		t_start = t_end;
	}
	return res;
}
} // namespace tetriz