EESchema Schematic File Version 2
LIBS:arduino_shield-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:switches
LIBS:arduino_shield-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title "LCD keypad Shield"
Date "2018-10-24"
Rev "v1.2"
Comp "Brno University of Technology, Czechia"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "Pin name legend: MCU PIN [ARDUINO PCB PIN NAME]"
$EndDescr
$Comp
L R R7
U 1 1 5A5F5406
P 8050 3000
F 0 "R7" V 8130 3000 50  0000 C CNN
F 1 "4k7" V 8050 3000 50  0000 C CNN
F 2 "" V 7980 3000 50  0001 C CNN
F 3 "" V 8130 3000 50  0001 C CNN
	1    8050 3000
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 5A5F540D
P 3200 1750
F 0 "R1" V 3280 1750 50  0000 C CNN
F 1 "680R" V 3200 1750 50  0000 C CNN
F 2 "" V 3130 1750 50  0001 C CNN
F 3 "" V 3280 1750 50  0001 C CNN
	1    3200 1750
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 5A5F5414
P 3850 3200
F 0 "R2" V 3930 3200 50  0000 C CNN
F 1 "3k" V 3850 3200 50  0000 C CNN
F 2 "" V 3780 3200 50  0001 C CNN
F 3 "" V 3930 3200 50  0001 C CNN
	1    3850 3200
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5A5F541B
P 3850 3650
F 0 "R3" V 3930 3650 50  0000 C CNN
F 1 "330" V 3850 3650 50  0000 C CNN
F 2 "" V 3780 3650 50  0001 C CNN
F 3 "" V 3930 3650 50  0001 C CNN
	1    3850 3650
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5A5F5422
P 3850 4050
F 0 "R4" V 3930 4050 50  0000 C CNN
F 1 "620" V 3850 4050 50  0000 C CNN
F 2 "" V 3780 4050 50  0001 C CNN
F 3 "" V 3930 4050 50  0001 C CNN
	1    3850 4050
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5A5F5429
P 3850 4450
F 0 "R5" V 3930 4450 50  0000 C CNN
F 1 "1k" V 3850 4450 50  0000 C CNN
F 2 "" V 3780 4450 50  0001 C CNN
F 3 "" V 3930 4450 50  0001 C CNN
	1    3850 4450
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5A5F5430
P 3850 4850
F 0 "R6" V 3930 4850 50  0000 C CNN
F 1 "3k3" V 3850 4850 50  0000 C CNN
F 2 "" V 3780 4850 50  0001 C CNN
F 3 "" V 3930 4850 50  0001 C CNN
	1    3850 4850
	1    0    0    -1  
$EndComp
$Comp
L LCD-016N002L-RESCUE-arduino_shield DS1
U 1 1 5A5F5437
P 7100 2050
F 0 "DS1" H 6300 2450 50  0000 C CNN
F 1 "LCD??" H 7800 2450 50  0000 C CNN
F 2 "WC1602A" H 7100 2000 50  0001 C CIN
F 3 "" H 7100 2050 50  0001 C CNN
	1    7100 2050
	1    0    0    -1  
$EndComp
$Comp
L POT-RESCUE-arduino_shield RP1
U 1 1 5A5F543E
P 5850 3050
AR Path="/5A5F543E" Ref="RP1"  Part="1" 
AR Path="/5A5F4C1A/5A5F543E" Ref="RP1"  Part="1" 
F 0 "RP1" V 5675 3050 50  0000 C CNN
F 1 "10K" V 5750 3050 50  0000 C CNN
F 2 "" H 5850 3050 50  0001 C CNN
F 3 "" H 5850 3050 50  0001 C CNN
	1    5850 3050
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q1
U 1 1 5A5F5445
P 8500 3000
F 0 "Q1" H 8700 3050 50  0000 L CNN
F 1 "9013" H 8700 2950 50  0000 L CNN
F 2 "" H 8700 3100 50  0001 C CNN
F 3 "" H 8500 3000 50  0001 C CNN
	1    8500 3000
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-arduino_shield D1
U 1 1 5A5F544C
P 3600 1750
AR Path="/5A5F544C" Ref="D1"  Part="1" 
AR Path="/5A5F4C1A/5A5F544C" Ref="D1"  Part="1" 
F 0 "D1" H 3600 1850 50  0000 C CNN
F 1 "PWR" H 3600 1650 50  0000 C CNN
F 2 "" H 3600 1750 50  0001 C CNN
F 3 "" H 3600 1750 50  0001 C CNN
	1    3600 1750
	-1   0    0    1   
$EndComp
$Comp
L SW_Push SW1
U 1 1 5A5F5453
P 3300 3450
F 0 "SW1" H 3350 3550 50  0000 L CNN
F 1 "RIGHT" H 3300 3390 50  0000 C CNN
F 2 "" H 3300 3650 50  0001 C CNN
F 3 "" H 3300 3650 50  0001 C CNN
	1    3300 3450
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW2
U 1 1 5A5F545A
P 3300 3850
F 0 "SW2" H 3350 3950 50  0000 L CNN
F 1 "UP" H 3300 3790 50  0000 C CNN
F 2 "" H 3300 4050 50  0001 C CNN
F 3 "" H 3300 4050 50  0001 C CNN
	1    3300 3850
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW3
U 1 1 5A5F5461
P 3300 4250
F 0 "SW3" H 3350 4350 50  0000 L CNN
F 1 "DOWN" H 3300 4190 50  0000 C CNN
F 2 "" H 3300 4450 50  0001 C CNN
F 3 "" H 3300 4450 50  0001 C CNN
	1    3300 4250
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW4
U 1 1 5A5F5468
P 3300 4650
F 0 "SW4" H 3350 4750 50  0000 L CNN
F 1 "LEFT" H 3300 4590 50  0000 C CNN
F 2 "" H 3300 4850 50  0001 C CNN
F 3 "" H 3300 4850 50  0001 C CNN
	1    3300 4650
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW5
U 1 1 5A5F546F
P 3300 5050
F 0 "SW5" H 3350 5150 50  0000 L CNN
F 1 "SELECT" H 3300 4990 50  0000 C CNN
F 2 "" H 3300 5250 50  0001 C CNN
F 3 "" H 3300 5250 50  0001 C CNN
	1    3300 5050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 5A5F5476
P 2800 5650
F 0 "#PWR1" H 2800 5400 50  0001 C CNN
F 1 "GND" H 2800 5500 50  0000 C CNN
F 2 "" H 2800 5650 50  0001 C CNN
F 3 "" H 2800 5650 50  0001 C CNN
	1    2800 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 3450 2800 3450
Wire Wire Line
	2800 3450 2800 3850
Wire Wire Line
	2800 3850 2800 4250
Wire Wire Line
	2800 4250 2800 4650
Wire Wire Line
	2800 4650 2800 5050
Wire Wire Line
	2800 5050 2800 5450
Wire Wire Line
	2800 5450 2800 5650
Wire Wire Line
	3100 5050 2800 5050
Connection ~ 2800 5050
Wire Wire Line
	3100 4650 2800 4650
Connection ~ 2800 4650
Wire Wire Line
	3100 4250 2800 4250
Connection ~ 2800 4250
Wire Wire Line
	3100 3850 2800 3850
Connection ~ 2800 3850
Wire Wire Line
	3500 5050 3850 5050
Wire Wire Line
	3850 5050 3850 5000
Wire Wire Line
	3850 4600 3850 4650
Wire Wire Line
	3850 4650 3850 4700
Wire Wire Line
	3850 4200 3850 4250
Wire Wire Line
	3850 4250 3850 4300
Wire Wire Line
	3850 3800 3850 3850
Wire Wire Line
	3850 3850 3850 3900
Wire Wire Line
	3850 3350 3850 3450
Wire Wire Line
	3850 3450 3850 3500
Wire Wire Line
	3500 4650 3850 4650
Connection ~ 3850 4650
Wire Wire Line
	3500 4250 3850 4250
Connection ~ 3850 4250
Wire Wire Line
	3500 3850 3850 3850
Connection ~ 3850 3850
Wire Wire Line
	3500 3450 3850 3450
Wire Wire Line
	3850 3450 4250 3450
Connection ~ 3850 3450
$Comp
L +5V #PWR4
U 1 1 5A5F549E
P 3850 2950
F 0 "#PWR4" H 3850 2800 50  0001 C CNN
F 1 "+5V" H 3850 3090 50  0000 C CNN
F 2 "" H 3850 2950 50  0001 C CNN
F 3 "" H 3850 2950 50  0001 C CNN
	1    3850 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2950 3850 3050
$Comp
L SW_Push SW6
U 1 1 5A5F54A5
P 3300 5450
F 0 "SW6" H 3350 5550 50  0000 L CNN
F 1 "RST" H 3300 5390 50  0000 C CNN
F 2 "" H 3300 5650 50  0001 C CNN
F 3 "" H 3300 5650 50  0001 C CNN
	1    3300 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 5450 2800 5450
Connection ~ 2800 5450
Wire Wire Line
	3500 5450 3850 5450
Text Label 4250 3450 0    60   ~ 0
PC0[A0]
Text Label 3850 5450 0    60   ~ 0
RESET[RESET]
$Comp
L GND #PWR6
U 1 1 5A5F54B8
P 5850 3250
F 0 "#PWR6" H 5850 3000 50  0001 C CNN
F 1 "GND" H 5850 3100 50  0000 C CNN
F 2 "" H 5850 3250 50  0001 C CNN
F 3 "" H 5850 3250 50  0001 C CNN
	1    5850 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR8
U 1 1 5A5F54BE
P 6750 2550
F 0 "#PWR8" H 6750 2300 50  0001 C CNN
F 1 "GND" H 6750 2400 50  0000 C CNN
F 2 "" H 6750 2550 50  0001 C CNN
F 3 "" H 6750 2550 50  0001 C CNN
	1    6750 2550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR5
U 1 1 5A5F54C4
P 5850 2800
F 0 "#PWR5" H 5850 2650 50  0001 C CNN
F 1 "+5V" H 5850 2940 50  0000 C CNN
F 2 "" H 5850 2800 50  0001 C CNN
F 3 "" H 5850 2800 50  0001 C CNN
	1    5850 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 2800 5850 2850
Wire Wire Line
	5850 2850 5850 2900
Wire Wire Line
	5850 3200 5850 3250
Wire Wire Line
	6000 3050 6550 3050
Wire Wire Line
	6550 3050 6550 2550
Wire Wire Line
	5850 2850 6450 2850
Wire Wire Line
	6450 2850 6450 2550
Connection ~ 5850 2850
$Comp
L GND #PWR7
U 1 1 5A5F54D2
P 6350 2550
F 0 "#PWR7" H 6350 2300 50  0001 C CNN
F 1 "GND" H 6350 2400 50  0000 C CNN
F 2 "" H 6350 2550 50  0001 C CNN
F 3 "" H 6350 2550 50  0001 C CNN
	1    6350 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2550 6750 2550
$Comp
L +5V #PWR11
U 1 1 5A5F54D9
P 7900 2800
F 0 "#PWR11" H 7900 2650 50  0001 C CNN
F 1 "+5V" H 7900 2940 50  0000 C CNN
F 2 "" H 7900 2800 50  0001 C CNN
F 3 "" H 7900 2800 50  0001 C CNN
	1    7900 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 3000 7900 3000
Wire Wire Line
	7750 2550 7750 2800
Wire Wire Line
	7750 2800 7750 3000
Wire Wire Line
	8200 3000 8300 3000
Wire Wire Line
	7850 2550 8600 2550
Wire Wire Line
	8600 2550 8600 2800
Wire Wire Line
	7900 2800 7750 2800
Connection ~ 7750 2800
$Comp
L GND #PWR12
U 1 1 5A5F54E7
P 8600 3250
F 0 "#PWR12" H 8600 3000 50  0001 C CNN
F 1 "GND" H 8600 3100 50  0000 C CNN
F 2 "" H 8600 3250 50  0001 C CNN
F 3 "" H 8600 3250 50  0001 C CNN
	1    8600 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 3200 8600 3250
Wire Wire Line
	6300 4950 6650 4950
Wire Wire Line
	6300 5050 6650 5050
Wire Wire Line
	6300 5150 6650 5150
Wire Wire Line
	6900 4950 7250 4950
Wire Wire Line
	6900 5050 7250 5050
Wire Wire Line
	6900 5150 7250 5150
Text Label 6300 5150 2    60   ~ 0
RESET[RESET]
Text Label 6300 5050 2    60   ~ 0
PB5[~~13]
Text Label 6300 4950 2    60   ~ 0
PB4[12]
$Comp
L +5V #PWR9
U 1 1 5A5F54F7
P 7250 4950
F 0 "#PWR9" H 7250 4800 50  0001 C CNN
F 1 "+5V" H 7250 5090 50  0000 C CNN
F 2 "" H 7250 4950 50  0001 C CNN
F 3 "" H 7250 4950 50  0001 C CNN
	1    7250 4950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR10
U 1 1 5A5F54FD
P 7250 5150
F 0 "#PWR10" H 7250 4900 50  0001 C CNN
F 1 "GND" H 7250 5000 50  0000 C CNN
F 2 "" H 7250 5150 50  0001 C CNN
F 3 "" H 7250 5150 50  0001 C CNN
	1    7250 5150
	1    0    0    -1  
$EndComp
Text Label 7250 5050 0    60   ~ 0
PB3[~~11]
Wire Wire Line
	6650 2550 6650 3250
Wire Wire Line
	6850 2550 6850 3250
Wire Wire Line
	7350 2550 7350 3250
Wire Wire Line
	7450 2550 7450 3250
Wire Wire Line
	7550 2550 7550 3250
Wire Wire Line
	7650 2550 7650 3250
Text Label 6650 3250 3    60   ~ 0
PB0[8]
Text Label 6850 3250 3    60   ~ 0
PB1[~~9]
Text Label 7350 3250 3    60   ~ 0
PD4[4]
Text Label 7450 3250 3    60   ~ 0
PD5[~~5]
Text Label 7550 3250 3    60   ~ 0
PD6[~~6]
Text Label 7650 3250 3    60   ~ 0
PD7[7]
$Comp
L +5V #PWR2
U 1 1 5A5F5510
P 2950 1750
F 0 "#PWR2" H 2950 1600 50  0001 C CNN
F 1 "+5V" H 2950 1890 50  0000 C CNN
F 2 "" H 2950 1750 50  0001 C CNN
F 3 "" H 2950 1750 50  0001 C CNN
	1    2950 1750
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR3
U 1 1 5A5F5516
P 3850 1750
F 0 "#PWR3" H 3850 1500 50  0001 C CNN
F 1 "GND" H 3850 1600 50  0000 C CNN
F 2 "" H 3850 1750 50  0001 C CNN
F 3 "" H 3850 1750 50  0001 C CNN
	1    3850 1750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3750 1750 3850 1750
Wire Wire Line
	3350 1750 3450 1750
Wire Wire Line
	2950 1750 3050 1750
NoConn ~ 6950 2550
NoConn ~ 7050 2550
NoConn ~ 7150 2550
NoConn ~ 7250 2550
Text Notes 5700 1950 0    118  ~ 24
LCD\n\n\n
Text Notes 5750 4850 0    118  ~ 24
ICSP connector\n\n
Text Notes 2750 3050 0    118  ~ 24
Buttons\n\n\n
$Comp
L AVR-ISP-6 J1
U 1 1 5BB531CC
P 6800 5050
F 0 "J1" H 6695 5290 50  0000 C CNN
F 1 "AVR-ISP-6" H 6535 4820 50  0000 L BNN
F 2 "AVR-ISP-6" V 6280 5090 50  0001 C CNN
F 3 "" H 6775 5050 50  0000 C CNN
	1    6800 5050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
