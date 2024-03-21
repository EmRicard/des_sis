const int sensorUmidadePin = A0; // Pino analógico onde o sensor de umidade está conectado
const int sensorTemperaturaPin = A1;
const int redLED1 = 9; // Pinos para os LEDs vermelhos
const int redLED2 = 8;
const int orangeLED1 = 11; // Pinos para os LEDs laranjas
const int orangeLED2 = 10;
const int greenLED1 = 13; // Pinos para os LEDs verdes
const int placa1 = 12;
const int placa2 = 7;
const int placa3 = 6;
const int placa4 = 5;
const int placa5 = 4;
const int placa6 = 3;
const int placa7 = 2;

void setup()
{
    Serial.begin(9600);                   // Inicializa a comunicação serial
    pinMode(sensorUmidadePin, INPUT);     // Define o pino do sensor de umidade como entrada
    pinMode(sensorTemperaturaPin, INPUT); // Define o pino do sensor de temperatura como entrada
    pinMode(greenLED1, OUTPUT);           // Define os pinos dos LEDs como saída
    pinMode(orangeLED1, OUTPUT);
    pinMode(orangeLED2, OUTPUT);
    pinMode(redLED1, OUTPUT);
    pinMode(redLED2, OUTPUT);
    pinMode(placa1, OUTPUT);
    pinMode(placa2, OUTPUT);
    pinMode(placa3, OUTPUT);
    pinMode(placa4, OUTPUT);
    pinMode(placa5, OUTPUT);
    pinMode(placa6, OUTPUT);
    pinMode(placa7, OUTPUT);
}

void loop()
{
    int sensorUmidadeValue = analogRead(sensorUmidadePin);         // Lê o valor do sensor de umidade
    int sensorTemperaturaValue = analogRead(sensorTemperaturaPin); // Lê o valor do sensor de temperatura

    // Converte o valor do sensor de temperatura para Celsius
    float temperaturaCelsius = map(((sensorTemperaturaValue - 20) * 3.04), 0, 1023, -40, 125);

    Serial.print("Umidade do Solo: ");
    Serial.println(sensorUmidadeValue); // Imprime a umidade do solo na porta serial
    Serial.print("Temperatura: ");
    Serial.print(temperaturaCelsius);
    Serial.println(" C"); // Imprime a temperatura na porta serial

    if ((temperaturaCelsius >= 20 && temperaturaCelsius <= 30))
    {
        // Temperatura normal - acende LEDs verdes
        digitalWrite(redLED1, LOW);
        digitalWrite(redLED2, LOW);
        digitalWrite(orangeLED1, LOW);
        digitalWrite(orangeLED2, LOW);
        digitalWrite(greenLED1, HIGH);
    }
    else if ((temperaturaCelsius >= 19 && temperaturaCelsius <= 21) || (temperaturaCelsius >= 31 && temperaturaCelsius <= 37))
    {
        // Temperatura em faixa crítica - acende LEDs laranjas
        digitalWrite(redLED1, LOW);
        digitalWrite(redLED2, LOW);
        digitalWrite(orangeLED1, HIGH);
        digitalWrite(orangeLED2, HIGH);
        digitalWrite(greenLED1, LOW);
    }
    else
    {
        // Temperatura muito baixa ou muito alta - acende LEDs vermelhos
        digitalWrite(redLED1, HIGH);
        digitalWrite(redLED2, HIGH);
        digitalWrite(orangeLED1, LOW);
        digitalWrite(orangeLED2, LOW);
        digitalWrite(greenLED1, LOW);
    }

    if (sensorUmidadeValue < 50)
    {
        digitalWrite(placa1, LOW);
        digitalWrite(placa2, LOW);
        digitalWrite(placa3, HIGH);
        digitalWrite(placa4, LOW);
        digitalWrite(placa5, HIGH);
        digitalWrite(placa6, LOW);
        digitalWrite(placa7, LOW);
    }
    else if (sensorUmidadeValue >= 50 && sensorUmidadeValue < 150)
    {
        digitalWrite(placa1, HIGH);
        digitalWrite(placa2, HIGH);
        digitalWrite(placa3, LOW);
        digitalWrite(placa4, HIGH);
        digitalWrite(placa5, HIGH);
        digitalWrite(placa6, LOW);
        digitalWrite(placa7, HIGH);
    }
    else if (sensorUmidadeValue >= 150 && sensorUmidadeValue < 680)
    {
        digitalWrite(placa1, LOW);
        digitalWrite(placa2, HIGH);
        digitalWrite(placa3, HIGH);
        digitalWrite(placa4, HIGH);
        digitalWrite(placa5, HIGH);
        digitalWrite(placa6, LOW);
        digitalWrite(placa7, HIGH);
    }
    else
    {
        digitalWrite(placa1, LOW);
        digitalWrite(placa2, LOW);
        digitalWrite(placa3, HIGH);
        digitalWrite(placa4, LOW);
        digitalWrite(placa5, HIGH);
        digitalWrite(placa6, HIGH);
        digitalWrite(placa7, HIGH);
    }
}