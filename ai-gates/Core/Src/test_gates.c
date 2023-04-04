/**
  ******************************************************************************
  * @file           : test_gates.c
  * @brief          : Test neural networks, trained to represent logical gates.
  * @author			: paspf
  * @date			: 2023-03-26
  * @copyright		: paspf, GNU General Public License v3.0
  ******************************************************************************
  */

#include <stdio.h>
#include "test_gates.h"

/* Include models */
#include "model_and_gate.h"
#include "model_and_gate_data.h"
#include "model_nor_gate.h"
#include "model_nor_gate_data.h"
#include "model_or_gate.h"
#include "model_or_gate_data.h"
#include "model_xnor_gate.h"
#include "model_xnor_gate_data.h"
#include "model_xor_gate.h"
#include "model_xor_gate_data.h"

/* Test data */
const uint32_t len_input_data = 4;
float input_data[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };

const int output_data_and_gate[] = { 0, 0, 0, 1 };
const int output_data_nor_gate[] = { 1, 1, 1, 0 };
const int output_data_or_gate[] = { 0, 1, 1, 1 };
const int output_data_xor_gate[] = { 0, 1, 1, 0 };
const int output_data_xnor_gate[] = { 1, 0, 0, 1 };

/**
 * @fn void test_gates()
 * @brief Run tests for all gates.
 *
 */
void test_gates() {
	test_and_gate();
	test_nor_gate();
	test_or_gate();
	test_xnor_gate();
	test_xor_gate();
}

/**
 * @fn void test_and_gate()
 * @brief Execute predictions on the and gate model.
 *
 */
void test_and_gate() {
	printf("test_and_gate\n");

	ai_error ai_err;

	// Chunk of memory used to hold intermediate values for neural network.
	AI_ALIGNED(4) ai_u8 activations[AI_MODEL_AND_GATE_DATA_ACTIVATIONS_SIZE];

	// Buffers used to store input and output tensors.
	AI_ALIGNED(4) ai_i8 in_data[AI_MODEL_AND_GATE_IN_1_SIZE_BYTES];
	AI_ALIGNED(4) ai_i8 out_data[AI_MODEL_AND_GATE_OUT_1_SIZE_BYTES];

	// Pointer to the model.
	ai_handle model = AI_HANDLE_NULL;

	// Set working memory and get weights/biases from model.
	ai_network_params model_params = { { {
			AI_MODEL_AND_GATE_DATA_WEIGHTS(ai_model_and_gate_data_weights_get()),
			AI_MODEL_AND_GATE_DATA_ACTIVATIONS(activations)
	} } };

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
	ai_buffer *ai_input = ai_model_and_gate_inputs_get(model, NULL);
	ai_buffer *ai_output = ai_model_and_gate_outputs_get(model, NULL);

	// Point to data buffers.
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	predict(ai_model_and_gate_run, model, &ai_input[0], &ai_output[0], output_data_and_gate);

}

/**
 * @fn void test_nor_gate()
 * @brief Execute predictions on the nor gate model.
 *
 */
void test_nor_gate() {
	printf("test_nor_gate\n");

	ai_error ai_err;

	// Chunk of memory used to hold intermediate values for neural network.
	AI_ALIGNED(4) ai_u8 activations[AI_MODEL_NOR_GATE_DATA_ACTIVATIONS_SIZE];

	// Buffers used to store input and output tensors.
	AI_ALIGNED(4) ai_i8 in_data[AI_MODEL_NOR_GATE_IN_1_SIZE_BYTES];
	AI_ALIGNED(4) ai_i8 out_data[AI_MODEL_NOR_GATE_OUT_1_SIZE_BYTES];

	// Pointer to the model.
	ai_handle model = AI_HANDLE_NULL;

	// Set working memory and get weights/biases from model.
	ai_network_params model_params = { { {
			AI_MODEL_NOR_GATE_DATA_WEIGHTS(ai_model_nor_gate_data_weights_get()),
			AI_MODEL_NOR_GATE_DATA_ACTIVATIONS(activations)
	} } };

	// Create instance of neural network.
	ai_err = ai_model_nor_gate_create(&model, AI_MODEL_NOR_GATE_DATA_CONFIG);
	if (ai_err.type != AI_ERROR_NONE) {
		printf("Error: could not create NN\r\n");
		while (1)
			;
	}

	// Initialize neural network.
	if (!ai_model_nor_gate_init(model, &model_params)) {
		printf("Error: could not initialize NN\r\n");
		while (1)
			;
	}

	// Initialize wrapper structs.
	ai_buffer *ai_input = ai_model_nor_gate_inputs_get(model, NULL);
	ai_buffer *ai_output = ai_model_nor_gate_outputs_get(model, NULL);

	// Point to data buffers.
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	predict(ai_model_nor_gate_run, model, &ai_input[0], &ai_output[0], output_data_nor_gate);

}

/**
 * @fn void test_or_gate()
 * @brief Execute predictions on the or gate model.
 *
 */
void test_or_gate() {
	printf("test_or_gate\n");

	ai_error ai_err;

	// Chunk of memory used to hold intermediate values for neural network.
	AI_ALIGNED(4) ai_u8 activations[AI_MODEL_OR_GATE_DATA_ACTIVATIONS_SIZE];

	// Buffers used to store input and output tensors.
	AI_ALIGNED(4) ai_i8 in_data[AI_MODEL_OR_GATE_IN_1_SIZE_BYTES];
	AI_ALIGNED(4) ai_i8 out_data[AI_MODEL_OR_GATE_OUT_1_SIZE_BYTES];

	// Pointer to the model.
	ai_handle model = AI_HANDLE_NULL;

	// Set working memory and get weights/biases from model.
	ai_network_params model_params = { { {
			AI_MODEL_OR_GATE_DATA_WEIGHTS(ai_model_or_gate_data_weights_get()),
			AI_MODEL_OR_GATE_DATA_ACTIVATIONS(activations)
	} } };

	// Create instance of neural network.
	ai_err = ai_model_or_gate_create(&model, AI_MODEL_OR_GATE_DATA_CONFIG);
	if (ai_err.type != AI_ERROR_NONE) {
		printf("Error: could not create NN\r\n");
		while (1)
			;
	}

	// Initialize neural network.
	if (!ai_model_or_gate_init(model, &model_params)) {
		printf("Error: could not initialize NN\r\n");
		while (1)
			;
	}

	// Initialize wrapper structs.
	ai_buffer *ai_input = ai_model_or_gate_inputs_get(model, NULL);
	ai_buffer *ai_output = ai_model_or_gate_outputs_get(model, NULL);

	// Point to data buffers.
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	predict(ai_model_or_gate_run, model, &ai_input[0], &ai_output[0], output_data_or_gate);
}

/**
 * @fn void test_xnor_gate()
 * @brief Execute predictions on the xnor gate model.
 *
 */
void test_xnor_gate() {
	printf("test_xnor_gate\n");

	ai_error ai_err;

	// Chunk of memory used to hold intermediate values for neural network.
	AI_ALIGNED(4) ai_u8 activations[AI_MODEL_XNOR_GATE_DATA_ACTIVATIONS_SIZE];

	// Buffers used to store input and output tensors.
	AI_ALIGNED(4) ai_i8 in_data[AI_MODEL_XNOR_GATE_IN_1_SIZE_BYTES];
	AI_ALIGNED(4) ai_i8 out_data[AI_MODEL_XNOR_GATE_OUT_1_SIZE_BYTES];

	// Pointer to the model.
	ai_handle model = AI_HANDLE_NULL;

	// Set working memory and get weights/biases from model.
	ai_network_params model_params = { { {
			AI_MODEL_XNOR_GATE_DATA_WEIGHTS(ai_model_xnor_gate_data_weights_get()),
			AI_MODEL_XNOR_GATE_DATA_ACTIVATIONS(activations)
	} } };

	// Create instance of neural network.
	ai_err = ai_model_xnor_gate_create(&model, AI_MODEL_XNOR_GATE_DATA_CONFIG);
	if (ai_err.type != AI_ERROR_NONE) {
		printf("Error: could not create NN\r\n");
		while (1)
			;
	}

	// Initialize neural network.
	if (!ai_model_xnor_gate_init(model, &model_params)) {
		printf("Error: could not initialize NN\r\n");
		while (1)
			;
	}

	// Initialize wrapper structs.
	ai_buffer *ai_input = ai_model_xnor_gate_inputs_get(model, NULL);
	ai_buffer *ai_output = ai_model_xnor_gate_outputs_get(model, NULL);

	// Point to data buffers.
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	predict(ai_model_xnor_gate_run, model, &ai_input[0], &ai_output[0], output_data_xnor_gate);

}

/**
 * @fn void test_xor_gate()
 * @brief Execute predictions on the xor gate model.
 *
 */
void test_xor_gate() {
	printf("test_xor_gate\n");

	ai_error ai_err;

	// Chunk of memory used to hold intermediate values for neural network.
	AI_ALIGNED(4) ai_u8 activations[AI_MODEL_XOR_GATE_DATA_ACTIVATIONS_SIZE];

	// Buffers used to store input and output tensors.
	AI_ALIGNED(4) ai_i8 in_data[AI_MODEL_XOR_GATE_IN_1_SIZE_BYTES];
	AI_ALIGNED(4) ai_i8 out_data[AI_MODEL_XOR_GATE_OUT_1_SIZE_BYTES];

	// Pointer to the model.
	ai_handle model = AI_HANDLE_NULL;

	// Set working memory and get weights/biases from model.
	ai_network_params model_params = { { {
			AI_MODEL_XOR_GATE_DATA_WEIGHTS(ai_model_xor_gate_data_weights_get()),
			AI_MODEL_XOR_GATE_DATA_ACTIVATIONS(activations)
	} } };

	// Create instance of neural network.
	ai_err = ai_model_xor_gate_create(&model, AI_MODEL_XOR_GATE_DATA_CONFIG);
	if (ai_err.type != AI_ERROR_NONE) {
		printf("Error: could not create NN\r\n");
		while (1)
			;
	}

	// Initialize neural network.
	if (!ai_model_xor_gate_init(model, &model_params)) {
		printf("Error: could not initialize NN\r\n");
		while (1)
			;
	}

	// Initialize wrapper structs.
	ai_buffer *ai_input = ai_model_xor_gate_inputs_get(model, NULL);
	ai_buffer *ai_output = ai_model_xor_gate_outputs_get(model, NULL);

	// Point to data buffers.
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	predict(ai_model_xor_gate_run, model, &ai_input[0], &ai_output[0], output_data_xor_gate);
}

/**
 * @fn int float_prediction_to_binary_int(float)
 * @brief Convert float value to binary int value (0 or 1).
 * If prediction > 0.5 -> return 1
 * Else -> return 0
 *
 * @param prediction Float value to convert.
 * @return Int value, 0 or 1.
 */
int float_prediction_to_binary_int(float prediction) {
	if (prediction > 0.5) {
		return 1;
	}
	return 0;
}

/**
 * @fn void print_single_prediction(float*, int, int)
 * @brief Print out a single prediction.
 *
 * @param x_input x-network input.
 * @param y_ref   y-network reference.
 * @param y_pred  y-network output.
 * @return 1 if y_pred matches y_ref.
 */
int print_single_prediction(const float *x_input, const int y_ref, const int y_pred) {
    if (y_ref == y_pred) {
        printf("|[%.1f, %.1f]|[%d]| -> %d -> True\n", x_input[0], x_input[1],
                y_ref, y_pred);
        return 1;
    }
    printf("|[%.1f, %.1f]|[%d]| -> %d -> False\n", x_input[0], x_input[1],
            y_ref, y_pred);
    return 0;
}

/**
 * @fn int predict(ai_i32(*)(ai_handle, const ai_buffer*, ai_buffer*), ai_handle, const ai_buffer*, ai_buffer*)
 * @brief Perform predictions for all entries in the input_data dataset using the given model.
 *
 * @param model_run AI model run function, generated by CubeAI.
 * @param model Pointer to the model.
 * @param ai_input AI input buffer.
 * @param ai_output AI output buffer.
 * @param output_data_reference Reference output data.
 * @return 1 if all predictions match the reference in the test data set.
 */
int predict(ai_i32 (*model_run)(ai_handle, const ai_buffer*, ai_buffer*), ai_handle model, const ai_buffer* ai_input, ai_buffer* ai_output, const int* output_data_reference) {
	int ret = 1;
	// Iterate through all rows in the input data set.
	for (int i = 0; i < len_input_data; i++) {
		// Fill input buffer (use test value).
		for (uint32_t j = 0; j < ai_input->size; j++) {
			((ai_float*) ai_input->data)[j] = (ai_float) input_data[i][j];
		}

		// Perform prediction.
		ai_i32 nbatch = model_run(model, &ai_input[0], &ai_output[0]);
		if (nbatch != 1) {
			printf("Error: could not run prediction\n");
		}

		// Read output (predicted y) of neural network.
		float y_pred = 30.0f;
		y_pred = ((float*) ai_output->data)[0];

		// Map prediction to integer value, print results.
		int y_int = float_prediction_to_binary_int(y_pred);
		if (print_single_prediction(input_data[i], output_data_reference[i], y_int) == 0) {
			// Set return value to 0 if a prediction does not match its reference.
			ret = 0;
		}
	}
	return ret;
}

