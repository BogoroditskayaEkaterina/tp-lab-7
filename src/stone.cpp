#include "stone.h"
#include "object.h"

Stone::Stone()
{
	cell = nullptr;
	type = ObjType::STONE;
}

void Stone::live() 
{}