/*
 * Source Pins.cpp
 *
 * Autor: Josue Lopes
 * 
 * Função: Configurar os pinos de entrada e saída
 * 
 */
 
#include "Pins.h"

Pins::Pins() {
  #ifdef SENSORNIVELPULLUP
    pinMode(sensorNivel, INPUT_PULLUP);
  #else
    pinMode(sensorNivel,INPUT);
  #endif // SENSORNIVELPULLUP
  
  #ifdef SENSORBARREIRAPULLUP
    pinMode(sensorBarreira, INPUT_PULLUP);
  #else
    pinMode(sensorBarreira, INPUT);
  #endif // SENSORBARREIRAPULLUP

  #ifdef BOTAORESETPULLUP
    pinMode(botaoReset, INPUT_PULLUP);
  #else
    pinMode(botaoReset, INPUT);
  #endif // BOTAORESETPULLUP
  
  pinMode(buzzer, OUTPUT);

  #ifdef RGB
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
  #endif // RGB

  #ifdef POTENCIOMETRO
    pinMode(potenciometro, INPUT);
    pinMode(triac, OUTPUT);
  #endif // POTENCIOMETRO
}

void Pins::ativaBuzzer() {
  digitalWrite(buzzer, HIGH);
}

void Pins::desativaBuzzer() {
  digitalWrite(buzzer, LOW);
}

void Pins::temporizaBuzzer(uint8_t ms_tempo) {
  digitalWrite(buzzer, HIGH);
  delay(ms_tempo);
  digitalWrite(buzzer, LOW);
}

void Pins::oscilaBuzzer(uint8_t tempoLigado, uint8_t tempoDesligado, uint8_t numeroDePulsos) {
  uint8_t vezes = 6;
  if (numeroDePulsos > 0)
    vezes = numeroDePulsos;
  while (vezes > 0) {
    digitalWrite(buzzer, HIGH);
    delay(tempoLigado);
    digitalWrite(buzzer, LOW);
    delay(tempoDesligado);
    vezes--;
  }
}

void Pins::oscilaBuzzer(uint8_t tempoLigado, uint8_t tempoDesligado) {
  uint8_t vezes = 6;
  while (vezes > 0) {
    digitalWrite(buzzer, HIGH);
    delay(tempoLigado);
    digitalWrite(buzzer, LOW);
    delay(tempoDesligado);
    vezes--;
  }
}

bool Pins::leSensorNivel(){
  #ifdef SENSORNIVELPULLUP
    return !digitalRead(sensorNivel);
  #else
    return digitalRead(sensorNivel);
  #endif // SENSORNIVELPULLUP
}

bool Pins::leSensorBarreira() {
  #ifdef SENSORBARREIRAPULLUP
    return !digitalRead(sensorBarreira);
  #else
    return digitalRead(sensorBarreira);
  #endif // SENSORBARREIRAPULLUP
}

bool Pins::leBotaoReset() {
  #ifdef BOTAORESETPULLUP
    return !digitalRead(botaoReset);
  #else
    return digitalRead(botaoReset);
  #endif // BOTAORESETPULLUP
}

#ifdef RGB
  void Pins::ativaRGB(uint8_t vermelho, uint8_t verde, uint8_t azul) {
    analogWrite(ledR, vermelho);
    analogWrite(ledG, verde);
    analogWrite(ledB, azul);
  }

  void Pins::ativaVermelho() {
    digitalWrite(ledR, HIGH);
  }

  void Pins::desativaVermelho() {
    digitalWrite(ledR, LOW);
  }

  void Pins::ativaVerde() { 
    digitalWrite(ledG, HIGH);
  }

  void Pins::desativaVerde() { 
    digitalWrite(ledG, LOW);
  }

  void Pins::ativaAzul() {
    digitalWrite(ledB, HIGH);
  }

  void Pins::desativaAzul() {
    digitalWrite(ledB, LOW);
  }
#endif // RGB

#ifdef POTENCIOMETRO
  int Pins::lePotenciometro() {
    uint16_t potenciometro = analogRead(potenciometro);
    return map(potenciometro, 0, 1024, 0, 255);
  }

  void Pins::ativaTriac(int potenciometro) {
    analogWrite(triac, potenciometro);
  }

  int Pins::porcentagem(int potenciometro) {
    return map(potenciometro, 0, 255, 0, 100);
  }
#endif // POTENCIOMETRO
