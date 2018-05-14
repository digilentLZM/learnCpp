#include"list.h"
#include<iostream>
using namespace std;
int main()
{
	List a;
	a.nodeInsert(2, 12);
	a.nodeInsert(2, 6);
	a.nodeInsert(1, 1);
	cout << "链表的节点情况：\n";
	a.print();
	cout << "节点个数: "<< a.getcount() << endl;

	a.nodeDelete(2);
	cout << "链表的节点情况：\n";
	a.print();
	cout << "节点个数: " << a.getcount() << endl;

	a.nodeDelete(1);
	cout << "链表的节点情况：\n";
	a.print();
	cout << "节点个数: " << a.getcount() << endl;

	a.nodeDelete(1);
	a.nodeDelete(2);
	cout << "链表的节点情况：\n";
	a.print();
	cout << "节点个数: " << a.getcount() << endl;
	return 0;
}