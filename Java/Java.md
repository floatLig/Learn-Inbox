# Java
### Java初级
- [成员变量](#成员变量)
- [函数](#函数)
- [面向对象](#面向对象)
- [继承、封装、多态](#继承、封装、多态)
- [思考经验](#思考经验)

![](https://github.com/floatLig/Learn-Inbox/blob/master/media/%E6%80%9D%E7%BB%B4%E8%AE%B0%E5%BF%86%E7%BB%93%E6%9E%84%20(2).png)

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

### public static final double MAX_MARK =(1.0+90L)；

**final**	
- 用于常量：必须赋初值，赋初值后不能再修改，例如：PI
- 用于方法：不能被重写
- 用于类：不能被继承，例如：String	

**double**
- 基本数据类型
	- boolean长度为：1个字节
	- char的长度为：2个字节（使用Unicode编码，可以表示世界上绝大多数字符）
	- char可以用作数字处理：'a'+4=101
	- 使用long时：123L而不是123l(很容易混淆)
	- 不要long a=b+c而要long a=(long)b+c
		- （long）b会自动将右边的等级提成为long，这样就不要报错
	 
**MAX_MARK**
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

**=（数据类型转化）**
- 隐式转换：byte（1个字节） - short(2个字节) - int(4个字节)/char(2个字节) - long(8个字节) - float(4个字节) - double(8个字节)
- 整数默认是int类型（如果不初始化，则默认值为0），小数默认是double类型（如果不初始化，则默认值为0.0），（char如果不初始化，则默认值为false）
- 若是要精确的小数运算（例如会计），则要使用**BigDecimal函数**，因为float、double会存在精度转化的问题
- 显式转化
```java
	long a=1;//这里的1是int,int自动转化为long
	float b=1.0F;//这里的1.0是double，double不能自动转化为float，所以必须写成1.0F
```


**+（运算符）**
- %取余
```java
		int a=-7%-2;//-7影响结果为“-”;-2对结果的正负不影响
		System.out.println(a);//-1：
```
	- 运算符会自动转化类型
- 逻辑运算符：&&与、 ||或、 ! 取反
- 位运算符
	- &与、 |或、 ^异或、 ~非
	- <<2:左移两位即“乘2”
	- +字符串连接符：1+“2”=12

	
### 对象
- Scanner
	- Scanner sc=new Scanner(System.in)
	- int exampleInt = sc.nextInt();

-----

## 函数
- 流程控制语句
	- 顺序
	- 选择(i)
		- if else
		- switch(case不用加{})：switch可包含的6种数据类型：byte、short、char、int、String、enum枚举类型
	- 循环
		- for
		- while
		- break、continue的作用是跳出一层循环，而不是if【若要跳出多层循环，使用return跳出函数】
		- continue,break配合if在循环中使用
- public static void main(String[] args)
	- return
		- 返回类型
		- 终止函数
- 常用
	- 函数被static修饰（属于类），可直接调用，不用创建该类的对象（public不行，因为public的功能不是这个）

-----

### 面向对象

- Java中一切皆为对象
- 数组也是对象
	- 其中一种初始化：int[] arr = new int[3] {1.2.3};
	- 因为数组是对象，因此可用length属性获得数组的长度
	-	数组也是对象：相同类型元素，有下标
	- 数组的每个元素都可以看成是：成员变量
	- 使用--声明：
		- User[] arr
		- 默认值和成员变量一样：0/false/null
		- 指明长度/分配**数组空间**（记录地址）：arr1=new User[10]
		- 分配**对象空间**：arr[0]=new arr()
		- 赋值
	- 使用--初始化
		- 静态初始化(直接赋值：数组空间确定、数组指定对象内容也确定)：
```java
		int[] arr=new{1,2}；//数组可以存放int类型
 
		User[] b={
		new User(1,"zzl"),
		new User(2,"zz")
		}//数组可以存放**对象地址**，数组空间确定的同时，数组指向**地址的对象**也初始化了
```
		- 动态初始化：数组空间，数组指向对象的空间；单独一一确定
```java
		int[] c=new int[3]；//默认初始化，同成员函数一样，默认为0/null/false
		int[] a=new int[2];
		a[0]=1;
		a[1]=2;//动态初始化，数组空间，数组指向对象的空间；单独一一确定
```
	- 数组遍历foreach
		- 专门用于读取数组元素，而不是赋值
```java
		for(Person outPerson:arr2){
		system.out.println(Pesson.getId());	
		}//“：” ；同时可以用对象.getId()
```
		
	- 异常：ArrayIndexOutOfBoundsException数组越界，比如数组只有10个，你写到了arr[10]
	- 可以利用二维数组存储一个表格的数据，例子如下：
	```java
	package io.github.floatLig.survival;
	
	import java.util.Arrays;
	
	import javax.xml.transform.Templates;
	
	/**
	 * 测试数组存储类型
	 * @author 25894
	 *
	 */
	public class ArrayTest {
		public static void main(String[] args) {
			
			// Object数组的对象 可以为任意的数据；可以用来表示一个元组的数据
			Object[] exampleObjects1 = {1001,"zz",18,"程序员","2006-6-6"};
			Object[] exampleObjects2 = {1002,"zzl",19,"学生","2006-6-6"};
			Object[] exampleObjects3 = {1003,"zzsd",18,"CTO"};
			
			// 创建Object的二维数组，可以用来表示一个表格
			Object[][] tableData = new Object[3][];
			tableData[0]=exampleObjects1;
			tableData[1]=exampleObjects2;
			tableData[2]=exampleObjects3;
			
			// 利用Arrays.toString可以打印整个表格的数据
			for(Object[] temObjects : tableData) {
				System.out.println(Arrays.toString(temObjects));
			}
			
	//		打印结果为：
	//		[1001, zz, 18, 程序员, 2006-6-6]
	//		[1002, zzl, 19, 学生, 2006-6-6]
	//		[1003, zzsd, 18, CTO]
			
		}
	}

	```


- string也是对象
	- String是常量是因为，源代码中的private final char value[]用来保存字符串，且value[]用final定义起来
	- String exampleString = "---"；其中"--"字符串是常量，而exampleTest则是类似于一个指针，指向“字符串所在位置的地址”
	- 注意：String testString; 在不给字符串变量赋值的情况下，其默认值为null，如果此时调用String方法，则会发生空指针异常
	- 获取字符串的长度：length（）
	- 获取指定位置的字符：char exampleChar = exampleString.charAt(4)
	- 获取子字符串的索引位置：int locate = exampleString.indexof('e');
	- 判断字符串首尾内容：boolean flag = exampleString.startWith（"清汤小肥羊"）; // endWith(String --)
	- 获取字符数组：char[] ch = str.toCharArray();
	- 判断字符串是否存在：str.contains(string);
	- 截取字符串：str.substring(beginIndex,endIndex);
	- 字符串替换：str.replace(oldstr,newstr)
	- 字符串分割：str.split(",")
	- 大小写转化：toLowerCase() // toUpperCase()
	- 去除空白内容：trim()
	- 比较**内容**是否相等：replace()
- 可变字符串StringBuffer
	- StringBuffer类是线程安全的可变字符序列，一个类似于String的字符缓冲区，两者的本质上是一样的，但是StringBuffer的执行效率要比String快很多
	- 相比String的优点：例如str1 = "123"; str2 = "abc"; str = str1 + str2;这样子String在堆中存在3个内存空间（因为"--"是常量），分别为"123","abc","123abc",而StringBuffer则只存在一块空间"123abc"
	- 但是编译器会对一些进行优化，如：String str = "abc" + "efg"；编译器会自动优化成一个内存空间，但是如果写成多个str，则不会优化
	- 追加字符串：append(str)
	- 将给定索引处的字符串修改为ch：setCharAt(int index, char ch)
	- insert(int offset, String str)
	- delete(int start, int end)
	- 其他String的方法
- StringBuffer和StringBuilder
	- StringBuffer线程安全，效率低
	- StringBulider线程不安全，效率高，经常用
- 面向对象
	- 宏观上用面向对象把握，微观仍是面向过程->函数
	- 都是解决问题的思维方式，都是代码组织的方式

### JVM的内存分析

![](https://github.com/floatLig/Learn-Inbox/blob/master/media/%E5%A0%86%E3%80%81%E6%A0%88%E3%80%81%E6%96%B9%E6%B3%95%E5%8C%BA.png)

- 栈stack--**DO**
	- 描述的是**方法**执行的内存模型
		- 主函数main运行
		- 构造函数（运行后立马被销毁）
	- 类似于子弹夹
		- 栈帧
		- 线程私有：不能共享
		- 先进后出，后进先出：main是最先创建的，最后销毁
		- 速度快
- 堆heap--**实例-大千世界**
	- 存放创建好的对象和数组（数组也是对象）
	- 所有线程共享
	- 不连续的内存空间，分配灵活、速度慢
- 方法区method area--**蓝图、基础数据**
	- JVM只有一个方法区，被所有线程共享
	- 方法区实际上也是堆，用于储存**类，常量的相关信息**--静态的一些数据
		- 代码
		- 静态变量
		- 静态方法
		- 字符串常量
- 合起来
	- **栈**（ToDo）调用**堆的对象**，**堆的对象**的内容由**其他堆、方法区**的内容组成

### 垃圾回收机制Garbage Collection

![](https://github.com/floatLig/Learn-Inbox/blob/master/media/%E5%9E%83%E5%9C%BE%E5%9B%9E%E6%94%B6%E6%9C%BA%E5%88%B6.png)

- 针对对象（**堆**），类似回收垃圾的服务员
	- C++没有垃圾回收机制，使用后必须把残渣带走，如果没有带走，则这块内存不能使用
- 算法：根搜索算法（引用可达法）
- 原理
	- 发现无用的对象
	- 回收无用对象占用的空间
	- Minor GC/Major GC/Full GC(全部清理，代价较高)
	- 年轻代
		- Eden：对象刚创建出来
		- Survival1
		- survival2
	- 年老代
		- Tenured/Old
	- System.gc()
		- 向系统建议调用垃圾回收机制
		
### 编程中的对象实现
- JVM顺序
	- 方法区：
		- 父类静态变量->父类静态代码块
		- 子类静态变量->子类静态代码块
	- 栈
		- main函数
	- 堆
		- 父类变量--父类代码块（对该类的共同属性进行赋值）--父类构造器
		- 子类变量--子类代码块（对该类的共同属性进行赋值）--子类构造器
- 类（蓝图）（抽象-抽出像的东西）
	- 书写注意：类是没有参数的
	- 属性（调用对象的属性“.”）
	- **类中有类**
	- 成员方法（调用对象的方法“.”）
- 对象object / instance（实例）
	- 和对象的关系
		- 是对象的模板
	- 使用：用new调用构造方法->初始化/实例化
		- 无参的构造方法由系统自动创建
		- 方法名称和类名保持一致
		- 经常重载（不用实例化）
		- this:表示创建的**这个对象**
		- 构造方法的第一句都是super（）--系统默认添加
	- 创建对象时的底层操作
		- 在堆中分配对象空间，并将对象成员初始化为0或null
		- 执行属性值的显式初始化（实例化+代码块）
		- 执行构造函数（实例化）
		- 返回对象地址给相关的变量
	- this
		- 表示创建的这个对象
		- 不能用于static，因为static位于方法区，而this只能调用**堆**里面对象的东西

- 方法区
	- static
		- 变量：从属于类（非static的变量从属于函数/对象）
		- 静态初始化块
			- JVM运行时会提前调用
			- 顺序：父类静态代码块->子类静态代码块
- 参数传值机制
	- 一般是值传递，例如：传的是int
	- 如果传递的是对象，则传递的为：对象地址的复制
	- 值传递底层操作
		- 在类的方法中，创造一个和参数一样的对象
		- 将参数的地址赋予这个对象--即类似于分身
		- 特殊例子：若是方法的代码写成：className=new newClass();这样子则说明，赋值的对象地址更换为【另一个新的对象的地址】，则那么与原先的参数就没有关系了

### 包 package（在不在同一个大千世界下）
- 简介：类似于文件夹，对类的管理
- 在src(源码)中创建
	- 结构--分为5层
		- 项目
		- 项目：lib(编译器给你创建的) + src(source)(自己创建的源代码)
		- 源代码： ♥ 包（域名倒写+自己包名）
		- 包：".java文件"
		- ".java文件"：public class+其他class
	- 域名倒着写：
		- 域名：独一无二，不会重复
		- 倒着写：习惯
		- com.github.floatLig.oo/newbie
		- 常见域名解释：org(非营利组织)  com(公司)
- 默认包：是不会创建文件夹的，因此，写项目的时候要加上自己的包
- java提供的很多包都是以java开头的
- 导入包：
	- **导入**什么**包**中的什么类/\* --**连通大千世界**
	- 导入别人写的包
	- 静态导入：import static java.lang.Math.PI
	- java.lang：（language）lang包是默认导入的，所以不用写也可以

-----

## 继承、封装、多态

### 继承 extends
- 蓝图更加具体化
	- 父类：又称为超类、基类、派生类（从之中派生）
	- 在内存模型中，对象要想到有父类的蓝图（包括超级父类object类）
	- object是所有类的父类
	- 查看继承结构树：
		- Ctrl+T（tree）
		- 右键--open type hirrarchy
- 接口可以多继承
- 原理：
	- 子类继承父类--可以**得到**类的全部属性和方法（除了构造方法）
	- 可是**不见得可以直接访问**，比如：私有成员和方法
- 重写
	- 重写返回值类型 可以重写并返回子类的的类型
		- 可以说是具体化了吧
	- 返回值类型和声明异常类型，子类等于父类
	- 重写的访问权限要【大于等于】父类，原因是：向上转型；可以调用父类，子类也必须可以调用，不然就没用了
- object类（超级父类）
	- tostring是最常用的方法
		- 打印：具体路径（包+类名）+哈希地址值
	- ==
		- 用于判断值时候相等：1==1
		- 引用类型：地址==地址，是不是同一个对象
	- equal
		- 用于判断对象是否相等，经常重写，不重写默认为（==）
		- 右键--source--equal（哈希的重写可以删掉）；其他小操作：右键--source--可以生成构造器generate construction form fields
		- String也重写了equal的方法
- super()直接父类的引用
	- 可以通过super来访问父类中被子类覆盖的方法或属性
	- 构造方法的第一句是默认super（）
		- 因此，在构造子类之前，必须先执行super（），即先创建父类的对象，包括**属性和方法**；接着在创建子类，同名的属性或方法则会被子类覆盖

### 封装
- 高内聚、低耦合；便于外部使用
- 就是加访问控制符
	- default：本包可以使用，同一个大千世界下
	- protected：不同包，只有使用extends的子类可以用（保护）
	- public：导入包中的这个类就可以
	- private：子类也看不到，只有类本身可以看的到（别人拥有一切，但是不能访问）
	- 一般的普通程序
		- 类的属性：private
		- 方法：public
		- setAge()赋值：在这个方法中，如果符合则成功赋值，如果不符合，则不给予赋值
		- getAge()获得值
		- isMan()布尔值
		- set/get右键--source生成
	
### 多态（一个方法的调用，由于对象不用而有着不同的行为）
- 多态是方法的多态，不是属性的多态
- 条件（必须都有）
	- 继承
	- 方法重写
	- 父类引用子类对象
	- 一个方法的参数是父类对象，子类作为参数被调用，多态就出现了（类似于c++的虚函数）
- 理解：同一个方法，不同的对象有不同的做法（前提是他们父类一样，是同一种类别）
- 转型casting
	- 向上转型：身份是父类

-----

### 异常
- 异常处理：使用异常处理语句，对可能出现的异常的代码块进行处理，如果代码块出现了异常，则会打印出catch中异常处理的信息，**代码不会中断**。
- try-catch语句
	- 其中，try中的“程序代码块”指的是可能产生异常的代码；
	- catch中的“对Exceptiontype的处理”的作用是捕捉并处理与已产生的异常类型相匹配的异常对象e；
	- finally中的代码块是异常处理过程中最后被执行的部分，无论程序是否异常，finally中的代码块都将被执行。实际应用时，finally中通常放置一些释放资源、关闭对象的代码。
	- 注意：catch代码块中异常类的顺序是先子类后父类,因为catch语句也是按照顺序执行的，按照常识，应该处理**更细致的异常类型**，例子如下：
	```
	try{
		----;
	}catch(ArrayIndexOutOfBoundsException aiobe){
		aiobe.printStackTrace();
	}catch(Exception e){
		e.printStackTrace();
	}
	```
- throws
	- throws关键字常被应用于方法上，表示方法可能抛出的异常，当方法抛出多个异常时，可用逗号分隔异常类型名。例子如下：
	```
	//在方法中 抛出异常
	public void pay(String dayPrice, double weight) 
				throws ArrayIndexOutOfBoundException{
		---;
	}

	//调用方法的上层代码 处理异常
	public static void main(String[] args){
		try{
			Tomato tomato = new Tomato();
			tomato.pay(dayPrice, weight);
		}catch(ArrayIndexOutOfBoundException aiobe){
			System.println("pay方法抛出数组元素下标越界异常！")
		}finally{
			sc.close();
		}
	}
	```
- throw抛出自定义异常
	- 创建自定义异常时，需继承RuntimeException类或者Exception类。例子如下：
	```java
	// 指定一个异常类对象
	class PriceException extends Exception{ // 自定义异常类，并继承异常类
		public PriceException(String message){ // 创建价格异常类有参构造方法
			super(message); // 调用异常类的有参构造方法
		}
	}

	// 方法中 new一个自定义异常对象，并用throw抛出
	public void setPrice(double price) throws PriceException{
		if(price > 7.0){
			throw new PriceException("国家规定西红柿单价不能超过7元！！")
		}
	}

	//调用方法的上层代码 处理异常
	public static void main(String[] args){
		Tomato tomato = new Tomato();
		try{
			tomato.setPrice(dayPrice);
		}catch(Exception e){
			System.println(e.getMessage());
		}finally{
			sc.close();
		}
	}
	```
- throws和throw关键字的区别
	- throws用在方法声明后面，表示抛出异常，由方法的调用者处理；而throw用在方法体内，用来制造一个异常，由方法体内的语句处理
	- throws是声明这个方法会抛出这种类型的异常，以便使它的调用者知道要捕捉这个异常；而throw是直接抛出一个异常实例
	- throws表示出现异常的一种可能性，并不一定会产生这些异常，但如果使用throw，就一定会产生某种异常（就像上面如果满足if,这就会有异常）

### 包装类

|基本数据类型|对应的包装类|基本数据类型|对应的包装类|
|:---|:---|:---|:---|
|byte|Byte|short|Short|
|int|Integer|long|Long|
|float|Float|double|Double|
|char|Character|boolean|Boolean|

构造方法

|构造方法|
|:--|
|Integer number = new Integer( int number)|
|Integer number = new Integer( String str)|

常用方法

|返回值|方法|
|:---|:---|
|Interger|valueOf(String str)|
|int|parseInt(String str)|
|String|toString()|
|String|toBinaryString()|
|String|toOctalString()|
|String|toHexString()|
|boolean|equals(Object IntergetObj)|
|int|intValue()|
|short|shortValue()|
|byte|byteShort()|
|int|compareTo( Integer anotherInteger)|

常量
- 以Integer为例
- MAX_VALUE：表示int类型可取的最大值，即2^31 -1
- MIN_VALUE：表示int类型可取的最小值，即-2^31
- SIZE：用来以二进制补码形式表示int值的位数
- TYPE：表示基本类型int的Class实例

Math类

|返回值|方法|功能|
|:--|:--|:--|
|---|---|Math类概述|
|---|Math.PI|圆周率PI|
|---|Math.E|自然对数底数e|
|---|---|Math类常用数学运算方法|
|double|Math.exp(double a)|e^a|
|double|Math.log(double a)|lna|
|double|Math.log10(double a)|用于取底数为10的对数|
|double|Math.sqrt(double a)|平方根|
|double|Math.cbrt(doble a)|立方根|
|double|Math.pow(double a, double b)|用于取a的b次方|
|---|---|---|
|---|---|Math类取整函数|
|double|Math.ceil(double a)|ceiling天花板，向上取整|
|double|Math.floor(double a)|地板，向下取整|
|double|Math.round()|四舍五入|
|---|---|---|
|---|---|Math类取最大值、最小值、绝对值|
|double|Math.max(double a, double b)|取最大值|
|double|Math.min(double a, double b)|取最小值|
|double|Math.abs(double a)|absolute，取绝对值|

Data类

构造方法

|构造方法|功能描述|
|:--|:--|
|Date date = new Date(timeMillis)|以毫秒数timeMillis分配它的时间（精确到毫秒）|
|Date date = new Date()|--|

常用方法

|返回值|方法|功能描述|
|:---|:---|:---|
|boolean|after(Date when)|测试当前日期是否在指定的日期之后|
|boolean|before(Date when)|测试当前日期是否在指定日期之前|
|long|getTime()|获得自1970年1月1日 00：00：99 GMT开始到现在所表示的毫秒数|
|void|setTime(long time)|设置当前的时间|

格式化当前日期

```java
Date nowDate - new Date(); // 创建当前日期

DateFormat df1 = DareFormat.getInstance(); // 日期格式，Java的默认日期格式
DateFormat df2 = new SimpleDateFormat("yyyy-mm-dd hh:mm:ss EE"); // 向上转型，自定义日期格式

System.out.println(df1.format(date))；// 依据java默认格式输出
System.out.println(df2.format(date))；// 依据自定义格式格式输出
```

## 思考经验
- 自己打代码：（对象化）
	- 初始值只会赋值一次
	- 半括号的范围：友半括号-向上
	- 终端光标要手动转到下一行
- 有疑问的，记住，然后后面学到的，可以解决前面的知识
- 学习JDK的源码是我们学习编程的一个非常好的套路
- [eclipse结构树的图标含义](https://blog.csdn.net/androidolblog/article/details/45503515)
- AWT和swing基本用不到，用到什么学什么，用不到就拉倒


链式调用：return this
```
		StringBuilder strStringBUilder = new StringBuilder("1234567890");

		//链式调用，因为insert的源代码：return this
		strStringBUilder.insert(0,'我').insert(1,'爱').insert(2,'你');
		System.out.println(strStringBUilder);
		
//		打印结果
//		我爱你1234567890
```

Java.lang：英文全称是language，是Java语言的基础包

阅读源码的小技巧
- Quick Type Hierarchy 快速查看类继承体系：快捷键 Ctrl+T
- 更详细的类继承体系：右键-Open Type Hierarchy(在我的Eclipse的左边显示)
- Open Call Hierachy 打开调用层级：右键-Open Call Hierarchy（在我Eclipse的右边显示）
- Debug断点的灵活使用：F5 单步进入；F6 单步结束；F7 跳出放发（跳出函数）；F8 继续执行到遇到下个断点
- Debug的时候，关注debug视图的线程栈（在Eclipse Debug界面的左边显示）


Throwable
- Error
- Excpetion：RuntimeEception、CheckException

所有的**运行时的异常**都能够用**if逻辑判断**避免

泛型：帮助我们建立类型安全的集合
- 类似标签的作用
- 本质：数据类型的参数化


读源码是有目的的，是为了让你更能够理解概念

List是有序、可重复的容器

```
//ArithmeticException 算术错误情形，如以零作除数
if(a != 0)

//ArrayIndexOutOfBoundsException 数组下标越界
if(i < arr.length)

//NullPointerException 尝试访问 null 对象成员
if(p != null)

//ClassNotFoundException 不能加载所需的类


//InputMismatchException 欲得到数据类型与实际输入类型不匹配


//IllegalArgumentException 方法接收到非法参数


//ClassCastException 对象强制类型转换出错
if(dog instanceof cat)

//NumberFormatException 数字格式转换异常，如把"ab"转换成数字
正则表达式

```



```java
package io.github.floatLig.survival;

import java.io.File;
import java.io.IOException;
import java.util.Date;

/**
 * 测试File的基本用法
 * @author 25894
 *
 */
public class TestFile {

	public static void main(String[] args) throws IOException {
		
		//测试文件
		File firstTestFile = new File("d:/a.txt"); // 存放的只是文件的路径,文件可能存在,也可能不存在
		firstTestFile.createNewFile();
		System.out.println(firstTestFile.exists());
		
//		打印结果;
//		true
		
		//重命名
		File fNewName = new File("d:/aaaa.txt");
		firstTestFile.renameTo(fNewName); 
		
		// 在工作的路径创建文件夹
		System.out.println(System.getProperty("user.dir")); // directory目录
		File userDirFile = new File("gg.txt");
		userDirFile.createNewFile();// 创建文件
		
		System.out.println("-------");
		System.out.println(userDirFile.exists());// 是否存在
		System.out.println(userDirFile.isDirectory());// 是否为文件夹  Directory英文
		System.out.println(userDirFile.isFile());// 是否是文件
		System.out.println(new Date(userDirFile.lastModified()));//最后的操作时间
		System.out.println(userDirFile.length());//大小
		System.out.println(userDirFile.getName());//名字
		System.out.println(userDirFile.getAbsolutePath());//绝对路径

//		打印结果;
//		D:\Workspace\Java\First_Learning_Inbox
//		-------
//		true
//		false
//		true
//		Tue Jul 16 11:33:06 CST 2019
//		0
//		gg.txt
//		D:\Workspace\Java\First_Learning_Inbox\gg.txt
		
		//用mkdir创建整个目录树   mkdir是Linux创建文件夹的命令
		System.out.println("++++++++++"); // 分割线
		File fDir = new File("D:桌面/华语/电影/大话西游");
		File fTxtFile = new File("D:桌面/华语/电影/大话西游/f4.txt");
		boolean flag = fDir.mkdirs();
		fTxtFile.createNewFile();
		System.out.println(fTxtFile.exists());
		System.out.println(fTxtFile.toString());
		System.out.println(flag);
	
//		打印结果:
//		++++++++++
//		true
//		D:桌面\华语\电影\大话西游\f4.txt
//		true
		
		fDir.delete(); // 路径下有文件，该路不能成功删除
		fTxtFile.delete();  
		System.out.println(fDir.exists());
		
		fTxtFile.delete();  
		fDir.delete(); // 路径下没有文件，该路径能成功删除
		System.out.println(fDir.exists());
		
//		打印结果
//		true (没有成功删除)
//		false (成功删除)
		
		// 用递归算法打印目录树
		System.out.println("=================");
		File fff = new File("D:/桌面/34 玩转VS Code");
		
		printFile(fff, 0);
		
		
		// 测试枚举类型
		// 枚举类型常用于switch
		System.out.println("``````````");
		System.out.println(Season.SPRING);
		
		Season a = Season.SPRING;
		
		switch (a) {
		case SPRING:
			System.out.println("春天来了");
			break;
		case SUMMER:
			System.out.println("夏天来了");
			break;
		case AUTUMN:
			System.out.println("秋天来了");
			break;
		case WINTER:
			System.out.println("冬天来了");
			break;
		default:
			break;
		}
		
		
		
	}
	
	
	// leval为层数
	static void printFile(File file,int level) {

		// 输出层数
		for (int i = 0; i < level; i++) {
			System.out.print("-");
		}
		System.out.println(file.getName());
		
		if(file.isDirectory()) {
			File[] files = file.listFiles();// 获得子目录
			
			for(File temp: files) {
				printFile(temp,level+1);
			}
		}
	}
	
	
	// 测试枚举类型
	
	enum Season{
		SPRING,SUMMER,AUTUMN,WINTER
	}
}

```

