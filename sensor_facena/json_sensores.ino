String json_sensores(){
    //Lectura de los sensores
    float Humedad = dht.getHumidity();
    float Temperatura = dht.getTemperature();
    float lux = lightMeter.readLightLevel();
    IPAddress ip = WiFi.localIP();

    //Transformación de tipos a Char
    char hum[8];
    dtostrf(Humedad, 6, 2, hum); 
    char tem[8];
    dtostrf(Temperatura, 6, 2, tem); 
    char luz[8];
    dtostrf(lux, 6, 2, luz); 
    String ipLocal="";
    for (int i=0; i<4; i++) {
      ipLocal += i  ? "." + String(ip[i]) : String(ip[i]);
    } 

    //Construcción del Objeto JSON
    StaticJsonBuffer<200> doc;
    JsonObject& root = doc.createObject();
    root["Nodo"] = String(ESP.getChipId());
    root["localIP"] = ipLocal;
    root["temp"] = tem;
    root["hum"] = hum;
    root["luz"] = luz;
    String output;
    root.printTo(output);
    return output;
}