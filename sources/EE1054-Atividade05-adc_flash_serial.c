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
#include <msp430f2274.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void swap(int* a, int* b);
void flash_write(unsigned int valor[100]);
int flash_read(int posicao);
char* itoa(int num, char* str, int base);
extern void BCSplus_init();
extern void USCI_A0_init();
volatile int a;
char array[5];
unsigned int var;
volatile int contador=0;
unsigned int amostras[100];
int k;

int main(void) {
  WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer
  unsigned int j;
  WDTCTL = WDTPW + WDTHOLD;  // Stop watchdog timer
  if (CALBC1_1MHZ ==0xFF || CALDCO_1MHZ == 0xFF) {
    while(1);  // If calibration constants erased
               // do not load, trap CPU!!
  }
  BCSCTL1 = CALBC1_1MHZ;  // Set DCO to 1MHz
  BCOCTL = CALDCO_1MHZ;
  FCTL2 = FWKEY + FSSEL0 + FN1;  // MCLK/3 for Flash Timing Generator
  //configuracao da serial
  BCSplus_init();
  P3SEL = 0x30;  // P3.4,5 = USCI_A0 TXD/RXD
  USCI_A0_init();
  P1DIR |= 0x03;  // COLOCA P1.0 E P1.1 COMO SAIDAS
                  // (leds 1 (vermelho) e 2 (verde))
  P1OUT = 0x00;
  IE2 |= UCA0RXIE;  // Enable USCI_A0 RX interrupt
  ADC10CTL1 = CONSEQ_2;  // Repeat single channel
  ADC10CTL0 = ADC10SHT_2 + MSC + ADC10ON + ADC10IE;
  ADC10DTC1 = 0x64;  // 100 conversions
  ADC10AE0 |= 0x03;  // P2.0  e P2.1 ADC option select
  P1DIR |= 0x01;     // Set P1.0 to output direction
  __delay_cycles(4000000);
  //loop infinito
  while (1) {
    while (contador<100) {
      ADC10CTL0 &= ~ENC;
      while (ADC10CTL1 & BUSY);  // Wait if ADC10 core is active
        ADC10SA = 0x200;  // Data buffer start
        P1OUT |= 0x01;  // Set P1.0 LED on
        ADC10CTL0 |= ENC + ADC10SC;  // Sampling and conversion start
        __bis_SR_register(CPUOFF + GIE);
    }
    contador=0;
    ADC10CTL0 &= ~ENC;
    flash_write(amostras);
    P1OUT ^= 0x01;
    __delay_cycles(2000000);
    _DINT();
    for(j=0;j<100;j++) {
      // envio continuo para serial
      while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
      UCA0TXBUF = 'x';
      var = flash_read(j);
      strcpy(array, itoa(var,array,10));
      while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
      UCA0TXBUF =array[4];
      __delay_cycles(3000);
      while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
      UCA0TXBUF =array[3];
      __delay_cycles(3000);
      while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
      UCA0TXBUF =array[2];
      __delay_cycles(3000);
      while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
      UCA0TXBUF =array[1];
      __delay_cycles(3000);
      while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
      UCA0TXBUF =array[0];
      __delay_cycles(3000);
    }
  }
}

void swap(int* a, int* b) {
  int* temp = a;
  a = b;
  b = temp;
}

void reverse(char str[], int length) {
  int start = 0;
  int end = length -1;
  while (start < end) {
    swap(*(str+start), *(str+end));
    start++;
    end--;
  }
}

//converte um inteiro de 16 bits em um array de 4 inteiros codificados em ascii
char* itoa(int num, char* str, int base) {
  int i = 0;
  int isNegative = 0;
  /* Handle 0 explicitely, otherwise empty string is printed for 0 */
  if (num == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }
  // In standard itoa(), negative numbers are handled only with
  // base 10. Otherwise numbers are considered unsigned.
  if (num < 0 && base == 10) {
    isNegative = 1;
    num = -num;
  }
  // Process individual digits
  while (num != 0) {
    int rem = num % base;
    str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
    num = num/base;
  }
  // If number is negative, append '-'
  if (isNegative) {
    str[i++] = '-';
  }
  str[i] = '\0'; // Append string terminator
  // Reverse the string
  reverse(str, i);
  return str;
}

void flash_write(unsigned int valor[100]) {
  int i;
  int *Flash_ptr;  // Flash pointer
  Flash_ptr = (int *)0x1000;
  FCTL3 = FWKEY;  // Clear Lock bit to enable erase access
  FCTL1 = FWKEY+ERASE;  // ERASE bit = 1; segment erase mode selected
  *Flash_ptr = 0;  // Dummy write to erase Flash segment
  // Write to flash segment D
  FCTL1 = FWKEY + WRT;  // Set WRT bit for byte/word write operation
  for (i = 0; i <200	  ; i++) {
    *Flash_ptr++ = valor[i];  // Byte write to flash location
  }
}

int flash_read(int posicao) {
  int valor;
  int *Flash_ptr = (int *)0x1000;
  *Flash_ptr=*Flash_ptr+posicao;
  valor =  *Flash_ptr;
  FCTL1 = FWKEY;  // Clear WRT bit
  FCTL3 = FWKEY + LOCK;  // Set LOCK bit to lock flash memory
  return valor;
}
//  interrupcao do RX da porta serial
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void) {
}
// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
  //interrupcao da conversao. Sale o valor da conversao aqui.
  amostras[contador]=ADC10MEM;
  contador++;
  __bic_SR_register_on_exit(CPUOFF);  // Clear CPUOFF bit from 0(SR)
}