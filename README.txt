README for CSC173 Project 5
Name: Ismael Kabore
Email: ikabore@u.rochester.edu


How to Run
Follow these steps to compile and run the program:

Open a terminal.

1.cd Desktop/csc173-project-5-boosim 
2.make
3. ./boosim


Overview
This C program is aBoolean Logic and Boolean Circuitssimulator. It includes the implementation and testing of various logic circuits (A, B, C, F, and G), each built using basic logic gates like AND, OR, and NOT. The program dynamically creates these circuits, tests them with all possible input combinations, and outputs the results. You can uncomment the Circuit_dump(circuitG); for displaying detailed information about the Circuit object.

Features
Dynamic Circuit Creation: Constructs logic circuits with different configurations of gates and connections.
Flexible Input/Output: Supports multiple input and output combinations for each circuit.
Comprehensive Testing: Tests each circuit with all possible input combinations and displays the output.
Main Components
Circuit Definitions: circuit_a(), circuit_b(), CircuitC(), f(), g()
Define logic circuits with various combinations of logic gates.
Test Function: testCircuit(Circuit circuit, int numInputs)
Tests a given circuit with all possible input combinations.
Main Function: main(int argc, char **argv)
Creates each circuit, tests it, and then frees the allocated memory.
Key Functions
new_Boolean(value): Creates a new Boolean variable.
new_Boolean_array(size): Creates an array of Boolean variables.
new_Gate_array(size): Creates an array of Gates.
new_Circuit(...): Constructs a new circuit with specified inputs, outputs, and gates.
Circuit_connect(...): Connects the gates in the circuit as per the logic design.
Boolean_getValue(...): Retrieves the value of a Boolean variable.
Circuit_setInput(...): Sets the value of a circuit's input.
Circuit_getInput(...): Gets the input value of a circuit.
Circuit_getOutput(...): Retrieves the output value of a circuit.
Circuit_update(circuit): Updates the circuit state based on its inputs.

