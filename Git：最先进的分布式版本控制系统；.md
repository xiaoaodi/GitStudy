https://blog.csdn.net/jiahuan_/article/details/105933423

https://mp.weixin.qq.com/s/Bf7uVhGiu47uOELjmC5uXQ

Git：最先进的分布式版本控制系统；

GitHub与Git的区别：

Git一个是软件

GitHub是存放代码的网页



本地仓库：本地化操作

git config --l

git config --global user.name ""

git config --global user.email ""



mkdir 文件名  

cd 文件名



git init 初始化本地仓库   文件中会有.git的文件





git的常用指令操作

查看当前的状态：git status 

添加到缓冲区：git add 文件名

说明：git add 可以添加一个文件 也可以同时添加多个文件

语法1：git add 文件名 

语法2：git add 文件名1 文件名2 文件名3

语法3：git add . 添加当前文件的所有的内容

添加当前的文件或者目录到缓冲区



git commit -m "描述文件的字段"





3、时光穿梭机----版本回退

步骤：1.查看版本

指令：git log 

​       	git log --pretty =oneline  //使用第二种

​			2.回退操作

指令：git reset --hard 提交的编号（查看版本的一连串字符）



注意：回到过去之后，要再想回到之前最新的版本的时候，则需要使用指令去查看历史操作。

已得到最新的commit id

指令：git reflog    回到未来

小结：1.要想回到过去，必须先得到commit id ,再通过 git reset --hard 进行回退

2.要想回到未来，需要使用git reflog进行历史操作查看，得到最新的commit id;

3.在写回退指令的时候commit id可以不用写全，git自动的识别，但是不能写的太少，至少要写四个字符



二、两种常规的使用方式

1.基于http协议

a.创建空目录，mkdir  文件名



b.使用clone指令克隆线上的仓库到本地

语法：git clone 线上的仓库地址



c.在仓库上做对应的操作（提交暂存区、提交本地仓库、提交线上仓库、拉取线上仓库）

提交到线上仓库的指令 ：git push



可能在首次的时候出现了403错误

需要进行一个配置

url:设置修改

在设置好了之后再进行push指令

此时可以观察浏览器、刷新线上仓库的地址





拉取线上的仓库:git  pull



提醒：

 在每天上班的第一件事就是先git pull 

下班前要做的就是 git push



2、基于ssh（推荐）

实现：1、打开提示

2、生成私钥    # 进入 C:\Users\Administrator\.ssh 目录``# 生成公钥``ssh-keygen

3、上传公钥文件的内容（id_rsa.pub）

4、后面的操作和前面一致

不会有403的错误，基于ssh提交的效果







分区管理：分支之间是互不影响

分支的相关的指令

查看分支：git branch

注意：会一个标记’*‘

创建分支：git branch 分支名

切换分支：git checkout 分支名   

合并分支：git  merge  分支名  将其他分支的文件合并到房当前的分支

删除分支：git branch -d 分区名 注意：不能处于当前分区操作本分区；

操作完记得git push  将master分区提交到远程的仓库





**冲突的产生和解决**







**忽略文件**

![image-20210306085308659](C:\Users\hasee\AppData\Roaming\Typora\typora-user-images\image-20210306085308659.png)

在文件中使用#代表注释

## 忽略文件

有些时候我们不想把某些文件纳入版本控制中，比如数据库文件，临时文件，设计文件等

在主目录下建立".gitignore"文件，此文件有如下规则：

1. 忽略文件中的空行或以井号（#）开始的行将会被忽略。
2. 可以使用Linux通配符。例如：星号（*）代表任意多个字符，问号（？）代表一个字符，方括号（[abc]）代表可选字符范围，大括号（{string1,string2,...}）代表可选的字符串等。
3. 如果名称的最前面有一个感叹号（!），表示例外规则，将不被忽略。
4. 如果名称的最前面是一个路径分隔符（/），表示要忽略的文件在此目录下，而子目录中的文件不忽略。
5. 如果名称的最后面是一个路径分隔符（/），表示要忽略的是此目录下该名称的子目录，而非文件（默认文件或目录都忽略）。



```
#为注释*.txt        #忽略所有 .txt结尾的文件,这样的话上传就不会被选中！!lib.txt     #但lib.txt除外/temp        #仅忽略项目根目录下的TODO文件,不包括其它目录tempbuild/       #忽略build/目录下的所有文件doc/*.txt    #会忽略 doc/notes.txt 但不包括 doc/server/arch.txt
```





**分支操作**

```
# 列出所有本地分支git branch
# 列出所有远程分支git branch -r
# 新建一个分支，但依然停留在当前分支git branch [branch-name]
# 新建一个分支，并切换到该分支git checkout -b [branch]
# 合并指定分支到当前分支$ git merge [branch]
# 删除分支$ git branch -d [branch-name]
# 删除远程分支$ git push origin --delete [branch-name]$ git branch -dr [remote/branch]
```