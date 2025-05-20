# Car-Parking-Sensor

### Project Overview 📖
This project implements a simple car parking aid using an ATmega32 microcontroller, an HC-SR04 ultrasonic sensor, 16×2 LCD, LEDs, and a buzzer. It measures distance to nearby obstacles and provides visual/auditory feedback to help drivers park safely.

### Objective 🛠️
- Use an ultrasonic sensor to measure obstacle distance in real-time.  
- Display numeric distance on an LCD and show "Stop" warning when too close.  
- Illuminate LEDs progressively based on proximity thresholds.  
- Activate a buzzer when distance ≤ 5 cm.  
- Modularize drivers for GPIO, ICU (Input Capture Unit), LCD, Ultrasonic, and Buzzer.  

### Features 🚀
1. **Ultrasonic Distance Measurement**: HC-SR04 sensor reads echo time via ICU and calculates distance (cm).  
2. **LCD Display**: Shows current distance in cm; displays **Stop** if ≤ 5 cm.  
3. **LED Indicators**: Three LEDs (Green, Yellow, Red) illuminate according to distance ranges:  
   - \> 20 cm: All LEDs OFF  
   - 16–20 cm: Red ON only  
   - 11–15 cm: Red & Yellow ON  
   - 6–10 cm: All LEDs ON  
   - ≤ 5 cm: All LEDs flashing  
4. **Buzzer Alert**: Sounds when distance ≤ 5 cm.  

### Hardware Components 🛠️
- **Microcontroller**: ATmega32 @ 16 MHz  
- **Ultrasonic Sensor**: HC-SR04 (Trigger: PD7, Echo: PD6)  
- **Display**: 16×2 LCD in 4‑bit mode (PA1→RS, PA2→E, PA3–PA6→D4–D7)  
- **LEDs**: Red (PC2), Yellow (PC1), Green (PC0)  
- **Buzzer**: PC5  

### Operation Flow 🔄
1. **Initialization**: Configure GPIO, ICU (F_CPU/8, rising edge), LCD, Ultrasonic, and Buzzer drivers.  
2. **Measurement Loop**:  
   - Trigger pulse via `Ultrasonic_Trigger()`  
   - Capture echo duration in `Ultrasonic_edgeProcessing()` callback  
   - Calculate distance:  
     \[distance (cm) = (time_us) / 58\]  
3. **Display & Alerts**:  
   - Update LCD with distance or **Stop**  
   - Set LED pattern based on thresholds  
   - Activate buzzer if ≤ 5 cm  

### Drivers & API 📚
- **GPIO Driver**:  
  ```c
  void GPIO_init(void);
  void GPIO_setPinDirection(uint8 port, uint8 pin, uint8 dir);
  void GPIO_writePin(uint8 port, uint8 pin, uint8 value);

- **GPIO Driver**:  
  ```c
  void GPIO_init(void);
  void GPIO_setPinDirection(uint8 port, uint8 pin, uint8 dir);
  void GPIO_writePin(uint8 port, uint8 pin, uint8 value);

- **ICU Driver**:  
  ```c
  void ICU_init(void);
  void ICU_setCallback(void (*callback)(void));
  uint16 ICU_getInputCaptureValue(void);
  void ICU_clear(void);

- **Ultrasonics Driver**:  
  ```c
  void Ultrasonic_init(void);            // calls ICU_init & sets trigger pin
  void Ultrasonic_Trigger(void);         // sends 10μs pulse
  uint16 Ultrasonic_readDistance(void);  // triggers & returns distance in cm
  void Ultrasonic_edgeProcessing(void);  // ICU callback to compute echo time

- **LCD Driver**:  
  ```c
  void LCD_init(void);
  void LCD_displayString(const char* str);
  void LCD_moveCursor(uint8 row, uint8 col);
  void LCD_clear(void);

- **Buzzer Driver**:  
  ```c
  void Buzzer_init(void);
  void Buzzer_on(void);
  void Buzzer_off(void);

### Simulation on Proteus 🖥️
![image](https://github.com/user-attachments/assets/0e7d1f0c-4d38-4783-a3ae-f272834174c2)

