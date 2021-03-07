### vs不能下载的问题

今天安装visual studio,在线安装需要使用Installer,但是一直处于无法下载的状态。。。在网上搜索了好多方法，都不行，比如修改DNS,换用手机热点，都不行。然后看网上说去查看日志C:\Users\xxx\AppData\Local\Temp
打开dd_bootstrapper_xxx（时间戳）.log发现：

VisualStudio Bootstrapper:2021/1/18 14:22:53: WebClient error 'TrustFailure' - proxy setting 'Default' - 'https://aka.ms/vs/16/release/installer'.
VisualStudio Bootstrapper:2021/1/18 14:22:53: WebClient failed in 'https://aka.ms/vs/16/release/installer' with '基础连接已经关闭: 未能为 SSL/TLS 安全通道建立信任关系。' - 'https://aka.ms/vs/16/release/installer'.
VisualStudio Bootstrapper:2021/1/18 14:22:53: WebClient failed attempting to access https://aka.ms/vs/16/release/installer via 127.0.0.1
VisualStudio Bootstrapper:2021/1/18 14:22:53: Download failed using WebClient engine. System.Net.WebException: 基础连接已经关闭: 未能为 SSL/TLS 安全通道建立信任关系。 ---> System.Security.Authentication.AuthenticationException: 根据验证过程，远程证书无效。
我用浏览器直接访问aka.ms会报隐私错误，所以这就是问题所在！

解决方法
如果上面的方法对你都没用：试试在C:\Windows\System32\drivers\etc\hosts文件里添加aka.ms的映射,随便在ip查询网址上查aka.ms的ip,我查到的是23.205.239.104，然后我这里建议安装一个notepad++，方便处理各类文件，而且只用一次授予管理员权限，下载地址，安装教程：

23.205.239.104 aka.ms
1
再次运行vs安装程序就可以了。
（花了将近一天的时间了，终于解决了，一定要记录下来
————————————————
版权声明：本文为CSDN博主「weixin_45642452」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_45642452/article/details/112782695