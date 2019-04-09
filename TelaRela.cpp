 /*
 * Source TelaRela.cpp
 *
 * Autor: Josue Lopes
 * 
 * Função: Função para configurar a tela de Relatórios com 
 * o objetivo de descentralizar a criação das telas.
 * 
 */

#include "TelaRela.h"

NexText TelaRela::txtT1 = NexText(RELA, TXTT1, "txt1");
NexText TelaRela::txtT2 = NexText(RELA, TXTT2, "txt2");
NexText TelaRela::txtT3 = NexText(RELA, TXTT3, "txt3");
NexText TelaRela::txtT4 = NexText(RELA, TXTT4, "txt4");

uint8_t TelaRela::posicao;
bool TelaRela::proximo;

TelaRela::TelaRela() {
  // Configura componentes da tela Relatórios
  TelaRela::txtT1 = NexText(RELA, TXTT1, "txt1");
  TelaRela::txtT2 = NexText(RELA, TXTT2, "txt2");
  TelaRela::txtT3 = NexText(RELA, TXTT3, "txt3");
  TelaRela::txtT4 = NexText(RELA, TXTT4, "txt4");
  setPosicao(0);
}

void TelaRela::atualizaTelaRela(uint8_t hora, uint8_t minuto, uint8_t segundo, bool proximo) {
  if (!tempoZero(hora, minuto, segundo)) {
    adicionaTempo(hora, minuto, segundo, getPosicao());
    setProximo(true);
  } else {
    if (!proximo && getProximo()) {
      proximoTempo();
      setProximo(false);
    }
  }
}

void TelaRela::adicionaTempo(uint8_t hora, uint8_t minuto, uint8_t segundo, uint8_t posicao) {
    char tempo[10];
    sprintf(tempo, "%02d:%02d:%02d", hora, minuto, segundo);
    switch (posicao) {
      case 0: TelaRela::txtT1.setText(tempo);
        break;
      case 1: TelaRela::txtT2.setText(tempo);
        break;
      case 2: TelaRela::txtT3.setText(tempo);
        break;
      case 3: TelaRela::txtT4.setText(tempo);
        break;
      default:
        zeraRelatorios();
        break;
    }
}

void TelaRela::zeraRelatorios(void) {
  char txt[] = "00:00:00";
  TelaRela::txtT1.setText(txt);
  TelaRela::txtT2.setText(txt);
  TelaRela::txtT3.setText(txt);
  TelaRela::txtT4.setText(txt);
  setPosicao(0);
}

uint8_t TelaRela::getPosicao(void) {
  return TelaRela::posicao;
}

void TelaRela::setPosicao(uint8_t value) {
  TelaRela::posicao = value;
  setProximo(false);
}

bool TelaRela::getProximo(void) {
  return TelaRela::proximo;
}

void TelaRela::setProximo(bool value) {
  TelaRela::proximo = value;
}

void TelaRela::proximoTempo(void) {
  TelaRela::posicao += 1;
}

bool TelaRela::tempoZero(uint8_t hora, uint8_t minuto, uint8_t segundo) {
  return hora == 0 && minuto == 0 && segundo == 0;
}