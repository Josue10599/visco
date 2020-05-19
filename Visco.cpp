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
  pins.ativaVermelho();
  inicia = false;
}

void Visco::processo() {
  while(!inicia) {
    inicia = pins.leSensorBarreira() && !pins.leSensorNivel();
    tela.atualizaDisplay(tempo.getMinuto(), tempo.getSegundo(), tempo.getMiliSegundo(), inicia);
  }
  if(inicia) {
    if (tempo.getMiliSegundo() == 0 && tempo.getSegundo() == 0 && tempo.getMinuto() == 0) {
      tempo.ativaTempo();
      pins.ativaRGB(0,0,255);
      pins.temporizaBuzzer(125);
    }
    inicia = !pins.leSensorNivel();
  }
  if(!inicia) {
    tempo.desativaTempo();
    tela.atualizaDisplay(tempo.getMinuto(), tempo.getSegundo(), tempo.getMiliSegundo(), inicia);
    tempo.zeraTempo();
    pins.ativaRGB(255,0,0);
    pins.temporizaBuzzer(250);
  }
  tela.atualizaDisplay(tempo.getMinuto(), tempo.getSegundo(), tempo.getMiliSegundo(), inicia);
}
