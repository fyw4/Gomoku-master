# Gomoku-master

# 介绍
基于Linux系统上运行的五子棋小游戏，本项目基于https://github.com/youngyangyang04/Gomoku项目基础上增改，遵循Apache Licence 2.0协议。

# 编译
进入根目录执行以下命令生成 server和client可执行文件：
```bash
make
```

# 运行
编译后在本地启动两个终端窗口分别执行server和client：
```bash
./bin/server
./bin/client
```


# 运行效果：

server：

0 1 2 3 4 5 6 7 8 9

1 _ _ _ _ _ _ _ _ _

2 _ _ _ _ _ _ _ _ _

3 _ _ _ _ _ _ _ _ _

4 _ _ _ _ _ _ _ _ _

5 _ _ _ _ _ _ _ _ _

6 _ _ _ _ _ _ _ _ _

7 _ _ _ _ _ _ _ _ _

8 _ _ _ _ _ _ _ _ _

9 _ _ _ _ _ _ _ _ _

五子棋游戏开始

请等待client下棋

client：

client start

client 请下棋：

1 1

0 1 2 3 4 5 6 7 8 9

1 x _ _ _ _ _ _ _ _

2 _ _ _ _ _ _ _ _ _

3 _ _ _ _ _ _ _ _ _

4 _ _ _ _ _ _ _ _ _

5 _ _ _ _ _ _ _ _ _

6 _ _ _ _ _ _ _ _ _

7 _ _ _ _ _ _ _ _ _

8 _ _ _ _ _ _ _ _ _

9 _ _ _ _ _ _ _ _ _

