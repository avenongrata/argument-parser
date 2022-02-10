#ifndef ARG_AP_H
#define ARG_AP_H

/*===========================================================================*/

#include "global.h"

/*---------------------------------------------------------------------------*/

typedef struct _arg_ap
{
    byte_t ** _input;    /* incoming arguments */
    byte_t ** _output;   /* array of found arguments */
    byte_t ** params;    /* found params after keys */

    /*-----------------------------------------------------------------------*/

    unsigned int _input_count;    /* count of inputed keys */
    unsigned int _found_count;    /* count of found keys */

    /*-----------------------------------------------------------------------*/
} arg_ap;

/*---------------------------------------------------------------------------*/

extern void _init_arg_ap(arg_ap * arg, const char * cmd);

/*===========================================================================*/

#endif // ARG_AP_H
