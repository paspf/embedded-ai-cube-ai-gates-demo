/**
  ******************************************************************************
  * @file    model_nor_gate_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Dec 22 15:53:46 2022
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

#include "model_nor_gate_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_model_nor_gate_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_model_nor_gate_weights_array_u64[9] = {
  0x4013a2b6401a8293U, 0xc00489cdbff88543U, 0xc00536b7c025af2eU, 0x402665e13fddcb0eU,
  0x4015b80fc03e160cU, 0xc024a1aa403a34afU, 0x40967fc0c05259c5U, 0xc03259b140ac183aU,
  0x3de67bf7U,
};


ai_handle g_model_nor_gate_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_model_nor_gate_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

