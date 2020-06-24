#include "object.h"

Object::Object() 
{
	this->cell = nullptr;
}

Cell* Object::getCell() 
{
	return this->cell;
}

ObjType Object::getType() 
{
	return this->type;
}

void Object::setCell(Cell* cell) 
{
	this->cell = cell;
}