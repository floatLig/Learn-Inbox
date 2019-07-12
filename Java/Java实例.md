# Java实例
- [小函数](#小函数)
	- [循环小练习](#循环小练习)
	- [对象化-掷色子](#对象化-掷色子)
	- [递归小函数](#递归小函数)
- [面向对象](#面向对象)
	- [构造函数](#构造函数)
	- [import导入包&instanceof用法](#import导入包&instanceof用法)
	- [构造函数](#构造函数)
	- [参数传递&静态代码块构造顺序](#参数传递&静态代码块构造顺序) 
	- [构造函数](#构造函数)
	- [参数传递&静态代码块构造顺序](#参数传递&静态代码块构造顺序)
	- [数组&右键自动生成代码](#数组&右键自动生成代码)
	- [重载](#重载)
	- [继承--Object.equal()和==](#继承--Object.equal和==)
	- [多态](#多态)

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

### JVM运行时的构造顺序
```java
package io.github.floatLig.newbie;
/*
 * JVM运行时的构造的顺序
 * 
 */
class Parent {
    /* 静态变量 */
	public static String p_StaticField = "父类--静态变量";
     /* 变量 */
	public String    p_Field = "父类--变量";
	protected int i = 9;
	protected int j = 0;
    /* 静态初始化块 */
	static {
    System.out.println( p_StaticField );
    System.out.println( "父类--静态初始化块" );
	}
    /* 初始化块 */
	{
    System.out.println( p_Field );
    System.out.println( "父类--初始化块" );
	}	
    /* 构造器 */
	public Parent(){
		System.out.println( "父类--构造器" );
		System.out.println( "i=" + i + ", j=" + j );
		j = 20;
	}
}

public class InitialOrderTest extends Parent {
     /* 静态变量 */
	public static String s_StaticField = "子类--静态变量";
     /* 变量 */
	public String s_Field = "子类--变量";
    /* 静态初始化块 */
	static {
    System.out.println( s_StaticField );
    System.out.println( "子类--静态初始化块" );
	}
    /* 初始化块 */
	{
    System.out.println( s_Field );
    System.out.println( "子类--初始化块" );
	}
    /* 构造器 */
	public InitialOrderTest(){
		System.out.println( "子类--构造器" );
		System.out.println( "i=" + i + ",j=" + j );
	}


    /* 程序入口 */
public static void main( String[] args ){
	System.out.println( "子类main方法" );
    new InitialOrderTest();
	}
}

/*
 *结果：
 父类--静态变量
父类--静态初始化块
子类--静态变量
子类--静态初始化块
子类main方法
父类--变量
父类--初始化块
父类--构造器
i=9, j=0
子类--变量
子类--初始化块
子类--构造器
i=9,j=20
 */
```

### import导入包&instanceof用法
```java
/**
 * 导入的包代表是不是同一个大千世界下面的
 * 包括  package要写在第一行,也同样代表导入这个package这个包的内容
 * import 导入其他的包
 * import 静态导入
 * A instanceof B:判断A是不是B的**子类或者本身**
/**
 * @author 25894
 *
 */
package io.github.floatLig.newbie;//一定要是非注释性语句第一句

import io.*;//导入了io中所有的类
import static java.lang.Math.PI;//静态导入，以后写的PI不用再加Math.

public class Demo extends Object{
	public static void main(String[] args) {
		Object object=new Object();
		Demo demo=new Demo();
		
		System.out.println(demo instanceof Object);//true:查看是不是属于继承结构树里面的东西
		System.out.println(demo instanceof Demo);//true
		System.out.println(object instanceof Demo);//false
	
	}
}

```

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

### 参数传递&静态代码块构造顺序
```java
package io.github.floatLig.newbie;

import static java.lang.Math.*;
/*
 * 静态代码块：构造的顺序
 * 
 * 参数传递--在方法又新建一个对象，参数传递是地址的传递
 */
class man{
	static {
		System.out.println("man的静态代码块");
	}
	int value=100;
	
	void outputValue() {
		System.out.println(value);
	}
}

public class Student extends man{
	long id;//id
	long num;//学号
	String nameString;//姓名
	//静态代码块，在工作区中，首先被执行
	static {
		System.out.println("Student的静态代码块");
	}
	
	void parameterTrannsferTest_1(Student stu) {
		//这个方法中会首先创建一个对象（参数写的对象：Student stu，这个方法结束后会自动被销毁）
		//传对象，是指参数中创建的对象的地址指向**上一层**的对象
		//这个地址所指的的对象的id改变了，即会同步改变
		stu.id=007;//这里值得改变会影响上一层值的变化
	}
	
	void parameterTransferTest_2(Student stu) {
		//这个方法中会首先创建一个对象（参数写的对象：Student stu，这个方法结束后会自动被销毁）
		//传对象，是指参数中创建的对象的地址指向**上一层**的对象
		stu=new Student();//这个方法中又创建了一个对象，参数创建的对象指向这个新创建的对象的地址
						//即和上一层的对象失去了联系
		stu.id=000;//因此这里的值改变，不会影响到上一层的值的改变
	}
	@Override
	void outputValue() {
		super.outputValue();
		System.out.println(value);
	}
	
	//main函数
	public static void main(String[] args) {
		Student stu=new Student();
		stu.id=16;//上一层的Student对象
		
		stu.parameterTrannsferTest_1(stu);
		System.out.println(stu.id);//上一层的Studied对象的值被改变
		
		stu.parameterTransferTest_2(stu);
		System.out.println(stu.id);//上一层的Student对象的值不会改变
		
		System.out.println(PI);
		
		stu.outputValue();
	}
	
}


```

### 数组&右键自动生成代码
```java
package io.github.floatLig.newbie;
/*
 * 数组：声明等
 * 
 * 利用右键，可以实现：构造函数，get(),set(),toSting()等函数的自动创建
 */
public class TestArrays {
	public static void main(String[] args) {
		String[] arr1=new String[10];
		Person[] arr2=new Person[2];
		
		arr2[0]=new Person(1,"T am 1");
		arr2[1]=new Person(2,"T am 2");
		
		for(Person outPerson:arr2) {
			System.out.println(outPerson.getId());
		}
	}
}

class Person{
	private long id;
	private String nameString;
	
	public Person() {
	}
	/**
	 * @param id
	 * @param nameString
	 */
	public Person(long id, String nameString) {
		this.id = id;
		this.nameString = nameString;
	}
	/**
	 * @return the id
	 */
	public long getId() {
		return id;
	}
	/**
	 * @param id the id to set
	 */
	public void setId(long id) {
		this.id = id;
	}
	/**
	 * @return the nameString
	 */
	public String getNameString() {
		return nameString;
	}
	/**
	 * @param nameString the nameString to set
	 */
	public void setNameString(String nameString) {
		this.nameString = nameString;
	}
	
	
}
```

### 重载
```java
/*
 *public的class一定得是```.java的名称 
 *
 *重载之：返回类型不同：父类的返回类型是父类；子类的重载该函数的返回类型可以是子类
 */

package io.github.floatLig.newbie;

//public的class一定得是```.java的名称
public class PackageExample{
	public static void main(String[] args) {
		Horse catHorse=new Horse();
		catHorse.run();
		catHorse.stop();
	}
}

class Vehicle{
	void run() {
		System.out.println("出发");
	}
	void stop() {
		System.out.println("停止");
	}
	man whoIsPsg() {//!!!访问权限
		return new man();
	}
}

class Horse extends Vehicle{
	void run() {
		System.out.println("驾");
	}
	void stop() {
		System.out.println("驭");
	}
	Student whoIsPsg() {////!!!!这样子也是重载，访问权限大于等于父类
		return new Student();
	}
}


```

### 继承--Object.equal和==
```java
package io.github.floatLig.newbie;

public class TestObject {
	/*
	 * equals默认函数	
	 * public boolean equals(Object obj) {
        	return (this == obj);
    	}
     *equals默认就是使用“==”，判断哈希值(如果是对象的话，则会判断地址是否相等)是否相同，默认是不是同一个对象
     *重写equal，可以使用右键，自动生成
	 */
	Object obj;
	String str;
	
	@Override
	public String toString() {
	return "TostObjiect's toString";
	}
	
	//main函数
	public static void main(String[] args) {
		User firstUser=new User(123, "郑");
		User secondUser=new User(123, "郑");
		
		System.out.println(firstUser==secondUser);//判断地址是否相等，默认的equal也是这样子
		
	}
	
}

class User{
	long id;
	String nameString;
	
	public User(long id, String nameString) {
		super();
		this.id = id;
		this.nameString = nameString;
	}

	@Override
	public boolean equals(Object obj) {
		if(this == obj)
			return true;
		if(obj == null)
			return false;
		if(getClass()!=obj.getClass())
			return false;
		User other=(User)obj;
		if (id != other.id)
			return false;
		return true;
	}
	
}

```

### 多态
```java
package io.github.floatLig.newbie;
/*
 * 多态测试
 * 
 * 有同一个父类，不同子类同种方法，的多种实现
 */
public class TestPolym {
	public static void main(String [] args) {
		Animal anAnimal = new Animal();
		Animal anDogAnimal = new Dog();
		Cat anCat = new Cat();
		Dog anDog=new Dog();
		
		shout(anAnimal);
		shout(anDogAnimal);//输出汪汪汪；
		shout(anCat);
		
		anDog.getLegNumber();
		anDogAnimal.shout();//输出汪汪汪;而不是动物的“叫了一声”;Animal只能使用重写的;
//		anDogAnimal.getLogNumber(); //报错;
	}
	
	//封装--继承--->父类引用对象：实现多态
	public static void shout(Animal anAnimal) {
		anAnimal.shout();
		
	}
}

class Animal{
	public void shout() {
		System.out.println("叫了一声");
	}
}
class Dog extends Animal{
	private int legNumber=4;
	
	@Override
	public void shout() {
		System.out.println("汪汪汪");
	}

	public int getLegNumber() {
		return legNumber;
	}
	
	
}
class Cat extends Animal{ 
	@Override
	public void shout() {
		System.out.println("喵喵喵");
	}
}
```
