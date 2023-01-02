/**
  ******************************************************************************
  * @file    model_or_gate_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Dec 22 15:53:39 2022
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

#include "model_or_gate_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_model_or_gate_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_model_or_gate_weights_array_u64[9] = {
  0x40f5575940db8007U, 0x40cef23e40c658a4U, 0x40a8ca8f40a85ecdU, 0x40d61e3040cbabfbU,
  0xc0775db6c0894941U, 0xc07e64b6c05a9658U, 0x404053e0405cb7c9U, 0x40314af23fc5f6c3U,
  0xc086ee84U,
};


ai_handle g_model_or_gate_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_model_or_gate_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

