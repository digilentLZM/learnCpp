#include"list.h"
#include<iostream>
using namespace std;

List::List()
{
	count = 0;//����countΪ0
	node *p1 = new node;
	cout << "�����һ���ڵ�����ݣ�\n";
	cin >> p1->data;
	head = p1;//��һ���ڵ�
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
		cout << "�����Ѿ�Ϊ��\n";
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
		cout << "�޷�����ýڵ�\n";
		return;
	}
	else if(pos > count)
	{
		cout << "�²���������ŵ�ĩβ\n";
		while (p1 ->next != NULL)//�ҵ���β
		{
			p2 = p1->next;
			p1 = p2;
		}
		p2 = new node;
		p2->data = num;
		p1->next = p2;
		p2->next = NULL;
	}
	else if (pos == 1)//���뵽��ͷ
	{
		p2 = new node;
		p2->data = num;
		head = p2;
		p2->next = p1;
	}
	else
	{
		int n = 1;
		while (n != pos - 1)//�ҵ�Ҫ�����λ�õ�ǰһ���ڵ�
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
		cout << "û�иýڵ㣡�޷�ɾ��" << endl;
		return;
	}
	else if (pos == 1)//ɾ��ͷ
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
		while (n != pos -1)//�ҵ�Ҫɾ���Ľڵ��ǰһ���ڵ�
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
