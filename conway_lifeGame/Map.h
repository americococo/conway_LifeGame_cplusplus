#pragma once

class Block;
#include <vector>
class Map
{
public:
	Map(int x, int y);
	~Map();

//�� ũ��
private:
	int _x;
	int _y;


	//���� �Ӽ�
public:
	void Init();
	void Update();
	void Change();//���� ��ü���� �ٲ�
	void Show();//�׸���
private:
	bool * _MapList;
	bool * _nextList;
};

