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
  void atualizaDisplay(uint8_t minuto, uint8_t segundo, uint32_t miliSegundo, bool sensor);
  uint8_t getPage(void);
private:
  static TelaRela rela;
  static TelaInfo info;
  static uint8_t page;
  bool recebeSerial(void);
  bool botaoPressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoHelpPressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoConfigPressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoOnOffPressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoHomePressionado(uint8_t page_id, uint8_t comp_id);
  bool botaoLimpPressionado(uint8_t page_id, uint8_t comp_id);
  void nextPage(void);
  bool goToTelaInfo(uint8_t page_id, uint8_t comp_id);
  bool goToTelaRela(uint8_t page_id, uint8_t comp_id);
  void setPage(uint8_t page_id);
};

#endif // DISPLAY_NEXTION_H
