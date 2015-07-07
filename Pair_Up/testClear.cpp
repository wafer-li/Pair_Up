#include <iostream>
#include <deque>
#include "Piece.h"
using namespace std;

//int main ()
int test()
{
	srand((unsigned)time(0));
	deque<Piece> deque1;

	for (int i = 0; i<9; i++)
	{
		Piece p;
		deque1.push_back(p);
	}

	for (int i = 0; i < 9; ++i)
	{
		cout << deque1[i].getType() << endl;
	}
	system("pause");
	return 0;

}
