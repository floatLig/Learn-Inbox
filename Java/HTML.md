## HTML

### 概念

web三大基石：
1. URL：统一资源定位符
2. HTTP：超文本传输协议
2. HTML：超文本标记语言

数据怎么显示:类似于markdown的语法格式

概念：超文本标记语言

作用：
1. 在浏览器中的数据“以友好的格式”展现给用户
2. 告诉浏览器接受的数据，以什么样的格式，呈现给用户
3. 浏览器解析执行

使用：
HTML的标准文档规范
HTML的标签

后缀：
1. html
2. htm

前端开发工具:
HBuilder


1. 块级标签
	1. 可以存在标签属性，对标签的内容进行进一步的补充
2. align:center left right

### CSS 

作用：
1. HTML可以有效的组织数据的展示；但是不同类型数据在浏览器的分布没有实现
2. 样式开发（穿衣服）
3. 布局

使用CSS选择器顺序：
1. *
2. 类选择器
3. 标签选择器
4. id选择器、属性选择器、style选择器

样式单：
1. 边框设置
	1. border:solid 1px(实线)
2. 字体设置
	1. font-size:10px
	2. font-family:"黑体"
	3. font-weight:bold;字体加粗
3. 字体颜色设置
	1. color:颜色
4. 背景颜色设置
	1. background-color:颜色；
5. 背景图片设置
	1. background-img:url
	2. background-repeate:no-repeate;设置图片不重复
	3. background-size:cover;平铺
6. 高和宽设置
7. 浮动设置
	1. float:left/right
8. 行高设置

margin:外边距
padding:内边距

border
width、height
background

margin
padding

position:relative：相对位置（小幅度移动）
left:
top:

position:fixed:固定位置（在某个框内大幅度移动）
position:absoluted：绝对位置（培训网站：客服联系方式）

z-index

百度首页模仿
1. 首页使用CSS+div进行页面布局
2. HTML对每一个块进行内容填充

JavaScript:
1. 加入特效
2. 检验功能


## Javascript

1. 弱类型语言：
2. 动态化：js只有var这个数据类型，具体的类型由“值”确定；且可以变化

var可以称为的类型：（用typeof查看）
变量初始化的时候尽量赋初始值
1. number
2. string
3. boolean
4. Object
5. null
	1. 声明：var a = null;就规定a为Object，只能接收对象
6. undefined

变量提升：
js的引擎的工作方式：先解析代码，获取所有声明的变量，然后再一行一行的运行

类型强制转化
1. Number（）
2. Boolean（）

### JavaScript的基本语法

变量提升

区块

条件语句：
1. = 赋值运算符
2. == 相等运算符
3. === 严格相等运算符
4. switch（1） case true: 采用的是严格相等运算符（===），所以1！==true

JavaScript学习的博客链接：https://zhaohd.gitee.io/pro-js/#/

事件机制：
通过事件机制触发函数
1. 单击事件
2. 鼠标事件
3. 键盘事件
4. 焦点事件
5. 页面加载机制

BOM 浏览器对象模型（是一个协议）
- js可以调用浏览器封存的代码：前进后退、地址栏主页

Windows也是一个对象
- window对象常用方法
- Windows对象常用属性  

Document:浏览器对外提供一个接口，用于操作HTML

理解：
Document和HTML区别开来，是不同的语言。
js获取HTML的文本，存在Document对象里面，这样子js就可以通过Document操纵HTML,js写Document的内容，Document会写回HTML；

都是类型 || 键值对： type  id name value + 函数 