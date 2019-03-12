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

 class DisplayNextion {
  public:
    DisplayNextion();
    void atualizaDisplay(unsigned char*, int);
    void atualizaDisplay(int, int, int, int);
    void adicionaTempo(int, int, int, int);
    void zeraRelatorios();
  private:
    void atualizaTempo(unsigned char*);
    void atualizaTempo(int hora, int minuto, int segundo);
    void atualizaVelocidade(int);
    uint8_t getPosicao();
    void setPosicao(uint8_t);
    void incrementaPosicao();
    static NexText txtTempo;
    static NexText txtPorc;
    static NexText txtT1;
    static NexText txtT2;
    static NexText txtT3;
    static NexText txtT4;
    static uint8_t posicao;
    static NexProgressBar progVelocidade;
 };
 
#endif // DISPLAY_NEXTION_H
