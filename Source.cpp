#include <iostream>
#include "RB-Tree.h"
using namespace std;

int main()
{
	RedBlackTree<int, char> t;
	for (int i = 1; i < 7; i++) {
		t.insert(i, (char)i + 56);
	}
	t.remove(2);
	t.print();
	cout << t.find(3);
}