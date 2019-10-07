#include <iostream>

using namespace std;

struct Point
{
	int x = 0;
	int y = 0;

	Point() : x(0), y(0) {}
	Point(int x, int y) :x(x), y(y) {}

	Point operator +(const Point & add)
	{	
		return Point{x + add.x, y+add.y};
	}

	Point operator *(const int scale)
	{
		return Point{x * scale, y * scale};
	}
};

Point current;
int scale = 2;

void move(Point&& point)
{
	current = point;
}

void update_display()
{
	cout << "현재 위치는 {" << current.x << "," << current.y << "} 입니다.\n";
}

void action()
{
	while (true)
	{
		cout << "어떻게 할까요:\n";	//행동을 요구
		string act;
		cin >> act;	//문자열에 문자를 읽기
		Point delta{ 0,0 };	//Point에 {x,y} 쌍을 저장
		for (char ch : act) 
		{
			switch (ch)
			{
			case 'u':	//위로
			case 'n':	//북쪽으로
				++delta.y;
				break;
			case 'r':	//오른쪽으로
			case 'e':	//동쪽으로
				++delta.x;
				break;
			case 'l':	//왼쪽으로
			case 'w':	//서쪽으로
				--delta.x;
				break;
			case 'd':	//아래로
			case 's':	//남쪽으로
				--delta.y;
				break;
			default:
				cout << "가만히 있겠습니다!\n";
			}
		}

		move(current + delta * scale);
		update_display();
	}
}

int main()
{
	action();
	return 0;
}