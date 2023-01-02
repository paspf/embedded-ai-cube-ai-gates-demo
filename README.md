# AI Gates using TensorFlow and Cube AI
This project demonstrates the usage of TensorFlow and CubeAI by running small neural networks on a STM32 L476RG. The networks are trained to predict logical gates (AND, OR, NOR, XOR, XNOR).

The networks were trained with Tensorflow 2.10 and brought to the microcontroller using Cube AI 7.3 . This git repo includes the associated Cube IDE project (in directory `ai-gates`) as well as the Jupyter notebook (see directory `tf-models`) required to train the neural networks.

The demo application includes the following features:
 - Predict functions for all gates (`test_gates.c`)
 - Print model evaluation to command line interface (`test_gates.c`)
 - Map a single gate to I/O ports (`io_gate.c`)
 - Usage of the [ES-PCB for Nucleo L476RG](https://github.com/paspf/ES-PCB-for-L476RG) as periphery board
