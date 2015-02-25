//Declaramos los pines de entrada.
const int analogInPinX = A0;
const int analogInPinY = A1;

//Declaramos los pines de salida.
const int analogOutPinX = 11;
const int analogOutPinY = 10;

int sensorValueX = 0;	//Valor leido del pin X del accelerometro.
int sensorValueY = 0;	//Valor leido del pin Y del accelerometro.

int outputValueX = 0;	//Valor de salida analogica (PWM).
int outputValueY = 0;	//Valor de salida analogica (PWM).




void setup() {

	Serial.begin(9600);
        
        Serial.println("Acelerometro Tinkerkit");


}//Fin de la funcion setup.




void loop() {

	//Leemos los valores de entrada.
	sensorValueX = analogRead(analogInPinX);
	sensorValueY = analogRead(analogInPinY);

	/*mapeamos los valores leidos para que esten dentro del
	rango de salida analogica. */
	outputValueX = map(sensorValueX, 0, 1023, 0, 255);
	outputValueY = map(sensorValueY, 0, 1023, 0, 255);

	//analogWrite(analogOutPinX, outputValueX);
	//analogWrite(analogOutPinY, outputValueY);

	//Mostramos los resultados por el monitor serie.
	Serial.print("Valor X: ");
	Serial.println(outputValueX);
	Serial.print("Valor Y: ");
	Serial.println(outputValueY);
        Serial.println();

	delay(1000);

}//Fin de la funcion loop.
