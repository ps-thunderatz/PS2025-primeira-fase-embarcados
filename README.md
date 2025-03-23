# Enunciado - Embarcados

Nessa tarefinha vocês devem fazer um programa para controlar o microcontrolador `STM32F103C8T6` da STMicroelectronics.

Para realizar a tarefinha, é necessário antes seguir os tutoriais existentes na pasta `tutoriais/`. Lá, você encontra o [guia de instalação](tutoriais/guia_de_instalacao.md) para instalar os programas necessários para realizar a tarefinha. Dentro da mesma pasta, no arquivo [teoria](tutoriais/teoria.md), você encontra também a teoria, que explica os conceitos de sistemas embarcados e como é feita a programação de dispositivos embarcados com microcontroladores usados na ThundeRatz.

## Índice

1. [Qual comportamento deve ser implementado](#-qual-comportamento-deve-ser-implementado)

2. [Execução da tarefa](#%EF%B8%8F-execução-da-tarefa)

    - 1ª parte: Configurando os arquivos do Cube
    - 2ª parte: Escrevendo o código

3. [Organização do repositório](#%EF%B8%8F-organização-do-repositório)

    - Estrutura dos arquivos

4. [Funções](#-funções)

    - Funções prontas
    - Funções a serem implementadas

-   [Apêndice A - Configuração do STM32CubeMX](#apêndice-a---configuração-do-stm32cubemx)

    -   Configurando Led
    -   Configurando Botões
    -   Configurando ADC

## ✨ Qual comportamento deve ser implementado

A tarefinha consiste em um controle de videogame, que contém um analógico, um LED e dois botões. A placa usada é a plaquinha do nRFDongle, do ThunderVolt. O analógico será lido, ter seu valor processado e enviado pelo USB.

> O analógico é um componete que possui dois potenciômetros, um para cada eixo, X e Y. Leia mais sobre analógicos [aqui](https://mundoprojetado.com.br/como-e-um-joystick-por-dentro/) e sobre potenciômetros [aqui](https://pt.wikipedia.org/wiki/Potenci%C3%B4metro).

-   [Vídeo de demonstração](https://youtube.com/shorts/XRpv_pIOct8?feature=share)

## 🖥️ Execução da tarefa

Certo, mas como fazer isso?

### **1ª parte** - Configurando os arquivos do Cube

Como vocês viram na aulinha de embarcados, antes de programar o seu microcontrolador é preciso configurar o arquivo do cube, setando os pinos do micro com as funções que precisamos no nosso projeto. O arquivo a ser configurado é o `dongle_joystick_v1.ioc` localizado na pasta `cube/`. As instruções de configuração do Cube estão mais detalhadas no [Apêndice A](#apêndice-a---configuração-do-stm32cubemx).
Configurem os pinos conforme descrito abaixo:

-   LED - GPIO Output - PC12
-   Botão 1 - GPIO Input - PA8
-   Botão 2 - GPIO Input - PB15

-   Joystick X - ADC - PA1 (ADC1_IN1)
-   Joystick Y - ADC - PA2 (ADC1_IN2)
-   Botão Joystick - GPIO Output - PA9

> Em algumas plaquinhas o botão do joystick está com problema :p

Os outros periféricos da plaquinha, como o USB já estão configurados.

### **2ª parte** - Escrevendo o código

Usando um editor de texto (de preferência o VSCode), implemente as funções dos arquivos `led.cpp`, `button.cpp`, `joystick.cpp`. A implementação do USB já está feita.

## 🗂️ Organização do repositório

Estrutura dos arquivos:

-   `mcu.hpp` e `mcu.cpp`: Esses arquivos possuem as funções que configuram o microcontrolador, e NÃO devem ser editados.
-   `utils.hpp`: Esse arquivo pode ser incluído onde vocês quiserem, ele contém diversas funções matemáticas úteis que podem facilitar as contas de vocês. Sintam-se à vontade para incrementá-lo se acharem necessário. As funções usadas nesse arquivo são feitas usando o que chamamos de operador ternário, que nada mais é que uma forma de simplificar if's e else's.
-   `main.cpp`: Aqui vocês farão a inicialização dos periféricos e o _loop_ principal do programa.
-   `led.cpp`: Aqui vocês implementarão as funções relacionadas ao LED.
-   `button.cpp`: Aqui vocês implementarão as funções relacionadas ao botão.
-   `joystick.cpp`: Aqui vocês implementarão as funções relacionadas ao joystick, sendo elas a inicialização do ADC e a leitura de seu valor.

> Os arquivos do código de vocês se encontram nas pastas `src/` (onde ficam os `.cpp`) e `inc/` (onde ficam os `.hpp`). Os arquivos `.hpp` já estão prontos.

## 🧱 Funções

### Funções prontas

1. `mcu::init()`: Função essencial do programa, está implementada no arquivo `mcu.cpp`. Nela serão inicializadados elementos como os pinos do botão e o clock do sistema. Essa função deve ser a primeira coisa a ser chamada no seu código.

### Funções a serem implementadas

> Consulte o [STM32Guide](https://github.com/ThundeRatz/STM32Guide) para implementar essas funções.

-   **1.** `led::set(bool state)`: Função que liga ou desliga o LED.

-   **2.** `button::is_pressed()`: Função que retorna se o botão foi pressionado ou não.

-   **3.** `joystick::init()`: Função que inicia o ADC do joystick.

-   **4.** `joystick::get_x()`: Função que retorna o valor do eixo X do joystick.

-   **5.** `joystick::get_y()`: Função que retorna o valor do eixo Y do joystick.

-   **6.** `joystick::is_pressed()`: Função que retorna se o botão do joystick foi pressionado ou não.

## Apêndice A - Configuração do STM32CubeMX

### Configurando LED

O LED utilizará o GPIO do pino PC12. Para configurá-lo, clique com o botão esquerdo do mouse sobre ele, e depois selecione a opção GPIO_Output. Essa configuração permite usar o LED como um pino de saída.

> Mais detalhes podem ser encontrados no [STM32Guide - GPIO](https://github.com/ThundeRatz/STM32Guide?tab=readme-ov-file#gpio)

### Configurando Botão

O Botão 1 utilizará o GPIO do pino PA8 e o Botão 2 utilizará o GPIO do pino PB15. Para configurá-los, clique com o botão esquerdo do mouse sobre eles, e depois selecione a opção GPIO_Input. Essa configuração permite usar o botão como um pino de entrada.

> Mais detalhes podem ser encontrados no [STM32Guide - GPIO](https://github.com/ThundeRatz/STM32Guide?tab=readme-ov-file#gpio)

### Configurando ADC

Para configurar o ADC consulte o STM32Guide.

-   [STM32Guide - ADC](https://github.com/ThundeRatz/STM32Guide#adc-e-dma)

Recomendações para configuração do ADC:

-   Sampling Time: 239.5 ciclos
-   ADC1 and ADC2 global interrupts: Disabled

## Sobre a Tarefinha

Entendemos que o tópico de embarcados é algo muito novo para a maioria de vocês, e que pode ser um pouco difícil de entender. Por isso, não se preocupem se não entenderem tudo de primeira, o importante é tentarem entender. Se tiverem dúvidas, não hesitem em mandar mensagens para seus veteranos, estamos aqui para ajudá-los. No mais é isso, boa tarefinha a todos!
