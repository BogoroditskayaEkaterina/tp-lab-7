#include "ocean.h"
#include "stone.h"
#include "corall.h"
#include "prey.h"
#include "predator.h"
#include "windows.h"
#include <iostream>
#include <vector>

Ocean::Ocean() 
{
	cells = new Cell *[rows];
	for (int i = 0; i < rows; i++) 
	{
		cells[i] = new Cell[columns];
		for (int j = 0; j < columns; j++) 
		{
			cells[i][j].init({ i, j }, this);
		}
	}
}
void Ocean::delObj(Object* object) 
{
	int n = stuff.size();
	for (int i = 0; i < n; i++)
	{
		if (stuff[i] == object)
		{
			stuff[i]->getCell()->killMe();
			auto iter = stuff.begin();
			stuff.erase(iter + i);
			break;
		}
	}
}

void Ocean::addObjs(ObjType type, int q) 
{
	for (int i = 0; i < q; i++)
		{
			Cell* cellAdd = &cells[rand() % rows][rand() % columns];

			while (cellAdd->getObj() != nullptr)
			{
				cellAdd = &cells[rand() % rows][rand() % columns];
			}

			if (type == ObjType::STONE)
			{
				Stone* stone = new Stone();
				stone->setCell(cellAdd);
				cellAdd->setObj(stone);
				stuff.push_back(stone);
				break;
			}

			 else if (type == ObjType::CORALL)
			{
				Corall* corall = new Corall();
				corall->setCell(cellAdd);
				cellAdd->setObj(corall);
				stuff.push_back(corall);
				break;
			}

			else if (type == ObjType::PREY)
			{
				Prey* prey = new Prey();
				prey->setCell(cellAdd);
				cellAdd->setObj(prey);
				stuff.push_back(prey);
				break;
			}

			else if (type == ObjType::PREDATOR)
			{
				Predator* predator = new Predator();
				predator->setCell(cellAdd);
				cellAdd->setObj(predator);
				stuff.push_back(predator);
				break;
			}

			else
			{
				break;
			}
		}
	}

void Ocean::print() 
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (cells[i][j].getObj() == nullptr)
			{
				printf(".");
			}

			ObjType type = cells[i][j].getObj()->getType();

			if (type == ObjType::PREY)
			{
				printf("f");
			}
			else if (type == ObjType::PREDATOR)
			{
				printf("F");
			}
			else if (type == ObjType::STONE)
			{
				printf("#");
			}
			else if (type == ObjType::CORALL)
			{
				printf("*");
			}
		}
		printf("\n");
	}
}

Cell* Ocean::freeCellcheck(pair crd)
{
	std::vector<pair> newcrd = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 0 }, { -1, 1 }, { -1, -1 } };
	int w = 9;

	while (--w)
	{
		int i = rand() % w;
		int xnew = crd.x + newcrd[i].x;
		int ynew = crd.y + newcrd[i].y;

		if (xnew >= 0 && xnew < rows && ynew >= 0 && ynew < columns)
		{
			if (cells[xnew][ynew].getObj() == nullptr)
				return &cells[xnew][ynew];
		}
		newcrd.erase(newcrd.begin() + i);

	}
	return nullptr;
}

Cell* Ocean::preyCellcheck(pair crd)
{
	std::vector<pair> newcrd = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 0 }, { -1, 1 }, { -1, -1 } };
	int w = 9;

	while (--w)
	{

		int i = rand() % w;
		int xnew = crd.x + newcrd[i].x;
		int ynew = crd.y + newcrd[i].y;

		if (xnew >= 0 && xnew < rows && ynew >= 0 && ynew < columns)
		{
			if (cells[xnew][ynew].getObj() != nullptr && cells[xnew][ynew].getObj()->getType() == ObjType::PREY)
			{
				return &cells[xnew][ynew];
			}
		}
		newcrd.erase(newcrd.begin() + i);
	}
	return nullptr;
}
void Ocean::run() 
{
	int preyN, predatorN;
	int iteration = 1;
	ObjType type;
	while (1)
	{
		preyN = 0;
		predatorN = 0;
		for (int i = 0; i < stuff.size(); i++)
		{
			type = stuff[i]->getType();
			if (type == ObjType::PREY)
			{
				preyN++;
			}
			else if (type == ObjType::PREDATOR)
			{
				predatorN++;
			}
		}

		if (preyN == 0)
		{
			printf("Predators survived");
			break;
		}

		else if (predatorN == 0)
		{
			printf("Preys survived");
			break;
		}

		for (int i = 0; i < stuff.size(); i++)
		{
			stuff[i]->live();
		}
		Sleep(1000);
		print();
	}
}