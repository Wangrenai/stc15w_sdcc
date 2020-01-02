##前提

- 现在用的是超极本，USB接口还需另外拓展，采用的是ARM的cpu,使用的是树莓派3B，进行测试；
- windows下keil软件是好用，到时毕竟是商业软件，破解的期限将至。

##安装环境搭建

- 自动安装

```
sudo apt-get  install sdcc sdcc-doc

```

编译器头文件目录/usr/share/sdcc/include下

- 手动安装

```
下载：http://sdcc.sourceforge.net/snap.php
下载解压；
将其添加到环境变量中；
```


- 烧录工具

`推荐使用stcgal`
```
https://github.com/grigorig/stcgal
```
自动安装
```
pip3 install stcgal

```


##安装make

使用的是makefile
###自动安装
```
sudo apt install make
```

###手动安装

```
1、查看make版本，在浏览器搜索：ftp://ftp.gnu.org/gnu/make/ 可进入下载页面

2、进入文件存放路径：cd /home/tool

3、下载安装包：wget http://ftp.gnu.org/gnu/make/make-3.81.tar.gz

4、解压压缩包：tar -zvxf make-3.81.tar.gz

5、进入解压文件目录：cd make-3.81

6、系统配置make：./configure --prefix=/usr/local/make-3.81

7、执行编译：make

8、安装make：sudo make install  

这里加上sudo是因为这一步会将编译好的make 3.81版本的文件转移到/usr/local/make-3.81目录下，这个目录只有root有权限写入。因此需要sudo权限

9、查看安装是否成功：make -v 会显示 GNU Make 3.81则说明安装成功


```
##使用例程

```
git clone https://github.com/Wangrenai/stc15w_sdcc.git

cd stc51_prj_more_files/src

make

```
自动在主目录生成文件夹`bin``build`
`bin`存放.bin文件用于烧录MCU
`build`存放编译生成的其他文件

`make clean` 清理文件,不会删除文件夹;
`make call`删除所有文件；

希望对搭建有帮助



