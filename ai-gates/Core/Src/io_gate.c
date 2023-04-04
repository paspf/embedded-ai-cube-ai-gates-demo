/**
 ******************************************************************************
 * @file            : io_gate.c
 * @brief           : Map a gate to gpio ports.
 * @author			: paspf
 * @date			: 2023-04-03
 * @copyright		: paspf, GNU General Public License v3.0
 ******************************************************************************
 */

#include <stdio.h>
#include "io_gate.h"
#include "stm32l4xx_hal.h"
#include "test_gates.h"

/* Include models */
#include "model_and_gate.h"
#include "model_and_gate_data.h"


/* Private variables */
static ai_handle model = AI_HANDLE_NULL;
static ai_buffer *ai_output;
static ai_buffer *ai_input;

/* Private function prototypes */
static void _gpio_init();
static void _gpio_read();
static void _nn_init_and_predict();
static void _gpio_write();

/**
 * @fn void io_gates()
 * @brief IO gates initialization and main loop.
 *
 */
void io_gates() {
	_gpio_init();
	_nn_init_and_predict();
	while(1) {
		_gpio_read();
		_nn_init_and_predict();
		_gpio_write();
		HAL_Delay(50);
	}
}

/**
 * @fn void _gpio_init()
 * @brief Initialize GPIO pins.
 *
 */
static void _gpio_init() {
	/* Buttons */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_Buttons = {0};
	GPIO_Buttons.Mode = GPIO_MODE_INPUT;
	GPIO_Buttons.Pull = GPIO_PULLDOWN;
	GPIO_Buttons.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Buttons.Pin = GPIO_PIN_8 | GPIO_PIN_9;

	HAL_GPIO_Init(GPIOB, &GPIO_Buttons);

	/* LEDS */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_Leds;
	GPIO_Leds.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Leds.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_Leds.Pin = GPIO_PIN_5;
	HAL_GPIO_Init(GPIOC, &GPIO_Leds);
}

/**
 * @fn void _gpio_read()
 * @brief Read out GPIO pins and wirte level into ai_input buffer.
 *
 */
static void _gpio_read() {
	int pin8 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);
	int pin9 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
	// Write GPIO level to ai_input buffer.
	((ai_float*) ai_input->data)[0] = (ai_float) pin8;
	((ai_float*) ai_input->data)[1] = (ai_float) pin9;
}

/**
 * @fn void _nn_init_and_predict()
 * @brief Initialize neural network and run prediction on the current values in ai_input buffer.
 *
 */
static void _nn_init_and_predict() {
	ai_error ai_err;

	// Chunk of memory used to hold intermediate values for neural network.
	AI_ALIGNED(4) ai_u8 activations[AI_MODEL_AND_GATE_DATA_ACTIVATIONS_SIZE];

	// Buffers used to store input and output tensors.
	AI_ALIGNED(4) ai_i8 in_data[AI_MODEL_AND_GATE_IN_1_SIZE_BYTES];
	AI_ALIGNED(4) ai_i8 out_data[AI_MODEL_AND_GATE_OUT_1_SIZE_BYTES];

	// Set working memory and get weights/biases from model.
	ai_network_params model_params = { { { AI_MODEL_AND_GATE_DATA_WEIGHTS(
			ai_model_and_gate_data_weights_get()),
			AI_MODEL_AND_GATE_DATA_ACTIVATIONS(activations) } } };

	// Create instance of neural network.
	ai_err = ai_model_and_gate_create(&model, AI_MODEL_AND_GATE_DATA_CONFIG);
	if (ai_err.type != AI_ERROR_NONE) {
		printf("Error: could not create NN\r\n");
		while (1)
			;
	}

	// Initialize neural network.
	if (!ai_model_and_gate_init(model, &model_params)) {
		printf("Error: could not initialize NN\r\n");
		while (1)
			;
	}

	// Initialize wrapper structs.
	ai_input = ai_model_and_gate_inputs_get(model, NULL);
	ai_output = ai_model_and_gate_outputs_get(model, NULL);

	// Point to data buffers.
	ai_input->data = AI_HANDLE_PTR(in_data);
	ai_output->data = AI_HANDLE_PTR(out_data);


	// Perform prediction.
	ai_i32 nbatch = ai_model_and_gate_run(model, &ai_input[0], &ai_output[0]);
	if (nbatch != 1) {
		printf("Error: could not run prediction\n");
	}

}

/**
 * @fn void _gpio_write()
 * @brief Write Hi or Lo to a GPIO bin based on the current value in ai_output buffer.
 *
 */
static void _gpio_write() {
	// Read output (predicted y) of neural network.
	int y_pred = float_prediction_to_binary_int(((float*) ai_output->data)[0]);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, y_pred);
}


