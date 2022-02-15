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
    char ** _input;    /* incoming arguments */
    char ** found;     /* array of found arguments */

    /*-----------------------------------------------------------------------*/

    unsigned int _input_count;    /* count of inputed keys */
    unsigned int found_count;     /* count of found keys */

    /*-----------------------------------------------------------------------*/

    void (*_deinit)(struct _behavior_keys * arg);

    /*-----------------------------------------------------------------------*/

    /* find all keys in cmd and fill array */
    unsigned int (*_find)(struct _behavior_keys * ctx, int argc, char ** argv);

    /*-----------------------------------------------------------------------*/
} behavior_keys;

/*---------------------------------------------------------------------------*/

extern void _init_beh_keys(behavior_keys * arg, const char * cmd);
extern void _deinit_beh_keys(behavior_keys * arg);
extern unsigned int _bh_find(behavior_keys * ctx, int argc, char ** argv);

/*===========================================================================*/

#endif // BEHAVIOR_KEYS_H
