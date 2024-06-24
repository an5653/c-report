#include <iostream>
#include <string>
using namespace std;

// string 클래스 배열을 가지는 스택 클래스 구현
class mystack {
	int size;
	string *stack;
	int last;
	int numitem;
public:
	mystack(int s = 10) {
		last = -1;
		numitem = 0;
		size = s;
		stack = new string[size];
	}
	~mystack() {
		delete[] stack;
	}
	void push(string c) {
		last ++;
		stack[last] = c;
		numitem ++;
	}
	bool isEmpty() {
		if (numitem != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	string pop() {
		if (isEmpty())
		{
			cout << "스텍이 비어 있슴니다" << endl;
			return "\0";
		}
		last--;
		numitem--;
		return stack[last+1];
	}
	string top() {
		if (isEmpty())
		{
			cout << "스텍이 비어 있슴니다" << endl;
			return "\0";
		}
		return stack[last];
	}
	void showStack() {
		cout << "[ ";
		for (int i = 0; i < numitem; i++)
		{
			cout << stack[i]<< " ";
		}
		cout << " ]" << endl;
	}
	int getNumitem() {
		return numitem;
	}
	string getItem(int i) {
		return stack[i];
	}
	void setSize(int s) {
		size = s;
	}
};

// 연산자 우선순위 판별 함수
int pri(string s) {

	if (s == "+" || s == "-") return 1;
	if (s == "*" || s == "/") return 2;
	return 0;
}
// 연산자인지 판별 함수
bool isOperator(string s) {
	if (s == "+") return true;
	if (s == "-") return true;
	if (s == "*") return true;
	if (s == "/") return true;
	return false;
}
// 정수 계산 함수
int calculate(int a,int b,string oper) {
	if (oper == "+") return a + b;
	if (oper == "-") return a - b;
	if (oper == "*") return a * b;
	if (oper == "/") return a / b;
	return 0;
}
// 후위표기 계산 함수
int postfix(mystack s) {
	mystack stack;
	string ch;

	for (int i = 0; i < s.getNumitem(); i++)
	{
		ch = s.getItem(i);

		if (!isOperator(ch))
		{
			stack.push(ch);
		}
		else
		{
			int a = stoi(stack.pop());
			int b = stoi(stack.pop());
			int result = calculate(b, a, ch);
			stack.push(to_string(result));
		}
	}

	return stoi(stack.pop());
}


int main() {
	string s,c;

	int sum = 0;
	cout << "7+23*5-100/25와 같이 연산할 문자열을 입력하세요." << endl;
	getline(cin, s, '\n');

	// 공백 제거 
	int fIndex = 0;
	fIndex = s.find(' ', 0);

	if (fIndex != 0)
	{
		s.erase(remove(s.begin(), s.end(), ' '),s.end());
	}
	
	// 연산자 기준으로 숫자를 string으로 나누고 'Sstack' 스택에 저장 연산자는 그대로 저장 
	// 마지막 숫자는 string 배열의 끝에 도달했을때 이전 연산자 뒤~배열의 마지막 으로 나눔
	int stacksize = s.length()+1;
	mystack oper(stacksize), tmp(stacksize), Sstack(stacksize);

	int startIndex = 0;
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		c = s[i];
		count = i - startIndex;
		if (isOperator(c))
		{
			string part = s.substr(startIndex,count);
			startIndex = i+1;
			Sstack.push(part);
			Sstack.push(c);
		}
		if (i == s.length()-1)
		{
			string part = s.substr(startIndex,count+1);
			Sstack.push(part);
		}
	}
	// 중위표기를 후위표기로 변경하여 tmp스택에 저장
	// 숫자는 바로 연산 기호는 oper 스택에 저장 후 우선 순위에 따라 tmp스택에 저장
	for (int i = 0; i < Sstack.getNumitem(); i++)
	{
		c = Sstack.getItem(i);
		if (!isOperator(c))
		{
			tmp.push(c);
		}
		else
		{
			while (!oper.isEmpty() && pri(oper.top()) >= pri(c))
			{
				tmp.push(oper.top());
				oper.pop();
			}
			oper.push(c);
		}
	}
	while (!oper.isEmpty()) {
		tmp.push(oper.top());
		oper.pop();
	}



	cout <<"계산 결과 : " << postfix(tmp);

	return 0;
}
