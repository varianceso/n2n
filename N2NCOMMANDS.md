# 服务端命令
        supernode -l <listening port>

# 客户端用法
        edge -a 你需要的第2个ip地址 -c 你的虚拟网名 -k 你的密码  -l 服务器的ip地址:端口

# 例子
        服务端:
            sudo supernode -f -v -l 8899
        客户端:
            sudo edge -d n2n0 -c myn2n -k 123456789 -a 1.2.3.4 -l 192.168.1.174:8899
