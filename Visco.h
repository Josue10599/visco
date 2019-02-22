/*
 * Cabeçalho Visco.h
 *
 * Autor: Josue Lopes
 * 
 * Função: Descrever as funções e métodos incrementados no código
 * Visco.cpp
 * 
 */

 #ifndef VISCO_H
  #define VISCO_H

  #include "Tempo.h"
  #include "Pins.h"

  class Visco {
    public:
      Visco();
      void processo();
    private:
      Tempo tempo;
      Pins pins;
      void atualizaDisplay();      
  };
  
 #endif // VISCO_H
