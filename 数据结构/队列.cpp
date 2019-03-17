
//--------------------------------------------------------------------
//队列
//--------------------------------------------------------------------

#include<iostream>
using namespace std;
#define QMaxSize 100//最大队列长度
#define OK 1
#define ERROR 0
typedef int QElemType;

struct SqQueue//循环队列
{
	QElemType *base;//初始化动态分配存储空间
	int front;//头指针，这里的指针可以用int表示的原因是：base[front]
	int rear;//尾指针
};

//循环队列初始化
int InitQueue(SqQueue &Q) {
	Q.base = new QElemType[QMaxSize];
	if (!Q.base) {//如果初始化失败，则溢出
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;//front和rear都初始化为0
	return OK;
}

//求循环队列长度
int QueueLength(SqQueue S) {
	return (S.front-S.rear+QMaxSize)%QMaxSize;//											!!注意求余
}

//循环队列入列
//int EnQueue(SqQueue &Q, QElemType e) {
//	if(Q.rear)
//}