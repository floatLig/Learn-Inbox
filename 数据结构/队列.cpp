
//--------------------------------------------------------------------
//����
//--------------------------------------------------------------------

#include<iostream>
using namespace std;
#define QMaxSize 100//�����г���
#define OK 1
#define ERROR 0
typedef int QElemType;

struct SqQueue//ѭ������
{
	QElemType *base;//��ʼ����̬����洢�ռ�
	int front;//ͷָ�룬�����ָ�������int��ʾ��ԭ���ǣ�base[front]
	int rear;//βָ��
};

//ѭ�����г�ʼ��
int InitQueue(SqQueue &Q) {
	Q.base = new QElemType[QMaxSize];
	if (!Q.base) {//�����ʼ��ʧ�ܣ������
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;//front��rear����ʼ��Ϊ0
	return OK;
}

//��ѭ�����г���
int QueueLength(SqQueue S) {
	return (S.front-S.rear+QMaxSize)%QMaxSize;//											!!ע������
}

//ѭ����������
//int EnQueue(SqQueue &Q, QElemType e) {
//	if(Q.rear)
//}