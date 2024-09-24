# Analog-Neural-Networks

<p> This is still a work in progress. Gerber files can be found in the board folder. Any code provided may have untested portions. I have done my best to label what has and has not been tested. <p>

## Overview

<p> The goal of this project is to prove the working principles behind my design for an analog neural network. This method breaks down mathematical operations and converts them into a collection of common electrical components. This can ultimately be implemented on an IC and used in low-power edge devices. <p>

## Progress

<p> Currently each individual component of the design has been tested independently, however, due to size constraints and interference in the breadboard prototype, a full implementation has not yet been tested. The following have been tested and verified. <p>

- Interfacing with the DAC
- Interfacing with the MOSFETs
- Reading voltages with analog inputs
- Setting ground and voltage references for the ADC

## Next Steps

- Assemble PCB
- Map voltages to summed values
- Validate simulation results