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

uint8_t DisplayNextion::page;

DisplayNextion::DisplayNextion(void) {
  // Configura comunicação Serial do display
  nexSerial.begin(9600);
  // Configura tela Relatórios
  DisplayNextion::rela = TelaRela();
  // Configura componentes da tela Informações
  DisplayNextion::info = TelaInfo();
  // Atribui valores as variáveis de localização
  DisplayNextion::page = 0;
}

bool DisplayNextion::recebeSerial(void) {
  static uint8_t texto[10];
  if (nexSerial.available() > 0) {
    delay(10);
    uint8_t evento = nexSerial.read();
    if (evento == BOTAO_PRESSIONADO) {
      if (nexSerial.available() >= 6) {
        texto[0] = evento;
        uint8_t i;
        for (i = 1; i < 7; i++) {
          texto[i] = nexSerial.read();
        }
        texto[i] = 0x00;
        if (texto[4] == COMANDO_FINALIZADO && texto[5] == COMANDO_FINALIZADO && texto[6] == COMANDO_FINALIZADO) {
          if (botaoPressionado(texto[1],texto[2])) {
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
    } else if (evento == VARIAVEL_INVALIDA) {
        return false;
    } else {
      return false;
    }
  } else {
   return false;
  }
}

bool DisplayNextion::botaoPressionado(uint8_t page_id, uint8_t comp_id) {
  switch (page) {
    case MENU:
      if (goToTelaInfo(page_id, comp_id)) return true;
      if (goToTelaRela(page_id, comp_id)) return true;
    case INFO:
      if (botaoOnOffPressionado(page_id, comp_id)) return true;
      if (botaoHomePressionado(page_id, comp_id)) return true;
      if (botaoHelpPressionado(page_id, comp_id)) return true;
      if (botaoConfigPressionado(page_id, comp_id)) return true;
    case RELA:
      if (botaoHomePressionado(page_id, comp_id)) return true;
      if (botaoHelpPressionado(page_id, comp_id)) return true;
      if (botaoLimpPressionado(page_id, comp_id)) return true;
    case TIME:
      if (goToTelaInfo(page_id, comp_id)) return true;
    case AJUDA_INFO:
      if (goToTelaInfo(page_id, comp_id)) return true;
    case AJUDA_RELA:
      if (goToTelaRela(page_id, comp_id)) return true;
  }
}

void DisplayNextion::atualizaDisplay(uint8_t minuto, uint8_t segundo, uint8_t miliSegundo, bool sensor) {
  recebeSerial();
  switch(getPage()) {
    case INFO: DisplayNextion::info.atualizaTelaInfo();
      break;
    case RELA: DisplayNextion::rela.atualizaTelaRela(minuto, segundo, miliSegundo, sensor);
      break;
  }
}

uint8_t DisplayNextion::getPage(void) {
  return DisplayNextion::page;
}

void DisplayNextion::setPage(uint8_t page_id) {
  DisplayNextion::page=page_id;
}

bool DisplayNextion::botaoHelpPressionado(uint8_t page_id, uint8_t comp_id) {
  if (page_id == INFO && comp_id == HELP_I) {
    setPage(AJUDA_INFO);
    return true;
  } else if (page_id == RELA && comp_id == HELP_R) {
    setPage(AJUDA_RELA);
    return true;
  } else {
    return false;
  }
}

bool DisplayNextion::botaoConfigPressionado(uint8_t page_id, uint8_t comp_id) {
  if (page_id == INFO && comp_id == B_CONFIG) {
    setPage(TIME);
    return true;
  } else {
    return false;
  }
}

bool DisplayNextion::botaoHomePressionado(uint8_t page_id, uint8_t comp_id) {
  if ((page_id == INFO && comp_id == HOME_I) || (page_id == RELA && comp_id == HOME_R)) {
    setPage(MENU);
    return true;
  } else {
    return false;
  }
}

bool DisplayNextion::botaoLimpPressionado(uint8_t page_id, uint8_t comp_id){
  if (page_id == RELA && comp_id == LIMPAR) {
    setPage(RELA);
    DisplayNextion::rela.zeraRelatorios();
    return true;
  } else {
    return false;
  }
}

bool DisplayNextion::botaoOnOffPressionado(uint8_t page_id, uint8_t comp_id) {
  if (page_id == INFO && comp_id == B_ON_OFF) {
    setPage(INFO); 
    DisplayNextion::info.onOffBatedeira();   
    return true;
  } else {
    return false;
  }
}

bool DisplayNextion::goToTelaInfo(uint8_t page_id, uint8_t comp_id) {
  if ((page_id == MENU && comp_id == B_INFO) || (page_id == AJUDA_INFO && comp_id == B_RETURN) || 
  (page_id == TIME && comp_id == B_CANCELAR) || (page_id == TIME && comp_id == B_CONFIRMAR)) {
    setPage(INFO);
    return true;
  } else {
    return false;
  }
}

bool DisplayNextion::goToTelaRela(uint8_t page_id, uint8_t comp_id) {
  if ((page_id == MENU && comp_id == B_RELA) || (page_id == AJUDA_RELA && comp_id == B_RETURN)) {
    setPage(RELA);
    return true;
  } else{
    return false;
  }
}
