# ssh 连接报错:debug1: expecting SSH2_MSG_KEX_ECDH_REPLY
        Edit /etc/ssh/ssh_config, uncomment the following lines

        Ciphers aes128-ctr,aes192-ctr,aes256-ctr,arcfour256,arcfour128,aes128-cbc,3des-cbc
        GSSAPIAuthentication yes
        GSSAPIDelegateCredentials no
        MACs hmac-md5,hmac-sha1,umac-64@openssh.com,hmac-ripemd160

        Add the following line
        HostKeyAlgorithms ssh-rsa,ssh-dss

        You should end up with your /etc/ssh/ssh_config file looking like this
        Host *
        Ciphers aes128-ctr,aes192-ctr,aes256-ctr,arcfour256,arcfour128,aes128-cbc,3des-cbc
        MACs hmac-md5,hmac-sha1,umac-64@openssh.com,hmac-ripemd160
        SendEnv LANG LC_*
        HashKnownHosts yes
        GSSAPIAuthentication yes
        GSSAPIDelegateCredentials no
        HostKeyAlgorithms ssh-rsa,ssh-dss
