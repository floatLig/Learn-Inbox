## 目录
- [206.Reverse Link List](#206.Reverse-Linked-List)
- [20.Valid Parentheses](#20.Valid-Parentheses)

### 206.Reverse Linked List

Reverse a singly linked list.

Example
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
**Solution**
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

## 20.Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order. 

Note that an empty string is also considered valid.

Example 1:
```
Input: "()"
Output: true
```
Example 2:
```
Input: "()[]{}"
Output: true
```
Example 3:
```
Input: "(]"
Output: false
```
Example 4:
```
Input: "([)]"
Output: false
```
Example 5:
```
Input: "{[]}"
Output: true
```
**Solution**
```C++
class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;//注意一：容器的定义：stack<char> paren
        for(char  c:s){//注意二：char/int & c:s的用法为逐个遍历数组/字符串
            switch(c){//错误一：switch而不是which；switch也是if的一种
                case '(':
                case '[':
                case '{':paren.push(c);break;
                case ')':
                        if(paren.empty() ||paren.top()!='(')return false;//错误三：top()是有括号的，如果stack是空的，stack.top()会错误
                        else paren.pop();//错误四：是要pop栈顶元素，而不是return true
                        break;
                case ']':
                        if(paren.empty() ||paren.top()!='[')return false;
                        else paren.pop();
                        break;
                case '}':
                        if(paren.empty() ||paren.top()!='{')return false;
                        else paren.pop();
                        break;
                default: break;
            }
        }
        return paren.empty();
    }
};
```