# 服务端命令
        supernode -l <listening port>

# 客户端用法
        edge -a 你需要的第2个ip地址 -c 你的虚拟网名 -k 你的密码  -l 服务器的ip地址:端口

# 例子
        服务端:
            sudo supernode -f -v -l 16575
        客户端:
            sudo edge -d edge0 -c myn2n -k qwert@54321abcdefg -a 10.10.10.1 -l 180.76.148.9:16575
