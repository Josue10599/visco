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
#ifdef SENSOR_NIVEL
  #ifdef SENSOR_NIVEL_PULLUP
    pinMode(SENSOR_NIVEL, INPUT_PULLUP);
  #else
    pinMode(SENSOR_NIVEL,INPUT);
  #endif // SENSOR_NIVEL_PULLUP
#endif // SENSOR_NIVEL

#ifdef SENSOR_BARREIRA
  #ifdef SENSOR_BARREIRA_PULLUP
    pinMode(SENSOR_BARREIRA, INPUT_PULLUP);
  #else
    pinMode(SENSOR_BARREIRA, INPUT);
  #endif // SENSOR_BARREIRA_PULLUP
#endif // SENSOR_BARREIRA

#ifdef BOTAO_RESET
  #ifdef BOTAO_RESET_PULLUP
    pinMode(BOTAO_RESET, INPUT_PULLUP);
  #else
    pinMode(BOTAO_RESET, INPUT);
  #endif // BOTAO_RESET_PULLUP
#endif //BOTAO_RESET

#ifdef BUZZER
  pinMode(BUZZER, OUTPUT);
  desativaBuzzer();
#endif // BUZZER

  #ifdef RGB
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    desativaVermelho();
    desativaVerde();
    desativaAzul();
  #endif // RGB

  #ifdef CONTROLE_PWM
    pinMode(POTENCIOMETRO, INPUT);
    pinMode(PWM, OUTPUT);
  #endif // CONTROLE_PWM
}

void Pins::ativaBuzzer() {
  #ifndef BUZZER_PULLUP
  digitalWrite(BUZZER, HIGH);
  #else
  digitalWrite(BUZZER, LOW);
  #endif // BUZZER_PULLUP
}

void Pins::desativaBuzzer() {
  #ifndef BUZZER_PULLUP
  digitalWrite(BUZZER, LOW);
  #else
  digitalWrite(BUZZER, HIGH);
  #endif // BUZZER_PULLUP
}

void Pins::temporizaBuzzer(uint8_t ms_tempo) {
  ativaBuzzer();
  delay(ms_tempo);
  desativaBuzzer();
}

void Pins::oscilaBuzzer(uint8_t tempoLigado, uint8_t tempoDesligado, uint8_t numeroDePulsos) {
  uint8_t vezes = 6;
  if (numeroDePulsos > 0)
    vezes = numeroDePulsos;
  while (vezes > 0) {
    ativaBuzzer();
    delay(tempoLigado);
    desativaBuzzer();
    delay(tempoDesligado);
    vezes--;
  }
}

bool Pins::leSensorNivel(){
  #ifdef SENSOR_NIVEL_PULLUP
    return !digitalRead(SENSOR_NIVEL);
  #else
    return digitalRead(SENSOR_NIVEL);
  #endif // SENSOR_NIVEL_PULLUP
}

bool Pins::leSensorBarreira() {
  #ifdef SENSOR_BARREIRA_PULLUP
    return !digitalRead(SENSOR_BARREIRA);
  #else
    return digitalRead(SENSOR_BARREIRA);
  #endif // SENSOR_BARREIRA_PULLUP
}

#ifdef BOTAO_RESET
bool Pins::leBotaoReset() {
  #ifdef BOTAO_RESET_PULLUP
    return !digitalRead(BOTAO_RESET);
  #else
    return digitalRead(BOTAO_RESET);
  #endif // BOTAO_RESET_PULLUP
}
#endif

#ifdef RGB
  void Pins::ativaRGB(unsigned char vermelho, unsigned char verde, unsigned char azul) {
    analogWrite(LED_RED, vermelho);
    analogWrite(LED_GREEN, verde);
    analogWrite(LED_BLUE, azul);
  }

  void Pins::ativaVermelho() {
    digitalWrite(LED_RED, HIGH);
  }

  void Pins::desativaVermelho() {
    digitalWrite(LED_RED, LOW);
  }

  void Pins::ativaVerde() { 
    digitalWrite(LED_GREEN, HIGH);
  }

  void Pins::desativaVerde() { 
    digitalWrite(LED_GREEN, LOW);
  }

  void Pins::ativaAzul() {
    digitalWrite(LED_BLUE, HIGH);
  }

  void Pins::desativaAzul() {
    digitalWrite(LED_BLUE, LOW);
  }
#endif // RGB

#ifdef CONTROLE_PWM
  int Pins::lePotenciometro() {
    uint16_t potenciometro = analogRead(POTENCIOMETRO);
    return map(potenciometro, 0, 1023, 0, 255);
  }

  void Pins::ativaPwm(int potenciometro) {
    analogWrite(PWM, potenciometro);
  }

  int Pins::porcentagem(int potenciometro) {
    return map(potenciometro, 0, 254, 0, 100);
  }
#endif // CONTROLE_PWM
