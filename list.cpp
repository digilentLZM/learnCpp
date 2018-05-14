#include"list.h"
#include<iostream>
using namespace std;

List::List()
{
	count = 0;//设置count为0
	node *p1 = new node;
	cout << "输入第一个节点的数据：\n";
	cin >> p1->data;
	head = p1;//第一个节点
	p1->next = NULL;
	count++;
}

List::~List()
{
	node *p1 = head;
	node *p2;
	while (p1 != NULL)
	{
		p2 = p1->next;
		delete p1;
		p1 = p2;
	}
	cout << "destructure\n";
	cout << endl;
	count = 0;
}

void List::print()
{
	node *p1 = head;
	node *p2;
	if (p1 == NULL)
	{
		cout << "链表已经为空\n";
		return;
	}
	while (p1 != NULL)
	{
		p2 = p1->next;
		cout << p1->data << endl;
		p1 = p2;
	}
	cout << endl;
}

void List::nodeInsert(int pos, int num)
{
	node *p1 = head;
	node *p2;
	if (pos <= 0)
	{
		cout << "无法插入该节点\n";
		return;
	}
	else if(pos > count)
	{
		cout << "新插入的数将放到末尾\n";
		while (p1 ->next != NULL)//找到表尾
		{
			p2 = p1->next;
			p1 = p2;
		}
		p2 = new node;
		p2->data = num;
		p1->next = p2;
		p2->next = NULL;
	}
	else if (pos == 1)//插入到表头
	{
		p2 = new node;
		p2->data = num;
		head = p2;
		p2->next = p1;
	}
	else
	{
		int n = 1;
		while (n != pos - 1)//找到要插入的位置的前一个节点
		{
			p2 = p1->next;
			p1 = p2;
			n++;
		}
		p2 = p1->next;
		node *p3 = new node;
		p3->data = num;
		p1->next = p3;
		p3->next = p2;
	}
	count++;
}

void List::nodeDelete(int pos)
{
	if (pos > count || pos <= 0)
	{
		cout << "没有该节点！无法删除" << endl;
		return;
	}
	else if (pos == 1)//删除头
	{
		node *p1 = head;
		node *p2 = p1->next;
		head = p2;
		delete p1;
	}
	else
	{
		int n = 1;
		node *p1 = head;
		node *p2;
		node *p3;
		while (n != pos -1)//找到要删除的节点的前一个节点
		{
			p2 = p1->next;
			p1 = p2;
			n++;
		}
		p2 = p1->next;
		p3 = p2->next;
		p1->next = p3;
		delete p2;
	}
	count--;
}

int List::getcount(void)
{
	return count;
}
