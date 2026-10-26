[README.md](https://github.com/user-attachments/files/33984375/README.md)
# ESP32 → ThingSpeak: Temperature & Humidity Monitor

## Full name + University ID
Saleh Albisher — 12217436

## Project description
An ESP32 reads temperature and humidity from a DHT22 sensor (simulated in Wokwi), connects to Wi-Fi, and sends the readings to a ThingSpeak channel every 20 seconds using HTTP. ThingSpeak's built-in charts display the live data publicly.

- Field 1: Temperature (°C)
- Field 2: Humidity (%)
- The University ID is sent with every request in the `status` parameter and is also printed in the Serial Monitor log.

## ThingSpeak public URL
https://thingspeak.mathworks.com/channels/3551612

## Wokwi link
https://wokwi.com/projects/478975479868533761

## Wiring diagram

| DHT22 pin | ESP32 pin |
|-----------|-----------|
| VCC       | 3V3       |
| GND       | GND       |
| DATA/SDA  | GPIO 15   |

![Wiring diagram](screenshots/wiring_diagram.png)

## Screenshots

### ThingSpeak channel page
![ThingSpeak channel page](screenshots/ThingSpeak%20channel%20page.png)

### Live temperature & humidity graphs
![Temperature & Humidity read data](screenshots/Temperature%20%26%20Humidity%20read%20data.png)
