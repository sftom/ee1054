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
// Fazer um programa para acionar dois LEDs da placa PIC fornecida.
// Utilizar o arquivo "2-Manual Proton" para identificar os LEDs e
// e onde estao conectados.
*/
#pragma orgall 0x1000

int i;
int x = 0;

void Board_Init(void);

void main(void) org 0x1000 {
  Board_Init();  // inicia placa
  // coloca so um dos LEDs aceso pra alternar
  PORTA.RA5 = 0;
  x = 0;
  while (1) {
    while (x == 1) {
      // alterna estado dos LEDs
      PORTA.RA4 ^= 1;
      PORTA.RA5 ^= 1;
      Delay_ms(100);
      if (PORTA.RA3 == 0) {
        x = 0;
        while (PORTA.RA3 == 0){}
      }
    }
    while (x == 0) {
      // alterna estado dos LEDs
      PORTA.RA5 = 0;
      for (i=0; i<10;i++) {
        PORTA.RA4 ^= 1;
        Delay_ms(100);
        if (PORTA.RA3 == 0) {
          x = 1;
          while (PORTA.RA3 == 0){}
          break;
        }
      }
      PORTA.RA4 = 1;
      PORTA.RA5 = 1;
      Delay_ms(100);
      PORTA.RA4 = 0;
      PORTA.RA5 = 0;
      Delay_ms(100);
    }
  }
}

void Board_Init (void) {
  RCON = 0X80;       // LIMPA REGISTRO DE RESET
  ADCON1 = 0x0F;     // CONFIGURA TODAS AS PORTAS ANALOGICAS 
                     // COMO I/O menos A0 (sensor temp/trimpot)
  CMCON = 0x0F;      // (DESABILITAR COMPARADOR)
  LATA = 0;
  TRISA = 0b11001111;
  T0CON = 0b11000101;// timer ativo, 8 bits,clock interno, 
                     // preescale 1:64
  LATB = 0;          // LIMPA O LATCH DA PORTA B
  TRISB = 0;         // tudo Saida
  LATD = 0;
  TRISD = 0x00;      // PORTA D TUDO SAIDA
  LATE = 0;
}