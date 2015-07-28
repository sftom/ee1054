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
#include "mbed.h"
#include "tsi_sensor.h"
/*
// Utilizando o teclado touch da placa, fazer acender o led e trocar
// de cores conforme o deslocamento pelo touch.
*/

#if defined (TARGET_KL25Z) || defined (TARGET_KL46Z)
  #define ELEC0 9
  #define ELEC1 10
#elif defined (TARGET_KL05Z)
  #define ELEC0 9
  #define ELEC1 8
#else
  #error TARGET NOT DEFINED
#endif

int main(void) {
  PwmOut R(LED_RED);
  PwmOut G(LED_GREEN);
  PwmOut B(LED_BLUE);
  TSIAnalogSlider tsi(ELEC0, ELEC1, 1);
  R = 1;
  G = 1;
  B = 1;
  while (true) {
    int x = tsi.readPercentage()*100;
    if (x > 1 && x < 20) {
      R = 0;
      G = 1;
      B = 1;
      wait(0.1);
    }
    if (x > 20 && x < 40) {
      R = 1;
      G = 0;
      B = 1;
      wait(0.1);
    }
    if (x > 40 && x < 60) {
      R = 1;
      G = 1;
      B = 0;
      wait(0.1);
    }
    if (x > 60 && x < 80) {
      R = 0;
      G = 0;
      B = 1;
      wait(0.1);
    }
    if (x > 80) {
      R = 0;
      G = 1;
      B = 0;
      wait(0.1);
    }
    if (x < 1) {
      R = 1;
      G = 1;
      B = 1;
      wait(0.1);
    }
  }
}