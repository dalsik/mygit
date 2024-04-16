#include <iostream>
#include <string>
#include <random>
#include "Player.h"
using namespace std;


/*
// 생성자를 사용하여 카드 딕셔너리 생성
Player::Player() {
	string words = "CSHD"; 		// C(클로버), S(스페이드), H(하트), D(다이아)로 표시
	for (char word : words) {	// CSHD 문자열을 한 문자씩 사용하여 반복문 진행
		for (int i = 2; i <= 10; i++) {		//2~10까지 카드 
			this->HoldomCards[to_string(i) + word] = 1;
		}
		this->HoldomCards["A" + std::string(1, word)] = 1;
		this->HoldomCards["J" + std::string(1, word)] = 1;
		this->HoldomCards["Q" + std::string(1, word)] = 1;
		this->HoldomCards["K" + std::string(1, word)] = 1;
	}
}
*/

// 배열에 카드를 대입하여 초기화 시키기
Player::Player() {
	cout << "********** 안녕하세요 홀덤게임에 오신 것을 환영합니다 **********" << endl << endl;;
	int index = 0;
	string words[4] = {"클로버", "스페이드","하트","다이아"};

	for (string  word : words) {
		for (int i = 2; i <= 10; i++) {						//숫자 카드는 2부터 10까지 존재하므로
			this->deck[index] = to_string(i) + " " + word;
			index++;
		}
		this->deck[index] = "J " + word;		// string(1, word) => word를 문자열 형식으로 1개 반환한다는 코드
		index++;											// 배열이므로 다음 인덱스로 넘어가기 위한 코드
		this->deck[index] = "Q " + word;
		index++;
		this->deck[index] = "K " + word;
		index++;
		this->deck[index] = "A " + word;
		index++;
	}
}



void Player::Playerdraw() {
	cout << " ※ 손에 들어올 카드 2장을 뽑겠습니다." << endl << endl;;
	random_device rd; // 랜덤 난수 생성을 위한 랜덤 디바이스 선언
	mt19937 gen(rd()); // C++에서 제공하는 랜덤엔진이다.
	int remeaning_cards = 52;
	for (int i = 1; i < 3; i++) {				// 카드 2개 뽑기
		uniform_int_distribution<int> dist(0, remeaning_cards - 1); // 난수의 범위를 설정하는 코드 
		int random_index = dist(gen);
		cout << i << " 번째 카드는 " << deck[random_index] << " 입니다." << endl;		//cout << dist(gen) -> 난수를 출력하는 코드
		swap(deck[random_index], deck[remeaning_cards-1]);					// 뽑힌 카드는 맨 마지막으로 보내기
		remeaning_cards--;									// 한 번 뽑힌 카드는 제거하도록 한다.	//맨 마지막 카드 내보내기
	}
}