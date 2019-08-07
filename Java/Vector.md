## Vector

Vector是线程安全，在每个方法后面都会添加一个synchronized，表示有同步标记，每一次运行的时候会检查有没有锁

一般不用，因为用在方法内部，ArraayList就已经足够了

## Map

键值对：其实数组也是一种键值对

Map的键可以为String等等

HashMap的实质是：数组+链表

Tree Map：红黑二叉树的底层，一般用于排序，需要重写implement comparable接口

打印信息：打印出来toString

HashMap：线程安全，允许key和value为null

HashTable：线程不安全，不允许key和value不为null

Set:没有顺序，不可重复

HashSet的核心代码的是Hash Map，不能重复的原因就是：加的值都是Hash Map的key 
(HashSet中的value用Present表示，默认值)

TreeSet



OOP 
容器：知其然 知其所以然

Collections
```java

public class TestCollection {
	
	public static void main(String[] args) {
		List<String> list = new ArrayList<>();
		
		for(int i = 0; i < 10; i++) {
			list.add("gao"+i);
		}
		
		System.out.println(list);

		Collections.shuffle(list); // 随机排列
		System.out.println(list);
		
		Collections.reverse(list);
		System.out.println(list); //反转
		
		Collections.sort(list);
		System.out.println(list); // 排列
		
		System.out.println(Collections.binarySearch(list, "gaop1"));
	}
}


```

```java
package sxt_07_17;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.sound.sampled.TargetDataLine;

/**
 * ORM思想:对象关系映射
 * 
 * 每一行数据用Map存储
 * 整个表格用一个List
 * 
 * 用HashMap保存表格的每一行：
 * 用List保存整个表格
 * id	name	薪水
 * 1001	张三		20000
 * 1002	李四		10000
 * 
 * 并打印出
 * 
 * @author 25894
 *
 */
public class TestStoreDate {
	public static void main(String[] args) {
		
		//用Map保存每一行
		Map<String, Object> row1 = new HashMap<String, Object>();
		
		row1.put("id", 1001); // 键为String，值为Object
		row1.put("name", "张三");
		row1.put("薪水", 20000);
		
		Map<String, Object> row2 = new HashMap<String, Object>();
		
		row2.put("id", 1002);
		row2.put("name", "李四");
		row2.put("薪水", 10000);
		
		//用List保存整个表格
		List<Map<String, Object>> table1 = new ArrayList<Map<String,Object>>();
		
		table1.add(row1);
		table1.add(row2);
		
		// 导出整个表格
		for(Map<String, Object> row : table1) {
			// 遍历Set
			Set<String> keySet = row.keySet(); // keySet
			
			for(String key : keySet) { // key : keySet
				System.out.print(key + row.get(key) + '\t');
			}
			
			System.out.println();

//			打印结果
//			name张三	薪水20000	id1001	
//			name李四	薪水10000	id1002	
		}
	}
}
```