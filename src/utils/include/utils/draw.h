#pragma once
#include <string_view>
#include <string>
#include <utils/terminal.h>
#include <fmt/core.h>
#include <array>

namespace tetriz
{
void draw_window(size_t top, size_t left, size_t width, size_t height, std::string_view title);
}