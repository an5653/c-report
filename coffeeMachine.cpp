#include<iostream>

using namespace std;

class CoffeMachime {
private:
	int coffe, water, sugar;



public:

	CoffeMachime() {}
	CoffeMachime(int a, int b, int c) { 
		coffe = a, water = b, sugar = c;

		if (coffe>100)
			coffe = 100;
		if (water > 100)
			water = 100;
		if (sugar > 100)
			sugar = 100;

		if (coffe < 0)
			coffe = 0;
		if (water < 0)
			water < 0;
		if (sugar < 0)
			sugar = 0;

	}
	void Refill() {
		int fill;

		if (coffe < 10) {
			fill = 100 - coffe;
			cout << "커피 " << fill << "개 추가" << endl<<endl;
			coffe += fill;
		}
		if (water < 10) {
			fill = 100 - water;
			cout << "물 " << fill << "개 추가" << endl<<endl;
			water += fill;
		}
		if (sugar < 10) {
			fill = 100 - sugar;
			cout << "설탕 " << fill << "개 추가" << endl<<endl;
			sugar += fill;
		}
	}
	int coffeCheck(){

		cout << "재료가 부족하여 커피를 제작할 수 없습니다." << endl;
		Refill();
		return 0;

	}

	void drinkEspresso() {
		int n = 1;
		if (coffe < 4 || water < 6)
			n = coffeCheck();
		
		coffe -= 4;
		water -= 6;

		if (n!=0)
		{
			cout << "에스프레소를 만들었습니다." << endl;
			show();
		}


	}
	void drinkAmericano() {
		int n = 1;
		if (coffe < 2 || water < 7)
			n = coffeCheck();
		
		coffe -= 2;
		water -= 7;

		if (n != 0)
		{
			cout << "아메리카노를 만들었습니다." << endl;
			show();
		}

	}
	void drinkSugerCoffe() {
		int n = 1;
		if (coffe < 3 || water < 5 || sugar < 3)
			n = coffeCheck();

		coffe -= 3;
		water -= 5;
		sugar -= 3;
		

		if (n != 0)
		{
			cout << "설탕 커피를 만들었습니다." << endl;
			show();
		}
	}
	void show() {
		cout << "커피 머신 상태 . 커피 :" << coffe << " 물 :" << water << " 설탕 :" << sugar <<endl<< endl;
	}

};


int main() {

	CoffeMachime java(11,11,11);

	while (true)
	{
		int key ;
		cout << "1. 에스프레소 2. 아메리카노 3. 설탕 커피 중 선택(0을 입력하면 종료)" << endl;
		cin >> key;
		
		if (key == 1)
			java.drinkEspresso();
		
		if (key == 2)
			java.drinkAmericano();
		
		if (key == 3)
			java.drinkSugerCoffe();

		if (key == 0) {
			cout << "종료";
			break;
		}

	}


	return 0;
}