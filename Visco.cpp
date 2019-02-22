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
  Serial.begin(9600);
  inicia = false;
}

void Visco::processo() {
  while(!inicia) {
    inicia = pins.leSensorBarreira();
    atualizaDisplay();    
  }
  if(inicia) {
    if (tempo.getSegundo() == 0) {
      tempo.ativaTempo();
    }
    inicia = !pins.leSensorNivel();
  }
  if(!inicia) {
    tempo.desativaTempo();
    tempo.zeraTempo();
    Serial.println("Fim");
    pins.temporizaBuzzer(1000); 
  }
  atualizaDisplay();
}

void Visco::atualizaDisplay() {
  Serial.println(tempo.getTempo());
  pins.ativaTriac(pins.lePotenciometro());
  Serial.println(String(pins.porcentagem(pins.lePotenciometro())) + "%");
  delay(700);
}
