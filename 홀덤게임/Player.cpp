#include <iostream>
#include <string>
#include <random>
#include "Player.h"
using namespace std;


/*
// �����ڸ� ����Ͽ� ī�� ��ųʸ� ����
Player::Player() {
	string words = "CSHD"; 		// C(Ŭ�ι�), S(�����̵�), H(��Ʈ), D(���̾�)�� ǥ��
	for (char word : words) {	// CSHD ���ڿ��� �� ���ھ� ����Ͽ� �ݺ��� ����
		for (int i = 2; i <= 10; i++) {		//2~10���� ī�� 
			this->HoldomCards[to_string(i) + word] = 1;
		}
		this->HoldomCards["A" + std::string(1, word)] = 1;
		this->HoldomCards["J" + std::string(1, word)] = 1;
		this->HoldomCards["Q" + std::string(1, word)] = 1;
		this->HoldomCards["K" + std::string(1, word)] = 1;
	}
}
*/

// �迭�� ī�带 �����Ͽ� �ʱ�ȭ ��Ű��
Player::Player() {
	cout << "********** �ȳ��ϼ��� Ȧ�����ӿ� ���� ���� ȯ���մϴ� **********" << endl << endl;;
	int index = 0;
	string words[4] = {"Ŭ�ι�", "�����̵�","��Ʈ","���̾�"};

	for (string  word : words) {
		for (int i = 2; i <= 10; i++) {						//���� ī��� 2���� 10���� �����ϹǷ�
			this->deck[index] = to_string(i) + " " + word;
			index++;
		}
		this->deck[index] = "J " + word;		// string(1, word) => word�� ���ڿ� �������� 1�� ��ȯ�Ѵٴ� �ڵ�
		index++;											// �迭�̹Ƿ� ���� �ε����� �Ѿ�� ���� �ڵ�
		this->deck[index] = "Q " + word;
		index++;
		this->deck[index] = "K " + word;
		index++;
		this->deck[index] = "A " + word;
		index++;
	}
}



void Player::Playerdraw() {
	cout << " �� �տ� ���� ī�� 2���� �̰ڽ��ϴ�." << endl << endl;;
	random_device rd; // ���� ���� ������ ���� ���� ����̽� ����
	mt19937 gen(rd()); // C++���� �����ϴ� ���������̴�.
	int remeaning_cards = 52;
	for (int i = 1; i < 3; i++) {				// ī�� 2�� �̱�
		uniform_int_distribution<int> dist(0, remeaning_cards - 1); // ������ ������ �����ϴ� �ڵ� 
		int random_index = dist(gen);
		cout << i << " ��° ī��� " << deck[random_index] << " �Դϴ�." << endl;		//cout << dist(gen) -> ������ ����ϴ� �ڵ�
		swap(deck[random_index], deck[remeaning_cards-1]);					// ���� ī��� �� ���������� ������
		remeaning_cards--;									// �� �� ���� ī��� �����ϵ��� �Ѵ�.	//�� ������ ī�� ��������
	}
}