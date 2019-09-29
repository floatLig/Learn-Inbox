#include"�ṹ��.h"

//���Ա��ʼ��
int InitSqList(SequenceList &L) {
	L.length = 0;
	return OK;
}
//���Ա����
int Output(SequenceList L) {
	if (L.length == 0)
		return ERROR;
	cout << "���Ա����Ϊ��" << endl;
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << "\t";
	}
	cout << endl;
	cout << "--------------������----------------";
	return OK;
}
//��ɫ���ݽṹP39  ���һ���㷨��ɾ����������ֵ����x��Ԫ��  ��ע��Sq��sequence ���е���˼

//������⣺ͨ�����ǲ���Ҫ�����ݣ��ﵽɾ����Ŀ��

int delNode(SequenceList  &L, ElemType e) {
	int num = 0;//num��¼L.data�е���e�ĸ���
	if (L.length == 0) {//������Ա�Ϊ�գ�����ERROR
		return ERROR;
	}
	for (int i = 1; i <= L.length; i++) {//�������飬���Ҹ������ֵ����x�ĸ���
		if (L.data[i - 1] == e) {
			num++;
		}
	}
	int j = 1;//���ڼ�¼�µ�����ı��
	for (int i = 1; i <= (L.length - num); i++) {//�������ݣ��������������д��
		if (L.data[i - 1] == e)//������ҵ�ֵ����x��������д��
			continue;
		L.data[j - 1] = L.data[i];//�µ������ֵ �ɾɵ������ֵ����
		j++;
	}
	return OK;
}
int delNodeStand(SequenceList &L, ElemType e) {//������׼����
	int num = 0;//������¼������x�ĸ�������Ҫ����L�е�Ԫ�صĸ���
	for (int i = 0; i <= L.length - 1; i++) {
		if (L.data[i] == e) {//���data[i]��ֵ����e,����
			continue;
		}
		L.data[num] = L.data[i];
		num++;
	}
	L.length = num;//˳���L�ĳ��ȵ���num
	return OK;
}
int delNodeStand2(SequenceList &L, ElemType e) {
	int num = 0;//i���ڼ�¼����e�ĸ���
	int i = 0;
	while (i <= L.length - 1)
	{
		if (L.data[i] == e) {//��������г��ֵ���x��ֵ
			num++;
			continue;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ע��
		}
		L.data[i - num] = L.data[i];
		i++;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ע��
	}
	L.length = L.length - num;//�µ����Ա�ĳ���
	return OK;
}


//��ɫ���ݽṹP41   ��һ��˳���L,����Ԫ������ElemTypeΪ���ͣ����һ�������ܸ�Ч���㷨���Ե�һ��Ԫ��Ϊ�ֽ��ߣ���׼����
//������С�ڵ�������Ԫ���Ƶ��û�׼��ǰ�棬�����д��ڵ�������Ԫ���Ƶ��û�׼�ĺ���
//˼·���Ե�һ��Ԫ��Ϊ��׼�����������ҵ�һ��С�ڵ��ڻ�׼��Ԫ��x,���������ҵ����ڵ��ڻ�׼��Ԫ��y�������߽�����ֱ��ȫ������

//������⣺�������У�ͨ���������ﵽĿ�ģ�������ͨ�������µ����ݶ��󣬱���ԭ�е�����
//������⣺�����ķ�ʽ�����֣�һ�����ԡ�����ɨ��--��������ɨ�裬��������ɨ�裬����������ɨ������ݡ�����һ���ǡ�ֱ�Ӵ�������ɨ�裬ǰ�����һ�����䣬���������ݲ��Ϸ�����������ܡ�
int partition(SequenceList &L) {
	ElemType pivot = L.data[0];//��data[0]Ϊ��Ŧ!!!!!!!!!!!���������ֵ��ֻ�ÿճ�һ��λ�þͿ��ԣ����λ����data[0]���Σ������ӵ��㷨��tmp=a,a=b,b=tmp������Ҫ��
	int i = 0;
	int j = L.length - 1;
	while (i < j)
	{
		while (i<j && L.data[j]>pivot)//��������ɨ�裬�ҵ�һ��С�ڵ���pivot��data[j]
		{
			j--;
		}
		L.data[i] = L.data[j];//�ҵ�������data[j]�����뵽data[i]���У����õ���data[i]�����ǣ���Ϊ�����ǵ�ֻ�е�һ��data[0],��data[0]�б�����pivot��
		while (i < j && L.data[i] <= pivot)//��������ɨ�棬�ҵ�һ������pivot��data[i]
		{
			i++;
		}
		L.data[j] = L.data[i];//�ҵ�������data[i],���뵽�����ҵ���data[j]�У������data[j]��������һ��data[i]����
	}
	L.data[i] = pivot;
	return OK;
}

void move(SequenceList &L) {
	int i = -1;//iָ��������������һ��Ԫ��
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