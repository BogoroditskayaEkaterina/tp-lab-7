
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
//#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, PREY, PREDATOR };

class Cell;
class Ocean;

class Object
{
protected:
	Cell *cell;
	int life;
	ObjType species;
	char symb;
	bool alive;
public:
	Object(Cell * = nullptr);
	//virtual ~Object();
	virtual void live() = 0; // ����� �������
	void setCell(Cell*);
	ObjType getSpecies();
	bool isAlive();
	Cell* getCell();
	char getSymb();
};
#endif