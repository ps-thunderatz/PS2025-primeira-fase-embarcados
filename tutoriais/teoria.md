# Embarcados

Fala galera, este documento tem como objetivo explicar como é feita a programação de dispositivos embarcados com microcontroladores da STMicroelectronics, voltado especialmente para os robôs da equipe ThundeRatz. Em cada tópico há uma breve introdução de cada assunto e, em seguida, os vídeos correspondentes. Para a compreensão de cada abordagem, é necessário assistir os vídeos. Em seguida, nos links do [STM32Guide](https://github.com/ThundeRatz/STM32Guide), demonstraremos como aplicar isso em nossos microcontroladores.

Os vídeos que estão marcados como "extras" não serão cobrados nas atividades, mas são bem interessantes para a compreensão de sistemas embarcados. Vale super a pena dar uma conferida.

## Introdução: O que é um embarcado ? ~~é de comer?~~

Um dispositivo embarcado se trata de um dispositivo com micropocessador o qual é destinado a realização de uma tarefa específica.

Mas bom, o que isso quer dizer? São como se fossem pequenos computadores destinados a certas tarefas, ou seja, são dispositivos que contém memória, processador, interface de entrada e saída porém destinados a somente determinadas aplicações.

Um exemplo de um dispositivo embarcado no meio comum trata-se de uma impressora: ela possui um processador, memória, recebe o comando via wireless ou USB e executa a sua função. Um outro exemplo trata-se do termômetro digital, o qual recebe o sinal recebido de um sensor (de temperatura), processa e trata o sinal e, em seguida, envia um comando para um display de forma a mostrar o valor da temperatura.

Entrando mais no âmbito da equipe, temos alguns de nossos robôs que lidam os dispositivos embarcados! Como o nosso robô seguidor de linha, o Tracer, e nossos robôs sumôs autônomos, como a Galena. Ambos tratam-se de robôs que recebem diversos sinais de diferente sensores, os processam aplicando algoritmos como, por exemplo, o PID, e assim geram os comandos para os dispositivos de saída.

Para saber mais sobre isso, confira o vídeo abaixo sobre introdução a embarcados.

Além disso, teremos a gravação da nossa aulinha de embarcados, que aborda os temas abaixo, mas de forma geral

[![Alt text](https://img.youtube.com/vi/kd728Egntjs/0.jpg)](https://www.youtube.com/watch?v=kd728Egntjs)

## HAL e Cube

A HAL (Hardware Abstraction Layer) é a camada entre o hardware físico de um computador e o software do mesmo. Usando os micros da ST, temos a disposição uma biblioteca composta por várias funções que ajudam na manipulação dos periféricos e pinos. É possível ver os arquivos dela na pasta Drivers, o Cube apenas copia para a pasta do seu projeto o que estiver sendo utilizado nele.

[![Alt text](https://img.youtube.com/vi/JOBCIYgiM1w/0.jpg)](https://www.youtube.com/watch?v=JOBCIYgiM1w)

Para saber mais sobre o HAL em microcontroladores da STMicroelectronics, acesse: [STM32Guide - HAL](https://github.com/ThundeRatz/STM32Guide#hal)

Para saber como mais sobre o Cube, acesse: [STM32Guide - CubeMX](https://github.com/ThundeRatz/STM32Guide#cube-mx)

## GPIO

O GPIO, abreviação de General Purpose Input Output (Pinos Gerais de Entrada e Saída) é como o Microcontrolador se comunica com o mundo externo. Ele consiste no conjunto de pinos que enviam ou recebem sinais elétricos.

[![Alt text](https://img.youtube.com/vi/PjPB32aGmoY/0.jpg)](https://www.youtube.com/watch?v=PjPB32aGmoY)

Para saber como é feita a programação dos pinos GPIO em microcontroladores da STMicroelectronics, acesse: [STM32Guide - GPIO](https://github.com/ThundeRatz/STM32Guide#gpio)

## Timer e Interrupções

O timer, no geral, é um contador que vai de zero até um determinado valor. Esse intervalo de tempo nos chamamos de “counter period”. Todo microcontrolador tem um clock, que é uma onda quadrada que atual em frequência constante e muito alta. A cada ciclo do clock, o contador do timer é incrementado.
Toda vez que o valor do contador alcança o counter period, o valor máximo, acontece um overflow e uma interrupção acontece.

Já interrupção é quando o programa está em um fluxo normal, até que ocorre uma parada e é realizada alguma tarefa, onde, após isso, o programa volta para o seu fluxo normal. As funções de interrupções são chamadas de callbacks.

[![Alt text](https://img.youtube.com/vi/flb2y5vqcBQ/0.jpg)](https://www.youtube.com/watch?v=flb2y5vqcBQ)

Para saber como é feita a programação de um Timer em microcontroladores da STMicroelectronics, acesse: [STM32Guide - Timer](https://github.com/ThundeRatz/STM32Guide#timers)

Para saber como é feita a programação de uma Interrupção em microcontroladores da STMicroelectronics, acesse: [STM32Guide - Interrupções](https://github.com/ThundeRatz/STM32Guide#interrup%C3%A7%C3%B5es)

## PWM

Uma PWM, abreviação de Pulse-Width Modulation (Modulação por largura de pulso), é a forma pela qual fornecemos uma tensão intermediária entre LOW e HIGH por pinos digitais. A partir de uma onda quadrada, usamos a proporção em que a onda fica em nível lógico alto em relacão ao período completo da onda. Essa proporção chamamos de duty cicle.

[![Alt text](https://img.youtube.com/vi/D-dqHjathTc/0.jpg)](https://www.youtube.com/watch?v=D-dqHjathTc)

Para saber como é feita a programação de uma PWM em microcontroladores da STMicroelectronics, acesse: [STM32Guide - PWM](https://github.com/ThundeRatz/STM32Guide#pwm)

## ADC

Se trata da conversão analógica-digital! Ou seja, converter um sinal analógico - contínuo - em um sinal digital - discreto.
No mundo “real”, os sinais recebidos por um microcontrolador, como a variação na tensão de um resistor ou um som ouvido, são contínuos, porém o computador não trabalha com intervalos contínuos, mas sim discretos, já que todo o seu funcionamento é em bits ( 0’s e 1’s). Assim, por exemplo, num intervalo de 0 a 1 ao invés de abranger todo o intervalo de reais, ele é dividido em degraus.
Mas, quantos degraus? Depende da resolução!
Em uma resolução de 2 bits, haveria apenas 4 níveis 00, 01, 10 e 11. Aplicando o intervalo de 0 a 1, teríamos os valores: 0 - 0,33... - 0,666… - 1.
Logo, quanto mais bits de resolução, mais preciso é o sinal digital.

[![Alt text](https://img.youtube.com/vi/_ktHBgMg5y0/0.jpg)](https://www.youtube.com/watch?v=_ktHBgMg5y0)

Para saber como é feita a programação de um ADC em microcontroladores da STMicroelectronics, acesse: [STM32Guide - ADC](https://github.com/ThundeRatz/STM32Guide#adc-e-dma)

## Extra: Memoria e Endereçamento

Nesse vídeo aqui vamos comentar melhor sobre o que acontece mais a fundo na memória e endereçamento em um dispositivo embarcado. Confira o vídeo abaixo que comenta melhor sobre isso:

[![Alt text](https://img.youtube.com/vi/L3oORp3hPLE/0.jpg)](https://www.youtube.com/watch?v=L3oORp3hPLE)
