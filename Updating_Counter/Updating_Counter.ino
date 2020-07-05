String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
 
String html_1 = R"=====(
<!DOCTYPE html>
<html>
 <head>
 <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
 <meta charset='utf-8'>
 <style>
  body {font-size:140%;} 
  #main {display: table; margin: auto;  padding: 0 10px 0 10px; } 
  h2 {text-align:center; } 
  .button { padding:10px 10px 10px 10px; width:100%;  background-color: #50FF50; font-size: 120%;}
 </style>
 
 <title>Counter</title>
</head>
<body>
 <div id='main'>
  <h2>Counter</h2>
)=====";
 
String html_2 = "";
 
String html_4 = R"=====(
  </div>
 </body>
</html>
)=====";
 
 
#include <ESP8266WiFi.h>
 
// change these values to match your network
char ssid[] = "12Jason";       //  your network SSID (name)
char pass[] = "samaraza";          //  your network password
 
WiFiServer server(80);
 
String request = "";
int count = 0;

void setup(){
    Serial.begin(115200);
    Serial.println();
    Serial.println("Serial started at 115200");
    Serial.println("ESP8266_LED_CONTROL_AJAX_01");
    Serial.println();
 
    // Connecting to a WiFi network
    Serial.print(F("Connecting to "));  Serial.println(ssid);
    WiFi.begin(ssid, pass);
 
    while (WiFi.status() != WL_CONNECTED) 
    {
        Serial.print(".");
        delay(500);
    }
 
    Serial.println("");
    Serial.println(F("[CONNECTED]"));
    Serial.print("[IP ");              
    Serial.print(WiFi.localIP()); 
    Serial.println("]");
 
    // start a server
    server.begin();
    Serial.println("Server started");
 
}

void loop() 
{
    // Check if a client has connected
    WiFiClient client = server.available();
    if (!client)  {  return;  }

    count = count + 1;
 
    client.flush();
    client.print( header );
    client.print( html_1 );    
    client.print( html_2 );
    client.print("<p> " + String(count) + " </p>");
    client.print( html_4);
 
    delay(5);
  // The client will actually be disconnected when the function returns and 'client' object is detroyed
 
}

