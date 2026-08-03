PROJETO MODULO DE SIMULAÇÃO PARA A FEIRA FEITO NO STM32-103 BLUE PILL

OS 4 BOTÕES ESTÃO LIGANDO CADA UM UMA SINALEIRA
AO CLICAR EM UM BOTÃO LIGA A SINALEIRA E O BUZZER (SÓ O BUZZER POR 3SEG)
A SINALEIRA ESTÁ CONFIGURADA PARA DESLIGAR EM 10 SEGUNDOS

*****SAIDAS DOS RELÉS*****

| Função  | Pino |
| ------- | ---- |
| SINAL_1 | PA15 | Saida para o rele 1
| SINAL_2 | PB3  | Saida para o rele 2
| SINAL_3 | PB4  | Saida para o rele 3
| SINAL_4 | PB5  | Saida para o rele 4

*****SAIDA DOS LEDS E LEDS STATUS*****
| Função         | Pino |               
| -------------- | ---- | ---------------------------- 
| LED_STATUS     | PC13 | LED integrado da Blue Pill  , PISCANDO SEMPRE
| LED_POWER      | PC15 | LED de alimentação           LIGADO SEMPRE QUE INICIA O PROGRAMA
| LED_STATUS_EXT | PB7  | LED externo de funcionamento está funcionando junto com o da blue Pill 
| LED_CAN        | PB6  | Reservado para CAN           
| BUZZER         | PB 12| BUZZER , LIGA QUANDO APERTA QUALQUER BOTÃO POR 3SEG DEPOIS DESLIGA

*****RESERVADO PARA O CAN*****
| Função | Pino |
| ------ | ---- |
| CAN_RX | PA11 |
| CAN_TX | PA12 |


*****BOTÕES*****

| Função | Pino | Configuração |

| BOTAO_1 | PA1 | Entrada com Pull-up 
| BOTAO_2 | PA2 | Entrada com Pull-up 
| BOTAO_3 | PA3 | Entrada com Pull-up 
| BOTAO_4 | PA4 | Entrada com Pull-up 


| Área                   | Uso               |
| ---------------------- | ----------------- |
| USER CODE BEGIN PV     | Variáveis globais |
| USER CODE BEGIN PFP    | Protótipos        |
| USER CODE BEGIN 2      | Inicializações    |
| USER CODE BEGIN WHILE  | Lógica principal  |
| USER CODE BEGIN 4      | Funções próprias  |

