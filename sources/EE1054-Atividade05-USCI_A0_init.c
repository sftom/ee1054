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
/*
 *  This file is automatically generated and does not require a license
 *
 *  ==== WARNING: CHANGES TO THIS GENERATED FILE WILL BE OVERWRITTEN ====
 *
 *  To make changes to the generated code, use the space between existing
 *      "USER CODE START (section: <name>)"
 *  and
 *      "USER CODE END (section: <name>)"
 *  comments, where <name> is a single word identifying the section.
 *  Only these sections will be preserved.
 *
 *  Do not move these sections within this file or change the START and
 *  END comments in any way.
 *  ==== ALL OTHER CHANGES WILL BE OVERWRITTEN WHEN IT IS REGENERATED ====
 *
 *  This file was generated from
 *      C:/ti/grace/grace_2_20_02_32/packages/ti/mcu/msp430/csl/communication/USCI_A0_init.xdt
 */
#include <msp430f2274.h>
/* USER CODE START (section: USCI_A0_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: USCI_A0_init_c_prologue) */
/*
 *  ======== USCI_A0_graceInit ========
 *  Initialize Universal Serial Communication Interface A0 UART 2xx
 */
void USCI_A0_init(void) {
  /* USER CODE START (section: USCI_A0_graceInit_prologue) */
  /* User initialization code */
  /* USER CODE END (section: USCI_A0_graceInit_prologue) */
  //IE2 |= UCA0RXIE;
  /* Disable USCI */
  UCA0CTL1 |= UCSWRST;
  /* 
  * Control Register 1
  * 
  * UCSSEL_2 -- SMCLK
  * ~UCRXEIE -- Erroneous characters rejected and UCAxRXIFG is not set
  * ~UCBRKIE -- Received break characters do not set UCAxRXIFG
  * ~UCDORM -- Not dormant. All received characters will set UCAxRXIFG
  * ~UCTXADDR -- Next frame transmitted is data
  * ~UCTXBRK -- Next frame transmitted is not a break
  * UCSWRST -- Enabled. USCI logic held in reset state
  * 
  * Note: ~<BIT> indicates that <BIT> has value zero
  */
  UCA0CTL1 = UCSSEL_2 | UCSWRST;
  /* 
  * Modulation Control Register
  * 
  * UCBRF_0 -- First stage 0
  * UCBRS_1 -- Second stage 1
  * ~UCOS16 -- Disabled
  * 
  * Note: ~UCOS16 indicates that UCOS16 has value zero
  */
  UCA0MCTL = UCBRF_0 | UCBRS_1;
  /* Baud rate control register 0 */
  UCA0BR0 = 104;
  /* Enable USCI */
  UCA0CTL1 &= ~UCSWRST;
  /* USER CODE START (section: USCI_A0_graceInit_epilogue) */
  /* User code */
  /* USER CODE END (section: USCI_A0_graceInit_epilogue) */
}