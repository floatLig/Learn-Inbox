#include"结构体.h"

//线性表初始化
int InitSqList(SequenceList &L) {
	L.length = 0;
	return OK;
}
//线性表输出
int Output(SequenceList L) {
	if (L.length == 0)
		return ERROR;
	cout << "线性表输出为：" << endl;
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << "\t";
	}
	cout << endl;
	cout << "--------------输出完毕----------------";
	return OK;
}
//彩色数据结构P39  设计一个算法，删除其中所有值等于x的元素  备注：Sq是sequence 序列的意思

//个人理解：通过覆盖不重要的数据，达到删除的目的

int delNode(SequenceList  &L, ElemType e) {
	int num = 0;//num记录L.data中等于e的个数
	if (L.length == 0) {//如果线性表为空，返回ERROR
		return ERROR;
	}
	for (int i = 1; i <= L.length; i++) {//遍历数组，查找该数组的值等于x的个数
		if (L.data[i - 1] == e) {
			num++;
		}
	}
	int j = 1;//用于记录新的数组的编号
	for (int i = 1; i <= (L.length - num); i++) {//遍历数据，对数组进行重新写入
		if (L.data[i - 1] == e)//如果查找的值等于x，跳过不写入
			continue;
		L.data[j - 1] = L.data[i];//新的数组的值 由旧的数组的值赋予
		j++;
	}
	return OK;
}
int delNodeStand(SequenceList &L, ElemType e) {//！！标准！！
	int num = 0;//用来记录不等于x的个数，即要插入L中的元素的个数
	for (int i = 0; i <= L.length - 1; i++) {
		if (L.data[i] == e) {//如果data[i]的值等于e,跳过
			continue;
		}
		L.data[num] = L.data[i];
		num++;
	}
	L.length = num;//顺序表L的长度等于num
	return OK;
}
int delNodeStand2(SequenceList &L, ElemType e) {
	int num = 0;//i用于记录等于e的个数
	int i = 0;
	while (i <= L.length - 1)
	{
		if (L.data[i] == e) {//如果遍历中出现等于x的值
			num++;
			continue;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!注意
		}
		L.data[i - num] = L.data[i];
		i++;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!注意
	}
	L.length = L.length - num;//新的线性表的长度
	return OK;
}


//彩色数据结构P41   有一个顺序表L,假设元素类型ElemType为整型，设计一个尽可能高效的算法，以第一个元素为分界线（基准），
//将所有小于等于他的元素移到该基准的前面，将所有大于等于它的元素移到该基准的后面
//思路：以第一个元素为基准，从右向左找到一个小于等于基准的元素x,从左向右找到大于等于基准的元素y，将两者交换，直到全部找完

//个人理解：在数组中，通过交换，达到目的，而不是通过建立新的数据对象，保存原有的数据
//个人理解：交换的方式有两种：一种是以“两个扫描--从左向右扫描，从右向左扫描，交换这两个扫描的数据”，另一种是“直接从左向右扫描，前面存在一个区间，交换的数据不断放在这个区间总”
int partition(SequenceList &L) {
	ElemType pivot = L.data[0];//以data[0]为枢纽!!!!!!!!!!!交换数组的值，只用空出一个位置就可以，这个位置有data[0]担任，这样子的算法比tmp=a,a=b,b=tmp的性能要高
	int i = 0;
	int j = L.length - 1;
	while (i < j)
	{
		while (i<j && L.data[j]>pivot)//从右向左扫描，找到一个小于等于pivot的data[j]
		{
			j--;
		}
		L.data[i] = L.data[j];//找到这样的data[j]，放入到data[i]当中，不用担心data[i]被覆盖，因为被覆盖的只有第一个data[0],而data[0]有保存在pivot中
		while (i < j && L.data[i] <= pivot)//从左向右扫面，找到一个大于pivot的data[i]
		{
			i++;
		}
		L.data[j] = L.data[i];//找到这样的data[i],放入到上面找到的data[j]中，上面的data[j]放在了上一个data[i]中了
	}
	L.data[i] = pivot;
	return OK;
}

void move(SequenceList &L) {
	int i = -1;//i指向奇数区间的最后一个元素
	for (int j = 0; j <= L.length - 1; j++) {
		if (L.data[j] % 2 == 1) {
			i++;
			int tmp;
			tmp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = tmp;
		}
	}
}

int main_list() {
	List L;
	for (int i = 0; i < 10; i++) {
		L.data[i] = i;
	}
	L.length = 10;
	move(L);
	Output(L);
	system("pause");
	return 0;
}