# Java实例

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
- 对象化
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
