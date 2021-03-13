

### Mysql 语言的学习

1、mysql的启动与关闭服务

win +R   

关闭 net stop mysql  开启 net start mysql 

win +R   输入services.msc 查看mysql状态

2、连接数据库

mysql -h localhost -P 3306 -u root -p  本地主机 端口  用户  密码

\s 查看当前数据库信息  

netstat -ano查看所有的端口信息；

netstat -ano|findstr "3306"查看指定的端口信息。

mysql -u root -p

\u = use  数据库名  使用数据库





show databases 显示所有的数据库

3、通过dos命令重新配置mysql   通过mysql安装目录中/bin/config文件

set character_set_client = gbk ; 重新配置客户端字符集编码

也可以修改my.ini文件  ，修改后重新启动mysql

```
show charset;查看mysql支持的字符集
```

4.查看库的字符集

语法：show database status from 库名 like  表名;

5.查看表的字符集

语法：show table status from 库名 like  表名;ale

6.查看表中所有列的字符集

语法：show full columns from com like xiao;

### 二、数据库和表的基本操作



1、操作数据库

create  database   [if not exist] 数据库名  ;

create database mydb1;创建mydb1数据库；

data文件中有数据信息；

create database mydb2 character set utf8;指定

create database mydb3 character set utf8 collation  utf8_bin ;;创建mydb3数据库,设置编码集并设置校验规则；





2、查看数据库

show databases 查看所有的数据库

show create database mydab2;查看前面创建的数据库的定义。



3、修改数据库

alter database mydb2 charcter set utf8 ;查看将字符集修改为utf8



4、删除数据库drop 

drop database mydb1;

5、选择数据库

use mydb2;没有退出的语法，直接切换 t

（1）select database()：查看数据库
（2）select version()：查看数据库版本
（3）select now()：查看数据库当前时间





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

​	create table  xiao (

​					id   int,

​					name  varchar(20)

);

 show  tables 表名字 查看表的信息。

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

1、主键约束：sh

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

create table  表名 {

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

create table  表名 {

​					id   int  primary key ,主键列   单字段的主键约束

​					name  varchar(20) unique  姓名不允许重复，

​					gender char(1) not null ,不允许性别列为空

​					primary key (id,name)两个字段共同作为主键 

} 

4、默认约束

create table  表名 {

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

create table  表名 {

​					id   int  primary key auto _increment ,主键列   id字段自动增长

​					name  varcha20) unique ,

​					gender char(1) not null ,不允许性别列为空

​					brithday  int ,

​					entry_date date,

​					constraint  brithday_a check (brithday>=0 and brithday  <=100  ),

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

**1、创建普通索引**

建表时创建索引

![image-20210310120324620](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310120324620.png)

create table user{

id int,

name char,

index (id)

}

查看是否用了索引explain select *from t1 where id =1

2、创建唯一的索引 



create table t1{

id int,

name char(20),

unique index unique_id(id ASC)

}



3、创建全文索引

create table t1{

id int,

name char(210),

fulltext index fulltext_name(name)

}engine=myisam;



4、创建多列索引

创建唯一的索引 

create table user1(

id int ,

name varchar (20),

index multi(id,name(20))

);

desc table user1;查看表的信息；

create table user1(

id int ,

name varchar (20),

space geometry not null,

spatial index sp(space)

)engine=myisam;

desc table user1;查看表的信息；

![image-20210310121041579](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310121041579.png)

![image-20210310121121372](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310121121372.png)

![image-20210310121256608](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310121256608.png)

create table book(

id int ,

name varchar (20),

space geometry not null

);

创建普通索引：

create index index_id on book(id);

![image-20210310121431279](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310121431279.png)

![image-20210310121507424](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310121507424.png)



![image-20210310121541803](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310121541803.png)

![image-20210310121721456](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310121721456.png)

![image-20210310121914773](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310121914773.png)



### 六、添加、更新、删除数据crud

**1、Insert** 

create table user1(

id int,

name varchar(20),

age int

);

insert into user1 (id,name,age) values(1,’肖飞’,22);

insert into user1 values (2,’李四‘,20),(3,’王五‘,30); 

//全部信息插入的情况下

![image-20210310122437704](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310122437704.png)

数据的值不应该超过规定大小，类型也应该一致

**2、update**

update user1 set age =100;

update user1 set age =200 where name = '肖飞';

update user1 set age =10 ,id =20where name = '王五';

update user1 set age=age+10 where name ='肖飞'；

![](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310122741530.png)

**3、delete(truncate 整表摧毁重新创建，auto_increment)**

delete from user1;

delete from user1 where id=2;

truncate user1;

![image-20210310123007667](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310123007667.png)

**4、select**

distinct 去除重复列

![image-20210310123135959](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310123135959.png)



select * from exam;

select name,english from exam;

select distinct english from exam;

select name as 名字,math+english+chinese  as 总分 from exam;

select name 名字,math+english+chinese  总分 from exam;

select name ,english+10 from exam;



![image-20210310123454880](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310123454880.png)

![image-20210310123623987](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310123623987.png)

![image-20210310123939047](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310123939047.png)

![image-20210310124536198](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310124536198.png)

![image-20210310124627847](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310124627847.png)

![image-20210310124806015](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310124806015.png)



![image-20210310125049248](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310125049248.png)

![image-20210310125016209](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310125016209.png)









分组查询

![image-20210310125236552](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310125236552.png)

![image-20210310125247204](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310125247204.png)

![image-20210310125749502](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310125749502.png)

![image-20210310130001675](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310130001675.png)

![image-20210310130012818](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310130012818.png)

![image-20210310130021684](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310130021684.png)

![image-20210310130119098](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310130119098.png)

![image-20210310130220737](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310130220737.png)

![image-20210310130257256](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310130257256.png)

![image-20210310130308609](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310130308609.png)







### 外键学习：

![image-20210310131007335](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310131007335.png)

![image-20210310131022450](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310131022450.png)

![image-20210310131450025](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310131450025.png)

![image-20210310131634586](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310131634586.png)

![image-20210310131808098](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310131808098.png)

![image-20210310140523876](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310140523876.png





![image-20210310141225454](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310141225454.png)



![image-20210310141319763](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310141319763.png)

![image-20210310141456137](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310141456137.png)

### 子查询：

![image-20210310155644516](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310155644516.png)

![image-20210310155751245](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310155751245.png)

![image-20210310155914384](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310155914384.png)

![image-20210310160022945](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310160022945.png)

![image-20210310160145868](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310160145868.png)







## 事务与存储过程

![image-20210310160215006](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310160215006.png)

![image-20210310160508836](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310160508836.png)

![image-20210310161052616](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310161052616.png)

**ACID**

![image-20210310161435786](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310161435786.png)

![image-20210310161606567](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310161606567.png)

![image-20210310161940907](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310161940907.png)

![image-20210310162327339](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310162327339.png)

![image-20210310162513306](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310162513306.png)

![image-20210310162535596](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310162535596.png)

![image-20210310163851394](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310163851394.png)





## 存储过程

![image-20210310164505426](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310164505426.png)

![image-20210310164859644](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310164859644.png)

![image-20210310165324207](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310165324207.png)

![image-20210310165611049](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310165611049.png)

![image-20210310165854692](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310165854692.png)

![image-20210310165942431](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310165942431.png)

![image-20210310170212975](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310170212975.png)

![image-20210310172018638](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172018638.png)

![](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172251979.png)



![image-20210310172300482](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172300482.png)

![image-20210310172329669](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172329669.png)

![image-20210310172414316](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172414316.png)

![image-20210310172443862](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172443862.png)

![image-20210310172524385](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172524385.png)

![image-20210310172535917](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172535917.png)





![image-20210310172648274](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172648274.png)

![image-20210310172801089](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172801089.png)

![image-20210310172834958](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172834958.png)

![image-20210310172906492](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172906492.png)

![image-20210310172946268](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310172946268.png)

![image-20210310173104851](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310173104851.png)







## 视图

![image-20210310173136026](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310173136026.png)

![image-20210310173324665](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310173324665.png)

![image-20210310173432147](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310173432147.png)

![image-20210310173540942](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310173540942.png)

![image-20210310173758987](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310173758987.png)



![image-20210310173936436](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310173936436.png)

![image-20210310174230652](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310174230652.png)

![image-20210310174401626](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310174401626.png)

**对真实表的操作**对视图的操作

![image-20210310174437645](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310174437645.png)

![image-20210310174522878](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310174522878.png)





## **8、数据的备份和还原**

![image-20210310174746885](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310174746885.png)

![image-20210310174804925](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310174804925.png)

![image-20210310174922442](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310174922442.png)

![image-20210310174906365](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310174906365.png)

![image-20210310175007842](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310175007842.png)





## 用户管理

![image-20210310175129858](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310175129858.png)

![image-20210310175203896](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310175203896.png)

![image-20210310175327757](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310175327757.png)

![image-20210310175441782](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310175441782.png)

![image-20210310175533356](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310175533356.png)

![image-20210310175658022](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310175658022.png)

![image-20210310180013933](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310180013933.png)

![](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310190217843.png)

![image-20210310190224855](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310190224855.png)

![image-20210310190334299](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310190334299.png)

![image-20210310190345608](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310190345608.png)

![image-20210310190437870](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310190437870.png)![image-20210310190521177](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310190521177.png)

![image-20210310190640197](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310190640197.png)

![image-20210310190752103](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310190752103.png)

![image-20210310190827283](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210310190827283.png)