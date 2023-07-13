#include <LiquidCrystal.h>

#define botao_h 7 //botão das horas
#define botao_m 6 //botão dos minutos
#define botao_s 5 //botão dos segundos
#define botao 3 //botão responsavel para escolher se vai aumentar
#define BOTAOM 4
#define BUZZER 2
//ou diminuir no ajuste de horario

LiquidCrystal lcd(13,12,11,10,9,8);
int h=0,m=0,s=0; 
int h_a=23,m_a=59,s_a=0;
int tempo_atual=0, tempo_anterior=0;
// Armazena o valor de seno que fazer o valor se elevar e diminuir
float sinVal;
// Pega o valor armazenado em sinVal e converte-o para frequência...
//solicitada
int toneVal;


void tempo()//responsavel pelo tempo que ira passar os segundos
{
  tempo_atual = (millis()/1000); //puxa o tempo que o arduino está
  //ligado, e divide por mil para ficar em segundos
  //por ser variavel inteiro, não ira ter casas decimais
  
  if(tempo_atual != tempo_anterior){//um laço para testar se passou
    //um segundo
    tempo_anterior = tempo_atual;
    s++;
    if( s==60){//para aumentar o minuto se o segundos chegar a 60
      s=0;
      m++;
    }
    
    if( m== 60){//aumenta as horas se o minuto chegar a 60
      m=0;
      h++;
    }
    if( h==24){//zera as horas se chegar a 24
      h=0;
    }
  }
}

void conf()//Função responsavel pelos botao
{
  if( digitalRead(botao_s) == LOW ){
    if(digitalRead(botao) ==LOW ){//aumenta os segundos
      s++;
      delay(250);
    }else {
      s--;
      delay(250);
    
    }//diminui os segundos
  }
  if( digitalRead(botao_m) == LOW ) {
    if(digitalRead(botao) == LOW ) {//aumenta os minutos
      m++;
      delay(250);
    
    } else {
      
      m--;
        
        delay(250);
    }//diminui os minutos
  }
  if( digitalRead(botao_h) == LOW ) {
    if(digitalRead(botao) == LOW ) {//aumenta as horas
      h++;
      delay(250);
      
    } else {
      
      h--;
      delay(250);
    
    }//diminui as horas
  }
  if(s==60){
      s=0;   
  }
  if(s<0){
      s=59;
    }
  if(m==60){
    m=0;
  }
  if(m<0){
      m=59;
    }
  if(h==24){
    h=0;
  }
  if(h<0){
    h=23;
  }
  
}

void alarme()//função que ajusta o horario do despertador
{
  if(digitalRead(BOTAOM)== LOW){
    delay(250);
    lcd.clear();//Para limpar o visor
    
  while (digitalRead(BOTAOM) != LOW){
    tempo();//para o tempo continuar contando
    lcd.setCursor(2,0);
    lcd.print("ALARME");//colocar a indicação no visor que esta
    //no modo de edição do alarme
    
    if(h_a<10){lcd.setCursor(1,1);lcd.print("H:0");lcd.print(h_a);}
    if(h_a>=10){lcd.setCursor(1,1);lcd.print("H:");lcd.print(h_a);}

    if(m_a<10){lcd.setCursor(6,1);lcd.print("M:0");lcd.print(m_a);}
    if(m_a>=10){lcd.setCursor(6,1);lcd.print("M:");lcd.print(m_a);}

    if(s_a<10){lcd.setCursor(11,1);lcd.print("S:0");lcd.print(s_a);}
    if(s_a>=10){lcd.setCursor(11,1);lcd.print("S:");lcd.print(s_a);}
    
    /*Essa parte é para o ajuste*/
    if( digitalRead(botao_s) == LOW ){
    if(digitalRead(botao) ==LOW ){//aumenta os segundos
      s_a++;
      delay(250);
    }else {
      s_a--;
      delay(250);
    
    }//diminui os segundos
  }
  if( digitalRead(botao_m) == LOW ) {
    if(digitalRead(botao) == LOW ) {//aumenta os minutos
      m_a++;
      delay(250);
    
    } else {
      
      m_a--;
        
        delay(250);
    }//diminui os minutos
  }
  if( digitalRead(botao_h) == LOW ) {
    if(digitalRead(botao) == LOW ) {//aumenta as horas
      h_a++;
      delay(250);
      
    } else {
      
      h_a--;
      delay(250);
    
    }//diminui as horas
  }
  if(s_a==60){
      s_a=0;   
  }
  if(s_a<0){
      s_a=59;
    }
  if(m_a==60){
    m_a=0;
  }
  if(m_a<0){
      m_a=59;
    }
  if(h_a==24){
    h_a=0;
  }
  if(h_a<0){
    h_a=23;
  }
  }//apos sair do ajuste, ele limpa o visor e mostra como antes
   lcd.clear();
   lcd.setCursor(2,0);
   lcd.print("RELOGIO  LCD");
  }
}
   
void despertar()//função responsavel por despertar o relogio
{
  if ( h_a == h && m_a == m && (s_a <= s && s<= s_a + 10) ){
    //foi adicionado esse if apenas para depois do while 
    //ser capaz colocar um limpa tela e printar a palavra
    //relogio depois
  while ( h_a == h && m_a == m && (s_a <= s && s<= s_a + 10) )
  {//verifica se o horario é o mesmo para despertar
    lcd.clear();
    lcd.setCursor(2,1);
    lcd.print("DESPERTANDO");
    delay(150);
    tempo();//o tempo conta para saber quando parar
    som();//emitir o som
    if(digitalRead(botao_h) ==LOW){//ao acionar o botao de aumentar
      //as horas, ele coloca no modo soneca
      noTone(BUZZER);
      s_a = s + 10;
    }
    if (digitalRead(botao_m) == LOW) {//ao acionar o botao de aumentar
      //os minutos, ele para o despertador
      noTone(BUZZER);
      m_a-=1;
    }
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("RELOGIO  LCD");
    
  }
  }
  noTone(BUZZER);
}
void som()//função para o som do despertador
{
  // Converte graus para radianos, e depois obtém o valor do seno
for (int x=0; x<180; x++) {

// Gera uma frequência a partir do valor do seno
sinVal = (sin(x*(3.1416/180)));

// Pega 2000 e adiciona sinVal multiplicando por 1000, gerando um...
//bom intervalo de frequências para o tom crescente e decrescente da...
//onda senoidal
toneVal = 2000+(int(sinVal*1000));

// O comando ton( ) é definido como ton(pin, frequency), o pin...
//corresponde o pino digital de saída e frequency é a frequência do...
//tom em Hertz
tone(BUZZER, toneVal);

delay(2); // Espera dois milissegundos entre as alterações de frequência
}
}
  
void setup()
{
   pinMode(BUZZER, OUTPUT);
   pinMode(BOTAOM, INPUT_PULLUP);
   pinMode(botao, INPUT_PULLUP);
   pinMode(botao_h, INPUT_PULLUP);
   pinMode(botao_m, INPUT_PULLUP);
   pinMode(botao_s, INPUT_PULLUP);
   lcd.begin(16, 2); 
   lcd.clear();
   lcd.setCursor(2,0);
   lcd.print("RELOGIO  LCD");
   
}
 
void loop()
{
   tempo();
   conf();
   alarme();
   despertar();
   
   
  
   if(h<10){lcd.setCursor(1,1);lcd.print("H:0");lcd.print(h);}
   if(h>=10){lcd.setCursor(1,1);lcd.print("H:");lcd.print(h);}

   if(m<10){lcd.setCursor(6,1);lcd.print("M:0");lcd.print(m);}
   if(m>=10){lcd.setCursor(6,1);lcd.print("M:");lcd.print(m);}

   if(s<10){lcd.setCursor(11,1);lcd.print("S:0");lcd.print(s);}
   if(s>=10){lcd.setCursor(11,1);lcd.print("S:");lcd.print(s);}
}
