#define _CRT_SECURE_NO_WARNING
#pragma warning(disable:4996)
#include<iostream>
using namespace std;


class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
	Book(const Book& b);
	~Book();
	void set(const char* title, int price);
	void show() {
		cout << title << ' ' << price << "원" << endl; 
	}
};
Book::Book(const char* title, int price) {
	int n = strlen(title);
	this->title = new char[n+1];
	strcpy(this->title, title);
	this->price = price;
}
Book::Book(const Book& b) {
	int n = strlen(b.title);
	this->title = new char[n + 1];
	strcpy(this->title, b.title);
	this->price = b.price;
}

void Book::set(const char* title, int price) {
	if (this->title)
		delete[] this->title;
	int n = strlen(title);
	this->title = new char[n + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::~Book() {
	delete[] title;
}


int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
	return 0;
}
