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

Batedeira TelaInfo::batedeira = Batedeira();
NexText TelaInfo::txtPorc = NexText(INFO, TXTPORC, "txtPorc");
NexProgressBar TelaInfo::progVelocidade = NexProgressBar(INFO, PROGVEL, "progVel");

bool TelaInfo::botaoOnOff;

TelaInfo::TelaInfo(void) {
  TelaInfo::txtPorc = NexText(INFO, TXTPORC, "txtPorc");
  TelaInfo::progVelocidade = NexProgressBar(INFO, PROGVEL, "progVel");
  TelaInfo::botaoOnOff = false;
}

void TelaInfo::atualizaTelaInfo(void) {
  batedeira.processoBatedeira(TelaInfo::botaoOnOff);
  atualizaBarra(batedeira.getPorcentagem());
  atualizaPorcentagem(batedeira.getPorcentagem());
  delay(100);
}

void TelaInfo::atualizaPorcentagem(int velocidade) {
  char texto[10];
  sprintf(texto, "%02d%%", velocidade);
  TelaInfo::txtPorc.setText(texto);
}

void TelaInfo::atualizaBarra(int porcentagem) {
  TelaInfo::progVelocidade.setValue(porcentagem);
}