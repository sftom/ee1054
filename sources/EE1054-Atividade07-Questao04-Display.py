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
import serial
# Bloco de bibliotecas do usuario
import Adafruit_DHT
import RPi.GPIO as GPIO
'''
Fazer um programa para configurar o display de cristal liquido
fornecido. Apresentar a mesma informacao de temperatura e umidade na
tela do display.
'''

# Define o tipo de sensor DHT11
sensor = Adafruit_DHT.DHT11
# Define a GPIO conectada ao pino de dados do sensor
GPIO.setmode(GPIO.BOARD)
pino_sensor = 25

# Definicoes para comunicacao serial com o display
port = serial.Serial("/dev/ttyAMA0", baudrate=9600, timeout=1)

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
  # Inicializa
  port.write('\x0d')
  # Limpa o LCD
  port.write('\xfe\x01')
  time.sleep(0.1)
  port.write("Temperatura")
  port.write("{0:0.1f}").format(temp)
  time.sleep(0.5)
  port.write("Umidade")
  port.write("{1:0.1f}").format(umid)
  time.sleep(0.5)