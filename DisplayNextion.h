/*
 * Cabeçalho DisplayNextion.h
 *
 * Autor: Josue Lopes
 * 
 * Função: Descrever as funções e métodos incrementados no código
 * DisplayNextion.cpp
 * 
 */

#ifndef DISPLAY_NEXTION_H
 #define DISPLAY_NEXTION_H

 #include <Arduino.h>
 #include <Nextion.h>
 #include "TelaRela.h"
 #include "TelaInfo.h"
 #include "TelaMenu.h"

 // Comandos do display enviado por eventos
 #define BOTAO_PRESSIONADO  0x65
 #define VARIAVEL_INVALIDA  0x1A
 #define COMANDO_FINALIZADO 0xFF  

 class DisplayNextion {
  public:
    DisplayNextion(void);
    void atualizaDisplay(uint8_t hora, uint8_t minuto, uint8_t segundo, uint8_t porcentagem, bool sensor);
    void proximoTempo(void);
  private:
    static TelaRela rela;
    static TelaInfo info;
    static uint8_t tempos[3];
    static uint8_t posicao;
    static uint8_t tela;
    bool recebeSerial(void);
    bool botaoHomePressionado(uint8_t page_id, uint8_t comp_id);
    bool botaoInfoPressionado(uint8_t page_id, uint8_t comp_id);
    bool botaoRelaPressionado(uint8_t page_id, uint8_t comp_id);
    bool confTelaMenu(void);
    bool confTelaInfo(void);
    bool confTelaRela(void);
    bool confTempo(uint8_t hora, uint8_t minuto, uint8_t segundo);
    void telaMenu(void);
    void telaInfo(void);
    void telaRela(void);
    void atualizaTempo(uint8_t hora, uint8_t minuto, uint8_t segundo);
    void atualizaVelocidade(int porcentagem);
 };
 
#endif // DISPLAY_NEXTION_H
