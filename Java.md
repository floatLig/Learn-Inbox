# Java
- Java初级
	- [成员变量](#成员变量)
	- [函数](#函数)

## 成员变量 

###  注释
- 单行注释
- 多行注释：
- 文档注释：文档注释会**自动生成API**，因此开发项目最好使用文档注释
```java
	//单行注释
	
	/*
	 * 多行注释
	 */
	
	/* 多行注释的另一种用法，可用于代码中间解释，但不推荐*/
	
	/**
	 * 文档注释
	 * 文档注释：比多行注释多写了一个*
	 */
```
		
### public static final *double* MAX_MARK =(1.0+90L)之double
- 基本数据类型
	- boolean是1byte
	- char可以用作数字处理：'a'+4=101
	- 使用long时：123L而不是123l(很容易混淆)
	- 不要long a=b+c而要long a=(long)b+c
		- （long）b会自动将右边的等级提成为long，这样就不要报错
	 
### public static final double *MAX_MARK* =(1.0+90L)之MAX_MARK
- 标识符命名规范
	- 驼峰原则：studentAge
	- class类名：首字母大写
	- 成员变量、函数：首字母小写
	- final常量：全部大写，用下划线连接
- 变量
	- 一行申明一种变量就可以，不要多写

```java
	int age;  
	int grade;
```

	- 静态变量static
		- 从属于**类**
	- 成员变量
		- 会有默认初始值，故可以不用初始化
		- 从属于**对象**
	- 局部变量
		- 从属于**方法**
	- 这些变量在初始化时，**最好都赋初始值**

### public static final double MAX_MARK *=* (1.0+90L)之=
- 自动类型转化
	- 容量小的数据类型向容量大的数据类型转化:int->long->float->double
	- 1e2=100
	- 整数默认是int类型，小数默认是double类型
	- 强制类型转化
```java
	long a=1;//这里的1是int,int自动转化为long
	float b=1.0F;//这里的1.0是double，double不能自动转化为float，所以必须写成1.0F
```
	- 因为浮点数（float、double）是自动类型转化，因此不精确。若是要精确的比较使用**BigDecimal函数**

### public static final double MAX_MARK = (1.0*+*90L)之+
- 运算符
	- %取余
```java
		int a=-7%-2;//-7影响结果为“-”;-2对结果的正负不影响
		System.out.println(a);//-1：
```
	- 运算符会自动转化类型
- 逻辑运算符
	- &&短路与--&与
```java
		boolean a= (1>2)&&(1/0>1);//不会报错“除数为0”，因为遇到前面是false，短路与&&不会继续往后看，写代码时推荐使用这个
		boolean b= (1>2)&(1/0>1);//会报错，因&无论前面是true还是false,都会继续往后读
```
- 位运算符
	- & | ^ ~
	- <<2:左移两位即“乘2”
	- +字符串连接符：1+“2”=12
	
### 对象
- Scanner
	- Scanner sc=new Scanner(System.in)

## 函数

