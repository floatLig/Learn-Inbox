# 安装Android Studio

> [成功：软件安装管家](https://mp.weixin.qq.com/s?__biz=MzIwMjE1MjMyMw==&mid=2650196923&idx=1&sn=fc2df766707d6d264feb32fd75270f2b&chksm=8ee16b57b996e241dfbcdd576543c3a423555521682ba4a9ed8aed3f48298401804ab1ca36b1&scene=21#wechat_redirect)



### 下载JDK，配置环境变量
> [参考链接：JDK下载以及配置环境变量](https://www.cnblogs.com/liuhongfeng/p/4177568.html)  
- 知识补充： 

		JDK：Java Development Kit 开发工具包 
		
		**环境变量**：一般是指在操作系统中用来指定操作系统“运行环境”的一些参数，例如在Path中，用户在使用DOS，
		告诉操作系统程序名字而没有告诉操作系统完整路径的时候，操作系统除了会在当前的目录寻找之外，还会在
		Path指定路径中寻找。环境变量的原理是把一个目录下有名字.exe的路径添加到系统变量Path中

- 小技巧
	
		 微软小娜搜索“环境变量”


- 需要配置的环境变量：

		 JAVA_HOME （可大写可小写，但是是系统变量，推荐大写 || JDK中包含JRE的bin，因此可单独设置JAVA_HOME为JDK的路径地址）
		 Path （bin包含可执行文件）
		 CLASSPATH
- 卸载注意

		卸载旧版本的Jdk,同时也要删除环境变量中的path等变量

### 使用SDK Tools安装SDK
> [参考链接：安装并配置Android sdk](https://www.jianshu.com/p/4ac1313b50cb)

![](https://github.com/floatLig/Learn-Inbox/blob/master/media/sdk%E9%95%9C%E5%83%8F.jpg)

- 注意内容-使用镜像下载sdk  
		HTTP Proxy Server填写：mirrors.neusoft.edu.cn
		HTTP Proxy Port 填写：80
		勾选 other-Force http://````

- 注意内容-需要下载的东西  
> [参考图片：下载API15以上的SDK](https://upload-images.jianshu.io/upload_images/4108891-6802b40511dcf0e3.png)

### 设置Adb、Gradle等其他环境变量
> [参考链接：设置Adb环境变量](http://blog.51cto.com/13238147/2130176)  

### Android Studio的安装  
> [参考链接：Android Studio的安装](https://my.oschina.net/zhangyujian/blog/1503559)
  
- 创建项目出现的ASCII问题
	- 名字不要使用**中文**
