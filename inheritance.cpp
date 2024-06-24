#include<iostream>
using namespace std;
class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
	
};
class ColorPoint :Point {
	string color;
public:
	ColorPoint(int x=0,int y=0):Point(x,y) {
		color = "black";
		move(x, y);
	}
	void setPoint(int x,int y) {
		move(x,y);
	}
	void setColor(string s) {
		color = s;
	}
	void show() {
		cout << color << "색으로 (" << getX()<<"," << getY() << ")에 위치한 점" << endl;;
	}
};

int main() {
	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}