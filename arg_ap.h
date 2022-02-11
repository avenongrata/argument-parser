#ifndef ARG_AP_H
#define ARG_AP_H

/*===========================================================================*/

#include "global.h"

/*---------------------------------------------------------------------------*/

typedef struct _arg_ap
{
    byte_t ** _input;    /* incoming arguments */
    byte_t ** found;     /* array of found arguments */
    byte_t ** params;    /* found params after keys */

    /*-----------------------------------------------------------------------*/

    unsigned int _input_count;    /* count of inputed keys */
    unsigned int _found_count;    /* count of found keys */

    /*-----------------------------------------------------------------------*/

    /* find all keys in cmd */
    byte_t ** (*_find)(struct _arg_ap * ctx, char ** argv);

    /*-----------------------------------------------------------------------*/
} arg_ap;

/*---------------------------------------------------------------------------*/

extern void _init_arg_ap(arg_ap * arg, const char * cmd);
extern byte_t ** _ap_find(arg_ap * ctx, char ** argv);

/*===========================================================================*/

#endif // ARG_AP_H
