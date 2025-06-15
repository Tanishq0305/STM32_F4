STM32 F4 HAL & Driver Development

Comprehensive driver development and hardware abstraction layer (HAL) for the STM32F446RE microcontroller. Focused on modular, reusable code and demonstrating essential peripheral drivers, delivered with clean documentation and a roadmap for future enhancements.

🔧 Repository Overview

This repo contains:

Hardware Abstraction Layer (HAL)-style drivers** for STM32F446RE.
* Deliverable modules include: **GPIO**, **USART**, **SPI**, **I2C**, **ADC**, and **Timers**.
* A **CMSIS-compliant** core enablement for easier portability.
* A **Makefile-based build system** designed for both SW4STM32 and Keil (plus exportable Eclipse `.cproject`).
* Example applications demonstrating driver usage.

## 💡 What’s Included

### 1. Driver Modules

* **GPIO** – Initialization, alternate functions, input/output, pull-up/down control.
* **USART2** – UART communication: initialization, blocking/non-blocking TX/RX, interrupts.
* **SPI1** – Full-duplex master mode: init, transfer, and DMA support.
* **I2C1** – Master-mode communication with address and register read/write functions.
* **ADC1** – Single-conversion and continuous-conversion with interrupt/DMA integration.
* **TIM2/TIM3** – Basic timer setup, interrupts, PWM output support.

Each module features:

**Initialization API**: Flexible configuration based on user-supplied struct.
**Polling and non-blocking operations**: Supports interrupt-driven and DMA-based transfers.
**Error handling**: Return values and callbacks for robust execution.

### 2. Core System Integration

* **CMSIS/Core** files for `STM32F446xx`.
* **Dynamic clock configuration** via PLL, enabling precise HCLK/PCLK setup.
* **NVIC setup utility** for clean interrupt configuration.

### 3. Example Applications

Sample projects included:

* **blinky\_gpio** – Simple blinking LED on PA5 using `HAL_GPIO`.
* **uart\_echo** – Echoing data over USART2.
* **spi\_test**, **i2c\_scanner**, **adc\_reader**, **pwm\_signal** – Demonstrations for testing each peripheral.

## 🚀 Getting Started

1. **Clone the repo**

   ```bash
   git clone https://github.com/Tanishq0305/STM32_F4.git
   cd STM32_F4
   ```

2. **Pick an example (e.g., `uart_echo`)** and open its project in SW4STM32 or import into your preferred IDE.

3. **Build & Flash**

   * Using SW4STM32 or Makefile:

     ```bash
     make BOARD=NUCLEO_F446RE
     make flash
     ```
   * Or adjust Keil/Eclipse project settings to suit.

⭐ What’s Done

* Foundation drivers for all key MCU peripherals.
* Build-system setup for easy compilation/porting.
* Working examples proving functional value.
* Modular, well-documented, and scalable driver architecture.

## 🔭 What’s Next

Planned improvements:

* **DMA enhancements**: full DMA support in SPI, ADC, USART.
* **Power optimization**: low-power modes, RTC support.
* **RTOS integration**: prototype APIs with FreeRTOS (semaphores, queues).
* **Expanded peripheral coverage**: CAN, USB OTG, SDIO.
* **Self-tests & CI**: unit tests, CI pipelines on GitHub Actions.
* **Detailed docs**: Doxygen outputs; `docs/` folder for reference.

🧩 Contribution & Collaboration

Contributions are very welcome! Feel free to:

* Open an issue or pull request.
* Add peripheral drivers or example projects.
* Improve overviews, docs, testing, CI pipelines.

Please adhere to the existing coding style and provide test/demo code for new features.


