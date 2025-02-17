/*
 * Cabeçalho Tempo.h
 *
 * Autor: Josue Lopes
 * 
 * Função: Descrever as funções e métodos incrementados no código
 * Tempo.cpp
 * 
 */

#ifndef TEMPO_H
  #define TEMPO_H

  #include <Arduino.h>
  #include <TimerOne.h>

  class Tempo {
    public:
      Tempo();
      Tempo(int);
      void zeraTempo();
      void desativaTempo();
      void ativaTempo();
      char* getTempo();
      int getMiliSegundo();
      int getSegundo();
      int getMinuto();
    private:
      static uint8_t minuto;
      static uint8_t segundo;
      static uint8_t miliSegundo;
      static void contaTempo(void);
  };
  
#endif // TEMPO_H
