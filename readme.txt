Class D driven Audio play

1. Hardware environment.
* C8051F930-TB board,
* 8 ohm 1W speaker.
* Full bridge Class-D amplifier circuit. 

2. Firmware
* It contains two 8bit PWM channels, P0.0 and P0.1.
* Timer0 enter ISR per 1/8000 seconds and feed PCM data into PWM 
* We have four sound clips. Human voice "ok", doorbell, alarm, windows power up sound.
* We support 8 bits, 8KHz, mono wav file
* In stuffs directory, There are two wav files, and wav2c.exe which can convert wav file to c files. 

3. Validation
* Simply build firmware in Silabs IDE and download it into C8051F930-TB boards
* Hardware connection
** Connect speaker to JP1 on Class-D amplifier circuit. 
** Connect P0.0 and P0.1 to R+ and R- on Class-D amplifier circuit. 
** Connect F930 board VDD to Class-D amplifier circuit VDD.
** Connect F930 board GND to Class-D amplifier circuit GND.
* run the firmware and will hear the voice clip from speaker.
* To change sound clip, just pick different header file in sound.h and rebuild the project.

