/*
 * Cabeçalho TelaRela.h
 *
 * Autor: Josue Lopes
 * 
 * Função: Definir os componentes e as ações que ocorrem na 
 * tela de relatórios.
 * 
 */

#ifndef TELA_RELA_H
  #define TELA_RELA_H

  #include <Arduino.h>
  #include <Nextion.h>

  // Id da página
  #define RELA 2
  
  // Ids dos componentes da tela de Relatórios
  #define TXTT1 2
  #define TXTT2 3
  #define TXTT3 4
  #define TXTT4 5
  #define HOME_R 1
  #define LIMPAR 6

  class TelaRela {
    public:
      TelaRela(void); // Configura os componentes da tela
      void atualizaTelaRela(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo, bool proximo);
      void zeraRelatorios(void);
    private:
      static uint8_t posicao;
      static bool proximo;
      static NexText txtT1;
      static NexText txtT2;
      static NexText txtT3;
      static NexText txtT4;
      uint8_t getPosicao(void);
      void setPosicao(uint8_t value);
      bool getProximo(void);
      void setProximo(bool value);
      void proximoTempo(void);
      void adicionaTempo(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo, uint8_t posicao);
      bool tempoZero(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo);
  };

#endif //TELA_RELA_H
