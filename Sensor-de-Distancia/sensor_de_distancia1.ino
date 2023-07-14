// C++ code
//

//Define o nome usado para cada pino na programação//
#define triggerPin 2
#define echoPin 3
#define motor 10
#define triggerPin2 4
#define triggerPin3 7
#define echoPin2 5
#define echoPin3 6
#define motor2 9
#define motor3 11
#define botao 12


//Variáveis que serão usadas para o cálculo//
//da distância do sensor//
float distancia;
float duracao;
float velocidade=0.0172316;
float distancia2;
float duracao2;
float velocidade2=0.0172316;
float distancia3;
float duracao3;
float velocidade3=0.0172316;

//A função de leitura do sensor e o retorno//
//em distância para a variável//
//Sensor de trás//
void readUltrasonicSensor(){
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  duracao = pulseIn(echoPin, HIGH);
  distancia = duracao * velocidade;
  Serial.print(distancia);
  Serial.println("cm atras");
  delay(500);
}
//Sensor da direita//
void readUltrasonicSensor2(){
  digitalWrite(triggerPin2,LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin2,LOW);
  duracao2 = pulseIn(echoPin2, HIGH);
  distancia2 = duracao2 * velocidade2;
  Serial.print(distancia2);
  Serial.println("cm direita ");
  delay(500);
}
//Sensor da esquerda//
void readUltrasonicSensor3(){
  digitalWrite(triggerPin3,LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin3,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin3,LOW);
  duracao3 = pulseIn(echoPin3, HIGH);
  distancia3 = duracao3 * velocidade3;
  Serial.print(distancia3);
  Serial.println("cm esquerda ");
  delay(500);
}

void setup(){
  pinMode(botao, INPUT_PULLUP);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(triggerPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  //Essa é a parte responsavel pelo modo 2//
  //Se o botão estiver ligado irá entrar no modo2//
  //Se não, seguirá para o modo principal//
  if(digitalRead(botao)== LOW){
    Serial.println("aqui na parte 1 ta ok");
    readUltrasonicSensor();
    int ultdist=distancia;
    while(digitalRead(botao)== LOW){
      Serial.println("ok tambem na parte 2");
      analogWrite(motor,255);
      readUltrasonicSensor();
      while(ultdist<=distancia + 5 && ultdist>= distancia - 5 && digitalRead(botao)!= HIGH){
        analogWrite(motor,0);
        readUltrasonicSensor();
        Serial.println("parte 3 ok");
      }
    }
  }
  //Modo principal//
  //Faz leitura de cada sensor e manda o comando//
  //Para o motor de vibração logo em seguida//
  readUltrasonicSensor();
  if(distancia>100) analogWrite(motor,0);
  if(distancia<=100)analogWrite(motor,70);
  if(distancia<=50) analogWrite(motor,127);
  if(distancia<=25) analogWrite(motor,200);
  if(distancia<10)analogWrite(motor,0);
  
  readUltrasonicSensor2();
  if(distancia2>100)analogWrite(motor2,0);
  if(distancia2<=100) analogWrite(motor2,70);
  if(distancia2<=50) analogWrite(motor2,127);
  if(distancia2<=25){
    analogWrite(motor2,200);
    Serial.println("motor 2 vibrando");
  }
  if(distancia2<10)analogWrite(motor2,0);
  
  readUltrasonicSensor3();
  if(distancia3>100) analogWrite(motor3,0);
  if(distancia3<=100)analogWrite(motor3,70);
  if(distancia3<=50) analogWrite(motor3,127);
  if(distancia3<=25) analogWrite(motor3,200);
  if(distancia3<10)analogWrite(motor3,0);
  
 
}