# Instalando o necessário - Embarcados

Olá pessoal! Espero que estejam todos muito bem!

Nesse guia irei mostrar como instalar os programinhas necessários para realizar a tarefinha de embarcados do PS da computação.
Primeiramente, todas as vezes que estiver escrito:

```bash
 aqui_eh_um_comando
```

O sinal de **$** serve para indicar que o próximo texto é na verdade um comando que você deve inserir no terminal. Esta terminologia é muito utilizada, e irei fazer uso da mesma.

Agora vamos de fato ao tutorial!

# Índice

 1. [Windows](#windows)
 2. [MacOS](#macos)
 3. [Linux](#linux)

# Windows

## GCC e Make

No Windows, instale o [MSYS2](https://www.msys2.org/) seguindo as instruções presentes no site. Após isso, baixe o GCC e o Make utilizando o terminal do MSYS2 utilizando o seguinte comando:

```bash
 pacman -S gcc make
```

Depois, vocês precisam colocar a pasta do MSYS2 nas variáveis de ambiente do Windows. Para isso, faça:

  1. Vá para Painel de Controle > Sistema e Segurança > Sistema > Configurações avançadas do sistema.
  2. Na janela que abriu, clique em "Variáveis de ambiente".
  3. Na parte de "Variáveis do sistema", encontra a variável Path, selecione-a e clique em "Editar".
  4. Clique em "Novo"
  5. Digite o caminho para os executáveis MSYS2 (normalmente C:\msys64\usr\bin).
  6. Mova o caminho para cima no PATH, deixando no primeiro lugar.
  7. Clique em "Ok".

Finalmente, para testar se a instalação foi feita corretamente, basta abrir o Prompt de Comando (não o MSYS2, o cmd mesmo) e insira o seguinte comando:

```bash
 gcc -v
```

Algo parecido com isso deve aparecer:

```bash
 Using built-in specs.
 COLLECT_GCC=gcc
 COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-pc-msys/6.4.0/lto-wrapper.exe
 Target: x86_64-pc-msys
 Configured with: /msys_scripts/gcc/src/gcc-6.4.0/configure --build=x86_64-pc-msys --prefix=/usr --libexecdir=/usr/lib --enable-bootstrap --enable-shared --enable-shared-libgcc --enable-static --enable-version-specific-runtime-libs --with-arch=x86-64 --with-tune=generic --disable-multilib --enable-__cxa_atexit --with-dwarf2 --enable-languages=c,c++,fortran,lto --enable-graphite --enable-threads=posix --enable-libatomic --enable-libcilkrts --enable-libgomp --enable-libitm --enable-libquadmath --enable-libquadmath-support --enable-libssp --disable-win32-registry --disable-symvers --with-gnu-ld --with-gnu-as --disable-isl-version-check --enable-checking=release --without-libiconv-prefix --without-libintl-prefix --with-system-zlib --enable-linker-build-id --with-default-libstdcxx-abi=gcc4-compatible
 Thread model: posix
 gcc version 6.4.0 (GCC)
```

Nesse mesmo prompt, insira o seguinte comando:

```bash
 make -v
```

Algo parecido com isso deve aparecer também:

```bash
 GNU Make 4.2.1
 Built for x86_64-pc-msys
 Copyright (C) 1988-2016 Free Software Foundation, Inc.
 License GPLv3+: GNU GPL version 3 or later 
 This is free software: you are free to change and redistribute it.
 There is NO WARRANTY, to the extent permitted by law.
```

## ARM-GCC

Primeiramente, faça o download do [arm-gcc](https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-win32.exe?rev=29bb46cfa0434fbda93abb33c1d480e6&hash=B2C5AAE07841929A0D0BF460896D6E52) e siga a instruções normais do Windows.

Após isso, é preciso colocar a pasta do arm-gcc nas variávies de ambiente do Windows (similar ao que foi feito com o MSYS2). Faça então:
 1. Vá para Painel de Controle > Sistema e Segurança > Sistema > Configurações avançadas do sistema.
 2. Na janela que abriu, clique em “Variáveis de ambiente”.
 3. Na parte de “Variáveis do sistema”, encontra a variável Path, selecione-a e clique em “Editar”.
 4. Clique em “Novo”.
 5. Digite o caminho para os executáveis do ARM-GCC (provavelmente C:\Program Files (x86)\GNU Tools ARM Embedded\8 2021-q4-major\bin).
 6. Clique em “OK”.

Para testar se deu certo a instalação, digite no Promp de Comando (cmd):

```bash
 arm-none-eabi-gcc --version
```

Algo parecido com isso deve aparecer:

```bash
 arm-none-eabi-gcc.exe (GNU Tools for Arm Embedded Processors 10.3-2021-q4-major) 8 2.1 20181213 (release) [gcc-8-branch 267074 revision]
 Copyright (C) 2021 Free Software Foundation, Inc.
 This is free software; see the source for copying conditions.  There is NO
 warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## STM32CubeMX e STM32CubeProgrammer

Faça o download do [STM23CubeMX](https://www.st.com/b/en/development-tools/stm32cubemx.html) e o [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html). Será necessário criar uma conta no site da ST e então clicar em "Get Software" (escolha sempre a última versão - Latest Version). Siga a instruções do instalador normalmente.

Agora será necessário adicionar o caminho do STM32CubeProgrammer na variável de ambiente Path (basicamente o que foi feito no gcc e msys2).

1. Vá para Painel de Controle > Sistema e Segurança > Sistema > Configurações avançadas do sistema.
2. Na janela que abriu, clique em “Variáveis de ambiente”.
3. Na parte de “Variáveis do sistema”, encontra a variável Path, selecione-a e clique em “Editar”.
4. Clique em “Novo”.
5. Digite o caminho para os executáveis do STM32CubeProgrammer (provavelmente C:\Program Files (x86)\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin).
6. Clique em “OK”.

Para o CubeMX, deve-se criar uma nova variável com o nome CUBE_PATH:

1. Na janela de Variáveis de Ambiente, clique em "Novo"
2. Digite CUBE_PATH como nome da variável
3. Coloque o caminho do CUbeMX como valor da variável (normalmente C:\Program Files (x86)\STMicroelectronics\STM32Cube\STM32CubeMX)
4. Clique em Ok. A variável deverá aparecer na lista de variáveis de ambiente.

Para checarmos se o STM32CubeProgrammer foi instalado corretamente, abra um terminal qualquer e rode:

```bash
 STM32_Programmer_CLI --version
```

Algo assim deve aparecer:

```bash
 -------------------------------------------------------------------
                        STM32CubeProgrammer v2.2.1                  
   -------------------------------------------------------------------

STM32CubeProgrammer version: 2.2.1
```

E para ver se a variável CUBE_PATH foi criada corretamente, insira o seguinte comando:

```bash
 echo %CUBE_PATH%
```

O caminho até o executável do CubeMX que você colocou será mostrado se tudo deu certo.

# MacOs

## GCC e Make

Ao realizar a instalação do Git com o Xcode Command Line Tools, o GCC e o Make já estarão instalados!

Para checar, insira no terminal:

```bash
 make --version
 gcc --version
```

## ARM-GCC

Faça o download do [arm-gcc](https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-mac.tar.bz2?rev=58ed196feb7b4ada8288ea521fa87ad5&hash=F095D2C3D1659B531BE482826BE4A6E1) e extraia em algum lugar que achar confortável.

Após isso, é preciso colocar a pasta do arm-gcc nas variáveis de ambiente. Para isso, faça:

Verifique a existência do arquivo ".bash_profile" (note o ponto no começo do nome) no seu diretório home, também simbolizado por _~_, ou seja veja se o arquivo "~/.bash_profile" existe. Senão crie ele, fazendo no terminal:

```bash
 touch .bash_profile
```

Então abra o arquivo criado ou já existente:

```bash
 open .bash_profile
```

E insira no final do arquivo:

```bash
 export PATH=${PATH}:/gcc-arm-none-eabi-10.3-2021.10/bin/
```

Salve o arquivo e para aplicar as alterações você pode abrir um novo terminal ou fazer:

```bash
 source ~/.bash_profile
```

Para testar se funcionou, insira:

```bash
 arm-none-eabi-gcc --version
```

Algo parecido com isso deve aparecer:

```bash
 arm-none-eabi-gcc (GNU Tools for Arm Embedded Processors 10.3-2021-q4-major) 10.3.0 20211025 (release) [arm 277599 arm-10-branch revision]
 Copyright (C) 2021 Free Software Foundation, Inc.
 This is free software; see the source for copying conditions.  There is NO
 warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## STM32CubeProgrammer e STM32CubeMX

Faça o download do [STM23CubeMX](https://www.st.com/b/en/development-tools/stm32cubemx.html) e o [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html). Será necessário criar uma conta no site da ST e então clicar em "Get Software" (escolha sempre a última versão - Latest Version). Extraia onde desejar.

Agora para instalar o CubeProgrammer, primeiramente, rode o seguinte comando no terminal:

```bash
 sudo spctl --master-disable
```

Então, vá em “Apple menu” > “System Preferences” > “Security & Privacy” > “General tab”. Aí em “Allow applications downloaded from:” selecione “Anywhere”.

Depois disso, vá no direório onde você extraiu o programa e excute o arquivo de setup clicando duas vezes nele, o arquivo SetupSTM32CubeProgrammer-X.X.X.app (os X estão substituindo o número da versão), ele vai te guiar no processo de instalação.

Se a instalação falhar, estando no local onde você extraiu a pasta, rode a linha de comando:

```bash
 ./SetupSTM32CubeProgrammerX.X.X.app/Contents/MacOs/SetupSTM32CubeProgrammer-X_X_X_macos
```

Para o CubeMX serão feitas algumas coisas semelhantes. Estando dentro da pasta que você extraiu, tendo privilégios de administrador, execute o arquivo de setup, clicando duas vezes no arquivo SetupSTM32CubeMX-X.X.X.app, isso iniciará a ferramenta de instalação.

Caso dê algum erro, estando dentro do diretório que você estraiu a pasta, execute o arquivo .exe fazendo da seguinte forma no terminal (novamente, os X substituem a versão):

```bash
 sudo java -jar SetupSTM32CubeMX-X.X.X.exe
```

Após a instalação, crie uma variável chamada CUBE_PATH com o local de instalação do CubeMX nas configurações da shell que você utiliza. A pasta deve conter o executável STM32CubeMX. O procedimento é similar a adicionar diretórios no PATH, mas, nesse caso, você vai criar uma variável. Então você vai fazer:

Coloque isso no final do arquivo "~/.bash_profile":

```bash
export CUBE_PATH=/STM32CubeMX
```

Adicione o caminho do CubeProgrammer na variável de ambiente Path, como feito anteriormente para o arm-gcc, adicionando essa linha:

```bash
 export PATH=$PATH:/STM32CubeProgrammer.app/Contents/MacOs/bin
```

O local de instalação provavelmente será a pasta /Applications.

Pra ver o CubeProgrammer está no PATH, abra um terminal qualquer e rode:

```bash
 STM32_Programmer_CLI --version
```

E então, algo assim deve surgir:

```bash
 -------------------------------------------------------------------
                        STM32CubeProgrammer v2.2.1                  
      -------------------------------------------------------------------

STM32CubeProgrammer version: 2.2.1
```

Para ver se a variável CUBE_PATH foi criada corretamente, abra um terminal e rode:

```bash
 echo $CUBE_PATH
```

O terminal deve mostrar o caminho até o executável.

# Linux

## GCC e Make

Como Linux envolve várias distribuições, para cada uma delas irei mostrar qual é o comando a se inserir dependendo do gerenciador de pacotes da sua distro.

### Ubuntu

```bash
 sudo apt update
 sudo apt install gcc make
```

### Fedora

```bash
 sudo dnf upgrade
 sudo dnf gcc make 
```

### Arch Linux

```bash
 sudo pacman -Syu
 sudo pacman -S gcc make
```

### FreeBSD

```bash
 pkg update
 pkg install gcc make
```

Para as demais distribuições, recomendo vocês acessarem esse [site](https://git-scm.com/download/linux). Lá vocês encontrarão os comandos certinhos para cada distro e também como fazer a instalação através dos binários do programa.

Para saber se a instalação foi feita corretamente, insira o seguinte comando no terminal:

```bash
 gcc --version
 make --version
```

O terminal irá cuspir a versão do GCC e do Make que foram instaldas.

## ARM-GCC

Faça o download do [arm-gcc](https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2?rev=78196d3461ba4c9089a67b5f33edf82a&hash=5631ACEF1F8F237389F14B41566964EC) e extraia em algum lugar que achar confortável.

Após isso, é preciso colocar a pasta do arm-gcc nas variáveis de ambiente. Para isso, faça:

Verifique a existência do arquivo ".bash_profile" (note o ponto no começo do nome) no seu diretório home, também simbolizado por _~_, ou seja veja se o arquivo "~/.bash_profile" existe.  Para isso, faça:

```bash
 test -e ~/.bash_profile && echo file found || echo file not found
```

Caso o terminal retorne "file found", signfica que ele encontrou o arquivo. Já se ele printar "file not found", então ele não o encontrou.

Senão existir, crie ele fazendo no terminal:

```bash
 touch .bash_profile
```

Então abra o arquivo criado ou já existente:

```bash
 open .bash_profile
```

E insira no final do arquivo:

```bash
 export PATH=${PATH}:/gcc-arm-none-eabi-10.3-2021.10/bin/
```

Salve o arquivo e para aplicar as alterações você pode abrir um novo terminal ou fazer:

```bash
 source ~/.bash_profile
```

Para testar se funcionou, insira:

```bash
 arm-none-eabi-gcc --version
```

Algo parecido com isso deve aparecer:

```bash
 arm-none-eabi-gcc (GNU Tools for Arm Embedded Processors 10.3-2021-q4-major) 10.3.0 20211025 (release) [arm 277599 arm-10-branch revision]
 Copyright (C) 2021 Free Software Foundation, Inc.
 This is free software; see the source for copying conditions.  There is NO
 warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## STM32CubeProgrammer e STM32CubeMX

Faça o download do [STM23CubeMX](https://www.st.com/b/en/development-tools/stm32cubemx.html) e o [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html). Será necessário criar uma conta no site da ST e então clicar em "Get Software" (escolha sempre a última versão - Latest Version). Extraia onde desejar.

Antes de continuar, é necessário instalar Java. Para isso, execute os seguintes comandos no terminal:
Para instalar o OpenJDK 8

```bash
 sudo apt install openjdk-8-jre-headless
```

Para definir o OpenJDK 8 como o padrão do Java Runtime Engine:

```bash
 sudo update-alternatives --config java
```

No terminal vai aparecer um print de escolha da versão do Java Runtime Engine, pedindo para escolher entre "0", "1" e "2". Escolha aquela correspondente ao _Java 8_ .

Para instalar o OpenJFX

```bash
 sudo apt purge openjfx
 sudo apt install openjfx=8u161-b12-1ubuntu2 libopenjfx-jni=8u161-b12-1ubuntu2 libopenjfx-java=8u161-b12-1ubuntu2
 sudo apt-mark hold openjfx libopenjfx-jni libopenjfx-java
```

Agora para instalar o CubeProgrammer, vá no direório onde você extraiu o programa e excute o arquivo de setup, dessa forma (os X são só pra substituir o número da versão):

```bash
 sudo ./SetupSTM32CubeProgrammer-X.X.X.linux
```

OBS: Pode ser que aqui você tenha baixado sem a extensão ".linux". Se apareceu ago como "SetupSTM32CubeMX-X.X.X" também está correto e basta rodar o mesmo comando porém sem o final ".linux".

Então diga as instruções na tela.

Além disso é necessário fazer mais duas coisinhas, para lidarmos com dispositivos USB.

Primeiramente é necessário instalar o libusb1.0, fazendo:

```bash
 sudo apt install libusb-1.0-0-dev
```

Depois, será necessário colocar alguns arquivos de regras para lidar com dispositivos USB. Para isso, vá onde você instalou o CubeProgrammer pelo terminal, entre na pasta Drivers e dentro dessa pasta, na pasta rules, faça:

```bash
 sudo cp *.* /etc/udev/rules.d
```

Para o CubeMX serão feitas algumas coisas semelhantes. Estando dentro da pasta que você extraiu, para poder executar o arquivo, faça (substitua X.X.X pela versão baixada):

```bash
 chmod 777 SetupSTM32CubeMX-X.X.X.linux
```

Depois disso, execute o arquivo fazendo:

```bash
 sudo ./SetupSTM32CubeMX-X.X.X.linux
```

Siga as instruções na tela.

É possível que ocorram alguns erros, porque o CubeMX depende de bibliotecas de sistemas de 32 bits. Instale a biblioteca libc6-i386 para resolver o problema:

```bash
 sudo apt install libc6-i386
```

Tente executar o arquivo novamente.

Após a instalação, crie uma variável chamada CUBE_PATH com o local de instalação do CubeMX nas configurações da shell que você utiliza. A pasta deve conter o executável STM32CubeMX. O procedimento é similar a adicionar diretórios no PATH, mas, nesse caso, você vai criar uma variável. Então você vai fazer:

Coloque isso no final do arquivo ~/.bashrc:

```bash
 export CUBE_PATH=/STM32CubeMX
```

Adicione o caminho do CubeProgrammer na variável de ambiente Path, como feito anteriormente para o arm-gcc, adicionando essa linha no arquivo .bash_profile:

```bash
 export PATH=$PATH:/STM32CubeProgrammer/bin
```

Pra ver se o CubeProgrammer está no PATH, abra um terminal qualquer e rode:

```bash
 STM32_Programmer_CLI --version
```

E então, algo assim deve surgir:

```bash
 -------------------------------------------------------------------
                        STM32CubeProgrammer v2.2.1                  
      -------------------------------------------------------------------

STM32CubeProgrammer version: 2.2.1
```

Para ver se a variável CUBE_PATH foi criada corretamente, abra um terminal e rode:

```bash
 echo $CUBE_PATH
```

O terminal deve mostrar o caminho até o executável.
