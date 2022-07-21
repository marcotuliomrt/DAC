## Digital to Analog Converter (DAC)
A DAC is a device that converts a digital signal to an analog signal. They can be made with different architectures/topologies, and for this project was used the R-2R topology.

## Usage
The interface of the DAC consists of 3 buttons, one changes the wave form, altering between them in a cyclical manner, the other two control the frequency, one rises and the other lowers it.

## Materials used:
-	Nucleo F103RB (because of the simplicity os the project, any board with ST microcontroller should work fine)
-	Mbed online IDE
-	Mbed library 
-	3x push buttons (to control de outputs of the DAC)
-	3x 10K resistors (pull-down resistors for the buttons)
-	1x oscilloscope (to visualize and test the wave formats and frequencies)


## About the DAC
It is a 8-bit DAC that can generate 3 wave formats, square, triangular and sinusoidal, and the hardware follows a R-2R topology.
The hardware simulation was done on the software Proteus:\
OBS 1: The logical gates on the schematic represent the direct connections with the board pins specified on the code.\
OBS 2: The multimeter on the schematic represents the osciloscope.

![image](https://user-images.githubusercontent.com/56456537/176966622-e89bb0b3-71bb-4817-88bd-57572b8ff2f9.png)

The assembly was done on a breadboard:

![image](https://user-images.githubusercontent.com/56456537/176966648-f14089fb-b448-4d9c-843c-597c398619c7.png)
