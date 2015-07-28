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
#include <Sio51.h>
#include <sfr51.h>
/*
// Desenvolver um programa para realizar as seguntes funcoes:
// a) Ao pressionar uma tecla acender e depois apagar todos os quatro
// LEDs da placa.
// b) Ao pressionar a segunda tecla fazer com que os 4 LEDs se acendam
// em ordem crescente.
// c) Ao pressionar a terceira tecla fazer com que os  LEDs se acendam
// em ordem decrescente.
// d) Ao pressionar a quarta tecla realizar os itens A, B e C em
// sequencia.
*/
#define TRUE  1
#define FALSE 0

void delay(void) {
  int n;
  int m;
  for(n=0; n<200; n++) {
    for(m=0; m<1000; m++);
  }
}

void F1(void) {
  #asm
  clr P1.7
  clr P1.6
  clr P1.5
  clr P1.4
  #endasm
  putc('+');
  delay();
  #asm
  setb P1.7
  setb P1.6
  setb P1.5
  setb P1.4
  #endasm
  delay();
}

void F2(void) {
  #asm
  clr P1.7
  #endasm
  delay();
  #asm
  setb P1.7
  #endasm
  #asm
  clr P1.6
  #endasm
  delay();
  #asm
  setb P1.6
  #endasm
  #asm
  clr P1.5
  #endasm
  delay();
  #asm
  setb P1.5
  #endasm
  #asm
  clr P1.4
  #endasm
  delay();
  #asm
  setb P1.4
  #endasm
}

void F3(void) {
  #asm
  clr P1.4
  #endasm
  delay();
  #asm
  setb P1.4
  #endasm
  #asm
  clr P1.5
  #endasm
  delay();
  #asm
  setb P1.5
  #endasm
  #asm
  clr P1.6
  #endasm
  delay();
  #asm
  setb P1.6
  #endasm
  #asm
  clr P1.7
  #endasm
  delay();
  #asm
  setb P1.7
  #endasm
}

int main() {
  int n;
  int m;
  InitSerialPort0(DEF_SIO_MODE); 
  putc('\n');
  while(TRUE) {
    if (P1_3==0) {
      F1();
    }
    if (P1_2==0) {
      F2();
    }
    if (P1_1==0) {
      F3();
    }
    if (P1_0==0) {
      F1();
      F2();
      F3();
    }
  }
}