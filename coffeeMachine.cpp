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
			cout << "Ŀ�� " << fill << "�� �߰�" << endl<<endl;
			coffe += fill;
		}
		if (water < 10) {
			fill = 100 - water;
			cout << "�� " << fill << "�� �߰�" << endl<<endl;
			water += fill;
		}
		if (sugar < 10) {
			fill = 100 - sugar;
			cout << "���� " << fill << "�� �߰�" << endl<<endl;
			sugar += fill;
		}
	}
	int coffeCheck(){

		cout << "��ᰡ �����Ͽ� Ŀ�Ǹ� ������ �� �����ϴ�." << endl;
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
			cout << "���������Ҹ� ��������ϴ�." << endl;
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
			cout << "�Ƹ޸�ī�븦 ��������ϴ�." << endl;
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
			cout << "���� Ŀ�Ǹ� ��������ϴ�." << endl;
			show();
		}
	}
	void show() {
		cout << "Ŀ�� �ӽ� ���� . Ŀ�� :" << coffe << " �� :" << water << " ���� :" << sugar <<endl<< endl;
	}

};


int main() {

	CoffeMachime java(11,11,11);

	while (true)
	{
		int key ;
		cout << "1. ���������� 2. �Ƹ޸�ī�� 3. ���� Ŀ�� �� ����(0�� �Է��ϸ� ����)" << endl;
		cin >> key;
		
		if (key == 1)
			java.drinkEspresso();
		
		if (key == 2)
			java.drinkAmericano();
		
		if (key == 3)
			java.drinkSugerCoffe();

		if (key == 0) {
			cout << "����";
			break;
		}

	}


	return 0;
}