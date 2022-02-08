/*
 * This file describes keys, which don't become argument as next parameter.
 */

#ifndef BEHAVIOR_KEYS_H
#define BEHAVIOR_KEYS_H

/*===========================================================================*/

#include "global.h"

/*---------------------------------------------------------------------------*/

#define _BH_INIT_ARGS(args) \
    { \
        .input        = NULL,       \
        ._output      = NULL,       \
        ._input_count = 0,          \
        ._found_count = 0,          \
        .find         = _find_keys  \
    }

#define _BH_ARGS(name) \
    behavior_keys name = _BH_INIT_ARGS(name)

/*---------------------------------------------------------------------------*/

typedef struct _behavior_keys
{
    byte_t *  input;     /* incoming arguments */
    byte_t ** _output;    /* array of found arguments */

    /*-----------------------------------------------------------------------*/

    unsigned int _input_count;    /* count of inputed keys */
    unsigned int _found_count;    /* count of found keys */

    /*-----------------------------------------------------------------------*/

    /* find all keys specified in the template in argv */
    int (*find)(char * _template, char ** _argv);

} behavior_keys;

extern int _find_keys(char * _template, char ** _argv);

/*===========================================================================*/

#endif // BEHAVIOR_KEYS_H
