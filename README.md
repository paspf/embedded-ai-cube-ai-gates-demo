# AI Gates using TensorFlow and Cube AI
This project demonstrates the usage of TensorFlow and CubeAI by running small neural networks on a STM32 L476RG. The networks are trained to predict logical gates (AND, OR, NOR, XOR, XNOR).

The networks were trained with Tensorflow `2.10` and brought to the microcontroller using Cube AI `7.3` within CubeIDE `1.11.2`. This git repo includes the associated Cube IDE project (in directory `ai-gates`) as well as the Jupyter notebook (see directory `tf-models`) required to train the neural networks.

The demo application includes the following features:
 - Predict functions for all gates (`test_gates.c`)
 - Print model evaluation to command line interface (`test_gates.c`)
 - Map a single gate to I/O ports (`io_gate.c`)
 - Usage of the [ES-PCB for Nucleo L476RG](https://github.com/paspf/ES-PCB-for-L476RG) as periphery board



## Setup

### Get Repository

```
git@github.com:paspf/embedded-ai-cube-ai-gates-demo.git
```

### Open Project in Cube IDE

Open the repositories folder in Cube IDE as workspace, import the `ai-gates`.

## Program Output

When running the program, the command line output should look similar to this:
```
test_nor_gate
|[0.0, 0.0]|[1]| -> 1 -> True
|[0.0, 1.0]|[1]| -> 1 -> True
|[1.0, 0.0]|[1]| -> 1 -> True
|[1.0, 1.0]|[0]| -> 0 -> True

```
