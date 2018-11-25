#include <iostream>

#include "Map.h"

#include <Windows.h>
#include <conio.h>
int main()
{
	int x, y;

	std::cout << "맵의 크기를 지정해주세요 (x y)"<<std::endl;
	std::cin >> x >> y;

	//맵초기화
	Map * map = new Map(x,y);
	map->Init();

	while (1)
	{
		system("cls");
		map->Update();
		map->Show();
		Sleep(500);

		if (_kbhit())
			break;
	}


	delete map;

	return 0;
}