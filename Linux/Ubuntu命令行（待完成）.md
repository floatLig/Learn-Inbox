# Ubuntu命令行
### 常用命令行
#### 终端信息查看命令行
1. cd命令：改变当前的路径

1. ls命令（list files）：显示当前路径的文件夹

1. echo $PARH命令：查看环境变量的路径有哪些

1. pwd命令（print working directory）：输出当前路径 

1. witch命令：which是在path路径中查看某个系统命令的位置，并返回；使用which命令可以查看某个系统命令是否存在；例如`which ls || which which`

1. su命令（swith user）:切换用户成root用户）（exit 退出超级用户）

1. env命令（environment）：当前用户的运行环境

1. gedit ./.bashrc
#### 其他命令行

1. man命令（Manual手册）可以使用这个命令查询其他命令的用法

1. df命令（disk free）:空余硬盘

1. reboot命令：重启

1. cat命令：cat A 用于显示A路径下文件的内容

### 文件操作常用命令行
#### 创建&删除
1. touch命令：touch A 在当前的路径创建A

1. mkdir命令（make directory）：用于创建文件夹

1. rm命令(remove)：用于删除文件（rm -f 用于强制删除软件 rm-rf删除文件夹）

#### 移动&复制&查看
1. mv命令（move）：mv A B 将A移动到B

1. rmdir命令：移动文件夹

1. cp命令(copy)：cp A B ，将A的路径的文件复制到B路径

1. less/more命令：用于查看文件的内容 （按q退出)

----
## 常用命令行的操作
#### APT安装软件
1. 普通安装：apt-get install sofename1 sofename2

1. 修复安装：apt-get -f install sofenam1 sofename2

1. 重新安装：apt-get --reinstall install sofename1 sofename2
#### APT卸载软件
1. 移除式卸载：apt-get remove softname1 softname2
#### 更新
1. 更新源：apt-get update

1. 更新已安装的包：apt-get upgrade

#### Dpkg安装.deb软件
1. 普通安装：dpkg -i package_name.deb
####Dpkg卸载.deb软件
1. 移除式卸载：dpkg -r pkg1 pkg2
#### 安装.gz文件(未测试)
1. 解压：tar -zxvf FileName.tar.gz

1. 编译：./configure

1. 配置：make

1. 执行：make install
