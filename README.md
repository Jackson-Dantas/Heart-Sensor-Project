# Heart-Sensor-Project

# Sensor de Frequência Cardíaca com Arduino Uno e MQTT

Este projeto consiste em um sensor de frequência cardíaca que utiliza uma placa Arduino Uno para medir os batimentos cardíacos e se conecta à internet através do Node-RED e do protocolo MQTT.

## Componentes Necessários

- Arduino Uno
- Sensor de frequência cardíaca 
- Gravity: IO Expansion Shield for Arduino V7.1


## Montagem

1. Conecte o sensor de frequência cardíaca ao Arduino Uno seguindo o esquema de pinos adequado.
2. Abra o Node-RED e crie um fluxo para receber os dados do sensor.
3. Configure o fluxo para publicar os dados via MQTT.

## Instalação

1. Clone este repositório para o seu computador.
2. Abra o Node-RED e importe o fluxo fornecido no arquivo `flow.json`.
3. Configure as credenciais MQTT no Node-RED.
4. Carregue o código Arduino (`heart_rate_sensor.ino`) no Arduino Uno.

## Uso

- Execute o fluxo no Node-RED.
- O sensor de frequência cardíaca começará a medir os batimentos cardíacos.
- Os dados serão publicados no tópico MQTT configurado.


## Licença

Este projeto está licenciado sob a licença MIT - consulte o arquivo LICENSE para obter detalhes.


