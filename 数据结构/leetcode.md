## 目录
- [206. Reverse Link List](#206-Reverse-Linked-List)
- [20. Valid Parentheses](#20-Valid-Parentheses)
- [155. Min Stack](#155-Min-Stack)
- [622. Design Circular Queue](622-Design-Circular-Queue)
- [698. Partition to K Equal Sum Subsets](698-Partition-to-K-Equal-Sum-Subsets)
- [102. Binary Tree Level Order Traversal](102-Binary-Tree-Level-Order-Traversal)

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
/*
要使链表反转，需要有三个位置定位；用curr、prev指针、nextTemp指针，curr->next=prev使指针反转;prev=curr;curr=nextTmep;两个指针顺延遍历
*/
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
/*
因为括号配对的过程：就是栈后进先出的过程；因此你可以遇到前括号就放进栈中，遇到后括号就从栈中弹出前括号
*/
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
```C++
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
```C++
/*
按照习惯来，front指的是有数据的，rear指的是没有数据的
数组使用容器：vector
队列满的时候，vector不要留空，因此队列空和队列满的判定条件都是一样的：front=rear，所以你可以需要通过设置一个emptyFlag来判断队列是不是空的
*/

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

## 698. Partition to K Equal Sum Subsets

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:
```
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 ```

Note:

- 1 <= k <= len(nums) <= 16.
- 0 < nums[i] < 10000.

**Solution**
```C++
/*
画图模型：
1. nums[n]:----------(beginIndex)
2. subsets: ___  ___  ___(一共k组，每一组都存放相加起来subsum/target的数)

思路：
1. 先算出每一组的subSum/targe
(含义相同，但是在canPartitionKSubsets函数中用subSum表示，Partition中用target表示)
2. nums中如果最大的数大于subSum，return false，如果刚好等于，则k--、beginIndex--,
则可确定一个数为一组，不用再尝试遍历
3. Partition函数功能为：尝试填充“每一组”的“任何个数据”
4. Partition为递归函数：
   终止条件为index<0;
   在k组中填充数据：for(i<subsets.size())
   在每一组中尝试填充n个数据：if(相加的和为超出界限) 递归Partition
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int b:nums)sum+=b;
        if(sum%k!=0)return false;//如果相加后整除的结果不是整数，那么直接return true
        int subSum=sum/k;//得到每个组的和subSum
        sort(nums.begin(), nums.end());//从小到大排列
        int beginIndex=nums.size()-1;//排序后最大数的下标
        if(nums[beginIndex]>subSum)return false;
        while(beginIndex>=0 && nums[beginIndex]==subSum){
            beginIndex--;
            k--;
        }
        vector<int>subsets(k,0);
        return Partition(subsets,nums,subSum,beginIndex);
    }
    bool Partition(vector<int>& subsets,vector<int>& nums,int target,int index){
        if(index<0)return true;//当nums中所有的数都能够成功的放进subsets中，即路的尽头
        int selected=nums[index];
        //每一条路都是进行遍历尝试，成功就返回true，不成功就选择另一条路进行尝试
        for(int i=0;i<subsets.size();i++){//Ⅰ：这个数在尝试换组存放👇
            if(subsets[i]+selected<=target){
                subsets[i]+=selected;//Ⅱ：不同的数在尝试在这个组存放
                if(Partition(subsets,nums,target,index-1))return true;//Ⅲ：所有的子问题都得到解决，return true。这条路走到了成功尽头：index<0，return true后来到这里；成功了，故每一层也同样层层return true
                subsets[i]-=selected;//这个数尝试在换组存放👆
            }
        //return false不是写在这里；总有一个return不会写在条件（for,while,if）里面
        }
        return false;//return false是写在这里
    }
};
```

## 102. Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,
```
    3
   / \
  9  20
    /  \
   15   7
```
return its level order traversal as:
```
[
  [3],
  [9,20],
  [15,7]
]
```

**Solution**

```
/*
知道了一棵树的根结点，就知道了整个树

按层输出，可借助queue先进先出这种数据结构

画图模型：
1. queue<TreeNode *> q:             -------通过信号量flag：表示一个row中要输入多少个值（当前一个row输出完毕后，flag=q.size()）
2. vector<int> row:                 ----while(flag!=0)push_back(q.front()->val)
3. vector<vector<int>> result:      直接可push_back(row)得到
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};//如果没有数据时，直接return{}
        vector<int>row;
        queue<TreeNode *>q;
        vector<vector<int>>result;
        
        q.push(root);
        int flag=1;
        //这一层的循环是，是确定result.size()的个数（多少个向量vector）
        while(!q.empty()){
            //这一层循环是判断每一个row要输出多少个元素
            while(flag!=0){
                if(q.front()->left!=NULL)q.push(q.front()->left);
                if(q.front()->right!=NULL)q.push(q.front()->right); 
                row.push_back(q.front()->val);
                q.pop();
                flag--;
            }
            result.push_back(row);//可以直接插入一整个向量
            row.clear();
            flag=q.size();
        }
        return result;
    }
};
```