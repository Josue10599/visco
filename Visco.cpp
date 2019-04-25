/*
 * Source Visco.cpp
 *
 * Autor: Josue Lopes
 * 
 * Função: Armazenar os principais processos do funcionamento da máquina.
 * 
 */

#include "Visco.h"

bool inicia;

Visco::Visco() {
  pins = Pins();
  tempo = Tempo();
  tela = DisplayNextion();
  inicia = false;
}

void Visco::processo() {
  while(!inicia) {
    inicia = pins.leSensorBarreira();
    tela.atualizaDisplay(tempo.getMinuto(), tempo.getSegundo(), tempo.getMiliSegundo(), inicia);
  }
  if(inicia) {
    if (tempo.getMiliSegundo() == 0) {
      tempo.ativaTempo();
    }
    inicia = !pins.leSensorNivel();
  }
  if(!inicia) {
    tempo.desativaTempo();
    tempo.zeraTempo();
    pins.oscilaBuzzer(2000,1000); 
  }
  tela.atualizaDisplay(tempo.getMinuto(), tempo.getSegundo(), tempo.getMiliSegundo(), inicia);
}