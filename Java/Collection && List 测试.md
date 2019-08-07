List是一个接口，而ArrayList是List接口的一个实现类。 

ArrayList类是继承AbstractList抽象类和实现List接口的一个实现类。 

因此，List接口不能被构造，也就是我们说的不能创建实例对象，但是我们可以像下面那样为List接口创建一个指向自己的对象引用，而ArrayList实现类的实例对象就在这充当了这个指向List接口的对象引用。 

```java
package io.github.floatLig.survival;

import java.util.List;
import java.util.ArrayList;
import java.util.Collection;

/**
 * 测试collection方法
 * @author 25894
 *
 */
public class TestList {

	public static void main(String[] args) {
		Collection<String>  collection = new ArrayList<>();
		
		System.out.println(collection.size());
		System.out.println(collection.isEmpty());
		
//		打印结果
//		0
//		true
		
		collection.add("高老大");
		collection.add("高老二");
		System.out.println(collection.size());
		System.out.println(collection.toString());
		
//		打印结果
//		2
//		[高老大, 高老二]
		
		collection.remove("高老二"); // 注意remove的作用是将 引用去除,而不是删除 对象"高老二" 
		System.out.println(collection);
		System.out.println(collection.size());
		
//		打印结果
//		[高老大]
//		1
		
		Object[] objs = collection.toArray();
		System.out.println(objs.toString());
		
//		打印结果
//		[Ljava.lang.Object;@6108b2d7
		
		List<String> list01 = new ArrayList<>();
		list01.add("aa");
		list01.add("bb");
		list01.add("cc");
		
		List<String> list02 = new ArrayList<>();
		list02.add("aa");
		list02.add("dd");
		list02.add("ee");
		
		System.out.println(list01); // println(Object x),并将Object转化成String
		System.out.println(list01.indexOf("bb"));
		list01.retainAll(list02);
		System.out.println(list01);
		
//		打印结果
//		[aa, bb, cc]
//		1
//		[aa]
		
		test03();
		
	}
	
	// 静态方法是不用对象也能够调用,当时如果想要调用
	// 该静态方法,还是需要在main函数中声明.不要和静态方法区
	// 的代码搞混了(静态代码区的代码,会自动运行)
	public static void test03() {
		
		List<String> list01 = new ArrayList<>();
		list01.add("aa");
		list01.add("bb");
		list01.add("cc");
		
		System.out.println(list01);
		
		System.out.println(list01.subList(1, 2)); // subList定义的是一个视图,对原有的list01没有影响
		
//		打印结果
//		[aa, bb, cc]
//		[bb]

		
	}
	
}

```