# 服务端命令
        supernode -l <listening port>

# 客户端用法
        edge -a 你需要的第2个ip地址 -c 你的虚拟网名 -k 你的密码  -l 服务器的ip地址:端口

# 例子
        服务端:
            sudo supernode -f -v -l 6688
        客户端:
            sudo edge -d edge0 -c myn2n -k qwert@54321abcdefg -a 10.10.10.1 -l 180.76.148.9:6688 -M 1000

## Mac系统下安装，需要将openssl目录软链接到/usr/local/include目录下
        ln -s /usr/local/Cellar/openssl/1.0.2o_2/include/openssl /usr/local/include/ 
