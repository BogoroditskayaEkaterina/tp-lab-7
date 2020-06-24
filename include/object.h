#pragma once
#pragma once

#include <string>
#include "pair.h"
#include "cell.h"

class Object 
{

protected:

	Cell* cell;
	ObjType type;

public:

	Object();
	Cell* getCell();
	ObjType getType();
	void setCell(Cell* cell);
	virtual void live() = 0;

};