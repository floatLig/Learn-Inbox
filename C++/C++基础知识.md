## 目录

- [容器](#容器)
	- [容器分类](#容器分类)
	- [容器的接口](#容器的接口)
	- [序列容器的操作](#序列容器的操作)
	- [代码实例](#代码实例)
	- []()
	- []()

## 容器

### 容器分类

1. 序列容器

	vector：向量
	deque:双向队列
	list:双向链表

2. 关联容器

	set:集合
	multiset:集合
	map:映射
	multimap:映射

3. 容器适配器--特殊顺序表

	stack:堆栈
	queue：队列
	priority queue：优先队列

|头文件  	|包含容器    			|
|:---------:|:---------------------:|
|<`vector>	|vector					|
|<`list>	|list					|
|<`deque>	|deque					|
|<`queue>	|queue 和 priority_queue	|
|<`stack>	|stack					|
|<`map>		|map 和 multimap			|
|<`set>		|set 和 multiset			|
|<`bitset>	|bitset					|

### 容器的接口

所有容器的共同操作

- Container表示容器类型，如vector、list;
- T表示容器的实例化类型：如int、double;
- c、c1、c2表示容器的对象

|表达式、函数调用			|功能								|
|:-------------			|:-------							|
|增						|									
|Container c			|默认构造空容器						|
|Container c(beg,end)	|以地址beg开始，到地址end的数据序列为初始值构造容器					|
|Container c1(c2)		|构造容器c2的副本						|
|c1=c2					|对象赋值							|
|删						|									|
|c.erase(pos)			|删除迭代器pos所指的元素				|
|c.erase(beg,end)		|删除以地址beg开始，到end结束的数据元素	|
|c.clear()				|删除容器中所有的元素					|
|改						|									|
|c1.swap(c2)			|交换同类型容器中的数据				|
|c.insert(pos,elem)		|在迭代器pos所指位置前插入元素elem		|
|查						|									|
|c.size()				|返回容器的元素个数					|
|c.empty()				|判断容器是不是为空					|
|c.max_size()			|返回容器可容纳元素的最大数量			|
|迭代器					|									|
|c.begin()				|返回指向**首元素**的迭代器			|
|c.end()				|返回指向**尾元素下一位置**的迭代器	|
|c.rbegin()				|返回指向逆向首元素（**尾元素**）		|
|c.rend()				|返回指向**逆向尾元素的下一位置**（c.rend()-1=c.begin()）的迭代器	|

### 序列容器的操作

|表达式、函数调用			|功能								|
|:-------------			|:-------							|
|增删					|									|
|c.push_back(elem)		|在容器末端插入数据elem				|
|c.pop_back(elem)		|在容器末端插入数据elem				|
|查						|									|
|c.front()				|访问容器的首元素数据					|
|c.back()				|访问容器的尾元素数据					|
|c[i]					|访问元素第i个元素					|
|c.at(i)				|返回索引（下标）i的元素				|

### 代码实例
```C++
	//增
	vector<int>V(10, 0);//实例化长度为10，置元素的初始值为0

	vector <int>V1(10);//创建长度为10的vector,若是没有指定初始值，则默认初始值为0

	vector<int>L;//说明第二个向量
	for (int i = 0; i < V.size(); i++)//注意一：使用for的时候，i<V1.size();
		L.push_back(V[i]);

	//向量对向量赋值
	vector<int>copyV(V);//创建L的副本
	
	vector<int>copyV1;
	copyV1 = copyV;
	
	//删
	copyV.erase(copyV.begin());//参数为迭代器
	copyV.erase(copyV.begin(), copyV.end()-1);
	copyV1.clear();//清除所有的数据

	//改
	for (int i = 0; i < 10; i++) {
		V[i] = i;//使用重载运算符operator[]对元素赋值
	}

	V.push_back(10);//在表尾追加一个元素

	V.insert(V.begin() + 3, 33);//在第4个位置插入一个元素

	V.swap(V1);//交换同类型向量的数据(长度大小可以不一致)
	
	//查
	cout << "size of V is:";
	cout << V.size() << endl;//输出表长

	cout << V.empty()<<endl;//是否为空
	cout << V.max_size() << endl;//最大可容纳的元素的数量

	cout << "the elements of V are:";
	for (int i = 0; i < V.size(); i++) {
		cout << V[i] << "  ";
	}
	cout << endl;

	cout << "the 6th  element is:";
	cout << V.at(5)<< endl;//输出索引（下标）为5的元素

	//查：使用迭代器
	cout << "the first element (use begin()is:)";
	cout << *(V.begin()) << endl;//输出第一个元素
	cout << "the last element (use rbegin()is:)";
	cout << *(V.rbegin()) << endl;//输出最后一个元素
	cout << "the last element (use end())is:";
	cout << *(V.end() - 1) << endl;//输出最后一个元素
	cout << "the first element (use rend())is:";
	cout << *(V.rend() - 1) << endl;
```

### List其他成员函数

|表达式、函数调用			|功能								|
|:-------------			|:-------							|
|unique					|删除重复元素							|
|splice/merge(L1,L2)	|有序合并列表							|
|sort(L1)				|排列列表							|
|reverse				|反转								|

### List代码实例

```
#include<iostream>
#include<list>
#include<cstdlib>
#include<ctime>
using namespace std;

void createList(list<int>&orderList, int len) {
	int k;
	for (int i = 0; i < len; i++) {
		k = rand() % 100;//生成随机数
		orderList.push_back(k);//插入链表
	}
	orderList.sort();//排序
}

void inorderMerge(list<int>&L1, list<int>L2) {
	L1.merge(L2);//把有序链表L2合并到L1中，并保持L1的有序
}

void outList(list<int>&List) {
	list<int>::iterator p;//建立容器list迭代器
	p = List.begin();
	while (p!=List.end())
	{
		cout << *p << "  ";
		p++;
	}
	cout << endl;
}

int main() {
	list<int>L1, L2;
	srand(int(time(0)));
	createList(L1, 10);
	cout << "List L1:" << endl;
	outList(L1);
	
	createList(L2, 5);
	cout << "List L2:" << endl;
	outList(L2);

	inorderMerge(L1, L2);
	cout << "list L1:" << endl;
	outList(L1);

	system("pause");
	return 0;
}
int main() {
	unsigned int i;
	

	system("pause");
	return 0;
}
```
	