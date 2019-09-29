
//---------------------------------------------------------------------------------------------------------------------------------------------
//链表都是使用指针来操作的，特别是在函数中创建“指针结点”																	   		      -----
//while(p && p->data)一般都是p,而不是p->next，如果是后者，p->next==NUILL的话，NULL前一个有数据的数也不会执行了，而求length则用p->next     -----
//链表的结构体为：指针域 ElemType * next; 数据域 ElemType data ;所以在进行函数判断的时候，要考虑这几个内容								  -----
//在初始化中创造头结点（结构体只是蓝图，不要在结构体中初始化）																			  -----
//着重看注释中”！！“的部分																										      -----
//---------------------------------------------------------------------------------------------------------------------------------------------

//system("cls")清除控制台

#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0

typedef int ElemType;//																			!!是typedef而不是define;所以这个必须得加";"

typedef struct LNode {
	ElemType data;//存放数据元素
	LNode *next;//指向后继结点
}LinkNode;

//建立单链表--头插法
void CreatListF_LinkNode(LinkNode *&L, ElemType a[], int n) {//数组a中得n个元素以头插法的方式赋值给L
	L = (LinkNode *)malloc(sizeof(LinkNode));//L初始化存储空间
	L->next = NULL;//创建头结点，其next域置NULL
	LinkNode *s;//																				！！数据结点
	for (int i = 1; i <= n; i++) {//遍历a[],将a[]得元素以头插法的方式插入到链表中
		s = (LinkNode *)malloc(sizeof(LinkNode));//												!!创建数据结点s，必须写：不然会出现“没有输出化局部变量s的错误”
		s->data = a[i - 1];//数据结点的值为a[]的值
		s->next = L->next;//将结点s插入到原有结点之前，头结点之后
		L->next = s;
	}
}

//建立单链表--尾插法
void CreatListR_LinkNode(LinkNode *& L, ElemType a[], int n) {//数组a[]中的n个元素以尾插法的方式赋值给L
	L = (LinkNode *)malloc(sizeof(LinkNode));//创建头结点
	L->next = NULL;
	LinkNode *s;//数据结点
	LinkNode *e= L;//尾结点，初始时指向头结点
	for (int i = 1; i <= n; i++) {
		s = (LinkNode *)malloc(sizeof(LinkNode));//创建数据结点
		s->data = a[i - 1];//数据结点的值为a[]的值
		e->next = s;//将s插在尾结点之后
		e = s;//尾结点指向链表的最尾端
	}
	e->next = NULL;//尾结点后面为NULL
}

//初始化线性表
int Init_LinkNode(LinkNode *& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));//初始化L
	L->next = NULL;//创建头结点，其next域置为NULL
	return OK;
}

//销毁线性表
int Destory_LinkNode(LinkNode * &L) {
	LinkNode *pre = L;
	LinkNode *p = pre->next;//pre是p的前驱结点；pre用于free
	while (p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);//																		!!需要释放最后的pre
	return OK;
}


//输出单链表的数据
int GetElem_LinkNode(LinkNode *L) {//
	LinkNode *s = L;//																	！！数据结点
	if (L->next) {
		cout << "L链表的数据为：" << endl;
	}else
	{
		cout << "L链表没有数据";
		return ERROR;
	}
	while (s->next)
	{
		s = s->next;//s指向本身的下一个结点
		cout << s->data << "\t";//输出s的数据

	}
	cout << endl;//输出结束后，输出换行符
	return OK;
}

//判断线性表是否为空表
int IsEmpty_LinkNode(LinkNode *L) {
	return (L->next == NULL);//															!!NULL和FALSE不是一回事
}

//求线性表的长度
int Length_LinkNode(LinkNode *L) {
	int n=0;//计数器n置为0
	LinkNode *p = L;//p指向头结点
	while (L->next)
	{
		n++;
		p = p->next;
	}
	return n;
}

//求线性表中某个元素的值
int GetElem_LinkNode(LinkNode *L, int n, int &elem) {//输出线性表L中逻辑序号为n的元素elem
	LinkNode *p=L;//数据结点初始化为头结点
	int i = 0;//计数器i
	while (p && (i < n)) {														//!!!!!!!!!!!!注意是p；这里为判断条件！
		p = p->next;
		i++;
	}
	
	if (n <= 0 || p == NULL) {//如果n的值小于0或者n的值过大						//！！！！！！注意是||，而不是&&，判断“错误”，一般为||
		cout << "输入错误" << endl;
		return ERROR;
	}
	elem = p->data;//将L中逻辑序号为n的元素赋值给elem
	cout << "第" << n << "个数据为：" << elem<<endl;//控制台输出
	return OK;
}

//按元素查找
int LocateElem(LinkNode *L, int e) {
	LinkNode *p = L->next;//数据结点初始化为头结点L
	int i=1;//计数器
	while (p)//																					!!!也可以while（p!=NULL&&p->data!=e）
	{
		if (p->data == e) {
			cout << e<<"是第" << i << "个元素";
			return i;
		}
		i++;
		p=p->next;
	}
	return ERROR;
}

//插入数据元素
int Insert_LinkNode(LinkNode *& L, int n, int e) {//在线性表L的第n个元素的位置上插入e
	//思路：将指针指向n的前一个结点，然后插入
	if (n <= 0)//如果输入的n过小，则返回ERROR
		return ERROR;
	LinkNode * p = L;//初始化数据结点p，指向头结点
	int i = 0;//计数器，初始化为0
	while (p && i<n-1)//将指针p指在第n-1个元素上												！！！！思维模式：要将指针定位到n-1的位置;而程序执行是：next；所以程序的终止条件是<n-1;
	//																							！！！！n-2的时候运行，然后->next就指向了n-1
	{
		p = p->next;
		i++;
	}
	if (p == NULL) {//如果输入的n过大，表现为p指向NULL
		cout << "插入数据，插入的位置n过大，错误";
		return ERROR;
	}
	LinkNode * insert;
	insert = (LinkNode*)malloc(sizeof(LinkNode));//												!!!!一定要初始化
	insert->data = e;//创建数据结点保存e的值
	insert->next = p->next;
	p->next = insert;
	return OK;
}

//删除数据元素
int Delete(LinkNode * &L, int n) {//删除线性表第i个结点的数据
	if (n <= 0) {
		cout << "删除函数中 n过小，删除失败";
		return ERROR;
	}
	LinkNode *p = L;//数据结点
	int i = 0;//计数器
	while (p && i < n - 1) {//将指针指向n-1个位置
		p = p->next;
		i++;
	}
	if (p == NULL) {//当输入的n过大的时候
		return ERROR;
	}
	LinkNode *del = p->next;//指针del指向要删除的结点
	if (del == NULL) {
		cout << "删除函数中 n过大，删除失败" << endl;//									!!!注意，这里也要检查，这里是检查漏洞
		return ERROR;
	}
	p->next = del->next;
	free(del);//删除del 
	return OK;
}

int main_LinkNode() {
	int a[] = { 1,2,3,4,5 };//数组
	LinkNode *L;//链式线性表L
	CreatListF_LinkNode(L, a, 5);//以头插法的方式初始化L
	GetElem_LinkNode(L);//输出L的所有元素
	int elem;
	GetElem_LinkNode(L, 2, elem);//输出线性表中逻辑序号为2的元素
	LocateElem(L, 2);//输出2在链表中的位置
	Insert_LinkNode(L, 22121, 20000);
	
	system("cls");
	cout << "插入数据后，原链表变化为：" << endl;
	GetElem_LinkNode(L);//输出所有元素


	system("pause");
	return 0;
}