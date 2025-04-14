# 🧑‍💻 Integrantes do Grupo
-Gabriel Akira           RM:565191           GitHub: Gakira06

-Gustavo Francisco       RM:561820           GitHub:

-José Rafael             RM:561849           GitHub: ZekiosZ

-Mauro Carlos            RM:556645           GitHub: DevMauroMaia

---

# Sensor de Luminosidade de 3 Níveis com Arduino

Este projeto consiste em um sistema de medição de luminosidade usando um "LDR (sensor de luz)", que ativa diferentes LEDs e um buzzer de acordo com a intensidade da luz no ambiente. Ele simula um semáforo de alerta: verde (ok), amarelo (atenção), e vermelho com buzzer (luz forte demais).

🔗 Acesse o projeto no Tinkercad:  
[Sensor de Luminosidade - 3 Níveis](https://www.tinkercad.com/things/4Envz2lJSud-sensor-de-luminosidade-3-niveis-?sharecode=Re9cIGe-s3GCfMcCq9KdghMA0Hda6GjprUWEYPvTazk)

---

-💡 Funcionamento

O projeto lê continuamente o valor de luminosidade (de 54 a 974(No thinkercad)) a partir do LDR e age da seguinte forma:

- Luminosidade ≤ 600: LED verde acende.
- 601 < Luminosidade ≤ 801: LED amarelo acende.
- Luminosidade > 802: LED vermelho acende e o buzzer toca por 3 segundos.

---

-🧰 Componentes utilizados

- 1x Arduino UNO R3
- 1x LDR (sensor de luz)
- 1x LED verde
- 1x LED amarelo
- 1x LED vermelho
- 1x Buzzer piezoelétrico
- 3x Resistores (220Ω para LEDs, 10kΩ para o LDR)
- 1x Protoboard
- Jumpers

---

-🧩 Dependências

Nenhuma biblioteca externa é necessária. O projeto é feito apenas com comandos nativos do Arduino IDE.

---

- 🚀 Como reproduzir

1. Acesse o link do projeto no Tinkercad:  
   [Abrir Projeto no Tinkercad](https://www.tinkercad.com/things/4Envz2lJSud-sensor-de-luminosidade-3-niveis-?sharecode=Re9cIGe-s3GCfMcCq9KdghMA0Hda6GjprUWEYPvTazk)

2. Clique em "Tinker This" ou "Simular" para iniciar a simulação.

3. Alterne a luminosidade simulada (clicando no LDR) para ver os LEDs e o buzzer reagirem.

---

- 📷 Visão geral do circuito

O circuito está montado em uma protoboard, com os LEDs conectados a portas digitais e o LDR ligado a uma entrada analógica (A0) com divisor de tensão.

---

- 🛠 Código-fonte básico

int ledPinVerd= 13;
int ledPinAm= 12;
int ledPinVer= 8;
int valorluz= 0;
int ldrpin= A0;
int buzzer= 7;

void setup()
{

pinMode(ledPinVerd, OUTPUT);
pinMode(ledPinAm, OUTPUT);
pinMode(ledPinVer, OUTPUT);
Serial.begin(9600);

}
void loop()
{
Serial.println (valorluz);
valorluz = analogRead(ldrpin);
 if (valorluz <= 600) {
    digitalWrite(ledPinVerd, HIGH);
  }else{
       digitalWrite(ledPinVerd, LOW);
   }

delay(100);
  if (valorluz > 601 && valorluz <=801){
    digitalWrite(ledPinAm, HIGH);
  } else {
    digitalWrite(ledPinAm, LOW);
}

delay(100);
  if (valorluz >802){
    digitalWrite(ledPinVer, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(3000);
    digitalWrite(buzzer, LOW);
  } else {
    digitalWrite(ledPinVer, LOW);
    digitalWrite(buzzer, LOW);
}
}
