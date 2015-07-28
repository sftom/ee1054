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
'''
Fazer um programa em Python para apresentar na tela a informacao
da disciplina e dos integrantes do grupo.
'''

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

# Bloco de repeticao para chamada do cabecalho
while(1):
  # Chama a funcao para imprimir o cabecalho
  cabecalho()