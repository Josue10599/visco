/*
 * Source Batedeira.cpp
 *
 * Autor: Josue Lopes
 * 
 * Função: Configurar as ações e o estado da batedeira.
 * 
 */

#include "Batedeira.h"

Batedeira::Batedeira(void) {
    processoBatedeira(false);
}

void Batedeira::processoBatedeira(bool estado) {
    if (estado) {
        setVelocidade(getVelocidade());
        ativaRGB(0,255,0);
    } else {
        setVelocidade(0);
        ativaRGB(255,0,0);
    }
}

void Batedeira::setVelocidade(uint8_t velocidade) {
    ativaPwm(velocidade);
}

uint8_t Batedeira::getVelocidade(void) {
    return lePotenciometro();
}

uint8_t Batedeira::getPorcentagem(void) {
    return porcentagem(getVelocidade());
}