const int sensorUmidadePin = A0;     // Pino analógico onde o sensor de umidade está conectado
const int sensorTemperaturaPin = A1; // Pino analógico onde o sensor de temperatura está conectado
const int greenLED1 = 13;            // Pinos para os LEDs verdes
const int greenLED2 = 12;
const int greenLED3 = 7; // Pinos para os LEDs verdes / umidade
const int greenLED4 = 6;
const int orangeLED1 = 11; // Pinos para os LEDs laranjas
const int orangeLED2 = 10;
const int orangeLED3 = 4; // Pinos para os LEDs laranjas / umidade
const int orangeLED4 = 5;
const int redLED1 = 9; // Pinos para os LEDs vermelhos
const int redLED2 = 8;
const int redLED3 = 3; // Pinos para os LEDs vermelhos / umidade
const int redLED4 = 2;

void setup()
{
    Serial.begin(9600);                   // Inicializa a comunicação serial
    pinMode(sensorUmidadePin, INPUT);     // Define o pino do sensor de umidade como entrada
    pinMode(sensorTemperaturaPin, INPUT); // Define o pino do sensor de temperatura como entrada
    pinMode(greenLED1, OUTPUT);           // Define os pinos dos LEDs como saída
    pinMode(greenLED2, OUTPUT);
    pinMode(greenLED3, OUTPUT); // Define os pinos dos LEDs como saída
    pinMode(greenLED4, OUTPUT);
    pinMode(orangeLED1, OUTPUT);
    pinMode(orangeLED2, OUTPUT);
    pinMode(orangeLED3, OUTPUT);
    pinMode(orangeLED4, OUTPUT);
    pinMode(redLED1, OUTPUT);
    pinMode(redLED2, OUTPUT);
    pinMode(redLED3, OUTPUT);
    pinMode(redLED4, OUTPUT);
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

    // Determina o estado dos LEDs com base nos valores lidos
    if ((temperaturaCelsius >= 20 && temperaturaCelsius <= 30))
    {
        // Temperatura normal - acende LEDs verdes
        digitalWrite(redLED1, LOW);
        digitalWrite(redLED2, LOW);
        digitalWrite(orangeLED1, LOW);
        digitalWrite(orangeLED2, LOW);
        digitalWrite(greenLED1, HIGH);
        digitalWrite(greenLED2, HIGH);
    }
    else if ((temperaturaCelsius >= 19 && temperaturaCelsius <= 21) || (temperaturaCelsius >= 31 && temperaturaCelsius <= 37))
    {
        // Temperatura em faixa crítica - acende LEDs laranjas
        digitalWrite(redLED1, LOW);
        digitalWrite(redLED2, LOW);
        digitalWrite(orangeLED1, HIGH);
        digitalWrite(orangeLED2, HIGH);
        digitalWrite(greenLED1, LOW);
        digitalWrite(greenLED2, LOW);
    }
    else
    {
        // Temperatura muito baixa ou muito alta - acende LEDs vermelhos
        digitalWrite(redLED1, HIGH);
        digitalWrite(redLED2, HIGH);
        digitalWrite(orangeLED1, LOW);
        digitalWrite(orangeLED2, LOW);
        digitalWrite(greenLED1, LOW);
        digitalWrite(greenLED2, LOW);
    }

    if (sensorUmidadeValue >= 150 && sensorUmidadeValue <= 750)
    {
        digitalWrite(redLED3, LOW);
        digitalWrite(redLED4, LOW);
        digitalWrite(orangeLED3, LOW);
        digitalWrite(orangeLED4, LOW);
        digitalWrite(greenLED3, HIGH);
        digitalWrite(greenLED4, HIGH);
    }
    else if ((sensorUmidadeValue >= 50 && sensorUmidadeValue <= 850))
    {
        digitalWrite(redLED3, LOW);
        digitalWrite(redLED4, LOW);
        digitalWrite(orangeLED3, HIGH);
        digitalWrite(orangeLED4, HIGH);
        digitalWrite(greenLED3, LOW);
        digitalWrite(greenLED4, LOW);
    }
    else
    {
        digitalWrite(redLED3, HIGH);
        digitalWrite(redLED4, HIGH);
        digitalWrite(orangeLED3, LOW);
        digitalWrite(orangeLED4, LOW);
        digitalWrite(greenLED3, LOW);
        digitalWrite(greenLED4, LOW);
    }

        delay(1000); // Espera 1 segundo antes de ler os sensores novamente
}
