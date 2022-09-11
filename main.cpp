#include <iostream>
#include <stack>
#include <conio.h>

#define VISITED			2
#define BACKTRACE		3

using namespace std;

//Right, Down, Left, Up
int MAP[10][10] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 0, 1, 1, 1},
	{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
	{1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

class Vector
{
public:
	int X;
	int Y;
};

int main()
{
	stack<Vector> History;

	Vector PlayerPosition;

	PlayerPosition.X = 1;
	PlayerPosition.Y = 1;

	History.push(PlayerPosition);
	MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
	while (true)
	{
		//종료 조건
		if (PlayerPosition.X == 8 && PlayerPosition.Y == 8)
		{
			for (int Y = 0; Y < 10; ++Y)
			{
				for (int X = 0; X < 10; ++X)
				{
					cout << MAP[Y][X] << " ";
				}
				cout << endl;
			}
			break;
		}

		

		//오른쪽에 길이 있냐?
		if (MAP[PlayerPosition.Y][PlayerPosition.X + 1] == 0)
		{
			PlayerPosition.X++;
			History.push(PlayerPosition);
			MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
			
		}

		//아래쪽에 길이 있냐?
		else if (MAP[PlayerPosition.Y + 1][PlayerPosition.X] == 0)
		{
			PlayerPosition.Y++;
			History.push(PlayerPosition);
			MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
			
		}
		//왼쪽 길이 있냐?
		else if (MAP[PlayerPosition.Y][PlayerPosition.X - 1] == 0)
		{
			PlayerPosition.X--;
			History.push(PlayerPosition);
			MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
			
		}
		//위쪽 길이 있냐?
		else if (MAP[PlayerPosition.Y - 1][PlayerPosition.X] == 0)
		{
			PlayerPosition.Y--;
			History.push(PlayerPosition);
			MAP[PlayerPosition.Y][PlayerPosition.X] = VISITED;
			
		}
		else
		{
			MAP[PlayerPosition.Y][PlayerPosition.X] = BACKTRACE;

			//돌아가길 없으면 탈출 불가
			if (History.empty())
			{
				cout << "No Escape!!" << endl;
				break;
			}

			cout <<"Not pop " <<  "X : " << PlayerPosition.X << "Y : " << PlayerPosition.Y << endl;

			History.pop();

			//새로운 길이 없으면 뒤로 돌아가기
			PlayerPosition.X = History.top().X;
			PlayerPosition.Y = History.top().Y;

			cout << "X : " << PlayerPosition.X << "Y : " << PlayerPosition.Y << endl;


		}


		for (int Y = 0; Y < 10; ++Y)
		{
			for (int X = 0; X < 10; ++X)
			{
				cout << MAP[Y][X] << " ";
			}
			cout << endl;
		}

		_getch();

	}

	stack<Vector> Result;
	int Count = History.size();
	
	for (int i = 0; i < Count; ++i)
	{
		Result.push(History.top());
		History.pop();


	}

	Vector VResult;
	Count = Result.size();
	
	cout << "<최적 경로 출력>" << endl;

	for (int i = 0; i < Count; ++i)
	{
		VResult = Result.top();
		cout << "X 좌표 : " << VResult.X << "   Y 좌표 : " << VResult.Y << endl;
		Result.pop();


	}

	return 0;



}