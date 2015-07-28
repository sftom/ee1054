#!/bin/python
# -*- coding: cp1252 -*-
'''
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
'''
import time
import sys
import subprocess
import platform
# Bloco de bibliotecas do usuario
import Adafruit_DHT
import RPi.GPIO as GPIO
'''
Fazer um programa para ler a temperatura e umidade, atraves do sensor 
fornecido. Apresentar os resultados em tela.
'''

# Define o tipo de sensor DHT11
sensor = Adafruit_DHT.DHT11
# Define a GPIO conectada ao pino de dados do sensor
GPIO.setmode(GPIO.BOARD)
pino_sensor = 25

'''
Imprime o cabecalho de informacoes
'''
def cabecalho():
  # Limpa o terminal
  subprocess.Popen(
    "cls" if platform.system() == "Windows"
    else "clear", shell=True
  )
  print ("+---------------------------------------------------+")
  print ("| Universidade Federal de Pernambuco                |")
  print ("| Programa de Pos-graduacao em Engenharia Eletrica  |")
  print ("+---------------------------------------------------+")
  print ("+---------------------------------------------------+")
  print ("| EE1054 Circuitos Integrados e Sistemas Embarcados |")
  print ("| Turma 2015.1                                      |")
  print ("+---------------------------------------------------+")
  print (" Alunos em ordem alfabetica:")
  time.sleep(1)
  print (" > Gustavo Ribeiro Porpino Esteves")
  time.sleep(1)
  print (" > Joao Ferreira da Silva Junior")
  time.sleep(1)
  print (" > Kadna Maria Alves Camboim Vale")
  time.sleep(1)
  print (" > Sergio Francisco Tavares de Oliveira Mendonca")
  print ("+---------------------------------------------------+")

# Bloco de comandos para leitura do sensor 
while(1):
  # Efetua a leitura do sensor
  umid, temp = Adafruit_DHT.read_retry(sensor, pino_sensor);
  # Chama a funcao para imprimir o cabecalho
  cabecalho()
  # Caso leitura esteja ok, mostra os valores na tela
  if umid is not None and temp is not None:
    print ("+---------------------------------------------------+")
    print ("| Temperatura = {0:0.1f}").format(temp)
    print ("| Umidade     = {1:0.1f}").format(umid)
    print ("+---------------------------------------------------+")
    time.sleep(2)
  else:
    #Mensagem de erro de comunicacao com o sensor
    print ("+---------------------------------------------------+")
    print ("| Falha ao ler dados do DHT11                       |")
    print ("+---------------------------------------------------+")
    time.sleep(2)