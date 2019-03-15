
//-----------------------------------------------------------------------------------------------------------
//栈的指针: top其实是指向首地址，但是为了便于理解，你也可以理解为【指向该存储空间】						-----
//delete:删除指针的所指的空间;但是指针本身不会被删除，所以需要补上 p = NULL								-----
//
//-----------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;
#define MAXSIZE 100//顺序栈存储空间的初始分配量为100
#define SElemType int//																！！注意：宏定义不要加”;“分号
#define OK 1
#define ERROR 0

typedef struct//顺序栈存储结构
{
	SElemType * base;//栈底指针
	SElemType * top;//栈顶指针
	int stackSize;//栈可使用的最大容量
} SqStack;

//栈的初始化
int InitStack(SqStack & S) {//								   									！！描述：构造一个空栈
	S.base = new SElemType[MAXSIZE];//栈的空间为MAXSIZE大的数组;base指向该内存空间的首地址      ！！为顺序栈动态分配一个最大容量为MAXSIZE的数组
	if (!S.base) {//初始化不成功，返回ERROR													    ！！存储空间分配失败
		return ERROR;//																			！！exit(OVERFLOW)
	}
	S.top = S.base;//top指针初始化 指向base，空栈
	S.stackSize = MAXSIZE;//S的大小为MAXSIZE
	return OK;
}

//入栈
int Push(SqStack &S, SElemType e) {
	if (S.top - S.base == S.stackSize) {//如果储存空间满了
		return ERROR;
	}
	*S.top = e;//栈顶指针赋值为e
	S.top++;//栈顶指针加1
	return OK;
}

//出栈
int Pop(SqStack &S, SElemType & e) {//删除栈顶指针，并用e记录栈顶指针并返回
	if (S.top == S.base) {//如果为空栈，放回ERROR
		return ERROR;
	}
	S.top--;//栈顶指针减1
	e = *S.top;//e记录栈顶的值
	return OK;
}

//取栈顶元素
SElemType GetTop(SqStack S) {//返回栈顶指针元素，不修改栈顶指针
	if (S.top == S.base) {//如果是空栈，则返回ERROR
		return ERROR;
	}
	return *(S.top - 1);//																	！！注意要减1，且是这么写
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

