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
    byte_t *  input;     /* incoming arguments */
    byte_t ** _output;    /* array of found arguments */

    /*-----------------------------------------------------------------------*/

    unsigned int _input_count;    /* count of inputed keys */
    unsigned int _found_count;    /* count of found keys */

    /*-----------------------------------------------------------------------*/

    /* find all keys specified in the template in argv */
    int (*find)(char * _template, char ** _argv);

}
behavior_keys_var;

/*---------------------------------------------------------------------------*/

extern behavior_keys_var behavior_keys;

/*===========================================================================*/

#endif // BEHAVIOR_KEYS_H
