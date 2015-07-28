// Licenca Creative Commons
// Circuitos Integrados e Sistemas Embarcados - Relatorio Final de 
// Gustavo Esteves, Joao Ferreira, Kadna Maria e Sergio Mendonca
// esta licenciado com uma Licenca Creative Commons
// Atribuicao-NaoComercial-CompartilhaIgual 4.0 Internacional.
// Baseado no trabalho disponivel em https://github.com/sftom/ee1054
//
// +---------------------------------------------------+
// | Universidade Federal de Pernambuco                |
// | Programa de Pos-graduacao em Engenharia Eletrica  |
// +---------------------------------------------------+
// +---------------------------------------------------+
// | EE1054 Circuitos Integrados e Sistemas Embarcados |
// | Turma 2015.1                                      |
// +---------------------------------------------------+
//  Alunos em ordem alfabetica:
//  > Gustavo Ribeiro Porpino Esteves
//  > Joao Ferreira da Silva Junior
//  > Kadna Maria Alves Camboim Vale
//  > Sergio Francisco Tavares de Oliveira Mendonca
// +---------------------------------------------------+
#include <msp430.h>
/*
// Realizar testes para piscar leds com a placa LaunchPad MSP-exp430G2
// e tambem com a placa eZ430-RF2500T.
*/

int main(void) {
  BCSCTL1 = CALBC1_1MHZ;    // Configura o DC0 para 8MHz
  WDTCTL = WDTPW | WDTHOLD; // Para o watchdog timer
  P1DIR |= 0x03;        // Configura o P1.0 para saida
  P2DIR |= 0x00;        // Configura o P2.0 para entrada
  P2REN |= 0xFF;
  P3DIR |= 0x03;        // Configura o P3.0 para saida
  long int g = 5;
  for(;;) {
    volatile unsigned long int i;
    if ((P2IN & BIT0) == 1) {
      g++;
      if (g>60) g = 60;
    }
    if ((P2IN & BIT2) == 4) {
      g--;
      if (g<1) g = 1;
    }
    P1OUT = 0x01;
    i = g*10000;
    do i--;
    while(i != 0);

    if ((P2IN & BIT0) == 1) {
      g++;
      if (g>60) g = 60;
    }
    if ((P2IN & BIT2) == 4) {
      g--;
      if (g<1) g = 1;
    }
    P1OUT = 0x00;
    i = g*10000;
    do i--;
    while(i != 0);
  }
  return 0;
}