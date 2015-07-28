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
// Fazer um programa para gerar pulsos em um pino de saida, bem como
// acender um indicador (LED) ao mesmo tempo, utilizando o Shield
// Arduino. Utilizar duas teclas externas uma para aumentar a veloci-
// dade das piscadas do LED e outra para diminuir a velocidade das
// piscadas do LED. Pede-se o controle de velocidade de 1 a 60 pisca-
// das por segundo.
 */
int led = 13;
const int botao1 = 2;
const int botao2 = 3;
int tempo = 1;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao1, INPUT); 
  pinMode(botao2, INPUT);   
}

void loop() {
  if (digitalRead(botao1) == HIGH) {
    tempo++;
    while(digitalRead(botao1) == HIGH){;}
  }
  if (digitalRead(botao2) == HIGH) {
    tempo--;
    while(digitalRead(botao2) == HIGH){;}
  }
  if (tempo > 60) {
    tempo = 60;
  }
  if (tempo < 1) {
    tempo = 1;
  }
  digitalWrite(led, HIGH);
  delay(tempo * 17);
  digitalWrite(led, LOW);
  delay(tempo * 17);
  
}