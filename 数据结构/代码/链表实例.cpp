#include "�ṹ��.h"

//��ɫ���ݽṹ P53  ��һ����ͷ���ĵ�����L=��a1,b1,a2,b2---an,bn��,���һ���㷨�����ֳ�������ͷ���ĵ�����L1.L2��
//����L1=��a1,a2,a3---��,L2=(bn,bn-1,----)��Ҫ��L1ʹ��L��ͷ���
void split(LinkNode &L, LinkNode &L1, LinkNode &L2) {//L1ʹ��β�巨��L2ʹ��ͷ�巨
	LinkNode p = L->next;//���ݽ��ָ�� ָ��L���׽��

	L1 = L;//��ĿҪ���L1ʹ��L��ͷ���
	LinkNode r = new LNode;
	r = L1;//rָ��L2,rʼ��ָ��L1��β��㣬��Ϊʹ��β�巨

	L2 = new LNode;//L2��ʼ��(ע��������LNode,������LinkNode)���int *p = new int
	L2->next = NULL;

	while (p)
	{
		r->next = p;
		r = p;//L1ʹ��β�巨��������Ԫ��
		p = p->next;

		LinkNode tmp = new LNode;
		tmp = p;//tmp��ʱ����p.��Ϊʹ��ͷ�巨��p�ĺ�̽ڵ�ᱻ����
		p->next = L2->next;
		L2->next = p;//ʹ��ͷ�巨��L2�в�������Ԫ��
		p = tmp->next;
	}
	r->next = NULL;
}

int main() {
	LinkNode L = new LNode;
	LinkNode p = new LNode;//���ݽڵ�
	LinkNode r = new LNode;
	r = L;//β���
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
	cout <<"L1�������" << endl;

	system("pause");
	return 0;
}