#include <SoftwareSerial.h>
#include "DHT.h"
#include <GyverBME280.h>

#define DHTPIN 2
#define SSID  " " //  имя wi-fi
#define PASS  " " //  пароль вашего wi-fi

#define RXPIN 11
#define TXPIN 10
 
String IP = "open-monitoring.online";
#define esp_bitrate 9600

DHT dht(DHTPIN, DHT11);
GyverBME280 bme;
SoftwareSerial espSerial(RXPIN, TXPIN);

long nextTime = 1000;
String ID = " ";
String KEY = " ";
long interval = 8000;

int irsensor1= 5;                  
int irsensor2= 6;
int photoresistorPin = A1; 
int sensorvalue1, sensorvalue2;
int N=0, m=0;
String KoTVdome="";
int TimeVivod=1;

String GET = "GET /get?cid=" + ID + "&key=" + KEY;
String HOST = "Host:" + IP + "\r\n\r\n";

void setup()
{ 
  Serial.begin(esp_bitrate);
  espSerial.begin(esp_bitrate);

  sendespSerial("AT");
  delay(1000);

  if(espSerial.find("OK")){
    Serial.println("Start working!!!");
    Serial.println("Received ESP: OK");
    connectWiFi();
  }
}

void loop() 
{
  pinMode(irsensor1,INPUT);                
  pinMode(irsensor2,INPUT);
  ///////////////////////////////////
 sensorvalue1=digitalRead(irsensor1);    
 sensorvalue2=digitalRead(irsensor2);
 while (sensorvalue1==0){
  if (sensorvalue2==1) {
   N=1;
   sensorvalue1=digitalRead(irsensor1);    
   sensorvalue2=digitalRead(irsensor2);   
  }
  if (sensorvalue2==0 && N==1) {
   N=2;
   sensorvalue1=digitalRead(irsensor1);    
   sensorvalue2=digitalRead(irsensor2);   
  }
  else sensorvalue1 = 1;
}

 sensorvalue1=digitalRead(irsensor1);    
 sensorvalue2=digitalRead(irsensor2);
 if (N==2) {
  if (sensorvalue1==1 && sensorvalue2==1){
     KoTVdome="НЕТ";
    N=0;
  }
 }
 sensorvalue1=digitalRead(irsensor1);    
 sensorvalue2=digitalRead(irsensor2);
 while (sensorvalue2==0){
  if (sensorvalue1==1) {
   m=1;
   sensorvalue1=digitalRead(irsensor1);    
   sensorvalue2=digitalRead(irsensor2);   
  }
  if (sensorvalue1==0 && m==1) {
   m=2;
   sensorvalue1=digitalRead(irsensor1);    
   sensorvalue2=digitalRead(irsensor2);   
  }
  else sensorvalue2 = 1;
}
 sensorvalue1=digitalRead(irsensor1);    
 sensorvalue2=digitalRead(irsensor2);
 if (m==2) {
  if (sensorvalue1==1 && sensorvalue2==1){
    KoTVdome="ДА";
    m=0;
  }
 }
 //////////////////////////////////////
  dht.begin();
  bme.begin(0x76);
  float h = dht.readHumidity(); //влажность
  float t = bme.readTemperature(); //температура
  float p = (bme.readPressure()/133.32); //давление
  //int l = analogRead(photoresistorPin);
  delay(2000);

  String T1 = String(h); // turn integer to string
  String T2 = String(t); 
  String T3 = String(p);
  //String T4 = String(l, DEC);
  //String T5 = KoTVdome;

  Serial.println(millis());
  //TimeVivod+=1;

  Serial.print("Влажность: ");
  Serial.print(T1);
  Serial.println("%");
  Serial.print("Температура: ");
  Serial.print(T2);
  Serial.println("*C");
  Serial.print("Атмосферное давление: ");
  Serial.print(T3);
  Serial.println(" мм рт.ст.");
  Serial.print("Освещенность: ");
  //Serial.println(T4); 
  Serial.print("Наличие питомца в доме: ");
  //Serial.println(T5);
 Serial.println();

 if ( millis() - nextTime > (interval - 4215) ) {
      update_param(T1, T2, T3); // Отправляем пакет на сервер, если добавляются еще параметры - дописать через запятую
      nextTime = millis();
      }
  //TimeVivod=TimeVivod-1999;
  
}

void sendespSerial(String cmd){
  Serial.print("SEND: ");
  Serial.println(cmd);
  espSerial.println(cmd);
}

boolean connectWiFi(){
      espSerial.println("AT+CWMODE=1");
      delay(2000);
      String cmd = "AT+CWJAP=\"";
      cmd+= SSID;
      cmd+= "\",\"";
      cmd+= PASS;
      cmd+= "\"";
      sendespSerial(cmd);
      delay(5000);
      if(espSerial.find("OK")){
        Serial.println("Connect: OK");
        return true;
      }
      else{
        Serial.println("Connect: ERROR");
        return false;  
      }

      cmd = "AT+CIPMUX=0"; 
      sendespSerial(cmd);
      if(espSerial.find("ERROR")){
        Serial.println("Received: error");
        return true;
      }
}


//*--- Отправка данных на сервер, если есть параметры, так же дописать через запятую с указанием типа, например: String T3
void update_param(String T1, String T2, String T3) {

  String cmd = "AT+CIPSTART=\"TCP\",\"";// Setup TCP connection
  cmd += IP;
  cmd += "\",80";
  sendespSerial(cmd);
  delay(1000);

  if ( espSerial.find( "Error" ) )
  {
    Serial.print( "RECEIVED: Error\nExit1" );
    return;
  }

  // Отправка строки на сервер
  cmd = GET + "&p1=" + T1; 
  cmd += "&p2=" + T2; 
  cmd += "&p3=" + T3;
  //cmd += "&p4=" + T4;
  cmd += " HTTP/1.1\r\n"  + HOST;
  espSerial.print( "AT+CIPSEND=" );
  espSerial.println( cmd.length() );
  if (espSerial.find( ">" ) )
  {
    Serial.print(">");
    Serial.print(cmd);
    espSerial.print(cmd);
    delay(30);
  }
  else
  {
    sendespSerial( "AT+CIPCLOSE" );//close TCP connection
  }
  if ( espSerial.find("OK") )
  {
    Serial.println( "RECEIVED: OK" );
  }
  else
  {
    Serial.println( "RECEIVED: Error\nExit2" );
  }
  serialread(); // Закомментировать после отладки
}

//*-- Отладочная функция 
String s = "";
void serialread() {
  while (espSerial.available()) {
    delay(20);
    if (espSerial.available() > 0) {
      char c = espSerial.read();
      s += c;
    }
  }
  Serial.println(s);
  Serial.println("\r\n");
  s = "";
}
