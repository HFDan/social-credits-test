#include "color.h"

#include <cstdio>

#ifndef _WIN32
void setclr(int FG, int BG) { printf("\033[%i;%im", FG, BG + 10); }
void resetclr() { printf("\033[0m"); }
#else
#include <windows.h> 
//#warning Changing colors is not currently supported on windows. This only executes a nop as a placeholder
// FIXME: This is a massive hack
void setclr(int FG, int BG) {
	HANDLE stdoutHand = GetStdHandle(STD_OUTPUT_HANDLE);	
	WORD attrib = 0;

	switch (FG) {
		case colors::RED:
			attrib |= FOREGROUND_RED;
			break;

		case colors::BLUE:
			attrib |= FOREGROUND_BLUE; 
			break;

		case colors::GREEN:
			attrib |= FOREGROUND_GREEN;
			break;

		case colors::YELLOW:
			attrib |= FOREGROUND_GREEN | FOREGROUND_RED;
			break;

		case colors::CYAN:
			attrib |= FOREGROUND_GREEN | FOREGROUND_BLUE;
			break;

		case colors::MAGENTA:
			attrib |= FOREGROUND_RED | FOREGROUND_BLUE;
			break;
		
		case colors::DEFAULT:
		case colors::WHITE:
			attrib |= FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;
			break;

	}

	switch (BG) {
		case colors::RED:
			attrib |= BACKGROUND_RED;
			break;

		case colors::BLUE:
			attrib |= BACKGROUND_BLUE; 
			break;

		case colors::GREEN:
			attrib |= BACKGROUND_GREEN;
			break;

		case colors::YELLOW:
			attrib |= BACKGROUND_GREEN | BACKGROUND_RED;
			break;

		case colors::CYAN:
			attrib |= BACKGROUND_GREEN | BACKGROUND_BLUE;
			break;

		case colors::MAGENTA:
			attrib |= BACKGROUND_RED | BACKGROUND_BLUE;
			break;

		case colors::WHITE:
			attrib |= BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN;
			break;

	}

	SetConsoleTextAttribute(stdoutHand, attrib);
}

void resetclr() {
	setclr(colors::DEFAULT, colors::BLACK);
}
#endif
