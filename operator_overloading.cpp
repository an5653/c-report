#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << "ÀÎ ¿ø" << endl; }
	Circle& operator ++() {
		radius++;
		return *this;
	}
	Circle operator ++(int x) {
		Circle tmp = *this;
		radius++;
		return tmp;
	}
	friend Circle operator +(int op1, Circle op2);
};

Circle operator +(int op1, Circle op2) {
	Circle tmp;
	tmp.radius = op1 + op2.radius;
	return tmp;
}

int main() {

	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
	Circle c(5), d(4);
	c = 1 + d;
	c.show();
	d.show();


	return 0;
}