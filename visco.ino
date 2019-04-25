/*
 *  Source visco.ino
 *  
 *  Autor: Josue Lopes
 *  
 *  Versão: 0.3
 *  
 *  Função: Sistema de controle de viscocidade de líquidos.
 *  
 */
#include "Visco.h"

Visco visco;

void setup() {
  // put your setup code here, to run once:
  visco = Visco();
}

void loop() {
  // put your main code here, to run repeatedly:
  visco.processo();
}
