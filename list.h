class List//����������
{
private:
	struct node//�ڵ�
	{
		int data;
		node *next;
	};
	node *head; //ͷָ��
	int count; //�ڵ�����
public:
	List();
	~List();
	void print();
	void nodeInsert(int pos, int num);//postition,number
	void nodeDelete(int pos);
	int getcount(void);
};
