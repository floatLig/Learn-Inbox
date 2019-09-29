#include "结构体.h"

//彩色数据结构 P53  有一个带头结点的单链表L=（a1,b1,a2,b2---an,bn）,设计一个算法将其拆分成两个带头结点的单链表L1.L2；
//其中L1=（a1,a2,a3---）,L2=(bn,bn-1,----)，要求L1使用L的头结点
void split(LinkNode &L, LinkNode &L1, LinkNode &L2) {//L1使用尾插法，L2使用头插法
	LinkNode p = L->next;//数据结点指针 指向L的首结点

	L1 = L;//题目要求的L1使用L的头结点
	LinkNode r = new LNode;
	r = L1;//r指向L2,r始终指向L1的尾结点，因为使用尾插法

	L2 = new LNode;//L2初始化(注意这里是LNode,而不是LinkNode)类比int *p = new int
	L2->next = NULL;

	while (p)
	{
		r->next = p;
		r = p;//L1使用尾插法插入数据元素
		p = p->next;

		LinkNode tmp = new LNode;
		tmp = p;//tmp暂时保存p.因为使用头插法，p的后继节点会被覆盖
		p->next = L2->next;
		L2->next = p;//使用头插法向L2中插入数据元素
		p = tmp->next;
	}
	r->next = NULL;
}

int main() {
	LinkNode L = new LNode;
	LinkNode p = new LNode;//数据节点
	LinkNode r = new LNode;
	r = L;//尾结点
	for (int i = 1; i <= 10; i++) {
		p->data = i;
		r->next = p;
		r = p;
	}
	LinkNode L1, L2;
	split(L, L1, L2);
	p = L1->next;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout <<"L1输出结束" << endl;

	system("pause");
	return 0;
}