/*
 * Source Tempo.cpp
 *
 * Autor: Josue Lopes
 * 
 * Função: Atribuir os métodos de contagem e inicializar 
 * o timer1 do Arduino
 * 
 */
 
#include "Tempo.h"

uint8_t Tempo::minuto;
uint8_t Tempo::segundo;
uint8_t Tempo::miliSegundo;

Tempo::Tempo() {
  Timer1.initialize();
  Timer1.setPeriod(10000);
  Timer1.attachInterrupt(contaTempo);
  desativaTempo();
  Tempo::minuto = 0;
  Tempo::segundo = 0;
  Tempo::miliSegundo = 0;
}

Tempo::Tempo(int periodo) {
  Timer1.initialize(periodo);
  Timer1.attachInterrupt(contaTempo);
  desativaTempo();
  zeraTempo();
}

void Tempo::contaTempo() {
  Tempo::miliSegundo++;
  if (Tempo::miliSegundo == 100) {
    Tempo::miliSegundo = 0;
    Tempo::segundo++;
  }
  if (Tempo::segundo == 60) {
    Tempo::segundo = 0;
    Tempo::minuto++;
  }
}

void Tempo::desativaTempo(){
  Timer1.stop();
  Timer1.detachInterrupt();
}

void Tempo::ativaTempo(void){
  Timer1.start();
  Timer1.attachInterrupt(contaTempo);
}

void Tempo::zeraTempo(void) {
  Tempo::minuto = 0;
  Tempo::segundo = 0;
  Tempo::miliSegundo = 0;
}

char* Tempo::getTempo(void) {
  char txt[10];
  sprintf(txt, "%02d:%02d:%02d", Tempo::minuto, Tempo::segundo, Tempo::miliSegundo);
  return txt;
}

int Tempo::getMiliSegundo(void) {
  return Tempo::miliSegundo;
}

int Tempo::getSegundo(void) {
  return Tempo::segundo;
}

int Tempo::getMinuto(void) {
  return Tempo::minuto;
}
