/* THEREMIN  AMB BUZZER I LDR

Obtenir diferents tons de so d'un buzzer en funció de la llum captada per la LDR.

*/

const int Buzzer=3;
int valorLDR=0;                         // Valor llegit pel LDR.
int freqBuzzer=0;                       //Variable que magatzema el valor de la freqüència del to del buzzer

void setup() 
{
  pinMode (Buzzer, OUTPUT);
  Serial.begin(9600);                        // Inicialitza la comunicació amb el port série a 9600 bauds

}

void loop() 
{
    valorLDR=analogRead(A0)                 // Llegeix el valor analógic de la LDR

/* 
Converteix el rang 0-1023 (valors reajustables) del LDR a un rang d'una freqüencia entrrre 20Hz i 5kHz pels tons del buzzer.
*/

freqBuzzer=map(valorLDR,0,1023,20,5000);      // Es pot experimentar amb aquests valors 20-5000 I canviar-los

tone(Buzzer, freqBuzzer);                     // El buzzer sona amb el to de la frequência guardada

Serial.print("LDR (0-1023)=");                
Serial.print(valorLDR);
Serial.print("\t To del so del buzzer =");
Serial.print(freqBuzzer);

delay(20);
}
