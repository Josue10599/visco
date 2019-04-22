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

  // Id da página
  #define INFO 1  
  
  // Ids dos componentes da tela de Informações.
  #define TXTPORC  3
  #define TXTTEMPO 4
  #define PROGVEL  2
  #define HOME_I   1
  #define HELP_I   10
  #define B_ON_OFF 8
  #define B_CONFIG 7

  class TelaInfo {
    public:
      TelaInfo(void);
      void atualizaTelaInfo(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo, int porcentagem);
    private:
      static NexText txtTempo;
      static NexText txtPorc;
      static NexProgressBar progVelocidade;
      void atualizaTempo(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo);
      void atualizaVelocidade(int velocidade);
      void atualizaBarra(int porcentagem);
      bool confTempo(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo);
  };

#endif //TELA_INFO_H
