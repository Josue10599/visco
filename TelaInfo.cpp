 /*
 * Source TelaInfo.cpp
 *
 * Autor: Josue Lopes
 * 
 * Função: Função para configurar a tela de Informação com 
 * o objetivo de descentralizar a criação das telas.
 * 
 */

#include "TelaInfo.h"

NexText TelaInfo::txtPorc = NexText(INFO, TXTPORC, "txtPorc");
NexText TelaInfo::txtTempo = NexText(INFO, TXTTEMPO, "txtTempo");
NexProgressBar TelaInfo::progVelocidade = NexProgressBar(INFO, PROGVEL, "progVel");

TelaInfo::TelaInfo(void) {
  TelaInfo::txtPorc = NexText(INFO, TXTPORC, "txtPorc");
  TelaInfo::txtTempo = NexText(INFO, TXTTEMPO, "txtTempo");
  TelaInfo::progVelocidade = NexProgressBar(INFO, PROGVEL, "progVel");
}

void TelaInfo::atualizaTelaInfo(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo, int porcentagem) {
  if (confTempo(minuto, segundo, miliSegundo)) {
    atualizaTempo(minuto, segundo, miliSegundo);
  }
  atualizaBarra(porcentagem);
  atualizaVelocidade(porcentagem);
}

void TelaInfo::atualizaTempo(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo) {
  char tempo[10];
  sprintf(tempo, "%02d:%02d:%02d", minuto, segundo, miliSegundo);
  TelaInfo::txtTempo.setText(tempo);
}

void TelaInfo::atualizaVelocidade(int velocidade) {
  char texto[10];
  sprintf(texto, "%02d%%", velocidade);
  TelaInfo::txtPorc.setText(texto);
}

void TelaInfo::atualizaBarra(int porcentagem) {
  TelaInfo::progVelocidade.setValue(porcentagem);
}

bool TelaInfo::confTempo(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo) {
  return (minuto != 0 || segundo != 0 || miliSegundo != 0);
}
