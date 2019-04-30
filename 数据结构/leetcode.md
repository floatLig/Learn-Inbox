## 目录
- [Reverse Link List](#Reverse-Linked-List)
- []()

### Reverse Linked List

Reverse a singly linked list.

**EXample**
```			
Input:1->2->3->4->5->NULL
Output:5->4->3->2->1->NULL
```
```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //递归
        if(head==NULL || head->next==NULL)return head;//错误三：C++的NULL必须为大写
        ListNode * p=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;//为了使反转后的尾结点n1指向null
        return p;
    }
};
```
```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //迭代
        ListNode * prev=NULL;//错误一：注意prev的类型,prev的类型为ListNode指针类型
        ListNode * curr=head;
        while(curr!=NULL){
            ListNode * temp=curr->next;//错误二：注意C++中使用结构的对象是用"->"
            curr->next=prev;
            prev=curr;//错误三：和下一行的顺序不要颠倒
            curr=temp;
        }
        return prev;//错误四：注意返回的是prev
   }
};
```