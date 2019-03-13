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

 NexText DisplayNextion::txtT1 = NexText(RELA, TXTT1, "txt1");
 NexText DisplayNextion::txtT2 = NexText(RELA, TXTT2, "txt2");
 NexText DisplayNextion::txtT3 = NexText(RELA, TXTT3, "txt3");
 NexText DisplayNextion::txtT4 = NexText(RELA, TXTT4, "txt4");

 NexText DisplayNextion::txtPorc = NexText(INFO, TXTPORC, "txtPorc");
 NexText DisplayNextion::txtTempo = NexText(INFO, TXTTEMPO, "txtTempo");
 NexProgressBar DisplayNextion::progVelocidade = NexProgressBar(INFO, PROGVEL, "progVel");

 uint8_t DisplayNextion::posicao;
 uint8_t DisplayNextion::tela;

 DisplayNextion::DisplayNextion(void) {
  // Configura comunicação Serial do display
  nexSerial.begin(9600);
  // Configura componentes da tela Relatórios
  DisplayNextion::txtT1 = NexText(RELA, TXTT1, "txt1");
  DisplayNextion::txtT2 = NexText(RELA, TXTT2, "txt2");
  DisplayNextion::txtT3 = NexText(RELA, TXTT3, "txt3");
  DisplayNextion::txtT4 = NexText(RELA, TXTT4, "txt4");
  // Configura componentes da tela Informações
  DisplayNextion::txtPorc = NexText(INFO, TXTPORC, "txtPorc");
  DisplayNextion::txtTempo = NexText(INFO, TXTTEMPO, "txtTempo");
  DisplayNextion::progVelocidade = NexProgressBar(INFO, PROGVEL, "progVel");
  // Atribui valores as variáveis de localização
  DisplayNextion::posicao = 0;
  DisplayNextion::tela = 0;
 }

 bool DisplayNextion::recebeSerial(void) {
  static uint8_t texto[10];
  if (nexSerial.available() > 0) {
    uint8_t evento = nexSerial.read();
    if (BOTAO_PRESSIONADO == evento) {
      if (nexSerial.available() >= 6) {
        texto[0] = evento;
        uint8_t i;
        for (i = 1; i < 7; i++) {
          texto[i] = nexSerial.read();
        }
        texto[i] = 0x00;
        if (texto[4] == COMANDO_FINALIZADO && texto[5] == COMANDO_FINALIZADO && texto[6] == COMANDO_FINALIZADO) {
          if (botaoInfoPressionado(texto[1],texto[2])) {
            return true;
          }
          else if (botaoRelaPressionado(texto[1],texto[2])) {
            return true;
          }
          else if (botaoHomePressionado(texto[1],texto[2])) {
            return true;
          }
          else {
            return false;
          }
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }
 }

 void DisplayNextion::atualizaTempo(uint8_t hora, uint8_t minuto, uint8_t segundo) {
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

 void DisplayNextion::atualizaDisplay(uint8_t hora, uint8_t minuto, uint8_t segundo, uint8_t porcentagem){
  recebeSerial();
  if (confTelaInfo()) {
    atualizaVelocidade(porcentagem);
    delay(60);
    if (confTempo(hora, minuto, segundo))
      atualizaTempo(hora, minuto, segundo);
  } else if (confTelaRela()) {
    if (confTempo(hora, minuto, segundo))
      adicionaTempo(hora, minuto, segundo, getPosicao());
  }
  delay(60);
 }

 void DisplayNextion::adicionaTempo(uint8_t hora, uint8_t minuto, uint8_t segundo, uint8_t posicao) {
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
      default:
        zeraRelatorios();
        setPosicao(0);
        break;
    }
 }

 void DisplayNextion::zeraRelatorios(void) {
  unsigned char txt[] = "00:00:00";
  DisplayNextion::txtT1.setText(txt);
  DisplayNextion::txtT2.setText(txt);
  DisplayNextion::txtT3.setText(txt);
  DisplayNextion::txtT4.setText(txt);
 }

 uint8_t DisplayNextion::getPosicao(void) {
  return DisplayNextion::posicao;
 }

 void DisplayNextion::setPosicao(uint8_t value) {
  DisplayNextion::posicao = value;
 }

 void DisplayNextion::proximoTempo(void) {
  DisplayNextion::posicao += 1;
 }

 void DisplayNextion::telaMenu(void) {
  DisplayNextion::tela = MENU;
 }

 void DisplayNextion::telaInfo(void) {
  DisplayNextion::tela = INFO;
 }

 void DisplayNextion::telaRela(void) {
  DisplayNextion::tela = RELA;
 }

 bool DisplayNextion::confTelaMenu(void) {
  return (DisplayNextion::tela == MENU);
 }

 bool DisplayNextion::confTelaInfo(void) {
  return (DisplayNextion::tela == INFO);
 }

 bool DisplayNextion::confTelaRela(void) {
  return (DisplayNextion::tela == RELA);
 }

 bool DisplayNextion::confTempo(uint8_t hora, uint8_t minuto, uint8_t segundo) {
  return (hora != 0 || minuto != 0 || segundo != 0);
 }

 bool DisplayNextion::botaoHomePressionado(uint8_t page_id, uint8_t comp_id) {
  if ((page_id == INFO && comp_id == HOME_I) || (page_id == RELA && comp_id == HOME_R)) {
    telaMenu();
    DisplayNextion::tela = 0;
    return true;
  } else {
    DisplayNextion::tela = 0;
    return false;
  }
 }

 bool DisplayNextion::botaoInfoPressionado(uint8_t page_id, uint8_t comp_id) {
  if (page_id == MENU && comp_id == B_INFO) {
    telaInfo();
    return true;
  } else {
    return false;
  }
 }

 bool DisplayNextion::botaoRelaPressionado(uint8_t page_id, uint8_t comp_id) {
  if (page_id == MENU && comp_id == B_RELA) {
    telaRela();
    return true;
  } else {
    return false;
  }
 }
