#include <iostream>
#include <vector>

using namespace std;

void print_increment()
{
	int v[] = { 0,1,2,3,4,5,6,7,8,9 };

	for (auto x : v)	//v에 포함된 각 x에 대해
		cout << x << ' ';
	cout << '\n';

	for (auto& x : v)	//v에 포함된 모든 x에 1을 더함
		++x;

	for (auto x : v)
		cout << x << ' ';
	cout << '\n';

	for (auto x : { 10,21,32,43,54,65 })
		cout << x << ' ';
	cout << '\n';
}

int count_x(const char* p, char x)
// p[]에 존재하는 x와 동일한 값의 수를 센다.
// p는 0으로 끝나는 char의 배열을 가리킨다고 가정(그렇지 않으면 아무것도 가르키지 않음)
{
	if (p == nullptr)
		return 0;
	int count = 0;
	/*
	for (; *p != 0; ++p)
		if (*p == x)
			++count;
	*/

	while (*p) {
		if (*p == x)
			++count;
		++p;
	}

	return count;
}

bool accept()
{
	cout << "계속 할까요?(y 또는 n)?\n";	//질문 출력
	char answer = 0;	//입력에 나타나지 않을 값으로 변수 초기화
	cin >> answer;	//응답 읽기
	if (answer == 'y')
		return true;
	return false;
}

bool accept2()
{
	cout << "계속 할까요?(y 또는 n)?\n";	//질문 출력
	char answer = 0;	//입력에 나타나지 않을 값으로 변수 초기화
	cin >> answer;	//응답 읽기
	switch (answer)
	{
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		cout << "거부한 것으로 받아들입니다.\n";
		return false;
	}
}

int main()
{
	print_increment();
	cout << count_x("abcabc", 'a') << endl;
}