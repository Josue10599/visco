/*
 * Cabeçalho Batedeira.h
 *
 * Autor: Josue Lopes
 * 
 * Função: Descrever as funções e métodos incrementados no código
 * Batedeira.cpp
 * 
 */

#ifndef BATEDEIRA_H
#define BATEDEIRA_H

#include "Arduino.h"
#include "Pins.h"

class Batedeira : public Pins{
    public:
        Batedeira();
        void processoBatedeira(bool estado);
        uint8_t getPorcentagem(void);
    private:
        void setVelocidade(uint8_t velocidade);
        uint8_t getVelocidade(void);
};

#endif // BATEDEIRA_H