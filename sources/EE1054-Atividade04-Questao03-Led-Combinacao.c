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
// Fazer um programa para ler um sinal proveniente de dois botoes
// externos a placa e realizar o acionamento de 4 LEDS, conforme a
// tabela:
// botao 1 | botao 2 | acionamento do LED
// 1         0         LED1
// 0         1         LED2
// 1         1         LED3
// 0         0         LED4
//
// Os LEDs deverao acender apos a combinacao realizada e permanecer
// acesso durante 1 segundo.
*/

int main(void) {
	BCSCTL1 = CALBC1_1MHZ;		// Configura o DC0 para 8MHz
	WDTCTL = WDTPW | WDTHOLD;	// Para o watchdog timer
	P1DIR |= 0x03;				// Configura o P1.0 para saida
	P2DIR |= 0x00;				// Configura o P2.0 para entrada
	P2REN |= 0xFF;
	P3DIR |= 0x03;				// Configura o P3.0 para saida
	for(;;) {
		volatile unsigned long int i;
		if ((P2IN & BIT0) == 1) {
			if ((P2IN & BIT2) == 4) {
				P1OUT = 0x01;
				P3OUT = 0x00;
			}
			if ((P2IN & BIT2) == 0) {
				P1OUT = 0x02;
				P3OUT = 0x00;
			}
		}
		if ((P2IN & BIT0) == 0) {
			if ((P2IN & BIT2) == 4) {
				P1OUT = 0x00;
				P3OUT = 0x01;
			}
			if ((P2IN & BIT2) == 0) {
				P1OUT = 0x00;
				P3OUT = 0x02;
			}
		}
	}
	return 0;
}