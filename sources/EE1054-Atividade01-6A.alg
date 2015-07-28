algoritmo "EE1054-Atividade01-6A"
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
var
   clock: inteiro
   // Portas do Microcontrolador
   // Portas de enderecamento
   P32, P33, P34: caractere
   // Portas de entrada digital
   P10, P11, P12, P13, P14, P15, P16, P17 : inteiro
   // Portas OE(RXD) e ALE(TXD)
   P30, P31: inteiro
   // Portas do conversor A/D
   // Portas de entrada analogica
   IN0, IN1, IN2, IN3, IN4, IN5, IN6, IN7: real
   // Portas de enderecamento
   A, B, C: caractere
   // Portas de saida digital
   DB0, DB1, DB2, DB3, DB4, DB5, DB6, DB7: inteiro
   // Vetor comum de enderecamento
   ADDR: vetor [1..3] de caractere
   // Variaveis comuns de iteracao
   i, j, k: inteiro
inicio
   // Atribui valores aleatorios para as entradas analogicas
   IN0 <- (exp(10 * rand, rand)) * 10
   IN1 <- (exp(10 * rand, rand)) * 10
   IN2 <- (exp(10 * rand, rand)) * 10
   IN3 <- (exp(10 * rand, rand)) * 10
   IN4 <- (exp(10 * rand, rand)) * 10
   IN5 <- (exp(10 * rand, rand)) * 10
   IN6 <- (exp(10 * rand, rand)) * 10
   IN7 <- (exp(10 * rand, rand)) * 10
   // Define o clock em 10KHz
   clock <- 10
   // O Microcontrolador envia o endereco a ser lido para o conversor A/D
   i <- 0
   j <- 1
   k <- 1
   P32 <- numpcarac(i)
   P33 <- numpcarac(j)
   P34 <- numpcarac(k)
   A <- P32
   B <- P33
   C <- P34
   ADDR[1] <- A
   ADDR[2] <- B
   ADDR[3] <- C
   escolha (ADDR[1] + ADDR[2] + ADDR[3])
      caso ("011")
           P31 <- 1
           timer 2
           P31 <- 0
           timer 2
           P30 <- 1
           timer (8 * clock)
           DB3 <- int(IN3)
           P30 <- 0
           timer 1
   fimescolha
   
   timer 10
   limpatela
   escreval("+---------------------------------------------------+")
   escreval("| Universidade Federal de Pernambuco                |")
   escreval("| Programa de Pos-graduacao em Engenharia Eletrica  |")
   escreval("+---------------------------------------------------+")
   escreval("+---------------------------------------------------+")
   escreval("| EE1054 Circuitos Integrados e Sistemas Embarcados |")
   escreval("| Turma 2015.1                                      |")
   escreval("+---------------------------------------------------+")
   escreval(" Alunos em ordem alfabetica:")
   escreval(" > Gustavo Ribeiro Porpino Esteves")
   escreval(" > Joao Ferreira da Silva Junior")
   escreval(" > Kadna Maria Alves Camboim Vale")
   escreval(" > Sergio Francisco Tavares de Oliveira Mendonca")
   escreval("+---------------------------------------------------+")
   escreval("")
   escreval("Display de LCD 16x2")
   escreval("+----------------+")
   escreval("  VALOR LIDO DB3  ")
   escreval("  >> " + numpcarac(DB3))
   escreval("+----------------+")
   timer 1000
   
fimalgoritmo
