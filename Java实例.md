# Java实例
- [小函数](#小函数)
	- [循环小练习](#循环小练习)
	- [对象化-掷色子](#对象化-掷色子)
	- [递归小函数](#递归小函数)
- [面向对象](#面向对象)
	- [构造函数](#构造函数)

## 小函数 

### 循环小练习
```java
		/*
		 * 题目：计算100以内的奇数、偶数的和
		 * 
		 * 一开始自己写不出来的原因，是因为没有考虑到选择，一步一步来，可以的
		 * 任何算法都要想到 循环+选择：100（循环）奇数偶数（选择）
		 */
		int sum1=0;//局部变量：和
		int sum2=0;
		for(int i=0;i<=100;i++) {//循环
			if(i%2==0) {//选择偶数
				sum1+=i;
			}
			if(i%2==1) {//选择偶数
				sum2+=i;
			}
		}
		System.out.println(sum1+"\n"+sum2);
		/*
		 * 题目：1~100之间，打印出5的倍数，同时每一行只打印5个
		 * 
		 * 解析：1~100：循环；5的倍数：选择，打印5个：选择
		 * 
		 * 不要使用'\t'，使用"\t",因为'\t'可能会被用成数字
		 * 循环+选择+位置放置     一开始自己打错了，是因为把每5个换行的选择判断位置放错了
		 */
		int count=0;//用于计数
		for(int i=1;i<=1000;i++) {
			if(i%5==0) {//如果是5的倍数，被选择！
				System.out.print(i+"\t");
				count++;
				if(count==5) {//如果被选择的数列中，又是5的倍数，又被选择！
					System.out.println();
					count=0;
				}
			}
		}
		/*
		 * 题目：1~100之间，打印出能被5整除，但不能被3整除的数，同时每一行打印5个数
		 * 
		 * 不能被3整除，选择：如果遇到3的倍数，就跳出这一次循环，进入下一次循环
		 */
		int count=0;
		for(int i=1;i<100;i++) {
			if(i%3==0) {//被3整除就跳过
				continue;
			}
			if(i%5==0) {
				System.out.print(i+"\t");
				count++;
				if(count==5) {
					System.out.println();
					count=0;
				}
			}
		}
```
### 对象化-掷色子
```java
		/*
		 * 掷色子：用户输入大/小，色子自动生成数字，并和用户输入的内容进行比较
		 */
		int diceInt;//获取1~6的随机数
		boolean bigResult=true;//色子随机结果，是否为大，为大返回true，否则返回false
		boolean gambResult = true;//用户输入的结果，是否为大，为大返回true,否则返回false
		
		while(true) {
			//获得随机数
			diceInt=(int)(6*Math.random())+1;//！！！！！！！！！！！！！！！！！！！！！放在循环里面
			//输入栏提示输入
			System.out.println("下押！大or小");
			Scanner scanner=new Scanner(System.in);
			String gambString=scanner.nextLine();//输入大 还是小
			System.out.println("摇出来的数字为："+diceInt);
			//判断色子随机结果是大还是小
			if(diceInt<4) {
				bigResult=false;
			}
			if(diceInt>=4) {
				bigResult=true;
			}
			//判断用户的输入
			if(gambString.equals("大")) {
				gambResult=true;//!!!!!!!!!!!!!!!!!!!!!!!!!!这个值是成员变量，必须加上这一步，因为最外面的初始化只会调用一次
			}
			if(gambString.equals("小")) {
				gambResult=false;
			}
			//判断结果并输出
			if(bigResult==gambResult) {
				System.out.println("----------------------"
						+ "押中了");
			}else {
				System.out.println("押错了");
			}
			System.out.println("*******************");
		}
```
### 递归小函数
```java
	static long factorial(int n) {
		/*
		 * 递归例子：算阶乘
		 * 
		 * 用if区别递归头和递归体
		 * 递归头：什么时候 终止
		 * 递归体：什么时候继续
		 * 
		 * System.CurrentTimeMills()显示时间
		 */
		if(n==1) {
			return 1;
		}else {
			return n*factorial(n-1);
		}
	}
	public static void main(String[] args) {
		long t1=System.currentTimeMillis();//计算January 1, 1970 UTC.到现在的毫秒数
		System.out.println(factorial(10));//若这里的数是100，则long不够存放，会溢出，最后的结果为0；
		long t2=System.currentTimeMillis();
		System.out.println(t2-t1);//计算上一步到这一步跑了多长时间
		
	}
```

## 面向对象

### 构造函数
```java
/*
 * 在写构造函数的推荐写法 / 一些注意事项
 */
public class Student {
	long id;//id
	long num;//学号
	String nameString;//姓名
	
	//重载构造函数：对对象的属性进行初始化
	Student(){//无参数的构造函数！！！一般要加上，因为你创建其他构造函数，系统就不会默认给你加上这个构造函数
	}
	Student(long _id,long num){
		id=_id;//传入的参数最好用“_id”这种形式
		this.num=num;//this表示“这个对象”，即“这个对象的num”等于“传入的num”
	}
	Student(long _id,long num,String _nameString){
		this(_id, num);//调用前面的构造函数，注意：这里只能用this，而不能用Student（_id,num）
		nameString=_nameString;
	}
}
```
