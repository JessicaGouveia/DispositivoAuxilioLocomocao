//Definição das portas de controle
const int trig = 13; //Sensor Ultrasonico
const int echo = 12; //Sensor Ultrasonico
const int led = 11; //Led
const int vibra = 10; //Motor vibracall

void setup(){
  Serial.begin (9600);c
  pinMode(trig, OUTPUT); //Coloca a porta de controle trig como saida
  pinMode(echo, INPUT); //Coloca a porta de controle echo como entrada
  pinMode(led, OUTPUT); //Coloca a porta de controle do led como saida
  digitalWrite(led, LOW); //Inicia com o led desligado
  pinMode(vibra, OUTPUT); //Coloca a porta de controle do motor vibracall como saida
  digitalWrite(vibra, LOW); //Inicia com o motor vibracall desligado.
}

void loop(){
  long duracao; //Variavel para medir a distancia através da duração / tempo.
  long distancia; //Variavel que recebe o valor da distancia em centimetros.
  
  //Inicia a capitação da distancia pelo sensor ultrasonico =========
  digitalWrite(trig, LOW);//Deliga a emissão do sinal            //==
  delayMicroseconds(2);//Aguarda 2 microsegundos                 //==
  digitalWrite(trig, HIGH);//Liga a emissão do sinal             //==
  delayMicroseconds(10);//Aguarda 10 microsegundos               //==
  digitalWrite(trig, LOW);//Deliga a emissão do sinal            //==
                                                                 //==
  duracao = pulseIn(echo, HIGH);//Liga a capitação do sinal      //==
  distancia = duracao / 58; //Calculo da distancia em centimetos //==
  //=================================================================

  //Caso a distancia calculada seja menor ou igual a 1 metro
  if(distancia > 0 && distancia <= 100){
    Serial.print(distancia);
    Serial.println(" cm");
    digitalWrite(trig, LOW); //Deliga o sensor ultrasonico
    digitalWrite(led, HIGH); //Liga o led
    digitalWrite(vibra, HIGH); //Liga o motor vibracall
  }else{ 
    digitalWrite(led, LOW); //Desliga o led
    digitalWrite(vibra, LOW); //Desliga o motor vibracall.
  }
  
  delay(500); //Aguarda meio segundo antes de reiniciar o processo.
}
