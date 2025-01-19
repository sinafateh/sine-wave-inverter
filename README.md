# sine-wave-inverter
### Inverter Design with Voltage Feedback Control  

**Project Title:** DC-to-AC Inverter with Feedback-Based Voltage Regulation  

---

**Description:**  
This project presents a DC-to-AC inverter system designed to generate a stable AC output while incorporating feedback control for voltage regulation. The feedback mechanism, though simplified, is modeled using a potentiometer and a DC voltage source. It dynamically adjusts the output through a PWM signal, which controls a buck-boost converter. This setup ensures consistent output voltage under varying load conditions.  

---

**Key Features:**  
1. **Stable AC Output:** The system converts DC input to an AC sine wave using SPWM (Sinusoidal Pulse Width Modulation).  
2. **Voltage Feedback Control:** A simulated feedback loop adjusts the PWM duty cycle to regulate the inverter's output voltage. The feedback is modeled with a DC voltage source and potentiometer rather than a real-time system, allowing for simplified testing and adjustments.  
3. **Buck-Boost Converter Integration:** The feedback PWM signal directly controls a buck-boost converter, enabling precise voltage adjustments.  
4. **Load Adaptability:** The system maintains a stable output voltage despite changes in load conditions.  

---

**How It Works:**  
1. The microcontroller generates a SPWM signal to control the inverter’s switching transistors (e.g., MOSFETs).  
2. The feedback mechanism, modeled using a potentiometer and DC voltage source, provides a reference signal.  
3. The reference feedback signal is processed by the microcontroller, which adjusts the PWM duty cycle of a buck-boost converter.  
4. The buck-boost converter modifies the DC input voltage to ensure the inverter's output remains stable, providing a regulated AC waveform to the load.  

---

**Applications:**  
- Renewable energy systems (e.g., solar inverters).  
- Uninterruptible Power Supplies (UPS).  
- AC power supply for sensitive equipment.  

---

**Components Used:**  
- **Microcontroller:** For SPWM generation and feedback control.  
- **Switching Transistors:** MOSFETs for high-efficiency DC-to-AC conversion.  
- **Buck-Boost Converter:** Controlled via PWM for voltage regulation.  
- **Feedback System:** Modeled with a potentiometer and DC voltage source for testing purposes.  

---

**Future Enhancements:**  
- Replace the simulated feedback with a real-time voltage sensor for practical applications.  
- Add wireless monitoring to track output parameters remotely.  
- Improve the SPWM resolution for smoother output waveform.  

---

**Repository Contents:**  
- **Code:** Microcontroller firmware for SPWM generation and feedback control.  
- **Schematics:** Circuit diagrams for inverter and feedback systems.  
- **Documentation:** Detailed explanations of design principles and implementation steps.  
- **Simulation Files:** Proteus or other simulation files for testing and validation.  

---

**License:**  
This project is open-source and distributed under the [MIT License](https://opensource.org/licenses/MIT).  

---

**Contributions:**  
Contributors are welcome to enhance the design, replace the modeled feedback with real-time components, or optimize the system further. Submit pull requests to collaborate!  

--- 

این توضیحات رسمی و مناسب برای گیت‌هاب است. اگر بخشی از اطلاعات نیاز به تغییر یا اصلاح دارد، اطلاع دهید تا آن را بهبود ببخشم. 😊
