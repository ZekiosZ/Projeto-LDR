int ledPinVerd= 13; /// led verde
int ledPinAm= 12; /// led amarelo
int ledPinVer= 8; /// led vermelho
int valorluz= 0; /// valor que o sensor de luz manda pra placa
int ldrpin= A0; /// sensor de luz
int buzzer= 7; /// buzina

void setup()
{

pinMode(ledPinVerd, OUTPUT);
pinMode(ledPinAm, OUTPUT);
pinMode(ledPinVer, OUTPUT);
Serial.begin(9600); /// Taxa de transferência de bits por segundo

}
void loop()
{
Serial.println (valorluz); /// vai falar o valor que o sensor de luz manda pra placa
valorluz = analogRead(ldrpin);
if (valorluz <= 600) {
    digitalWrite(ledPinVerd, HIGH);  /// Se o valor da luz for menor igual a 600, o LED verde irá ligar
    }else {
        digitalWrite(ledPinVerd, LOW);  /// Caso o valor da luz for maior que 600, o LED verde irá desligar
        }

delay(100);
if (valorluz > 600 && valorluz <=801) {
    
    digitalWrite(ledPinAm, HIGH); /// Se o valor da luz for maior que 600 e menor igual a 801, o LED amarelo irá ligar
    
    }else {
        
        digitalWrite(ledPinAm, LOW); /// Caso o valor da luz nao tiver dentro desse parametro, o LED amarelo irá desligar
        }

delay(100);

if (valorluz > 801) { ///se o valor da luz for maior que 801
    
    digitalWrite(ledPinVer, HIGH); /// Irá ligar o LED vermelho
    tone(buzzer, 500);  ///liga o buzzer com a frequencia de 500hz
    delay(3000);
    noTone(buzzer); /// Irá tocar a buzina por 3 segundos e logo depois desligar, se continuar o LED vermelho continuar ligado a buzina irá tocar de novo
  
    }else {
        digitalWrite(ledPinVer, LOW);
        digitalWrite(buzzer, LOW);  ///Se o valor da luz não for maior que 801 
        }
}