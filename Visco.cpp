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
    tela.atualizaDisplay(tempo.getHora(), tempo.getMinuto(), tempo.getSegundo(), valorPorcentagem());
  }
  if(inicia) {
    if (tempo.getSegundo() == 0) {
      tempo.ativaTempo();
    }
    inicia = !pins.leSensorNivel();
  }
  if(!inicia) {
    tempo.desativaTempo();
    tela.proximoTempo();
    tempo.zeraTempo();
    pins.oscilaBuzzer(2000,1000); 
  }
  tela.atualizaDisplay(tempo.getHora(), tempo.getMinuto(), tempo.getSegundo(), valorPorcentagem());
}

int Visco::valorPorcentagem() {
  int potenciometro = pins.lePotenciometro();
  pins.ativaTriac(potenciometro);
  return pins.porcentagem(potenciometro);
}
