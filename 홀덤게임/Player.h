#pragma once
#include <map>
#include <iostream>
using namespace std;

class Player {
private:
	string deck[52];				// 배열을 사용하여 52개의 카드를 저장하기 위한 변수
public:
	Player();					// 생성자를 사용하여 홀덤 카드를 매핑
	void Playerdraw();		// 플레이어가 랜덤으로 카드 2개를 뽑기 위한 함수
};