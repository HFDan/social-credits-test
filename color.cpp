#include "color.h"

#include <cstdio>

#if UNIX
void setclr(int FG, int BG) { printf("\033[%i;%im", FG, BG + 10); }
void resetclr() { printf("\033[0m"); }
#elif WIN32
#include <windows.h>
#warning Changing colors is not currently supported on windows. This only executes a nop as a placeholder
void setclr(int FG, int BG) {
	__asm {
		nop;
	}
}
#endif
