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
/*
// Utilizando um timer para acender um LED, esperar um segundo com ele
// acesso e depois trocar para a segunda cor do LED, esperar mais um
// segundo e trocar novamente a cor, para a terceira cor do LED.
// Reiniciar o processo.
*/
DigitalOut L1(LED1);
DigitalOut L2(LED2);
DigitalOut L3(LED3);

int main() {
  L1 = 1;
  L2 = 1;
  L3 = 1;
  while(1) {
    L1 = 0;
    wait(1);
    L1 = 1;
    wait(1);
    L2 = 0;
    wait(1);
    L2 = 1;
    wait(1);
    L3 = 0;
    wait(1);
    L3 = 1;
    wait(1);
  }
}