/* 

UTILITZEM EL SENSOR D'ULTRASONS

*/
int trigpin=8;
int echoPin=9;
1ong duration; //temps d'anada/Sormada 
int cm = 0; //Per enmagatzemar el valor obtingut en cm valor=0

void setup() 
{
Serial.begin(9600); 7;
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop()
{
//posem al trigger a low per activar-lo després 14. digitalWrite (trigPin, LOW);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

//Activar el modul and pois de timberbanc 17. digitalWrite(trigPin, HIGH);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10) ;
digitalWrite(trigPin, LOW);

//Esperem l'arribada d'un pols HIGH
duration= pulseIn (echoPin, HIGH); valor de pola alt en microsecons

//temps d'anada i tornada, dividim per 2

duration=duration/2; 
//La velocitat del so és de 340 m/s
//El pin echo entrega un pols alt d'una durada 29 microsegons per cada centímetre de distància a la que estigui l'obiecte.

cm = duration/29;

Serial.print("Distancia: "); 
Serial.println(cm);

delay(100); // Ens asseguren de que el seguent trigger echo actual no es barregin (recomanen 50 ms).
}
