/**
  ******************************************************************************
  * @file    model_xor_gate_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Dec 22 15:54:00 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "model_xor_gate_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_model_xor_gate_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_model_xor_gate_weights_array_u64[9] = {
  0x412f57f2c022292dU, 0xc1568bb4c1629f0aU, 0x413c91dbc0359438U, 0x410439d7c14c7707U,
  0x409fd6e6c03805c5U, 0xc041b920c03ba84eU, 0xc17e0717c0dc6f1cU, 0x4175c4a4c0fcdeb2U,
  0x40e9a8d8U,
};


ai_handle g_model_xor_gate_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_model_xor_gate_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

