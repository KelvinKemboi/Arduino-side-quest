# Arduino Side Quest

A collection of small Arduino sketches for practicing LEDs, serial input, random output, Morse code, and ultrasonic distance sensing. Each folder contains an independent sketch that can be opened and uploaded on its own.

## Projects

### Basic LED

Controls two LEDs from the Arduino IDE Serial Monitor.

| Component | Arduino pin |
| --- | --- |
| LED 1 (red) | 9 |
| LED 2 (blue) | 5 |

Open the Serial Monitor at **9600 baud** and send one of these commands:

| Command | Action |
| --- | --- |
| `r` | Toggle the red LED |
| `b` | Toggle the blue LED |
| `a` | Turn both LEDs on |
| `n` | Turn both LEDs off |

Sketch: [`Basic-LED/Basic-LED.ino`](Basic-LED/Basic-LED.ino)

### HC-SR04 Basic Sensor

Measures distance with an HC-SR04 ultrasonic sensor and changes an LED's blink speed according to the measured distance.

| Component | Arduino pin |
| --- | --- |
| HC-SR04 Echo | 5 |
| HC-SR04 Trigger | 6 |
| LED | 11 |

The measured pulse duration and distance in centimeters are printed to the Serial Monitor at **9600 baud**.

| Distance | LED behavior |
| --- | --- |
| Less than 10 cm | Fast blink |
| 10–49 cm | Medium blink |
| 50 cm or more | Slow blink |

Sketch: [`HC-SRO4-basic-Sensor/HC-SRO4-basic-Sensor.ino`](HC-SRO4-basic-Sensor/HC-SRO4-basic-Sensor.ino)

### Random Flickering

Randomly selects one of three LEDs, turns it on for 300 ms, then pauses for 500 ms before selecting again.

| LED | Arduino pin |
| --- | --- |
| LED 1 | 6 |
| LED 2 | 9 |
| LED 3 | 11 |

Analog pin A0 supplies noise to seed the random number generator and should be left unconnected.

Sketch: [`Random-Flickering/Random-Flickering.ino`](Random-Flickering/Random-Flickering.ino)

### SOS Morse

Repeatedly blinks `... --- ...` (SOS in Morse code) on an LED connected to pin 11.

Sketch: [`SOS-Morse/SOS-Morse.ino`](SOS-Morse/SOS-Morse.ino)

## Hardware

- An Arduino-compatible board, such as an Arduino Uno
- LEDs
- 220–330 Ω current-limiting resistors for the LEDs
- Breadboard and jumper wires
- HC-SR04 ultrasonic sensor for the distance-sensor project
- USB cable

Connect each LED's anode (long leg) to its listed Arduino pin through a current-limiting resistor. Connect the cathode (short leg) to GND. For the HC-SR04, also connect VCC to 5V and GND to GND.

## Getting Started

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Clone or download this repository.
3. Open the `.ino` file for the project you want to run.
4. Select your board and port under **Tools** in the Arduino IDE.
5. Assemble the circuit using the pin table for that project.
6. Click **Upload**.

Only upload one sketch at a time. The sketches use only Arduino's built-in functions, so no additional libraries are required.

## Safety

Disconnect USB power before changing the circuit. Always use a current-limiting resistor with an external LED, and double-check power and ground connections before uploading a sketch.
