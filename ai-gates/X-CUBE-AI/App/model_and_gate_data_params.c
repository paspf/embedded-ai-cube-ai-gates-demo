/**
  ******************************************************************************
  * @file    model_and_gate_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Dec 22 15:53:32 2022
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

#include "model_and_gate_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_model_and_gate_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_model_and_gate_weights_array_u64[9] = {
  0x3f8fdd6f40518274U, 0xc0989938be3ff37bU, 0xbff9de60c04a9b71U, 0xbfef672dc01372b3U,
  0x3fdca5f7bff951acU, 0x4000b19d40365439U, 0xc09f322240530b2dU, 0xc07f73b0c0c3650dU,
  0x3fcd6a89U,
};


ai_handle g_model_and_gate_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_model_and_gate_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

