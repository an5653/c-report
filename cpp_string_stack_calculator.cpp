#include <iostream>
#include <string>
using namespace std;

bool isOperator(char s) {
	if (s == '+') return true;
	if (s == '-') return true;
	if (s == '*') return true;
	if (s == '/') return true;
	return false;
}

int calculate(int a, int b, char oper) {
	if (oper == '+') return a + b;
	if (oper == '-') return a - b;
	if (oper == '*') return a * b;
	if (oper == '/') return a / b;
	return 0;
}

int main() {
	string s;
	cout << "7+23*5-100/25와 같이 연산할 문자열을 입력하세요." << endl;



	getline(cin, s, '\n'); // 문자열 입력

	int sIndex = 0;
	sIndex = s.find(' ', 0);
	if (sIndex != 0)
	{
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
	}

	int result = 0;
	int startIndex = 0;
	int count = 0;
	char ch,oper=' ';

	for (int i = 0; i < s.length(); i++)
	{
		ch = s[i];
		count = i - startIndex;
		if (isOperator(ch))
		{
			if (oper == ' ')
			{
				string part = s.substr(startIndex, count);
				result = stoi(part);
				startIndex = i + 1;
				oper = ch;
			}
			else
			{
				string part = s.substr(startIndex, count);
				result = calculate(result, stoi(part), oper);
				oper = ch;
				startIndex = i + 1;
			}
		}
		if (i == s.length()-1)
		{
			string part = s.substr(startIndex, count +1);
			result = calculate(result, stoi(part), oper);
		}
	}
	
	cout << "계산결과 : " << result;

	return 0;
}
