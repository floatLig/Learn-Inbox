## 目录
- [206. Reverse Link List](#206-Reverse-Linked-List)
- [20. Valid Parentheses](#20-Valid-Parentheses)
- [155. Min Stack](#155-Min-Stack)
- [622. Design Circular Queue](622-Design-Circular-Queue)

## 206. Reverse Linked List

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

## 20. Valid Parentheses

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

## 155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- getMin() -- Retrieve the minimum element in the stack.

Example:
```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

**Solution**
```
/*
思路:该算法的核心是如何找到栈中的最小值；因为栈对栈，因此你可以再创造一个“用来存储最小值的栈s_min”；输入该栈s_min的数据为“当前最小值”（受限制的数据）
*/

class MinStack {
public:
    /** initialize your data structure here. */
    /*错误一：注释掉的内容为自己的一开始想法，我应该可以使用容器的
    int a[100];
    int size;
    int pTop;
    */
    
    //MinStack() {
        //size=100;
        //pTop=-1;
    //}
    stack<int>s_data;
    stack<int>s_min;
    
    void push(int x) {
        //if(this->pTop+1==size)return false;
        //a[pTop+1]=x;
        //pTop++;
        s_data.push(x);
        //只有当前数据的最小值才可以输入到栈中；注意，相等的最小值也要输进去
        if(s_min.empty() || s_min.top()>=x)s_min.push(x);//错误二：top()后面一定要加（）
    }
    
    void pop() {
        //if(pTop==-1)return false;
        //pTop--;
        //如果弹出去的是最小值，s_min栈中的数据也要相对的弹出去
        if(s_data.top()==s_min.top())s_min.pop();
        s_data.pop();
    }
    
    int top() {
        //return a[pTop];
        return s_data.top();
    }
    
    int getMin() {
        /*
        int min=-1000;
        for(int i=0;i<=pTop;i++){
            if(min<a[i])
                min=a[i];
        }
        return min;
        */
        return s_min.top( );
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

## 622. Design Circular Queue

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

- MyCircularQueue(k): Constructor, set the size of the queue to be k.
- Front: Get the front item from the queue. If the queue is empty, return -1.
- Rear: Get the last item from the queue. If the queue is empty, return -1.
- enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
- deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
- isEmpty(): Checks whether the circular queue is empty or not.
- isFull(): Checks whether the circular queue is full or not.
 

Example:
```
MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
 ```
Note:

- All values will be in the range of [0, 1000].
- The number of operations will be in the range of [1, 1000].
- Please do not use the built-in Queue library.

**Solution**
```
//按照习惯来，front指的是有数据的，rear指的是没有数据的

class MyCircularQueue {
private:
    vector<int>q;//注意一：C++应该学会类的使用方法，善于用vector、stack、queue等工业容器
    int front;//错误一：确定好参数，不要front和head混在一起
    int rear;
    bool emptyFlag;//错误二：因为题目要求队列满的时候，vector不要留有空；判断队列是不是empty,因为满和空的判定条件都是front=rear;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    
    MyCircularQueue(int k) {
        q.resize(k);
        front=0;
        rear=0; 
        emptyFlag=true;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        /*
        //判断队列是否满了
        //if((rear+1)%size==front)return false;//错误二：==不要写成=
        if(isFull())return false;
        //如果队列为空
        if(front==-1)front++;
        rear=(rear+1)%size;
        q[rear]=value;
        return true;
        */
        if(isFull())return false;
        if(isEmpty())emptyFlag=false;
        q[rear]=value;
        rear=(rear+1)%q.size();
        return true;
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        //判断队列是否为空
        //if(front==-1)return false;
        //if(isEmpty())return false;
        //front=(front+1)%size;
        //return true;
        if(isEmpty())return false;
        front=(front+1)%q.size();
        if(front==rear)emptyFlag=true;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        //判断队列是否为空
        //if(isEmpty())return -1;
        //return q[front];
        if(isEmpty())return -1;
        return q[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        //判断队列是否为空
        //if(isEmpty())return -1;
        //return q[rear];
        if(isEmpty())return -1;
        return q[(rear+q.size()-1)%q.size()];//错误三：当rear处于第一个位置时，-1是要变成最后一个位置，如果0-1%q.size()=-1
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        //if(front==-1)return true;
        //return false;
        if(front==rear && emptyFlag)return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        //if((rear+1)%size==front)return true;
        //return false;
        if(front==rear && !emptyFlag)return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```