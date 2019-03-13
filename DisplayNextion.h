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

 // Configura o número das telas
 #define MENU 0
 #define INFO 1
 #define RELA 2

 // Configura o número dos componentes
 // Tela menu
 #define B_INFO 1
 #define B_RELA 2

 // Tela Info
 #define TXTPORC  3
 #define TXTTEMPO 4
 #define PROGVEL  2
 #define HOME_I   1

 // Tela Rela
 #define TXTT1 2
 #define TXTT2 3
 #define TXTT3 4
 #define TXTT4 5
 #define HOME_R 1

 // Comandos do display enviado por eventos
 #define BOTAO_PRESSIONADO  0x65
 #define COMANDO_FINALIZADO 0xFF  

 class DisplayNextion {
  public:
    DisplayNextion(void);
    void atualizaDisplay(uint8_t hora, uint8_t minuto, uint8_t segundo, uint8_t porcentagem);
    void proximoTempo(void);
  private:
    static NexText txtTempo;
    static NexText txtPorc;
    static NexText txtT1;
    static NexText txtT2;
    static NexText txtT3;
    static NexText txtT4;
    static NexProgressBar progVelocidade;
    static uint8_t tempos[3];
    static uint8_t posicao;
    static uint8_t tela;
    uint8_t getPosicao(void);
    void setPosicao(uint8_t value);
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
    void adicionaTempo(uint8_t hora, uint8_t minuto, uint8_t segundo, uint8_t posicao);    
    void zeraRelatorios(void);  
 };
 
#endif // DISPLAY_NEXTION_H
