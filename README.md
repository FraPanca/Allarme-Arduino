# Allarme-Arduino

## Italiano

Un sistema di allarme con sensore di movimento a ultrasuoni, LED RGB di stato e display LCD.

**Stack:** C/C++ (Arduino) · Libreria LiquidCrystal · Sensore a ultrasuoni (tipo HC-SR04)

### Descrizione

Sistema di allarme realizzato con Arduino UNO R3: un pulsante attiva/disattiva l'allarme, mentre un sensore a ultrasuoni rileva la presenza di un oggetto entro una soglia di distanza configurabile. Lo stato del sistema (disattivato / attivo / scattato) è mostrato sia tramite un LED RGB sia su un display LCD 16×2, e l'allarme scattato produce un segnale sonoro a due toni tramite un buzzer passivo.

### Componenti necessari

- UNO R3 Controller Board
- LCD1602 Module (with pin header)
- Sensore ultrasuoni
- Passive Buzzer
- RGB Led
- Bottone
- 6 resistori 220 Ohm
- Breadboard
- Breadboard jumpers

### Come si esegue

1. Installa la libreria **LiquidCrystal** (inclusa di default nell'IDE Arduino).
2. Apri `Allarme.ino`, seleziona la scheda "Arduino UNO" e la porta seriale corretta.
3. Collega i componenti secondo lo schema elettrico incluso (`Allarme-Tinkercad.png` / `Allarme.pdf`).
4. Carica lo sketch sulla scheda. Premi il bottone per attivare l'allarme; se il sensore rileva un oggetto entro la soglia impostata (50 cm di default) mentre l'allarme è attivo, questo scatta e produce un suono. Premi nuovamente il bottone per silenziare l'allarme scattato o per disattivare l'allarme quando è attivo ma non ancora scattato.

### Funzionalità principali

- Attivazione/disattivazione dell'allarme tramite un singolo pulsante, con attesa del rilascio del tasto per evitare letture multiple accidentali (debounce software)
- Misurazione della distanza tramite sensore a ultrasuoni (calcolo basato sul tempo di andata e ritorno dell'impulso e sulla velocità del suono), con soglia di attivazione configurabile (50 cm di default)
- Tre stati distinti (disattivato / attivo / scattato) rappresentati sia da un LED RGB con colore dedicato (giallo, verde, rosso) sia da un messaggio testuale sul display LCD 16×2
- Segnale sonoro a due toni alternati (4000 Hz / 1000 Hz) generato tramite un buzzer passivo quando l'allarme scatta
- Log su Serial Monitor (9600 baud) della distanza misurata rispetto alla soglia impostata, utile per il debug e la calibrazione del sensore

### Struttura del progetto

```
Allarme-Arduino/
├── Allarme.ino               # Sketch principale: gestione stati, sensore ultrasuoni, LED RGB, LCD, buzzer
├── Allarme-Tinkercad.png     # Schema elettrico del circuito
└── Allarme.pdf               # Schema elettrico (esportazione Tinkercad)
```

### Note

Progetto didattico/personale con Arduino UNO R3. Il debounce del pulsante è realizzato tramite un ciclo bloccante (`while`) che attende il rilascio del tasto, mettendo in pausa il resto della logica durante la pressione.

### Licenza

MIT

---

## English

An alarm system with an ultrasonic motion sensor, an RGB status LED and an LCD display.

**Stack:** C/C++ (Arduino) · LiquidCrystal library · Ultrasonic sensor (HC-SR04 type)

### Description

Alarm system built with an Arduino UNO R3: a button arms/disarms the alarm, while an ultrasonic sensor detects an object within a configurable distance threshold. The system's state (disarmed / armed / triggered) is shown both by an RGB LED and on a 16×2 LCD display, and a triggered alarm produces a two-tone sound through a passive buzzer.

### Required components

- UNO R3 Controller Board
- LCD1602 Module (with pin header)
- Ultrasonic sensor
- Passive Buzzer
- RGB Led
- Button
- 6 resistors 220 Ohm
- Breadboard
- Breadboard jumpers

### How to run

1. Install the **LiquidCrystal** library (bundled by default with the Arduino IDE).
2. Open `Allarme.ino`, select the "Arduino UNO" board and the correct serial port.
3. Wire the components according to the included circuit diagram (`Allarme-Tinkercad.png` / `Allarme.pdf`).
4. Upload the sketch to the board. Press the button to arm the alarm; if the sensor detects an object within the configured threshold (50 cm by default) while armed, it triggers and produces a sound. Press the button again to silence a triggered alarm, or to disarm it while armed but not yet triggered.

### Key features

- Alarm arming/disarming via a single button, waiting for the key release to avoid accidental multiple reads (software debounce)
- Distance measurement via an ultrasonic sensor (computed from the pulse round-trip time and the speed of sound), with a configurable activation threshold (50 cm by default)
- Three distinct states (disarmed / armed / triggered), each represented by a dedicated RGB LED color (yellow, green, red) and a text message on the 16×2 LCD display
- Two-tone alternating sound (4000 Hz / 1000 Hz) generated via a passive buzzer when the alarm triggers
- Serial Monitor logging (9600 baud) of the measured distance against the configured threshold, useful for debugging and sensor calibration

### Project structure

```
Allarme-Arduino/
├── Allarme.ino               # Main sketch: state handling, ultrasonic sensor, RGB LED, LCD, buzzer
├── Allarme-Tinkercad.png     # Circuit diagram
└── Allarme.pdf               # Circuit diagram (Tinkercad export)
```

### Notes

Educational/personal project with an Arduino UNO R3. Button debouncing is implemented with a blocking `while` loop that waits for the key release, pausing the rest of the logic while the button is held down.

### License

MIT
