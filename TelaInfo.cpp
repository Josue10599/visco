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
uint16_t TelaInfo::atualiza;

TelaInfo::TelaInfo(void) {
  TelaInfo::txtPorc = NexText(INFO, TXTPORC, "txtPorc");
  TelaInfo::progVelocidade = NexProgressBar(INFO, PROGVEL, "progVel");
  TelaInfo::botaoOnOff = false;
  TelaInfo::atualiza = 0;
}

void TelaInfo::onOffBatedeira(void) {
  if (TelaInfo::botaoOnOff){
    TelaInfo::botaoOnOff = false;
  } else {
    TelaInfo::botaoOnOff = true;
  }
}

void TelaInfo::atualizaTelaInfo(void) {
  batedeira.processoBatedeira(TelaInfo::botaoOnOff);
  if (atualiza == 10) {
    atualizaBarra(batedeira.getPorcentagem());
    atualizaPorcentagem(batedeira.getPorcentagem());
    atualiza = 0;
  } else {
    atualiza +=1;
  }
}

void TelaInfo::atualizaPorcentagem(int velocidade) {
  char texto[10];
  sprintf(texto, "%02d%%", velocidade);
  TelaInfo::txtPorc.setText(texto);
}

void TelaInfo::atualizaBarra(int porcentagem) {
  TelaInfo::progVelocidade.setValue(porcentagem);
}
