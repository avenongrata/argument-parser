#ifndef ARG_AP_H
#define ARG_AP_H

/*===========================================================================*/

#include "global.h"

/*---------------------------------------------------------------------------*/

typedef struct _arg_ap
{
    char ** _input;    /* incoming arguments */
    char ** found;     /* array of found arguments */
    char ** param;     /* found params after keys */

    /*-----------------------------------------------------------------------*/

    unsigned int _input_count;    /* count of inputed keys */
    unsigned int found_count;     /* count of found keys */

    /*-----------------------------------------------------------------------*/

    void (*_deinit)(struct _arg_ap * arg);

    /*-----------------------------------------------------------------------*/

    /* find all keys in cmd */
    unsigned int (*_find)(struct _arg_ap * ctx, int argc, char ** argv);

    /*-----------------------------------------------------------------------*/
} arg_ap;

/*---------------------------------------------------------------------------*/

extern void _init_arg_ap(arg_ap * arg, const char * cmd);
extern void _deinit_arg_ap(arg_ap * arg);
extern unsigned int _ap_find(arg_ap * ctx, int argc, char ** argv);

/*===========================================================================*/

#endif // ARG_AP_H
