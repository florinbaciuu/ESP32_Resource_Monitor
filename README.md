# 🧠 ESP32_Resource_Monitor

![PlatformIO](https://img.shields.io/badge/PlatformIO-Ready-orange?logo=platformio)
![ESP-IDF](https://img.shields.io/badge/ESP--IDF-5.x-blue?logo=espressif)

**Advanced resource monitor for ESP32**  
📟 Tracks tasks, memory, PSRAM, heap, timers, and more, with detailed configuration options via Kconfig.  
✍️ Created by [Baciu Aurel Florin](mailto:baciuaurelflorin@gmail.com) (a.k.a. The Lightbringer)

---

## ✨ Features

- ✅ **CPU usage per task** (load, stack usage, core ID, priority)
- ✅ Advanced **heap and PSRAM dump**
- ✅ **Segmented stats** (DMA, RTCRAM, 8bit/32bit, etc.)
- ✅ Supports **ESP timer dump**
- ✅ Optional: **full memory heap dump** (`heap_caps_dump()`)
- ✅ Debug mode with **timestamp and benchmarking**
- ✅ **Full Kconfig** configuration
- ✅ Runs using:
  - Dedicated task (with notify)
  - Directly from `esp_timer` (with or without task)
  - Pure FreeRTOS mode (`vTaskDelayUntil`) 
- ✅ ESP-IDF v5.x+ compatible

---

## 📂 Structure

```text
ESP32S3_Resource_Monitor/
├── CMakeLists.txt
├── Kconfig
├── include/
│   └── ResourceMonitor.h
├── src/
│   └── ResourceMonitor.c
└── README.md
```

---

## ⚙️ Kconfig Options

Component has a dedicated menu:

```menuconfig
Component config  --->
  ESP32S3 Resource Monitor Configuration  --->
    [*] Enable Resource Monitor
    [*] Use Kconfig for configuration
        (4)  Dump interval (seconds)
        (40) Max number of monitored tasks
        [*] Include timestamp in logs
        [*] Enable task monitoring output
        [*] Enable memory usage dump
        [*] Use printf instead of ESP_LOGI for memory info
        [ ] Enable full heap memory dump
        [*] Enable ESP timer diagnostics
        [*] Use ESP timer for triggering resource monitor
        [ ] Run monitor directly inside ESP timer
```

---

## 🛠️ Usage

### 1. **Include the component:**

In your `CMakeLists.txt`:
```cmake
set(EXTRA_COMPONENT_DIRS "<path>/ESP32S3_Resource_Monitor")
```

### 2. **Use in your code:**

```c
#include "ResourceMonitor.h"

void app_main() {
    start_resource_monitor();  // Start the monitor
}
```

---

## 🧪 Sample Output

📌 _Replace with real screenshot from console output._

```
-----------------Task Dump Start-----------------
Load    Stack   State    CoreID   PRIO     Name
 0.34     512   Ready    1        5        [RESMONITOR(R)]
 5.12     2048  Running  0        1        [IDLE0          ]
...
-----------------Task Dump End-------------------
```

---

## 🧩 Extensibility

Callback functions are modular:
- `task_monitor_cb()`
- `memory_monitor_cb()`
- `esp_timers_monitor_cb()`
- `memory_dump_cb()`

You can invoke them independently or integrate into custom diagnostics.

---

## 🔐 License

Apache 2.0 — use freely, contribute confidently.

---

## 🤝 Contribute

Pull requests, feedback, and enhancements are welcome!  
Please follow the existing code style and provide comments.

---

## 📧 Contact

📮 Author: Baciu Aurel Florin  
✉️ Email: [baciuaurelflorin@gmail.com](mailto:baciuaurelflorin@gmail.com)

---

## 🧙‍♂️ The Lightbringer Rulez

This isn't just a library. It's your eyes inside the system.  
The heresy of idle tasks shall burn in the fire of RAM.

---

# 🧠 ESP32_Resource_Monitor (în română)

**Monitor avansat de resurse pentru ESP32**  
📟 Monitorizează taskuri, memorie, PSRAM, heap, timere și mai mult, cu opțiuni detaliate de configurare via Kconfig.  
✍️ Creat de [Baciu Aurel Florin](mailto:baciuaurelflorin@gmail.com) (a.k.a. The Lightbringer)

---

## ✨ Caracteristici

- ✅ Monitorizare **CPU per task** (load, stack usage, core ID, prioritate)
- ✅ Dump avansat de **heap și PSRAM**
- ✅ Statistici **segmentate** (DMA, RTCRAM, 8bit/32bit, etc.)
- ✅ Suport pentru **ESP timer dump**
- ✅ Opțional: **memory heap dump complet** (`heap_caps_dump()`)
- ✅ Mod debug cu **timestamp și benchmark**
- ✅ **Kconfig complet** pentru configurare ușoară
- ✅ Suport pentru rulare în:
  - Task dedicat (cu notificare)
  - Direct în `esp_timer` (cu sau fără task)
  - Mod FreeRTOS pur (`vTaskDelayUntil`)
- ✅ Compatibil ESP-IDF v5.x+

---

## 📂 Structură

```text
ESP32S3_Resource_Monitor/
├── CMakeLists.txt
├── Kconfig
├── include/
│   └── ResourceMonitor.h
├── src/
│   └── ResourceMonitor.c
└── README.md
```

---

## ⚙️ Configurare Kconfig

Librăria vine cu un meniu Kconfig dedicat:

```menuconfig
Component config  --->
  ESP32S3 Resource Monitor Configuration  --->
    [*] Enable Resource Monitor
    [*] Use Kconfig for configuration
        (4)  Dump interval (seconds)
        (40) Max number of monitored tasks
        [*] Include timestamp in logs
        [*] Enable task monitoring output
        [*] Enable memory usage dump
        [*] Use printf instead of ESP_LOGI for memory info
        [ ] Enable full heap memory dump
        [*] Enable ESP timer diagnostics
        [*] Use ESP timer for triggering resource monitor
        [ ] Run monitor directly inside ESP timer
```

---

## 🛠️ Utilizare

### 1. **Include componenta în proiectul tău:**

Adaugă în `CMakeLists.txt`:
```cmake
set(EXTRA_COMPONENT_DIRS "<cale>/ESP32S3_Resource_Monitor")
```

### 2. **Include header-ul în codul tău:**

```c
#include "ResourceMonitor.h"

void app_main() {
    start_resource_monitor();  // Pornește monitorul
}
```

---

## 🧪 Exemplu de output

📌 _Aici poți adăuga un screenshot real din consolă după ce rulezi aplicația._

```
-----------------Task Dump Start-----------------
Load    Stack   State    CoreID   PRIO     Name
 0.34     512   Ready    1        5        [RESMONITOR(R)]
 5.12     2048  Running  0        1        [IDLE0          ]
...
-----------------Task Dump End-------------------
```

---

## 🧩 Extensibilitate

Toate callback-urile de monitorizare sunt separate:
- `task_monitor_cb()`
- `memory_monitor_cb()`
- `esp_timers_monitor_cb()`
- `memory_dump_cb()`

Le poți apela individual sau le poți integra într-un sistem propriu de diagnostic.

---

## 🔐 Licență

Apache 2.0 — folosește liber, contribuie cu încredere.

---

## 🤝 Contribuie

Pull requests, idei și îmbunătățiri sunt binevenite!  
Te rog adaugă comentarii clare și păstrează stilul de cod existent.

---

## 📧 Contact

📮 Autor: Baciu Aurel Florin  
✉️ Email: [baciuaurelflorin@gmail.com](mailto:baciuaurelflorin@gmail.com)

---

## 🧙‍♂️ The Lightbringer Rulez

Aceasta nu este doar o librărie. Este o extensie a ochilor tăi în sistem.  
Eresul taskurilor inutile va fi ars în focul RAM-ului.

---
