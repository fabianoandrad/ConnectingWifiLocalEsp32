#include <WiFi.h>
#include <WebServer.h>

// Dados da sua rede Wi-Fi
const char* ssid = "AFFA_2.4G";
const char* password = "Affa@2307";

WebServer server(80);

void handleRoot()
{
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>ESP32</title>
    </head>

    <body>
      <h1>ESP32 Web Server</h1>
      <p>Conexão funcionando!</p>
    </body>
    </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void setup()
{
  Serial.begin(115200);

  Serial.println();
  Serial.println("Conectando ao Wi-Fi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi conectado!");

  Serial.print("IP do ESP32: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();

  Serial.println("Servidor HTTP iniciado!");
}

void loop()
{
  server.handleClient();
}
