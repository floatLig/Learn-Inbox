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

#### 常用样式
1. display:block / table 块级元素
2. overflow:hidden 文本溢出隐藏
3. text-indent: 规定一个元素首行文本内容之前应该有多少个水平空格
4. line-height: 属性设置行间举例
5. clear：指定一个浮动元素，其他元素是否移动位置
6. zoom：代表缩放 1.0/100%代表不缩放
7. background-position: 为每个背景图片设置初始位置
	1. 背景为一张图片，通过background-position，可以获得不同的背景叠加效果（background-position指定背景图位置，本身的大小height weight 决定背景叠加效果的大小）
8. margin: 外边距（上 右 下 左）
	1. em 字距； px 像素； auto 居中；
9. div必须有内容才能显示，或者要指定长宽高

#### 实例
1. 如何把一个超链接文字扩大点击范围并隐藏起来？
	1. 扩大范围：.logo{width,height}
	2. 隐藏位置：text-index:-999cm
	3. 这样子就可以实现，感觉在一张图片上面，一点就有超链接
2. 样式可以不断地叠加.class + div

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

span无语义行内元素

js的全局代码区只有一个，这样子会造成同名变量的值被覆盖 


什么是jQuery：
1. 是js的一个框架，本质是js

jQuery的特点:
1. 支持各种主流浏览器
2. 使用简单
3. 便捷的插件扩展机制

闭包：用一个大的全局变量来保存局部变量的值
window.jQuery = window.$ = jQuery

返回的是只有一个对象的数组！！数组获取value的值，只能用函数val()；如果你获取的是一个对象，还是可以直接调用.value

jQuery中选择器获取的是存储了HTML元素对象的数组->.val()
jQuery获取的元素对象不能够直接使用js的内容，除非按照数组的方式取出对象： inp[0].value;

attr("value")不能获得实时的数据，只能够通过uname.val()获取实时数据

not a function 说明你的代码出现一定的**语法错误**

## EasyUI:
因为HTML是写错不会报错，所以！能复制就不要手写

EasyUI是前端框架
1. 封装了大量的CSS，js

使用前端框架
1. 给标签class属性
2. data-options属性定义easyui属性
3. 如果easyui提供的属性和HTML标签属性相同，可以把这个属性不写在data-options中
4. 每一个效果使用纯标签方式和使用标签结合js方式
	1. 如果效果是静态的（数据来源固定）建议使用HTML标签方式
	2. 如果效果是动态的，建议使用HTML结合js方式
5. 在easyui中所有脚本功能语法
```javascript	
//如果该效果（组件）是abc,控制abc的语法
$("jquery 选择器获取到abc").abc({
		属性名：值
		事件：function
	})
//如果该效果（组件）是abc,控制abc方法的语法
$("jquery 选择器获取到abc").abc("方法名")；调用方法
&("jquery 选择器获取到abc").abc("方法名","参数");//调用方法
```