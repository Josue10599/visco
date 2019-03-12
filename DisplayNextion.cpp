/*
 * Source DisplayNextion.cpp
 *
 * Autor: Josue Lopes
 * 
 * Função: Configurar a comunicação e os comandos enviados
 *  e recebidos do display.
 * 
 */

#include "DisplayNextion.h"

 NexText DisplayNextion::txtTempo = NexText(1, 4, "txtTempo");
 NexText DisplayNextion::txtPorc = NexText(1, 3, "txtPorc");
 NexText DisplayNextion::txtT1 = NexText(2, 2, "txtT1");
 NexText DisplayNextion::txtT2 = NexText(2, 3, "txtT2");
 NexText DisplayNextion::txtT3 = NexText(2, 4, "txtT3");
 NexText DisplayNextion::txtT4 = NexText(2, 5, "txtT4");
 uint8_t DisplayNextion::posicao;
 NexProgressBar DisplayNextion::progVelocidade = NexProgressBar(0, 3, "progVelocidade");

 DisplayNextion::DisplayNextion() {
  DisplayNextion::txtTempo = NexText(0, 2, "txtTempo");
  DisplayNextion::txtPorc = NexText(0, 5, "txtPorc");
  DisplayNextion::txtT1 = NexText(1, 2, "txtT1");
  DisplayNextion::txtT2 = NexText(1, 3, "txtT2");
  DisplayNextion::txtT3 = NexText(1, 4, "txtT3");
  DisplayNextion::progVelocidade = NexProgressBar(0, 3, "progVelocidade");
  posicao = 0;
  nexSerial.begin(115200);
 }

 void DisplayNextion::atualizaTempo(unsigned char tempo[10]) {
  DisplayNextion::txtTempo.setText(tempo);
 }

 void DisplayNextion::atualizaTempo(int hora, int minuto, int segundo) {
  unsigned char tempo[10];
  sprintf(tempo, "%02d:%02d:%02d", hora, minuto, segundo);
  DisplayNextion::txtTempo.setText(tempo);
 }

 void DisplayNextion::atualizaVelocidade(int porcentagem) {
  unsigned char velocidade[10];
  sprintf(velocidade, "%02d%%", porcentagem);
  DisplayNextion::txtPorc.setText(velocidade);
  DisplayNextion::progVelocidade.setValue(porcentagem);
 }

 void DisplayNextion::atualizaDisplay(unsigned char tempo[10], int porcentagem) {
  atualizaTempo(tempo);
  atualizaVelocidade(porcentagem);
 }

 void DisplayNextion::atualizaDisplay(int hora, int minuto, int segundo, int porcentagem){
  atualizaTempo(hora, minuto, segundo);
  atualizaVelocidade(porcentagem);
  adicionaTempo(hora, minuto, segundo, posicao);
 }

 void DisplayNextion::adicionaTempo(int hora, int minuto, int segundo, int posicao) {
  if (posicao < 3 && posicao >= 0) {
    unsigned char tempo[10];
    sprintf(tempo, "%02d:%02d:%02d", hora, minuto, segundo);
    switch (posicao) {
      case 0: DisplayNextion::txtT1.setText(tempo);
        break;
      case 1: DisplayNextion::txtT2.setText(tempo);
        break;
      case 2: DisplayNextion::txtT3.setText(tempo);
        break;
      case 3: DisplayNextion::txtT4.setText(tempo);
        break;
    }
  }
 }

 void DisplayNextion::zeraRelatorios() {
  unsigned char txt[] = "00:00:00";
  DisplayNextion::txtT1.setText(txt);
  DisplayNextion::txtT2.setText(txt);
  DisplayNextion::txtT3.setText(txt);
  DisplayNextion::txtT4.setText(txt);
 }

 uint8_t DisplayNextion::getPosicao() {
  return DisplayNextion::posicao;
 }

 void DisplayNextion::setPosicao(uint8_t value) {
  DisplayNextion::posicao = value;
 }

 void DisplayNextion::incrementaPosicao() {
  DisplayNextion::posicao += 1;
 }
