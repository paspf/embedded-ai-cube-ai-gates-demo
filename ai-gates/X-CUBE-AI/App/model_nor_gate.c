/**
  ******************************************************************************
  * @file    model_nor_gate.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Dec 22 15:53:46 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "model_nor_gate.h"
#include "model_nor_gate_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_model_nor_gate
 
#undef AI_MODEL_NOR_GATE_MODEL_SIGNATURE
#define AI_MODEL_NOR_GATE_MODEL_SIGNATURE     "42de298b082ebe6efeff8d9fbbe22afc"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Thu Dec 22 15:53:46 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_MODEL_NOR_GATE_N_BATCHES
#define AI_MODEL_NOR_GATE_N_BATCHES         (1)

static ai_ptr g_model_nor_gate_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_model_nor_gate_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  input_2_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)
/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_dense_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &dense_4_dense_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &dense_4_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_dense_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &dense_5_dense_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &dense_5_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_dense_weights, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 2, 4, 1, 1), AI_STRIDE_INIT(4, 4, 8, 32, 32),
  1, &dense_4_dense_weights_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_dense_bias, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &dense_4_dense_bias_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_dense_weights, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 4, 1, 1, 1), AI_STRIDE_INIT(4, 4, 16, 16, 16),
  1, &dense_5_dense_weights_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_dense_bias, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &dense_5_dense_bias_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  input_2_output, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &input_2_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_5_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_5_layer, 2,
  NL_TYPE, 0x0, NULL,
  nl, forward_sigmoid,
  &dense_5_chain,
  NULL, &dense_5_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_5_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_5_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_5_dense_weights, &dense_5_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_5_dense_layer, 2,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_5_dense_chain,
  NULL, &dense_5_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_4_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_4_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_4_layer, 1,
  NL_TYPE, 0x0, NULL,
  nl, forward_sigmoid,
  &dense_4_chain,
  NULL, &dense_5_dense_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_4_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_4_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_4_dense_weights, &dense_4_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_4_dense_layer, 1,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_4_dense_chain,
  NULL, &dense_4_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 68, 1, 1),
    68, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 24, 1, 1),
    24, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_MODEL_NOR_GATE_IN_NUM, &input_2_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_MODEL_NOR_GATE_OUT_NUM, &dense_5_output),
  &dense_4_dense_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 68, 1, 1),
      68, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 24, 1, 1),
      24, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_MODEL_NOR_GATE_IN_NUM, &input_2_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_MODEL_NOR_GATE_OUT_NUM, &dense_5_output),
  &dense_4_dense_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool model_nor_gate_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_model_nor_gate_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_2_output_array.data = AI_PTR(g_model_nor_gate_activations_map[0] + 0);
    input_2_output_array.data_start = AI_PTR(g_model_nor_gate_activations_map[0] + 0);
    
    dense_4_dense_output_array.data = AI_PTR(g_model_nor_gate_activations_map[0] + 8);
    dense_4_dense_output_array.data_start = AI_PTR(g_model_nor_gate_activations_map[0] + 8);
    
    dense_4_output_array.data = AI_PTR(g_model_nor_gate_activations_map[0] + 8);
    dense_4_output_array.data_start = AI_PTR(g_model_nor_gate_activations_map[0] + 8);
    
    dense_5_dense_output_array.data = AI_PTR(g_model_nor_gate_activations_map[0] + 0);
    dense_5_dense_output_array.data_start = AI_PTR(g_model_nor_gate_activations_map[0] + 0);
    
    dense_5_output_array.data = AI_PTR(g_model_nor_gate_activations_map[0] + 4);
    dense_5_output_array.data_start = AI_PTR(g_model_nor_gate_activations_map[0] + 4);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool model_nor_gate_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_model_nor_gate_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    dense_4_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_4_dense_weights_array.data = AI_PTR(g_model_nor_gate_weights_map[0] + 0);
    dense_4_dense_weights_array.data_start = AI_PTR(g_model_nor_gate_weights_map[0] + 0);
    
    dense_4_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_4_dense_bias_array.data = AI_PTR(g_model_nor_gate_weights_map[0] + 32);
    dense_4_dense_bias_array.data_start = AI_PTR(g_model_nor_gate_weights_map[0] + 32);
    
    dense_5_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_5_dense_weights_array.data = AI_PTR(g_model_nor_gate_weights_map[0] + 48);
    dense_5_dense_weights_array.data_start = AI_PTR(g_model_nor_gate_weights_map[0] + 48);
    
    dense_5_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_5_dense_bias_array.data = AI_PTR(g_model_nor_gate_weights_map[0] + 64);
    dense_5_dense_bias_array.data_start = AI_PTR(g_model_nor_gate_weights_map[0] + 64);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_model_nor_gate_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_MODEL_NOR_GATE_MODEL_NAME,
      .model_signature   = AI_MODEL_NOR_GATE_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 67,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_model_nor_gate_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_MODEL_NOR_GATE_MODEL_NAME,
      .model_signature   = AI_MODEL_NOR_GATE_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 67,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_model_nor_gate_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_model_nor_gate_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_model_nor_gate_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_model_nor_gate_create(network, AI_MODEL_NOR_GATE_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_model_nor_gate_data_params_get(&params) != true) {
        err = ai_model_nor_gate_get_error(*network);
        return err;
    }
#if defined(AI_MODEL_NOR_GATE_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_MODEL_NOR_GATE_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_model_nor_gate_init(*network, &params) != true) {
        err = ai_model_nor_gate_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_model_nor_gate_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_model_nor_gate_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_model_nor_gate_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_model_nor_gate_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= model_nor_gate_configure_weights(net_ctx, params);
  ok &= model_nor_gate_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_model_nor_gate_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_model_nor_gate_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_MODEL_NOR_GATE_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

