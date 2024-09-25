# Scheduling Policy to the Linux Kernel
# O que é o Escalonador do Linux?
O escalonador é um componente essencial em sistemas operacionais modernos, responsável por determinar qual processo ou thread será executado pela CPU em um dado momento. Com múltiplos processos competindo por tempo de processamento, o escalonador organiza essa fila, priorizando e distribuindo os recursos de forma eficiente. A maioria dos algoritmos de escalonamento no Linux baseia-se em prioridades para garantir que os processos sejam executados de forma justa e otimizada, proporcionando um uso balanceado e eficaz da CPU e dos dispositivos de entrada e saída (E/S).


# Tutorial
1. Primeiramente usamos uname para o kernel do sistema: 

```uname -r```

2. Utilizando o comando wget e o link do kernel.org conseguimos o código do kernel:
```wget https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/snapshot/linux-5.15.tar.gz```

3. Extraia o arquivo .tar:

```tar -xzvf linux-5.15.tar.gz```

4.  Instalar a biblioteca curses e algumas outras ferramentas para nos ajudar a compilar :

```sudo apt-get install kernel-package libncurses5-dev fakeroot```

5. Aplicar as mudanças de implementação e criação de novos arquivos:

/include/uapi/linux/sched.h  

/kernel/sched.h 

/kernel/core.c 

/kernel/sched_background.c

/kernel/sched_background.h

6. Configure o kernel
```
Possui duas opções de configurações usando cp /boot/config-$(uname -r) .config que baixa as configurações do kernel atual,
logo se o kernel não for o mesmo, ou caso tenha um kernel especifico,
será necessário modificações, ou usando make defconfig vem configurações padrões, onde drivers e outros utensílios estão desativados.
Utilize make menuconfig para modificações desejadas, caso não tenha pode pular
```
7. Compile o kernel

```make -j$(nproc)```

8. Instale o kernel
```
sudo make modules_install
sudo make install
```
10. Atualize o grub e reinicie(segurando shift para selecionar o kernel desejado)
```
sudo update-grub
sudo reboot
```
11. Verifique a nova versão do kernel
```
uname -r
```
12. Teste a nova política
```
Criar dois arquivos teste_background.c e teste_performance.c para os testes.
Após a criação basta usar os comandos:
gcc -o teste_background teste_background.c
sudo ./teste_background

gcc -o teste_performance teste_performance.c
sudo ./teste_performance
```
