#pragma once
#include <map>
#include <iostream>
using namespace std;

class Player {
private:
	string deck[52];				// �迭�� ����Ͽ� 52���� ī�带 �����ϱ� ���� ����
public:
	Player();					// �����ڸ� ����Ͽ� Ȧ�� ī�带 ����
	void Playerdraw();		// �÷��̾ �������� ī�� 2���� �̱� ���� �Լ�
};