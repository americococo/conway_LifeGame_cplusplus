#include "Map.h"

#include <chrono>
#include <iostream>
Map::Map(int x, int y)
{
	_x = x;
	_y = y;

	_MapList = (bool*)malloc((sizeof(bool))*_y*_x);

	_nextList = (bool*)malloc((sizeof(bool))*_y*_x);

}

Map::~Map()
{
}
void Map::Init()
{
	std::vector<bool> rowList;
	srand(time(NULL));
	for (int y = 0; y < _y; y++)
	{
		for (int x = 0; x < _x; x++)
		{
			if (rand() % 100 < 50)
				_MapList[y* _x + x] = true;
			else
				_MapList[y* _x + x] = false;
		}
	}
}

void Map::Update()
{
	for (int y = 0; y < _y; y++)
	{
		for (int x = 0; x < _x; x++)
		{
			int neighbors = 0;

			int minX = x - 1 < 0 ? 0 : x - 1;
			int maxX = x + 1 == _x ? _x : x + 1;

			int minY = y - 1 < 0 ? 0 : y - 1;
			int maxY = y + 1 == _y ? _y : y + 1;

			for (int posY = minY; posY <= maxY; posY++)
			{
				for (int posX = minX; posX <= maxX; posX++)
				{
					if (!(posX == x && posY == y))
						if (_MapList[posY*_x+posX] == true)
							neighbors++;

				}
			}

			//change rule
			if (_MapList[y*_x + x] == false && neighbors == 3)
				_nextList[y*_x + x] = true;

			else if (_MapList[y*_x + x] == true && neighbors == 2 || neighbors == 3)
				_nextList[y*_x + x] = true;

			else
				_nextList[y*_x + x] = false;
		}
	}
	Change();
}
void Map::Change()
{
	for (int y = 0; y < _y; y++)
	{
		for (int x = 0; x < _x; x++)
		{
			_MapList[y*_x + x] = _nextList[y*_x + x];
		}
	}
}
void Map::Show()
{
	std::cout << std::endl;
	for (int y = 0; y < _y; y++)
	{
		for (int x = 0; x < _x; x++)
		{
			if (_MapList[y*_x + x])
				std::cout << "бс";
			else
				std::cout << "бр";
		}
		std::cout << std::endl;
	}
	
}