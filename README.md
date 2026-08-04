# ESP32 ADC Timer-Driven PWM Duty Cycle Control

Un proiect demonstrativ pentru **ESP32** creat în Arduino / C++, care exemplifică eșantionarea periodică a unui semnal analogic (potențiometru) prin **întreruperi de Timer Hardware** și controlul dinamic al factorului de umplere (**Duty Cycle**) al unui semnal **PWM pe 12 biți**.

---

##  Funcționalități Principal
1. **Citire ADC pe Timer Hardware:**
   - Eșantionarea potențiometrului (`GPIO 34`) este declanșată precis la fiecare **10 ms** ($10.000\ \mu\text{s}$) prin intermediul unei întreruperi generate de un temporizator hardware de $1\text{ MHz}$.
2. **Control PWM pe 12 Biți (`LEDC`):**
   - Perifericul PWM (`GPIO 2`) este configurat la o frecvență de **5000 Hz** și o rezoluție de **12 biți** (domeniu $0 - 4095$).
   - Valoarea de la ADC este aplicată direct asupra canalului PWM fără a fi necesară scalarea sau maparea suplimentară.
3. **Execuție Non-Blocantă (Non-blocking):**
   - Citirea și actualizarea stării hardware au loc în Rutina de Servire a Întreruperii (`ISR` - `IRAM_ATTR`), iar bucla `loop()` se ocupă doar de afișarea asincronă pe interfața Serială folosind un flag logic (`printFlag`).

---

##  Componente Hardware
- **1x** Placă de dezvoltare **ESP32**
- **1x** LED integrat (pe `GPIO 2`) sau LED extern cu rezistență de limitare ($220\ \Omega$)
- **1x** Potențiometru ($10\text{ k}\Omega$)
- Breadboard și fire de conexiune (Jumper Wires)

---

##  Schema de Conectare (Pinout)

| Componentă | Pin ESP32 | Conectare / Detalii |
| :--- | :--- | :--- |
| **Potențiometru (VCC)** | `3V3` | Alimentare referință analogică |
| **Potențiometru (GND)** | `GND` | Masa sistemului |
| **Potențiometru (Signal)** | `GPIO 34` | Terminalul central (Cursor) $\rightarrow$ `ADC1_CH6` |
| **LED (PWM Output)** | `GPIO 2` | Output PWM pe 12 biți (LED integrat / extern) |
