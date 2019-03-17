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
//unsigned char TelaRela::tempo1[10];
//unsigned char TelaRela::tempo2[10];
//unsigned char TelaRela::tempo3[10];
//unsigned char TelaRela::tempo4[10];

TelaRela::TelaRela() {
  // Configura componentes da tela Relatórios
  TelaRela::txtT1 = NexText(RELA, TXTT1, "txt1");
  TelaRela::txtT2 = NexText(RELA, TXTT2, "txt2");
  TelaRela::txtT3 = NexText(RELA, TXTT3, "txt3");
  TelaRela::txtT4 = NexText(RELA, TXTT4, "txt4");
  setPosicao(0);
  zeraRelatorios();
}

void TelaRela::atualizaTelaRela(uint8_t hora, uint8_t minuto, uint8_t segundo, bool proximo) {
  if (!proximo) {
    proximoTempo();
  }
  if (confTempo(hora,minuto,segundo)) {
    adicionaTempo(hora, minuto, segundo, getPosicao());
    atualizaTempos();
  }
}

void TelaRela::adicionaTempo(uint8_t hora, uint8_t minuto, uint8_t segundo, uint8_t posicao) {
    switch (posicao) {
      case 0: //sprintf(TelaRela::tempo1, "%02d:%02d:%02d", hora, minuto, segundo);
        break;
      case 1: //sprintf(TelaRela::tempo2, "%02d:%02d:%02d", hora, minuto, segundo);
        break;
      case 2: //sprintf(TelaRela::tempo3, "%02d:%02d:%02d", hora, minuto, segundo);
        break;
      case 3: //sprintf(TelaRela::tempo4, "%02d:%02d:%02d", hora, minuto, segundo);
        break;
      default:
        zeraRelatorios();
        setPosicao(0);
        break;
    }
}

void TelaRela::atualizaTempos(void) {
  uint8_t txt[] = "00:00:00";
  TelaRela::txtT1.setText(txt);
}

void TelaRela::zeraRelatorios(void) {
//  strcpy(TelaRela::tempo1, "00:00:00");
//  strcpy(TelaRela::tempo2, "00:00:00");
//  strcpy(TelaRela::tempo3, "00:00:00");
//  strcpy(TelaRela::tempo4, "00:00:00");
  atualizaTempos();
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

bool TelaRela::confTempo(uint8_t hora, uint8_t minuto, uint8_t segundo) {
  return (hora != 0 || minuto != 0 || segundo != 0);
}
