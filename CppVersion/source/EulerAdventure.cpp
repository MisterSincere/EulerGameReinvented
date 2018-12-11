
#include <iostream>

#include "MainLoop.h"


int main(char** argv, int argc)
{
	MainLoop* ml = new MainLoop;

	// Let the game set itself up
	if (!ml->Init()) return -1;

	// Start main loop
	int retVal = ml->Run();
	if (retVal) system("PAUSE");

	// Free memory
	delete ml;

	return retVal;
}