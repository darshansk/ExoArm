# ExoSkeletonArm
Welcome to the final year project of students Sindhu Gm, Chidananda J and Darshan Sk. We aim at making a robust arm for helping anyone who needs external support at a very affordable cost.

We post regularyly at our blog: https://theexoarm.wordpress.com/


Under the mentorship of : Roopesh Kumar sir and K. Venkat Rao sir.
#Open source LICENSE:

#MIT LICENSE:
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished.


Any suggestions is always welcome to mail id: darshansk@protonmail.com

Thank you for stopping by!

Hardware components required: 

1 × Load cell with Load Cell Amplifier
1 × Aluminum 4 x 30 x at least 2000mm
1 × Li-Po battery 3S 5500mAh, 
1 × Wearable suspender unit, 
1 × Screws and nuts. M4 and M6, 
1 × Wooden plates  
1 × Insulin tape, 
2 × Arduino Uno 
1 × VNH2SP30 motor driver, 
1 × Car Windshield Wiper Motor (or similar) for heavy loads Long wires

Software requirements
•    Arduino IDE.
•    Android Studio.
•    Windows/ Linux OS/ IOS.

Project description 
This is open source product where the product is helpful in lifting weighted load by person who can’t lift the object by his own and needs an external support. This product is mainly helpful for people who suffer fatigue or polio affected person. This product has basically three modules which are integrated to form a whole system. First main module is the motor module which is responsible for the movement of the arm. Second module speaks about the display of the load that is been lifted in grams with the help of load cell and the load cell amplifier. The last module deals with the IoT where we upload the values of all these hardware components to be displayed on the screen.

Project building steps

1.    Constructing the External frame of the exoskeleton arm
2 metal sheet of 1mm thickness, 20 cm long and 3 cm long in width are used, we fix one of the metal sheet to the rigid support of the motor which will act as the support to the shoulder, another sheet will be fixed to the motor shaft of the motor to obtain arm movement and support. We use lockable belts in order to keep the who frame intact to our arm so it fits perfectly.

2.    Connection of motor to motor driver, Arduino and power supply
The windshield motor is to be connected to the motor driver first, where this motor will be fixed to the external frame from the motor driver we connect it to the Arduino and also power source is connected. The respective Arduino code is compiled and implemented. The connections are done as per the circuit diagram.

3.    Load cell implementation with load cell amplifier HX711
The load cell and the load cell amplifier HX711 are connected and inturn connected to the Arduino, a display is also used to display the weight of the object the provided code is loaded and is made to run. The connections are done as per the circuit diagram.

4.    Node MCU ESP 
The node MCU is connected to the Arduino such that the data is transmitted from the Arduino to the Node MCU and those data are constantly sent to know the number of rotation of the motor, the speed of the motor and also the battery percentage of the motor. 

Minute functionalities: Two button circuits are used to control the direction of the motor in clockwise and anti-clockwise direction.
The other functionality is a switch that is been provided to cut the power and supply the power to the whole circuit.

Finally all the chips are embedded on the backpack based on placing preferences.

