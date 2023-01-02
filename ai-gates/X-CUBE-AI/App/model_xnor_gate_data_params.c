/**
  ******************************************************************************
  * @file    model_xnor_gate_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Dec 22 15:53:53 2022
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

#include "model_xnor_gate_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_model_xnor_gate_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_model_xnor_gate_weights_array_u64[9] = {
  0xc1492ecc418ca8e5U, 0x4144be72c0e37963U, 0xc132004240a45ee4U, 0x417a921a416807c6U,
  0x40134d10408413feU, 0xc0af39aebf7fe0f6U, 0x3fe6b6ad41388d5dU, 0xc0b4400fc12ec94aU,
  0xbff3abf0U,
};


ai_handle g_model_xnor_gate_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_model_xnor_gate_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

