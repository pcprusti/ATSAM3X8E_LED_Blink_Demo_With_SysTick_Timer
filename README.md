# ATSAM3X8E_LED_Blink_Demo_With_SysTick_Timer
This demo showcases how to use the SysTick timer—a built-in feature of ARM Cortex-M3 cores—to generate precise timing for blinking an LED. 
Instead of relying on software delay loops, the SysTick timer provides accurate millisecond-level interrupts, allowing the LED to toggle at 
consistent intervals without blocking the CPU.

# Key Concepts:

* Configure SysTick to fire every 1 ms

* Use SysTick_Handler() to increment a counter

* Toggle the LED when the counter reaches a threshold (e.g., 500 ms)

* Ideal for multitasking and real-time systems

```
+---------------------------+
|       System Init         |
| - Enable PIOB Clock       |
| - Configure PB27 as Output|
| - Setup SysTick (1ms)     |
+------------+--------------+
             |
             v
+---------------------------+
|     SysTick_Handler()     |
| - Increment tick_count    |
| - If tick_count % 500 == 0|
|   → Toggle LED            |
+------------+--------------+
             |
             v
+---------------------------+
|         Main Loop         |
| - Remains free for other  |
|   tasks or idle           |
+---------------------------+

```

# Benefits:

* Non-blocking timing

* Precise control

* Scalable for more complex tasks


