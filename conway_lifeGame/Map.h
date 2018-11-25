#pragma once

class Block;
#include <vector>
class Map
{
public:
	Map(int x, int y);
	~Map();

//∏  ≈©±‚
private:
	int _x;
	int _y;


	//∏ ¿« º”º∫
public:
	void Init();
	void Update();
	void Change();//∏ ¿« ¿¸√ºæ¿¿ª πŸ≤ﬁ
	void Show();//±◊∏Æ±‚
private:
	bool * _MapList;
	bool * _nextList;
};

