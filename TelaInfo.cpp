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

void TelaInfo::atualizaTelaInfo(uint8_t hora, uint8_t minuto, uint8_t segundo, int porcentagem) {
  if (confTempo(hora, minuto, segundo)) {
    atualizaTempo(hora, minuto, segundo);
  }
  atualizaBarra(porcentagem);
  atualizaVelocidade(porcentagem);
}

void TelaInfo::atualizaTempo(uint8_t hora, uint8_t minuto, uint8_t segundo) {
  unsigned char tempo[10];
  sprintf(tempo, "%02d:%02d:%02d", hora, minuto, segundo);
  TelaInfo::txtTempo.setText(tempo);
}

void TelaInfo::atualizaVelocidade(int velocidade) {
  unsigned char texto[10];
  sprintf(texto, "%02d%%", velocidade);
  TelaInfo::txtPorc.setText(texto);
  TelaInfo::progVelocidade.setValue(velocidade);
}

void TelaInfo::atualizaBarra(int porcentagem) {
  TelaInfo::progVelocidade.setValue(porcentagem);
}

bool TelaInfo::confTempo(uint8_t hora, uint8_t minuto, uint8_t segundo) {
  return (hora != 0 || minuto != 0 || segundo != 0);
}
