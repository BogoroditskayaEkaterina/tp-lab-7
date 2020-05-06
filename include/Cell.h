#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "Object.h"

class Ocean;

class Cell
{
	friend Ocean;
	friend Object;
private:
	Pair crd;
	Object *obj = nullptr;
	Ocean *ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		crd(p),
		//obj(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Object* getObject();
	void setObject(Object*);
	void killMe();
};
#endif