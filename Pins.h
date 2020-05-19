/*
 * Cabeçalho Pins.h
 *
 * Autor: Josue Lopes
 * 
 * Função: Definir a pinagem dos pinos do Arduino referente
 * ao itens posicionado.
 * 
 */

#ifndef PINS_H
  #define PINS_H
  
  #include <Arduino.h>

  /*
   *                Pinagem do Arduíno Nano
   *    
   *  Pinos Digitais 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13;
   *  Pinos Analógicos: A0, A1, A2, A3, A4, A5, A6 e A7;
   *  Pinos Serial: 0(RX) e 1(TX);
   *  Pinos PWM: 3, 5, 6, 9, 10 e 11; (Por causa do Timer1 os pinos 9 e 10 não possuem PWM)
   *  Pinos com Interrupção Externa: 2, 3;
   *  Pinos I2C: A4(SDA) e A5(SCL);
   *  Pinos SPI: 10(SS), 11(MOSI), 12(MISO), 13(SCK).
   *  
   */

//  *** Sensores e Entradas de Sinal *** 
  #define SENSOR_NIVEL 4     // Pino do Arduíno que recebe o sinal do Sensor de Nível de Líquido
  #define SENSOR_BARREIRA 7  // Pino do Arduíno que recebe o sinal do Sensor de Barreira  
  //#define BOTAO_RESET 12     // Pino do Arduíno que recebe o sinal do Botão Reset

  //Configurar resistor de Pull UP para inverter o sentido do sinal
  //#define SENSOR_NIVEL_PULLUP
  #define SENSOR_BARREIRA_PULLUP
  #define BUZZER_PULLUP
  //#define BOTAO_RESET_PULLUP  

  #define CONTROLE_PWM
  #ifdef CONTROLE_PWM
    #define POTENCIOMETRO A0  // Pino do Arduíno que recebe o sinal do Potênciometro
    #define PWM 3           // Pino do Arduíno que envia sinal para a comutação do Batedeira
  #endif // CONTROLE_PWM

//  *** Atuadores e Saídas de Sinal *** 
  #define BUZZER 8          // Pino do Arduíno que envia sinal para acionar o Buzzer

  #define RGB
  #ifdef RGB
    #define LED_RED 5  // Pino do Arduíno que envia o sinal para a cor VERMELHA do led RGB
    #define LED_GREEN 6 // Pino do Arduíno que envia o sinal para a cor VERDE do led RGB
    #define LED_BLUE 11 // Pino do Arduíno que envia o sinal para a cor AZUL do led RGB
  #endif // RGB

  class Pins {
    public:
      Pins();
      void ativaBuzzer();
      void desativaBuzzer();
      void temporizaBuzzer(uint8_t ms_tempo);
      void oscilaBuzzer(uint8_t tempoLigado, uint8_t tempoDesligado, uint8_t numeroDePulsos);
      
      bool leSensorNivel();
      bool leSensorBarreira();
      bool leBotaoReset();
      
      #ifdef RGB
        void ativaRGB(unsigned char vermelho, unsigned char verde, unsigned char azul);
        void ativaVermelho();
        void desativaVermelho();
        void ativaVerde();
        void desativaVerde();
        void ativaAzul();
        void desativaAzul();
      #endif // RGB
      
      #ifdef CONTROLE_PWM
        int lePotenciometro();
        void ativaPwm(int potenciometro);
        int porcentagem(int potenciometro);
      #endif // CONTROLE_PWM
      
  };
  
#endif //PINS_H
