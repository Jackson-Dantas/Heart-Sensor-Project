# Integração Arduino com Node-RED e MQTT

Este projeto demonstra como integrar um Arduino Uno com o Node-RED e publicar dados em um servidor MQTT (Mosquitto Cloud) usando a porta COM4. O sensor de frequência cardíaca é utilizado para coletar os dados que são enviados para o Node-RED via porta serial e, posteriormente, publicados no servidor MQTT.

## Componentes Utilizados

- Arduino Uno
- Gravity: IO Expansion Shield for Arduino V7.1
- Gravity: PPG Heart Rate Monitor Sensor for Arduino (Analog/Digital)
- Node-RED
- Servidor MQTT (Mosquitto Cloud)

## Configuração do Arduino

### Hardware

1. Conecte o Gravity: IO Expansion Shield ao Arduino Uno.
2. Conecte o Gravity: PPG Heart Rate Monitor Sensor ao shield:
   - **VCC** do sensor ao **VCC** do shield.
   - **GND** do sensor ao **GND** do shield.
   - **S (Signal)** do sensor ao pino analógico **A0** do shield.

### Código Arduino

Carregue o seguinte código no Arduino para ler os dados do sensor de frequência cardíaca e enviá-los via porta serial:

```cpp
#define HEART_RATE_SENSOR_PIN A0

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 baud
  Serial.println("Inicializando leitura do sensor de frequência cardíaca...");
  pinMode(HEART_RATE_SENSOR_PIN, INPUT);
}

void loop() {
  int heartRate = analogRead(HEART_RATE_SENSOR_PIN); // Lê o valor do sensor
  Serial.print("Frequência Cardíaca: ");
  Serial.println(heartRate); // Imprime o valor lido no Monitor Serial
  delay(1000); // Espera 1 segundo antes de ler novamente
}


