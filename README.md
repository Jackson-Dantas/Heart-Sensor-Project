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

```
## Configuração do Node-RED
Instalação
Instale o Node-RED seguindo as instruções em: https://nodered.org/docs/getting-started/local
Instale o nó serial no Node-RED:
Abra o Node-RED no navegador (http://localhost:1880).
Vá para o menu (três linhas horizontais no canto superior direito) -> Manage palette.
Na aba Install, procure por node-red-node-serialport e instale-o.
Fluxo Node-RED
Importe o seguinte fluxo no Node-RED para ler os dados da porta serial e publicá-los no servidor MQTT:



[
    {
        "id": "serial_in_node_id",
        "type": "serial in",
        "z": "flow_id",
        "name": "",
        "serial": "serial_port_id",
        "x": 200,
        "y": 200,
        "wires": [
            [
                "mqtt_out_node_id",
                "debug_node_id"
            ]
        ]
    },
    {
        "id": "mqtt_out_node_id",
        "type": "mqtt out",
        "z": "flow_id",
        "name": "",
        "topic": "sensor/heartRate",
        "qos": "0",
        "retain": "false",
        "broker": "mqtt_broker_id",
        "x": 400,
        "y": 200,
        "wires": []
    },
    {
        "id": "debug_node_id",
        "type": "debug",
        "z": "flow_id",
        "name": "",
        "active": true,
        "tosidebar": true,
        "console": false,
        "tostatus": false,
        "complete": "true",
        "targetType": "full",
        "x": 400,
        "y": 300,
        "wires": []
    },
    {
        "id": "serial_port_id",
        "type": "serial-port",
        "z": "",
        "serialport": "COM4",
        "serialbaud": "9600",
        "databits": "8",
        "parity": "none",
        "stopbits": "1",
        "xonxoff": false,
        "rtscts": false,
        "dsrdtr": false,
        "cts": false,
        "dtr": false,
        "rts": false
    },
    {
        "id": "mqtt_broker_id",
        "type": "mqtt-broker",
        "z": "",
        "name": "",
        "broker": "test.mosquitto.org",
        "port": "1883",
        "clientid": "",
        "usetls": false,
        "compatmode": true,
        "keepalive": "60",
        "cleansession": true,
        "birthTopic": "",
        "birthQos": "0",
        "birthPayload": "",
        "closeTopic": "",
        "closePayload": "",
        "willTopic": "",
        "willQos": "0",
        "willPayload": ""
    }
]

### Configuração do Fluxo
Importar o Fluxo:

No Node-RED, clique no menu (três linhas horizontais) -> Import -> Clipboard.
Cole o JSON acima e clique em Import.
Configurar a Porta Serial:

Clique duas vezes no nó serial in para abrir a configuração.
Configure a porta serial (COM4) e o baud rate (9600).
Configurar o Broker MQTT:

Clique duas vezes no nó mqtt out para abrir a configuração.
Clique no ícone de lápis ao lado de Server e configure o broker MQTT (test.mosquitto.org).
Salvar e Implementar:

Clique no botão Deploy no canto superior direito para salvar e iniciar o fluxo.
Teste da Integração
Conectar o Arduino ao computador usando o cabo USB.
Carregar o código no Arduino usando o Arduino IDE.
Abrir o Node-RED no navegador (http://localhost:1880).
Verificar as Mensagens no Node-RED:
As leituras da frequência cardíaca aparecerão no painel de depuração do Node-RED.
As mensagens serão publicadas no tópico sensor/heartRate no broker MQTT test.mosquitto.org.

### Ferramentas de Verificação
Para verificar se os dados estão sendo publicados corretamente no broker MQTT, você pode usar ferramentas como:

MQTT Explorer
MQTT.fx
Conecte-se ao broker test.mosquitto.org e inscreva-se no tópico sensor/heartRate para visualizar as mensagens publicadas.

Conclusão
Este projeto demonstra como integrar um Arduino Uno com o Node-RED e publicar dados em um servidor MQTT. Utilizando a porta serial COM4, os dados do sensor de frequência cardíaca são lidos pelo Arduino e enviados ao Node-RED, que os publica no broker MQTT, facilitando a comunicação em aplicações de IoT.


