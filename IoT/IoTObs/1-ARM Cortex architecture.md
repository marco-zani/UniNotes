Arm is RISC-based to be more power and instruction efficient 
## ARM companies
The ARM company produces designs, which are then lincensed to other manifacturers

# ARM families
## Cortex-A Series
High performance processors with full OS support
## Cortex-R series
HIgh performance and reliability for real-time application
## Cortex-M Series
**Cost sensitive for micro-controllers**. They also implement smaller code, simpler hardware and are **designed for embedded applications**

The most simple processor is the Cortex-M0, the others are the M3, **M4 and M7**, which the last two implement **Digital Signal Processing** and **accellerated floating point** for **faster and power-efficient algorithms**

#### Von Neuman vs Harward architecture
In **Von Neuman** architecture, is the **memory who keeps data and instructions**, but in **Harvard** architecture, the two part are **separated in different physical memories**. This provides **higher performance**

# Cortex M4
Designed with plenty of **Signal Processing features**, low power consuption and **enhanced determinism**, or the **capacity to quickly manage interrupt and critical tasks**.

It Uses a 32-bit RISC processor with harvard architecture and a branch speculation pipeline, capable of predicting the behaviour of the code.
It also implements:
- **Sleep modes**: 240 different wake-up interrupts and sleep on exit capabilities
- Enhanced instructions
- Debug: JTAG and **Serial-Wire Debug ports**
- **Memory Protection Unit**

## Block Diagram
It uses a three stage pipeline: fetch, decode and execution

#### Components
- Neste