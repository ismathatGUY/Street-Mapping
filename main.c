/*
 * File: main.c
 * Creator: George Ferguson
 * Created: Mon Nov 28 14:11:17 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"

// inputs
bool inputs[4][2] = {
    {false, false},
    {false, true},
    {true, false},
    {true, true}}; 



// Implement the creation logic for circuit A
static Circuit circuit_a()
{

    char *title = "circuit a";
    int numInputs = 2;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean *inputs = new_Boolean_array(numInputs);
    inputs[0] = x;
    inputs[1] = y;

    // Create the outputs
    int numOutputs = 1;
    Boolean result = new_Boolean(false);
    Boolean *outputs = new_Boolean_array(numOutputs);
    outputs[0] = result;

    // Create the gates
    int NGATES = 4;
    Gate A1 = new_AndGate();
    Gate A2 = new_AndGate();
    Gate A3 = new_Inverter();
    Gate A4 = new_OrGate();
    Gate *gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
                                  numInputs, inputs,
                                  numOutputs, outputs,
                                  NGATES, gates);

    // create connections
    // connect  x AND y
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Boolean x_and_y = Gate_getOutput(A1);

    // invert x AND y
    Circuit_connect(circuit, x_and_y, Gate_getInput(A3, 0));
    Boolean inverted_x_and_y = Gate_getOutput(A3);
    // connect x OR y
    Circuit_connect(circuit, x, Gate_getInput(A4, 0));
    Circuit_connect(circuit, y, Gate_getInput(A4, 1));
    Boolean x_OR_y = Gate_getOutput(A4);

    // connect inverted_x_and_y  AND x_OR_y
    Circuit_connect(circuit, inverted_x_and_y, Gate_getInput(A2, 0));
    Circuit_connect(circuit, x_OR_y, Gate_getInput(A2, 1));
    Boolean inverted_x_and_y_AND_x_OR_y = Gate_getOutput(A2);

    Circuit_connect(circuit, inverted_x_and_y_AND_x_OR_y, result);

    return circuit;
}



// Implement the creation logic for circuit B
static Circuit circuit_b()
{

    char *title = "circuit b";
    int numInputs = 2;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean *inputs = new_Boolean_array(numInputs);
    inputs[0] = x;
    inputs[1] = y;

    // Create the outputs
    int numOutputs = 1;
    Boolean result = new_Boolean(false);
    Boolean *outputs = new_Boolean_array(numOutputs);
    outputs[0] = result;

    // Create the gates
    int NGATES = 6;

    Gate or1 = new_OrGate();
    Gate inv1 = new_Inverter();
    Gate or2 = new_OrGate();
    Gate inv2 = new_Inverter();
    Gate or3 = new_OrGate();
    Gate inv3 = new_Inverter();
    Gate *gates = new_Gate_array(NGATES);
    gates[0] = or1;
    gates[1] = inv1;
    gates[2] = or2;
    gates[3] = inv2;
    gates[4] = or3;
    gates[5] = inv3;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
                                  numInputs, inputs,
                                  numOutputs, outputs,
                                  NGATES, gates);

    // create connections
    // connect x Or1 y

    Circuit_connect(circuit, x, Gate_getInput(or1, 0));
    Circuit_connect(circuit, y, Gate_getInput(or1, 1));
    Boolean x_or_y = Gate_getOutput(or1);

    // invert x or y

    Circuit_connect(circuit, x_or_y, Gate_getInput(inv1, 0));
    Boolean inverted_x_or_y = Gate_getOutput(inv1);

    Circuit_connect(circuit, inverted_x_or_y, Gate_getInput(or2, 0));
    Circuit_connect(circuit, inverted_x_or_y, Gate_getInput(or2, 1));

    Boolean inverted_x_or_y_OR_inverted_x_or_y = Gate_getOutput(or2);

    Circuit_connect(circuit, inverted_x_or_y_OR_inverted_x_or_y, Gate_getInput(inv2, 0));
    Boolean inverted_inverted_x_or_y_OR_inverted_x_or_y = Gate_getOutput(inv2);

    Circuit_connect(circuit,  inverted_inverted_x_or_y_OR_inverted_x_or_y, result);

    return circuit;


}


static Circuit CircuitC() {
    char *title = "Circuit C";
    int NINPUTS = 3;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean z = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;
    inputs[2] = z;
    // Create the outputs
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 5;
    Gate A1 = new_OrGate();
    Gate A2 = new_OrGate();
    Gate A3 = new_OrGate();
    Gate A4 = new_AndGate();
    Gate A5 = new_AndGate();
    Gate *gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;
    gates[4] = A5;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
                                  NINPUTS, inputs,
                                  NOUTPUTS, outputs,
                                  NGATES, gates);

    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Boolean x_or_y = Gate_getOutput(A1);

    Circuit_connect(circuit, x, Gate_getInput(A2, 0));
    Circuit_connect(circuit, z, Gate_getInput(A2, 1));
    Boolean x_or_z = Gate_getOutput(A2);

    Circuit_connect(circuit, y, Gate_getInput(A3, 0));
    Circuit_connect(circuit, z, Gate_getInput(A3, 1));
    Boolean y_or_z = Gate_getOutput(A3);

    Circuit_connect(circuit, x_or_y, Gate_getInput(A4, 0));
    Circuit_connect(circuit, x_or_z, Gate_getInput(A4, 1));
    Boolean x_or_y_and_x_or_z = Gate_getOutput(A4);

    Circuit_connect(circuit, x_or_y_and_x_or_z, Gate_getInput(A5, 0));
    Circuit_connect(circuit, y_or_z, Gate_getInput(A5, 1));
    Boolean resultC = Gate_getOutput(A5);

    Circuit_connect(circuit, resultC, result);

    // Done!
    return circuit;
}



// Ext'ra Credit Function F
static Circuit f() {
    char *title = "Function F";

    // Create the inputs
    int NINPUTS = 3;
    Boolean a = new_Boolean(false);
    Boolean b = new_Boolean(false);
    Boolean c = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = a;
    inputs[1] = b;
    inputs[2] = c;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 14;
    Gate N1 = new_Inverter();
    Gate N2 = new_Inverter();
    Gate N3 = new_Inverter();
    Gate A11 = new_AndGate();
    Gate A12 = new_AndGate();
    Gate A13 = new_AndGate();
    Gate A14 = new_AndGate();
    Gate A21 = new_AndGate();
    Gate A22 = new_AndGate();
    Gate A23 = new_AndGate();
    Gate A24 = new_AndGate();
    Gate O1 = new_OrGate();
    Gate O2 = new_OrGate();
    Gate O3 = new_OrGate();

    Gate* gates = new_Gate_array(NGATES);
    gates[0] = N1;
    gates[1] = N2;
    gates[2] = N3;
    gates[3] = A11;
    gates[4] = A12;
    gates[5] = A13;
    gates[6] = A14;
    gates[7] = A21;
    gates[8] = A22;
    gates[9] = A23;
    gates[10] = A24;
    gates[11] = O1;
    gates[12] = O2;
    gates[13] = O3;

    // Create the circuit
    Circuit circuit = new_Circuit(title, NINPUTS, inputs, NOUTPUTS, outputs, NGATES, gates);

    // Connect the gates
    Circuit_connect(circuit, a, Gate_getInput(N1, 0));
    Circuit_connect(circuit, b, Gate_getInput(N2, 0));
    Circuit_connect(circuit, c, Gate_getInput(N3, 0));
    Boolean na = Gate_getOutput(N1);
    Boolean nb = Gate_getOutput(N2);
    Boolean nc = Gate_getOutput(N3);

    Circuit_connect(circuit, na, Gate_getInput(A11, 0));
    Circuit_connect(circuit, nb, Gate_getInput(A11, 1));

    Circuit_connect(circuit, na, Gate_getInput(A12, 0));
    Circuit_connect(circuit, b, Gate_getInput(A12, 1));

    Circuit_connect(circuit, na, Gate_getInput(A13, 0));
    Circuit_connect(circuit, b, Gate_getInput(A13, 1));

    Circuit_connect(circuit, a, Gate_getInput(A14, 0));
    Circuit_connect(circuit, b, Gate_getInput(A14, 1));

    Boolean a11 = Gate_getOutput(A11);
    Boolean a12 = Gate_getOutput(A12);
    Boolean a13 = Gate_getOutput(A13);
    Boolean a14 = Gate_getOutput(A14);

    Circuit_connect(circuit, a11, Gate_getInput(A21, 0));
    Circuit_connect(circuit, c, Gate_getInput(A21, 1));

    Circuit_connect(circuit, a12, Gate_getInput(A22, 0));
    Circuit_connect(circuit, nc, Gate_getInput(A22, 1));

    Circuit_connect(circuit, a13, Gate_getInput(A23, 0));
    Circuit_connect(circuit, c, Gate_getInput(A23, 1));

    Circuit_connect(circuit, a14, Gate_getInput(A24, 0));
    Circuit_connect(circuit, c, Gate_getInput(A24, 1));

    Boolean a21 = Gate_getOutput(A21);
    Boolean a22 = Gate_getOutput(A22);
    Boolean a23 = Gate_getOutput(A23);
    Boolean a24 = Gate_getOutput(A24);

    Circuit_connect(circuit, a21, Gate_getInput(O1, 0));
    Circuit_connect(circuit, a22, Gate_getInput(O1, 1));

    Circuit_connect(circuit, a23, Gate_getInput(O2, 0));
    Circuit_connect(circuit, a24, Gate_getInput(O2, 1));

    Boolean o1 = Gate_getOutput(O1);
    Boolean o2 = Gate_getOutput(O2);

    Circuit_connect(circuit, o1, Gate_getInput(O3, 0));
    Circuit_connect(circuit, o2, Gate_getInput(O3, 1));

    Boolean final_output = Gate_getOutput(O3);
    Circuit_connect(circuit, final_output, result);

    return circuit;
}


static Circuit g() {
    char *circuitTitle = "Function G";

    // Initialize inputs
    int totalInputs = 3;
    Boolean inputA = new_Boolean(false);
    Boolean inputB = new_Boolean(false);
    Boolean inputC = new_Boolean(false);
    Boolean* inputArray = new_Boolean_array(totalInputs);
    inputArray[0] = inputA;
    inputArray[1] = inputB;
    inputArray[2] = inputC;

    // Initialize output
    int totalOutputs = 1;
    Boolean outputResult = new_Boolean(false);
    Boolean* outputArray = new_Boolean_array(totalOutputs);
    outputArray[0] = outputResult;

    // Set up gates
    int totalGates = 14;
    Gate notGateA = new_Inverter();
    Gate notGateB = new_Inverter();
    Gate notGateC = new_Inverter();

    Gate andGate11 = new_AndGate();
    Gate andGate12 = new_AndGate();
    Gate andGate13 = new_AndGate();
    Gate andGate14 = new_AndGate();
    Gate andGate21 = new_AndGate();
    Gate andGate22 = new_AndGate();
    Gate andGate23 = new_AndGate();
    Gate andGate24 = new_AndGate();

    Gate orGate1 = new_OrGate();
    Gate orGate2 = new_OrGate();
    Gate orGate3 = new_OrGate();

    Gate* gateArray = new_Gate_array(totalGates);
    gateArray[0] = notGateA;
    gateArray[1] = notGateB;
    gateArray[2] = notGateC;
    gateArray[3] = andGate11;
    gateArray[4] = andGate12;
    gateArray[5] = andGate13;
    gateArray[6] = andGate14;
    gateArray[7] = andGate21;
    gateArray[8] = andGate22;
    gateArray[9] = andGate23;
    gateArray[10] = andGate24;
    gateArray[11] = orGate1;
    gateArray[12] = orGate2;
    gateArray[13] = orGate3;

    // Assemble the circuit
    Circuit circuit = new_Circuit(circuitTitle, totalInputs, inputArray, totalOutputs, outputArray, totalGates, gateArray);

    // Connect gates and inputs
    Circuit_connect(circuit, inputA, Gate_getInput(notGateA, 0));
    Circuit_connect(circuit, inputB, Gate_getInput(notGateB, 0));
    Circuit_connect(circuit, inputC, Gate_getInput(notGateC, 0));

    Boolean invertedA = Gate_getOutput(notGateA);
    Boolean invertedB = Gate_getOutput(notGateB);
    Boolean invertedC = Gate_getOutput(notGateC);

    // Connect the AND gates
    Circuit_connect(circuit, invertedA, Gate_getInput(andGate11, 0));
    Circuit_connect(circuit, invertedB, Gate_getInput(andGate11, 1));

    Circuit_connect(circuit, invertedA, Gate_getInput(andGate12, 0));
    Circuit_connect(circuit, inputB, Gate_getInput(andGate12, 1));

    Circuit_connect(circuit, inputA, Gate_getInput(andGate13, 0));
    Circuit_connect(circuit, invertedB, Gate_getInput(andGate13, 1));

    Circuit_connect(circuit, inputA, Gate_getInput(andGate14, 0));
    Circuit_connect(circuit, inputB, Gate_getInput(andGate14, 1));

    // Output of first layer AND gates
    Boolean outputAnd11 = Gate_getOutput(andGate11);
    Boolean outputAnd12 = Gate_getOutput(andGate12);
    Boolean outputAnd13 = Gate_getOutput(andGate13);
    Boolean outputAnd14 = Gate_getOutput(andGate14);

    // Connect second layer AND gates
    Circuit_connect(circuit, outputAnd11, Gate_getInput(andGate21, 0));
    Circuit_connect(circuit, inputC, Gate_getInput(andGate21, 1));

    Circuit_connect(circuit, outputAnd12, Gate_getInput(andGate22, 0));
    Circuit_connect(circuit, invertedC, Gate_getInput(andGate22, 1));

    Circuit_connect(circuit, outputAnd13, Gate_getInput(andGate23, 0));
    Circuit_connect(circuit, invertedC, Gate_getInput(andGate23, 1));

    Circuit_connect(circuit, outputAnd14, Gate_getInput(andGate24, 0));
    Circuit_connect(circuit, inputC, Gate_getInput(andGate24, 1));

    // Output of second layer AND gates
    Boolean outputAnd21 = Gate_getOutput(andGate21);
    Boolean outputAnd22 = Gate_getOutput(andGate22);
    Boolean outputAnd23 = Gate_getOutput(andGate23);
    Boolean outputAnd24 = Gate_getOutput(andGate24);

    // Connect OR gates
    Circuit_connect(circuit, outputAnd21, Gate_getInput(orGate1, 0));
    Circuit_connect(circuit, outputAnd22, Gate_getInput(orGate1, 1));

    Circuit_connect(circuit, outputAnd23, Gate_getInput(orGate2, 0));
    Circuit_connect(circuit, outputAnd24, Gate_getInput(orGate2, 1));

    Boolean outputOr1 = Gate_getOutput(orGate1);
    Boolean outputOr2 = Gate_getOutput(orGate2);

    // Connect final OR gate
    Circuit_connect(circuit, outputOr1, Gate_getInput(orGate3, 0));
    Circuit_connect(circuit, outputOr2, Gate_getInput(orGate3, 1));

    // Connect the output of the final OR gate to the circuit output
    Boolean finalOutputOr = Gate_getOutput(orGate3);
    Circuit_connect(circuit, finalOutputOr, outputResult);

    return circuit;
}

// Generalized function to test any circuit with all possible input combinations
static void testCircuit(Circuit circuit, int numInputs) {
    int numCombinations = 1 << numInputs; // Calculate the number of combinations (2^numInputs)

    printf("Testing Circuit: %s\n", Circuit_getTitle(circuit));

    for (int i = 0; i < numCombinations; i++) {
        // Set each input according to the current combination
        for (int j = 0; j < numInputs; j++) {
            bool inputValue = (i >> j) & 1; // Extract the j-th bit of i
            Circuit_setInput(circuit, j, inputValue);
        }

        Circuit_update(circuit);

        // Print the input combination and output on the same line
        for (int j = 0; j < numInputs; j++) {
            printf("%d ", Boolean_getValue(Circuit_getInput(circuit, j)));
        }

        printf("| Output: %d\n", Boolean_getValue(Circuit_getOutput(circuit, 0)));
    }
    printf("\n");
}



int main(int argc, char **argv) {


    Circuit circuitA = circuit_a();
    Circuit_dump(circuitA);
    testCircuit(circuitA, 2); 
    free_Circuit(circuitA);

    Circuit circuitB = circuit_b();
    Circuit_dump(circuitB);
    testCircuit(circuitB, 2); 
    free_Circuit(circuitB);

    Circuit circuitC = CircuitC();
    Circuit_dump(circuitC);
    testCircuit(circuitC, 3);
    free_Circuit(circuitC);

    Circuit circuitF = f();
    Circuit_dump(circuitF);
    testCircuit(circuitF, 3);
    free_Circuit(circuitF);

    Circuit circuitG = g();
    Circuit_dump(circuitG);
    testCircuit(circuitG, 3);
    free_Circuit(circuitG); 
    return 0;
}
