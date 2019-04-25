/*
 * Source Batedeira.cpp
 *
 * Autor: Josue Lopes
 * 
 * Função: Configurar as ações e o estado da batedeira.
 * 
 */

#include "Batedeira.h"

Pins Batedeira::pins = Pins();

Batedeira::Batedeira() {
    Batedeira::pins = Pins();
}

void Batedeira::processoBatedeira(bool estado) {
    if (estado) {
        setVelocidade(getVelocidade());
    } else {
        setVelocidade(0);
    }
}

void Batedeira::setVelocidade(uint8_t velocidade) {
    Batedeira::pins.ativaTriac(velocidade);
}

uint8_t Batedeira::getVelocidade(void) {
    return Batedeira::pins.lePotenciometro();
}

uint8_t Batedeira::getPorcentagem(void) {
    return Batedeira::pins.porcentagem(getVelocidade());
}