#pragma once
#include <cstdint>

enum colors {
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	MAGENTA = 35,
	CYAN = 36,
	WHITE = 37,
	DEFAULT = 39
};

/**
 * @brief Sets terminal color
 * @param FG Foreground
 * @param BG Background
 */
void setclr(int FG, int BG);

/**
 * @brief Resets terminal color to default
 */
void resetclr();
