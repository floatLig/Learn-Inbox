
//-----------------------------------------------------------------------------------------------------------
//ջ��ָ��: top��ʵ��ָ���׵�ַ������Ϊ�˱�����⣬��Ҳ�������Ϊ��ָ��ô洢�ռ䡿						-----
//delete:ɾ��ָ�����ָ�Ŀռ�;����ָ�뱾���ᱻɾ����������Ҫ���� p = NULL								-----
//
//-----------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;
#define MAXSIZE 100//˳��ջ�洢�ռ�ĳ�ʼ������Ϊ100
#define SElemType int//																����ע�⣺�궨�岻Ҫ�ӡ�;���ֺ�
#define OK 1
#define ERROR 0

typedef struct//˳��ջ�洢�ṹ
{
	SElemType * base;//ջ��ָ��
	SElemType * top;//ջ��ָ��
	int stackSize;//ջ��ʹ�õ��������
} SqStack;

//ջ�ĳ�ʼ��
int InitStack(SqStack & S) {//								   									��������������һ����ջ
	S.base = new SElemType[MAXSIZE];//ջ�Ŀռ�ΪMAXSIZE�������;baseָ����ڴ�ռ���׵�ַ      ����Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������
	if (!S.base) {//��ʼ�����ɹ�������ERROR													    �����洢�ռ����ʧ��
		return ERROR;//																			����exit(OVERFLOW)
	}
	S.top = S.base;//topָ���ʼ�� ָ��base����ջ
	S.stackSize = MAXSIZE;//S�Ĵ�СΪMAXSIZE
	return OK;
}

//��ջ
int Push(SqStack &S, SElemType e) {
	if (S.top - S.base == S.stackSize) {//�������ռ�����
		return ERROR;
	}
	*S.top = e;//ջ��ָ�븳ֵΪe
	S.top++;//ջ��ָ���1
	return OK;
}

//��ջ
int Pop(SqStack &S, SElemType & e) {//ɾ��ջ��ָ�룬����e��¼ջ��ָ�벢����
	if (S.top == S.base) {//���Ϊ��ջ���Ż�ERROR
		return ERROR;
	}
	S.top--;//ջ��ָ���1
	e = *S.top;//e��¼ջ����ֵ
	return OK;
}

//ȡջ��Ԫ��
SElemType GetTop(SqStack S) {//����ջ��ָ��Ԫ�أ����޸�ջ��ָ��
	if (S.top == S.base) {//����ǿ�ջ���򷵻�ERROR
		return ERROR;
	}
	return *(S.top - 1);//																	����ע��Ҫ��1��������ôд
}

int main_stack() {
	SqStack S;
	InitStack(S);
	int a[] = { 1,2,3,4,5 };
	cout << "Get" << GetTop(S)<<endl;
	cout << "--------------" << endl;

	system("pause");
	return 0;
}

