
//---------------------------------------------------------------------------------------------------------------------------------------------
//⭐⭐⭐⭐⭐结构体的创建-----联想该数据结构的图⭐⭐⭐⭐⭐在写函数时，用该数据结构的图进行判断（返回ERROR）									  -----
//顺序线性表结构体：首地址指针/直接数组（但不是很好）;length   所以在进行函数的判断的时候，需要多注意这个地方				   		      -----
//着重看注释中”！！“的部分																										      -----
//*elem  如果指向的是数组，如elem=new ElemType[MAXSIZE];    则可以直接elem[i];     删除的时候，也要delete []elem;						  -----
//---------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;
//#define MaxSize 50
#define MaxSize 10000//图书表可能到达的最大长度
#define OK 1;
#define ERROR 0;
//															!!使用for时，
//线性表
typedef int ElemType;//ElemTyepe为int类型
typedef struct {
	ElemType data[MaxSize];//存放顺序表中的元素				!!变量名data，data数组//注释描述：是为了做什么!!可以指针，可以数组
	int length;//存放线性表的长度
}Sqlist;//顺序表类型										！！注释描述，是什么

//建立顺序表
void CreatList(Sqlist *&L, ElemType a[], int n) {//由a中的n个元素建立顺序表					//!!!! 变量名L
	L = (Sqlist *)malloc(sizeof(Sqlist));//分配线性表的空间
	for (int i = 0; i < n; i++) {//i扫描数组a的元素
		L->data[i] = a[i];//将元素a[i]存放到L中
	}
	L->length = n;//设置L的长度
}

//初始化线性表
void Init_List(Sqlist *&L) {//								!!需要指针
	L = (Sqlist *)malloc(sizeof(Sqlist));
	L->length = 0;//设置L的初始长度为0
}

//销毁线性表
void Dele_List(Sqlist *&L) {
	free(L);//释放L上所指的顺序表空间						!!length也被销毁，所有不用专门写length=0
}

//判断线性表是否为空表
bool IsEmpty_List(Sqlist *L) {
	return (L->length == 0);
}

//求线性表的长度
int Length_List(Sqlist *L)
{
	return L->length;
}

//输出线性表
void Display_List(Sqlist *L) {
	for (int i = 0; i <= L->length - 1; i++) {//			!!注释：扫描顺序表输出各元素
		cout << L->data[i];
	}
}

//求线性表中某个数据的元素值
bool GetElem_List(Sqlist *L, int i, ElemType &e) {
	if (i<1 || i>L->length) {//参数i错误时返回false			!!注释：什么条件下，做什么事情
		return 0;
	}
	e = L->data[i];//取元素值
	return 1;//成功找到元素时返回true
}

//按元素查找
int LocateElem_List(Sqlist *L, ElemType e) {
	for (int i = 0; i <= L->length - 1; i++) {//扫描顺序表
		if (e == L->data[i])//如果找到该元素则返回其逻辑序号
			return i + 1;
	}
	return 0;
}

//插入数据元素
bool Insert_List(Sqlist *& L, int i, ElemType e) {//向线性表L的第i个逻辑序号插入数据元素e
	if (i<1 || i>L->length + 1)
		return false;//										!!return false
	for (int j = L->length - 1; j >= i-1; j--) {//扫描第data中i-1个元素到最后一个元素				!!物理地址
		L->data[j + 1] = L->data[j];//将data[j]的元素后移一位
	}
	L->data[i - 1] = e;//向线性表L的第i个逻辑序号插入数据元素e
	L->length++;
	return true;
}

//删除数据元素
bool Dele_List(Sqlist *& L, int i, ElemType & e) {//删除线性表L的第i个元素，并将该删除的元素赋值给e，并返回
	if (i<1 || i>L->length + 1) {//当参数输入错误时，放回false
		return false;
	}
	e = L->data[i - 1];//将删除的元素赋值给e
	for (int j = i - 1; j < L->length - 1; j++) {//遍历，将data[i]之后的元素向前移动一位
		L->data[j] = L->data[j + 1];
	}
	L->length--;//L的长度减1
	return true;
}

//时间复杂度：（减少for的使用）
//该算法是将L中的元素重新赋值---如果它的值不为x的话
//而不是采用传统方法：如果找到要删去x的值，就将其删除
//---这种算法的时间复杂度为O（n）,传统算法的时间复杂度为O（n^2）

//空间复杂度：（不创建新的顺序表）
//该算法是在原来的线性表L上进行操作
//而不是采用创建一个新的线性表储存不等于x的元素
//---这种算法的空间复杂度为O（1），第二种算法的空间复杂度为O（n）

//删除线性表中所有值等于x的元素
void DelNodel_List(Sqlist *& L, ElemType x) {
	int k=0;//L.data中不等于x的个数
	for (int i = 0; i < L->length; i++) {//遍历
		if (L->data[i] != x) {//如果data[i]的不等于x,则被保留
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->length =k;//								!!是L->length而不是L.length
}

//有一个顺序表L，假设元素类型为ElemType为整型，设计一个尽可能高效的算法，以第一个元素为分界线（基准），将所有小于等于他的元素移到该基准的前面，
//将所有大于它的元素移到该基准的后面

	void Partition(Sqlist *& L) {
	int k=0;//计算有多少个数小于等于第一个元素（有多少个数要移到前面）
	for (int i = 0; i < L->length; i++) {//遍历，计算小于等于第一个元素的个数
		if (L->data[i] <= L->data[0]) {
			k++;
		}
	}
	
}



//------------------------------------------------------------------------------------



typedef struct {//图书信息定义
	string nomber;//图书ISBN
	string name;//图书名字
	float price;//图书价格
}Book;

struct SqList {//线性表
	Book *elem;//存储空间的基地址
	int length;//图书表中当前图书个数
};//图书表的顺序存储结构类型为SqList


//初始化
int init_List(SqList &L) {
	//构造一个空的顺序表
	L.elem = new Book[MaxSize];//为顺序表分配一个大小为MAXSIXZE的数组空间
	if (!L.elem)//存储分配失败退出
		return ERROR;
	L.length = 0;//空表长度为0
	return OK;
}

//取值
int GetElem_List(SqList L,int i,Book &b){
	if (i<1 || i>L.length)
		return ERROR;
	b = L.elem[i];
	return OK;
}

//查找
int LocateElem_List(SqList L, string str) {
	for (int i = 0; i < L.length; i++) {
		if (str == L.elem[i].name) {
			return i+1;//查找成功，返回序号i+1
		}
	}
	return ERROR;//查找失败，返回0
}

//插入
int Insert_List(SqList &L, int i, Book b) {
	//在顺序表中第i个位置插入新元素b,i值的合法范围1<=i<=L.length+1
	if (i<1 || i>L.length + 1)
		return ERROR;//i值不合法
	if (L.length == MaxSize)
		return ERROR;//当前存储空间已满
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = b;
	++L.length;
	return OK;
}

//删除
int Delete_List(SqList &L,int i){
//在顺序表L中删除第i个元素，i值的合法范围是i<=L.length
	if (i<1 || i>L.length)														//用数据表的角度来考虑，下标就是第几个，不用减1
		return ERROR;
	for (int j = 1; j <= L.length - 1; j++) {									//在用for操作时，是对数据进行操作，故要以数组的下标考虑，即下标要减1
		L.elem[j - 1] = L.elem[j];
		--L.length;//表长减1
		return OK;
	}
	return OK;
}

//显示
int Display_List(SqList L) {
	cout << "线性表的元素为：" << endl;
	for (int i = 0; i < L.length; i++) {
		cout << L.elem[i].name << "\t" << L.elem[i].nomber << "\t" << L.elem[i].price << endl;
	}
	return OK;
}

int main_List2() {
	SqList LBook;//创造Book线性表
	init_List(LBook);
	Book b1;
	b1.name = "假如给我三天光明";
	b1.nomber = "001";
	b1.price = 10;

	Book b2;
	b2.name = "格林童话";
	b2.nomber = "002";
	b2.price = 20;

	Book b3;

	Insert_List(LBook, 1, b1);
	Insert_List(LBook, 1, b2);
	//Delete_List(LBook, 1);
	Display_List(LBook);
	GetElem_List(LBook, 1, b3);
	cout << b3.name<<endl;
	cout<<LocateElem_List(LBook, "假如给我三天光明")<<endl;

	cout << "------我是分割线------";
	system("pause");
	return 0;
}

//---------------------------------------------------------------------------------------------------------

//#define MaxSize 1000												//define 不要加分号！！！！
//#define ERROR 0
//#define OK 1

//学生类
class Student
{
public:
	Student() {
	};
	Student(long,string,string );
	~Student();

	long number;//学号
	string  name;//姓名
	string sex;//性别
};

Student::Student(long _number, string _name, string _sex)
{
	number = _number;
	name = _name;
	sex = _sex;
}

Student::~Student()
{
}

//线性表
class sqList
{
public:
	sqList();
	~sqList();
	int init_sqList(sqList &);//线性表初始化
	int insert_sqList(Student, int , sqList &);	//姓名-插入的序列--增
	int dele_sqList(string, sqList &);//根据姓名--删
	int change_sqList(string, string, sqList &);//根据姓名查找--改性别
	int find_sqList(string,sqList);//根据姓名--查
	int display_sqList(sqList);//展示


	Student *stuElem;//学生指针
	int length;//线性表的长度
};

sqList::sqList()
{
}

sqList::~sqList()
{
}

int sqList::init_sqList(sqList &sqList)//线性表初始化			//如果是本身初始化，则不用传对象，用Java中的this
{
	sqList.stuElem = new Student[MaxSize];
	if (!sqList.stuElem)										//判断是否初始化成功
		return ERROR;
	sqList.length = 0;//长度初始化为0
	return true;
}

int sqList::insert_sqList(Student stu, int i, sqList &sqList)
{
	if (i<0 || i>sqList.length + 1)//判断插入的位置是否正确
		return ERROR;
	if (sqList.length == MaxSize)								//当前储存空间已满
		return ERROR;
																//sqList.stuElem[i - 1] = stu;//在线性表中插入新增加的元素
	for (int j = sqList.length - 1; j >= i - 1; j--) {
		sqList.stuElem[j + 1] = sqList.stuElem[j];
	}
	sqList.stuElem[i - 1] = stu;
	sqList.length++;											//要注意++
	return OK;
}

int sqList::dele_sqList(string strName, sqList & sqList)
{
	for (int i = 0; i <= sqList.length - 1; i++) {//查找删除的数据项
		if (strName == sqList.stuElem[i].name) {//如果找到该项
			for (int j = i; j < sqList.length - 1; j++)
				sqList.stuElem[i] = sqList.stuElem[i + 1];
			sqList.length--;									//表长要减1
			return OK;
		}
	}
	return ERROR;
}

int sqList::change_sqList(string strName, string strSex, sqList &sqList)
{
	if (strSex != "男"&&strSex != "女")//输入的strSex是否正确
		return ERROR;
	for (int i = 0; i <= sqList.length - 1; i++) {
		if (strName == sqList.stuElem[i].name) {//如果找的到该项
			sqList.stuElem[i].sex = strSex;//性别更换
			return OK;
		}
	}
	return ERROR;
}

int sqList::find_sqList(string strName,sqList sqList)
{
	for (int i = 0; i <= sqList.length - 1; i++) {//查找数据项			//注意由等于！！！！
		if (strName == sqList.stuElem[i].name) {//如果找到该项
			cout << sqList.stuElem[i].name << "\t" << sqList.stuElem[i].number << "\t"
				<< sqList.stuElem[i].sex << endl;
			return OK;
		}
	}
	return ERROR;
}

int sqList::display_sqList(sqList sqList)
{
	cout << "线性表元素为：\n";
	for (int i = 0; i <= sqList.length - 1; i++) {
		cout << sqList.stuElem[i].name << "\t" << sqList.stuElem[i].number << "\t"
			<< sqList.stuElem[i].sex << endl;
	}
	return OK;
}

int main_List() {
	sqList test_sqList;
	Student stu1(1, "砸金蛋JFK是", "男");
	Student stu2(2, "002发电机房", "女");

	test_sqList.init_sqList(test_sqList);//初始化自己
	test_sqList.insert_sqList(stu1, 1, test_sqList);
	test_sqList.insert_sqList(stu2, 10, test_sqList);
	test_sqList.dele_sqList("砸金蛋K是", test_sqList);
	test_sqList.change_sqList("砸金蛋JFK是", "女fasd", test_sqList);
	test_sqList.find_sqList("砸金蛋sfdsJFK是", test_sqList);
	test_sqList.display_sqList(test_sqList);

	system("pause");
	return 0;
}

