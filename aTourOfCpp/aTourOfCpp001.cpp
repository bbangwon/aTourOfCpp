﻿#include <iostream>	//입출력 스트림 라이브러리의 선언을 포함(불러옴)

using namespace std;	//std::을 지정하지 않고도 std의 이름을 볼 수 있게 함

double square(double x)	//배정도 부동소수점 수를 제곱
{
	return x * x;
}

void print_square(double x)
{
	cout << "the square of " << x << " is " << square(x) << "\n";
}

constexpr double nth(double x, int n)	//0 <= n 이라고 가정
{
	double res = 1;
	int i = 0;
	while (i<n)	//while루프 : 조건이 true일 동안 반복
	{
		res *= x;
		++i;
	}
	return res;
}

int main()
{
	print_square(1.234);	//'the square of 1.234 is 1.52276'를 출력
}

