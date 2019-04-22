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
  #include "DisplayNextion.h"

  class Visco {
    public:
      Visco();
      void processo();
    private:
      bool inicia;
      Tempo tempo;
      Pins pins;
      DisplayNextion tela;
      int valorPorcentagem();      
  };
  
 #endif // VISCO_H
