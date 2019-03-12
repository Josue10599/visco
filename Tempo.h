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
      unsigned char getTempo();
      int getSegundo();
      int getMinuto();
      int getHora();
    private:
      static uint8_t hora;
      static uint8_t minuto;
      static uint8_t segundo;
      static void contaTempo();
  };
  
#endif // TEMPO_H
