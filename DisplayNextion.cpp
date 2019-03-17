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

TelaRela DisplayNextion::rela = TelaRela();
TelaInfo DisplayNextion::info = TelaInfo();

uint8_t DisplayNextion::tela;

DisplayNextion::DisplayNextion(void) {
  // Configura comunicação Serial do display
  nexSerial.begin(9600);
  // Configura tela Relatórios
  DisplayNextion::rela = TelaRela();
  // Configura componentes da tela Informações
  DisplayNextion::info = TelaInfo();
  // Atribui valores as variáveis de localização
  DisplayNextion::tela = 1;
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
            } else if (botaoRelaPressionado(texto[1],texto[2])) {
              return true;
            } else if (botaoHomePressionado(texto[1],texto[2])) {
              return true;
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
  } else {
   return false;
  }
}

void DisplayNextion::atualizaDisplay(uint8_t hora, uint8_t minuto, uint8_t segundo, uint8_t porcentagem, bool sensor){
  recebeSerial();
  if (confTelaInfo()) {
    DisplayNextion::info.atualizaTelaInfo(hora, minuto, segundo, porcentagem);
  } else if (confTelaRela()) {
    //DisplayNextion::rela.atualizaTelaRela(hora, minuto, segundo, sensor);
  }
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

bool DisplayNextion::botaoHomePressionado(uint8_t page_id, uint8_t comp_id) {
  if ((page_id == INFO && comp_id == HOME_I) || (page_id == RELA && comp_id == HOME_R)) {
    telaMenu();
    return true;
  } else {
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
