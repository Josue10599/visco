/*
 * Cabeçalho DisplayNextion.h
 *
 * Autor: Josue Lopes
 * 
 * Função: Descrever as funções e métodos incrementados no código
 * DisplayNextion.cpp
 * 
 */

#ifndef DISPLAY_NEXTION_H
#define DISPLAY_NEXTION_H

 #include <Arduino.h>
 #include <Nextion.h>
 #include "TelaRela.h"
 #include "TelaInfo.h"
 #include "TelaMenu.h"
 #include "TelaAjuda.h"
 #include "TelaTime.h"

// Comandos do display enviado por eventos
#define BOTAO_PRESSIONADO 0x65
#define VARIAVEL_INVALIDA 0x1A
#define COMANDO_FINALIZADO 0xFF

class DisplayNextion
{
public:
  DisplayNextion(void);
  void atualizaDisplay(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo, uint8_t porcentagem, bool sensor);
  void proximoTempo(void);
private:
  static TelaRela rela;
  static TelaInfo info;
  static uint8_t tempos[3];
  static uint8_t posicao;
  static uint8_t tela;
  bool recebeSerial(void);
  bool botaoPressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoHelpPressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoConfigPressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoOnOffPressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoHomePressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoLimpPressionado(uint8_t page_id, uint8_t comp_id);
  bool goToTelaInfo(uint8_t page_id, uint8_t comp_id);
  bool goToTelaRela(uint8_t page_id, uint8_t comp_id);
  bool confTelaInfo(void);
  bool confTelaRela(void);
  bool confTempo(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo);
  void setPage(uint8_t page_id);
  void telaTempo(void);
  void telaAjuda(void);
  void atualizaTempo(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo);
  void atualizaVelocidade(int porcentagem);
};

#endif // DISPLAY_NEXTION_H
