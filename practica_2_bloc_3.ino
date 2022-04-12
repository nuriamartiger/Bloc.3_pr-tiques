/*
Controlant un servo amb un potenciometre.
Utilitzem el port digital 3 PWM pel senyal del servo.
Utilitzem el port analògic A0 pel senyal del potenciometre.
El potenciomentre donarà valors entre 0 i 1023.
El servo necessita valors entre 0 i 180.
La funció map es basa en la següent fórmula: 
(valor_llegit_potenciometre - valor_minim_potenciometre) * (valor_màxim_servo - valor_mínim_servo) / (valor_màxim_potenciometre - valor_mínim_potenciometre) + valor_mínim_servo
O sigui: (valor - 0) * (180-0) / (1023-0) + 0
Robòtica educativa - CRP del Tarragonès
*/

#include <Servo.h>

Servo servo1;  // creem un objecte servo per a controlar un servo

int valor;    // variable que llegeix el valor del pin analògic

void setup() {
  servo1.attach(3);  // connectem el senyal de l'objecte servo al pin 3
}

void loop() {
  valor = analogRead(0);            // llegeix el valor del potenciometre (dóna un valor entre 0 i 1023)
  valor = map(valor, 0, 1023, 0, 180);     // escala el valor obtingut del potenciometre al valor que necessita el servo (0 és 0 i 1023 és 180)
  servo1.write(valor);                  // envia el valor ja escalat al servo
  delay(15);                           // espera un temps breu
}
