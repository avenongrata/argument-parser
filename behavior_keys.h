/*
 * This file describes keys, which don't become argument as next parameter.
 */

#ifndef BEHAVIOR_KEYS_H
#define BEHAVIOR_KEYS_H

/*===========================================================================*/

#include "global.h"

/*---------------------------------------------------------------------------*/

typedef struct _behavior_keys
{
    byte_t ** _input;    /* incoming arguments */
    byte_t ** _output;   /* array of found arguments */

    /*-----------------------------------------------------------------------*/

    unsigned int _input_count;    /* count of inputed keys */
    unsigned int _found_count;    /* count of found keys */

    /*-----------------------------------------------------------------------*/
} behavior_keys;

extern void _init_beh_keys(behavior_keys * arg, const char * cmd);

/*===========================================================================*/

#endif // BEHAVIOR_KEYS_H
