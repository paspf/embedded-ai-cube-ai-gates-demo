/**
  ******************************************************************************
  * @file           : test_gates.c
  * @brief          : Test neural networks, trained to represent digital gates.
  * @author			: paspf
  * @date			: 2022-12-22
  * @copyright		: paspf, GNU General Public License v3.0
  ******************************************************************************
  */

#ifndef INC_TEST_GATES_H_
#define INC_TEST_GATES_H_

/* Include CubeAI platform */
#include "ai_datatypes_defines.h"
#include "ai_platform.h"

void test_gates();
void test_and_gate();
void test_nor_gate();
void test_or_gate();
void test_xnor_gate();
void test_xor_gate();

int float_prediction_to_binary_int(float prediction);
int print_single_prediction(const float *x_input, const int y_ref, const int y_pred);
int predict(ai_i32 (*model_run)(ai_handle, const ai_buffer*, ai_buffer*), ai_handle model, const ai_buffer* ai_input, ai_buffer* ai_output, const int* output_data_reference);

#endif /* INC_TEST_GATES_H_ */
