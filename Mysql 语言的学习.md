### Mysql 语言的学习

1、mysql的启动与关闭服务

win +R   

关闭 net stop mysql  开启 net start mysql 

win +R   输入services.msc 查看mysql状态

2、连接数据库

mysql -h localhost -P 3306 -u root -p  本地主机 端口  用户  密码

\s 查看当前数据库信息  

mysql -u root -p

\u = use  数据库名  使用数据库

show database 显示所有的数据库

3、通过dos命令重新配置mysql   通过mysql安装目录中/bin/config文件

set character_set_client = gdk ; 重新配置客户端字符集编码

也可以修改my.ini文件  ，修改后重新启动mysql



### 二、数据库和表的基本操作

1、操作数据库

create  database   [if not exist] 数据库名  ;

create database mydb1;创建mydb1数据库；

data文件中有数据信息；

create database mydb2 character set gdk;指定编码集

create database mydb3 character set utf8 collation  utf8_bin ;;创建mydb3数据库,设置编码集并设置校验规则；





2、查看数据库

show database 查看所有的数据库

show create database mydab2;查看前面创建的数据库的定义。



3、修改数据库

alter database mydb2 charcter set utf8 ;查看将字符集修改为utf8



4、删除数据库

drop database mydb1;

5、选择数据库

use mydb2;没有退出的语法，直接切换 

select databse()查看当前所选的数据库。





### 三、数据库中表的操作

1、mysql常用的数据类型

整数类型：int , tinyint ,smallint mediumint   ,int ,   bigint 

小数类型：float  double  定点 decimal(m,a)整数m 小数a

时间与日期：

year  date time  datetime  timestamp

current_timestamp当前的时间与日期

char 和 varchar 

char(10)固定10个字节，只用一个也占用了10个字节     （检索和查询速率问题）

varchar(20)变长的数据类型，最大的长度，实际用的内存，占用4个则只用4个字节。

binary varbinary二进制  65535 

大文本text

blob数据量大的类型

enum枚举类型  之存取了数据编号

set类型  

bit 类型   bit(1);一位的二进制

1、增加表  utf中三个字节代表一个字

​	create table  表名 {

​					id   int,

​					name  varchar(20)，

​					gender char(1),

​							brithday  date,

​						entry_date date,

​							job _varchar(50),

​							salary double,

​						resume text  ,

}  show  table 表名字 查看表的信息。

2、查看表

查看表的基本结构：desc tab_name ;

查看所有的表 show tables;

查看建表语句：show  create table  表名

3、修改表

alter table 表名 add ;

alter table employ add image blob ;增加一列

alter table employ modify job varchar(80),修改列

alter table employ drop gender ,删除列

alter table employ to user ；修改表名

alter table  user character ser utf8; 设置字符集为utf 8

alter table user change name username varchar(20),对name列重新进行命名username

4、删除表

drop table user;删除user表

### 四、表的约束

0、primary key 主键约束，用于唯一的标识对应的记录。

​	foreign key 外键约束

​	not null 非空约束

​	unique 唯一性约束

​	default  默认值约束，用于设置字段的默认值

1、主键约束：

create table  表名 {

​					id   int  primary key ,主键列   单字段的主键约束

​					name  varchar(20)，

​					gender char(1),

​					brithday  date,

​					entry_date date,

​					job _varchar(50),

​					salary double,

​					resume text  , 

​					primary key (id,name)两个字段共同作为主键 

} 

2、非空约束

reate table  表名 {

​					id   int  primary key ,主键列   单字段的主键约束

​					name  varchar(20) unique  xin，

​					gender char(1) not null ,不允许性别列为空

​					brithday  date,

​					entry_date date,

​					job _varchar(50),

​					salary double,

​					resume text  , 

​					primary key (id,name)两个字段共同作为主键 

} 

3、唯一约束

reate table  表名 {

​					id   int  primary key ,主键列   单字段的主键约束

​					name  varchar(20) unique  姓名不允许重复，

​					gender char(1) not null ,不允许性别列为空

​					primary key (id,name)两个字段共同作为主键 

} 

4、默认约束

reate table  表名 {

​					id   int  primary key ,主键列   单字段的主键约束

​					name  varchar(20) unique  xin，

​					gender char(1) not null ,不允许性别列为空

​					brithday  date,

​					entry_date date,

​					job _varchar(50)  default '实习生', 这一列有一个默认值实习生，没给这列赋值时

​					salary double,

​					resume text  , 

​					primary key (id,name)两个字段共同作为主键 

} 

5、设置表的字段值自动增加

reate table  表名 {

​					id   int  primary key auto _increment ,主键列   id字段自动增长

​					name  varchar(20) unique  xin，

​					gender char(1) not null ,不允许性别列为空

​					brithday  date,

​					entry_date date,

​					job _varchar(50)  default '实习生', 这一列有一个默认值实习生，没给这列赋值时

​					salary double,

​					resume text  , 

​					primary key (id,name)两个字段共同作为主键 

} 

### **五、索引**

字典的列子  字典前的查找音序表

1、普通索引

2、唯一性索引

3、全文索引

4、单列索引

5、多列索引

6、空间索引

索引不一定是好的，会占用磁盘空间，创建和维护根据数据量的增加而增加

1、创建普通索引

建表时创建索引

create table t1{



}

