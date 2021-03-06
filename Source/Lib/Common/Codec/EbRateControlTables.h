/*
* Copyright(c) 2019 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#ifndef EbRateControlTables_h
#define EbRateControlTables_h

#include "EbDefinitions.h"
#include "EbDefinitions.h"
#include "EbUtility.h"


/**************************************
 * Rate Control Defines
 **************************************/
#define SAD_PRECISION_INTERVAL                              4

#define VAR_ROUND_INTERVAL                                  20

#define NUMBER_OF_SAD_INTERVALS                             128      // number of intervals in SAD tables

#define NUMBER_OF_INTRA_SAD_INTERVALS                       NUMBER_OF_SAD_INTERVALS      // number of intervals in intra Sad tables

#define TOTAL_NUMBER_OF_INTERVALS                           (NUMBER_OF_SAD_INTERVALS + \
                                                             NUMBER_OF_INTRA_SAD_INTERVALS )
#if RC
#define TOTAL_NUMBER_OF_REF_QP_VALUES                       64
#define TOTAL_NUMBER_OF_INITIAL_RC_TABLES_ENTRY             (TOTAL_NUMBER_OF_REF_QP_VALUES)
#else
#define TOTAL_NUMBER_OF_REF_QP_VALUES                       1
#define TOTAL_NUMBER_OF_INITIAL_RC_TABLES_ENTRY             (TOTAL_NUMBER_OF_REF_QP_VALUES * TOTAL_NUMBER_OF_INTERVALS)
#endif

 /**************************************
  * The EB_BitFraction is used to define the bit fraction numbers
  **************************************/
typedef uint16_t EbBitNumber;

/**************************************
 * Initial Rate Control Structure
 **************************************/
typedef struct InitialRateControlTables 
{
#if RC
    EbBitNumber  sad_bits_array[MAX_TEMPORAL_LAYERS][NUMBER_OF_SAD_INTERVALS];
    EbBitNumber  intra_sad_bits_array[MAX_TEMPORAL_LAYERS][NUMBER_OF_INTRA_SAD_INTERVALS];
#else
    EbBitNumber  sad_bits_array[MAX_TEMPORAL_LAYERS][NUMBER_OF_SAD_INTERVALS];
    EbBitNumber  intra_sad_bits_array[MAX_TEMPORAL_LAYERS][NUMBER_OF_INTRA_SAD_INTERVALS];
#endif
} RateControlTables;
#if !RC
static const uint8_t ref_qp_list_table[] =

{ 0,    1,    2,    3,    4,    5,    6,    7,
  8,    9,   10,   11,   12,   13,   14,   15,
 16,   17,   18,   19,   20,   21,   22,   23,
 24,   25,   26,   27,   28,   29,   30,   31,
 32,   33,   34,   35,   36,   37,   38,   39,
 40,   41,   42,   43,   44,   45,   46,   47,
 48,   49,   50,   51 };
#endif
/**************************************
 * Extern Function Declarations
 **************************************/
extern EbErrorType rate_control_tables_ctor(
    RateControlTables *rate_control_tables_array
);



#endif //EbRateControlTables_h
