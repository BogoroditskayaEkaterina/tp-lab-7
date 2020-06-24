#include "ocean.h"
#include <ctime>
#include <time.h>
#include <cstdlib>

int main() 
{
	srand((unsigned)time(NULL));
	Ocean* ocean = new Ocean;
	ocean->addObjs(ObjType::PREY, 100);
	ocean->addObjs(ObjType::PREDATOR, 50);
	ocean->addObjs(ObjType::STONE, 15);
	ocean->addObjs(ObjType::CORALL, 10);
	ocean->print();
	ocean->run();
	delete ocean;
	return 0;
}