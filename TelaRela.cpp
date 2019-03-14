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

static uint8_t TelaRela::posicao;

TelaRela::TelaRela() {
  // Configura componentes da tela Relatórios
  TelaRela::txtT1 = NexText(RELA, TXTT1, "txt1");
  TelaRela::txtT2 = NexText(RELA, TXTT2, "txt2");
  TelaRela::txtT3 = NexText(RELA, TXTT3, "txt3");
  TelaRela::txtT4 = NexText(RELA, TXTT4, "txt4");
  setPosicao(0);
}

void TelaRela::atualizaTelaRela(uint8_t hora, uint8_t minuto, uint8_t segundo, bool proximo) {
  if (!proximo) {
    proximoTempo();
  }
  adicionaTempo(hora, minuto, segundo, getPosicao());
}

void TelaRela::adicionaTempo(uint8_t hora, uint8_t minuto, uint8_t segundo, uint8_t posicao) {
    unsigned char tempo[10];
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
        setPosicao(0);
        break;
    }
}

void TelaRela::zeraRelatorios(void) {
  unsigned char txt[] = "00:00:00";
  TelaRela::txtT1.setText(txt);
  TelaRela::txtT2.setText(txt);
  TelaRela::txtT3.setText(txt);
  TelaRela::txtT4.setText(txt);
}

uint8_t TelaRela::getPosicao(void) {
  return TelaRela::posicao;
}

void TelaRela::setPosicao(uint8_t value) {
  TelaRela::posicao = value;
}

void TelaRela::proximoTempo(void) {
  TelaRela::posicao += 1;
}
