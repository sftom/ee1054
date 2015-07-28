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
// Ao pressionar uma tecla acender o LED, ao pressionar a mesma tecla
// uma segunda vez apagar o LED.
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
	PE_low_level_init();

	RED_SetVal(RED_DeviceData);
	RED_ClrVal(RED_DeviceData);

	for(;;) {
		if (SW1_GetVal(NULL) == 0) { /* botao e pressionado */
			RED_ClrVal(RED_DeviceData); /* LED acesso */
			WAIT1_Waitms(1000);
		}
		if (SW1_GetVal(NULL) == 0) { /* botao e pressionado */
			RED_SetVal(RED_DeviceData); /* LED apagado */
			WAIT1_Waitms(1000);
		}
	}
}
