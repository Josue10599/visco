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

uint8_t Tempo::hora;
uint8_t Tempo::minuto;
uint8_t Tempo::segundo;

Tempo::Tempo() {
  Timer1.initialize();
  Timer1.attachInterrupt(contaTempo);
  desativaTempo();
  Tempo::hora = 0;
  Tempo::minuto = 0;
  Tempo::segundo = 0;
}

Tempo::Tempo(int periodo) {
  Timer1.initialize(periodo);
  Timer1.attachInterrupt(contaTempo);
  desativaTempo();
  Tempo::hora = 0;
  Tempo::minuto = 0;
  Tempo::segundo = 0;
}

static void Tempo::contaTempo() {
  Tempo::segundo++;
  if (Tempo::segundo == 60) {
    Tempo::segundo = 0;
    Tempo::minuto++;
  }
  if (Tempo::minuto == 60) {
    Tempo::minuto = 0;
    Tempo::hora++;
  }
}

void Tempo::desativaTempo(){
  Timer1.stop();
  Timer1.detachInterrupt();
}

void Tempo::ativaTempo(){
  Timer1.start();
  Timer1.attachInterrupt(contaTempo);
}

void Tempo::zeraTempo() {
  Tempo::hora = 0;
  Tempo::minuto = 0;
  Tempo::segundo = 0;
}

String Tempo::getTempo() {
  String texto = String(Tempo::hora);
  texto.concat(':');
  texto.concat(Tempo::minuto);
  texto.concat(':');
  texto.concat(Tempo::segundo);
  return texto;
}

int Tempo::getSegundo() {
  return Tempo::segundo;
}

int Tempo::getMinuto() {
  return Tempo::minuto;
}

int Tempo::getHora() {
  return Tempo::hora;
}
