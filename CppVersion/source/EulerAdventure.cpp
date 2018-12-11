
#include <iostream>

#include "Tuna.h"


int main(char** argv, int argc)
{
	Tuna* ml = new Tuna;

	// Let the game set itself up
	if (!ml->Init()) return -1;

	// Start main loop
	int retVal = ml->Run();
	if (retVal) system("PAUSE");

	// Free memory
	delete ml;

	return retVal;
}