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
