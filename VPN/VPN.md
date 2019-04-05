# VPN使用手册

### 基础知识
> WIki：A virtual private network (VPN) extends a private network across a public network, and enables users to send and receive data across shared or public networks as if their computing devices were directly connected to the private network. Applications running across a VPN may therefore benefit from the functionality, security, and management of the private network. Encryption is a common though not an inherent part of a VPN connection.   
> 
>  Encryption：加密；inherent：固有的

- VPN的的作用
	1、 让世界上任意两台机器进入一个虚拟的局域网中
	2、翻墙

- 翻墙用途
	- 需要在vps上部署vpn server，客户端所有数据将经过虚拟网卡的加密封装后都转发给vps上的vpn server，由它来转发给目标服务器，这和ss server原理类似，**由vpn协议加密从而绕过GFW实现访问墙外网站**

### 通过PureVPN进行翻墙
- 通过[PureVPN官网](https://www.purevpn.com/)进行付费
(目前了解到最低的费用为0.99$ / mon,即一年为80块，可以使用两个账户，共可连接10个设备)
- 电脑端配置：在[PureVPN官网中下载软件](https://www.purevpn.com/download)（账号密码登录）/[电脑VPN配置](Windows IKEV Manual Configuration.pdf)
- 在安卓手机端配置：
	- Go to settings on your android phone 
• Tap on VPN
 • Insert Name PureVPN IPsec
• Type: Select IPSec Xauth PSK from drop down menu 
• Type server address: 
• IPSec pre-shared key: 12345678 
• Tap on Save 
• Tap on PureVPN IPSEC 
• Insert Username and Password provided by PureVPN 
• Select "Save account information" and tap on Connect 
• You should be Connected Now!!! 
Make sure you follow all the steps and use the recommended servers usny2-cn.sslwonders.com 
uswdc2-cn.sslwonders.com 
usla2-cn.sslwonders.com 
usut2-cn.sslwonders.com 
ussf2-cn.sslwonders.com 
us2-cn.sslwonders.com 
ukman2-cn.sslwonders.com 
ukl2-cn.sslwonders.com