class List//整型链表类
{
private:
	struct node//节点
	{
		int data;
		node *next;
	};
	node *head; //头指针
	int count; //节点数量
public:
	List();
	~List();
	void print();
	void nodeInsert(int pos, int num);//postition,number
	void nodeDelete(int pos);
	int getcount(void);
};
