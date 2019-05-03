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
NexDSButton TelaInfo::onOff = NexDSButton(INFO, B_ON_OFF, "");

bool TelaInfo::botaoOnOff;
uint16_t TelaInfo::velocidade;
uint8_t TelaInfo::atualizaTela;

TelaInfo::TelaInfo(void) {
  TelaInfo::txtPorc = NexText(INFO, TXTPORC, "txtPorc");
  TelaInfo::progVelocidade = NexProgressBar(INFO, PROGVEL, "progVel");
  TelaInfo::onOff = NexDSButton(INFO, B_ON_OFF, "btnOnOff");
  TelaInfo::botaoOnOff = false;
  TelaInfo::velocidade = 0;
  TelaInfo::atualizaTela = 0;
}

void TelaInfo::onOffBatedeira(void) {
  uint32_t estado;
  TelaInfo::onOff.getValue(&estado);
  if (estado) {
    TelaInfo::botaoOnOff = true;
  } else {
    TelaInfo::botaoOnOff = false;
  }
}

void TelaInfo::atualizaTelaInfo(void) {
  if (atualizaTela >= 25) {
    onOffBatedeira();
    batedeira.processoBatedeira(TelaInfo::botaoOnOff);
    atualizaTela = 0;
  } else {
    atualizaTela += 1;
  }
  if (velocidade != batedeira.getPorcentagem()) {
    atualizaBarra(batedeira.getPorcentagem());
    atualizaPorcentagem(batedeira.getPorcentagem());
    velocidade = batedeira.getPorcentagem();
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
