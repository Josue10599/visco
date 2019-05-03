/*
 * Cabeçalho TelaInfo.h
 *
 * Autor: Josue Lopes
 * 
 * Função: Definir os componentes e as ações que ocorrem na 
 * tela de informações.
 * 
 */

#ifndef TELA_INFO_H
  #define TELA_INFO_H

  #include <Arduino.h>
  #include <Nextion.h>
  #include <NexDualStateButton.h>
  #include "Batedeira.h"

  // Id da página
  #define INFO 1  
  
  // Ids dos componentes da tela de Informações.
  #define TXTPORC  3
  #define PROGVEL  2
  #define HOME_I   1
  #define HELP_I   10
  #define B_ON_OFF 8
  #define B_CONFIG 7

  class TelaInfo {
    public:
      TelaInfo(void);
      void atualizaTelaInfo(void);
      void onOffBatedeira(void);
    private:
      static bool botaoOnOff;
      static NexDSButton onOff;
      static uint8_t atualizaTela;
      static uint16_t velocidade;
      static Batedeira batedeira;
      static NexText txtPorc;
      static NexProgressBar progVelocidade;
      void atualizaPorcentagem(int velocidade);
      void atualizaBarra(int porcentagem);
  };

#endif //TELA_INFO_H
