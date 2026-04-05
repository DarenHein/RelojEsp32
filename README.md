# 🕰️ ESP32 WiFi Digital Clock (NTP Server)

Este proyecto consiste en un reloj digital inteligente que utiliza un **ESP32** para conectarse a internet y obtener la hora exacta mediante el protocolo **NTP (Network Time Protocol)**, mostrándola en una pantalla **OLED SSD1306**.

---

## 🇪🇸 Versión en Español

### 💡 ¿Por qué estos componentes?
* **ESP32:** Se eligió por su módulo WiFi integrado, lo que permite sincronizar la hora sin necesidad de un módulo de reloj externo (RTC) como el DS3231.
* **Pantalla OLED (I2C):** Es ideal por su bajo consumo de energía y excelente contraste en entornos oscuros.
* **Protocolo NTP:** Se utilizó para garantizar que la hora siempre sea precisa, ajustándose automáticamente a través de servidores de Google o NTP Pool.

### 🔌 Conexiones (Diagrama de Cableado)
La pantalla OLED utiliza el protocolo de comunicación **I2C**. Aquí tienes el mapa de pines para un ESP32 estándar (30 pines):

| OLED Pin | ESP32 Pin | Descripción |
| :--- | :--- | :--- |
| **VCC** | 3.3V | Alimentación de poder |
| **GND** | GND | Tierra |
| **SCL** | GPIO 22 | Reloj de comunicación I2C |
| **SDA** | GPIO 21 | Datos de comunicación I2C |

---

## 🇺🇸 English Version

### 💡 Why these components?
* **ESP32:** Chosen for its built-in WiFi module, allowing time synchronization without the need for an external Real-Time Clock (RTC) module.
* **OLED Display (I2C):** Perfect for its low power consumption and high visibility in low-light conditions.
* **NTP Protocol:** Used to ensure the time is always accurate, automatically fetching data from Google or NTP Pool servers.

### 🔌 Connections (Wiring Diagram)
The OLED display uses the **I2C** communication protocol. Below is the pinout for a standard ESP32 (30-pin version):

| OLED Pin | ESP32 Pin | Description |
| :--- | :--- | :--- |
| **VCC** | 3.3V | Power Supply |
| **GND** | GND | Ground |
| **SCL** | GPIO 22 | I2C Serial Clock |
| **SDA** | GPIO 21 | I2C Serial Data |

---

## 🛠️ Requisitos / Requirements

Para compilar este código, necesitarás instalar las siguientes librerías en tu Arduino IDE:
1. `Adafruit SSD1306`
2. `Adafruit GFX Library`

> [!IMPORTANT]
> **Nota de seguridad:** Recuerda que antes de subir el código a un repositorio público, debes ocultar tus credenciales de WiFi (`ssid` y `password`).

## 🚀 Instalación / Installation
1. Clona este repositorio.
2. Abre el archivo `.ino` en Arduino IDE.
3. Configura tu zona horaria en la variable `gmtOffset_sec`.
4. ¡Carga el código y disfruta de tu reloj sincronizado!
