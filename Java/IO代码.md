String + Byte[]

```java
	/**
	* 编码、译码测试
	* 将String转为byte[],再转为String
	*/
	public static void main(String[] args) {
		String msg = "一二三四";
		
		// 改成字符数组,编码
		
		byte[] datas = msg.getBytes();
		System.out.println(datas.length); // 工程默认编码 GBK ：一个中文2个字节
		
//		打印结果：
//		8
		
		// 编码，由字节数组变为字符
		
		try {
			msg = new String(datas,0,datas.length,"GBK"); // string的构造方法
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(msg);
		
//		打印结果
//		一二三四
		
	}

```

reader + writer

```java
/**
 * reader读出 + writer写出，中间用string临时存储
 * 很容易理解，因为reader，writer操作的是String
 * 
 * 套上BufferedReader
 * 
 * @author 25894
 *
 */
public class ConvertTest {
	public static void main(String[] args) {
		//system.in 和system.out 
		try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
				BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));){
			
			//循环获取键盘的输入（exit退出），输出此内容
			//reader读出，writer立马写出
			String msg = "";//初始化，进入第一次循环
			while(!msg.equals("exit")) {
				msg = reader.readLine(); // 循环读取一行
				writer.write(msg); // 循环写出
				writer.newLine(); // 在输出文本中写出一个换行符， 作为对比，reader能读取一行
				writer.flush(); // 强制刷新，才能读出内容
			}
			
		} catch (IOException e) {
			// TODO: handle exception
		} 
	}
}

```


设计模式：装饰 举例
```java
/**
 * 模拟咖啡
 * 
 * 1、抽象组件：需要装饰的抽象对象（接口或抽象父类）
 * 2、具体组件：需要装饰的对象
 * 3、抽象装饰类：包含了对抽象组件的引用以及装饰着共有的方法
 * 4、具体的装饰类：被装饰的对象
 * 
 * 在不改变原来代码的基础上，增加功能
 * 
 * @author 25894
 *
 */
public class DecorateCoffee {
	public static void main(String[] args) {
		Drink cofee = new Coffee();
		Drink suger = new Suger(cofee); // 具体的修饰类 包含 具体组件；类似于StringBuffer 包含 InputString
		
		System.out.println(suger.info() + "-->" + suger.cost());
		
	}
}

// 抽象组件，类似于InputString
interface Drink{
	double cost();
	String info();// 说明
}

// 具体组件，类似于FileString
class Coffee implements Drink{
	private String name = "原味咖啡";
	
	@Override
	public double cost() {
		return 10;
	}
	
	@Override
	public String info() {
		return name;
	}
	 
}


// 抽象的装饰类，功能为：对传进来的具体组件Coffee 具体化
// 这里的属性主要是要和Coffee同级，这里可以为 Drink，因为Drink是Coffee的父类
// 属性为Drink，可以传进来Coffee
// 类似于FilterInputString
abstract class Decorate implements Drink{
	//对抽象组件引用
	private Drink drink;

	/**
	 * @param drink
	 */
	public Decorate(Drink drink) {
		super();
		this.drink = drink;
	}
	
	@Override
	public double cost() {
		return this.drink.cost();
	}
	
	@Override
	public String info() {
		return this.drink.info();
	}
		
}

// 具体的装饰类:抽象装饰类Decorate的具体化
// 类似于BufferedInputString
class Milk extends Decorate{

	public Milk(Drink drink) {
		super(drink);
	}
	
	@Override
	public double cost() {
		return super.cost() *4;
	}
	
	@Override
	public String info() {
		return super.info() + "加入了牛奶";
	}
}

//具体的装饰类
class Suger extends Decorate{

	public Suger(Drink drink) {
		super(drink);
	}
	
	@Override
	public double cost() {
		return super.cost() *2;
	}
	
	@Override
	public String info() {
		return super.info() + "加入了蔗糖";
	}
}

```

BufferedString + URL流

```java
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.URL;

/**
 *  操作网络流 下载百度的源代码，  --> 拓展 ： 网络爬虫 分析数据 提取有效信息 真正表达式
 * 
 *  使用try..with..resource 可以自动释放（finally里面的内容）
 *  
 * @author 25894
 *
 */
public class ConvertTest02 {
	public static void main(String[] args) {
		
		// BufferedReader是装饰者，装饰着InputStreamReader
		// InputStream 构造器可以可以构造URL
		// 使用try..with..resource 可以自动释放（finally里面的内容）
		try (BufferedReader reader = 
				new BufferedReader(
						new InputStreamReader(
								new URL("http://www.baidu.com").openStream(),"UTF-8"));
				BufferedWriter writer = 
						new BufferedWriter(
								new OutputStreamWriter(
										new FileOutputStream("baidu.html"),"UTF-8"));){ // 和你工程的字符集对应，好像又不是和你的工程的字符集对应

			
			String msg;
			while((msg = reader.readLine()) != null) {
				writer.write(msg);
				writer.newLine();
			}
			writer.flush();
			
		} catch (IOException e) {
			// TODO: handle exception
		} 
	}
}
```