#include <stdarg.h>

#include "arg_parser.h"

/*---------------------------------------------------------------------------*/

void INIT_ARGS(struct cmd_args * arg,
               const char * bk,
               const char * ak)
{
    arg->state = NOT_FOUND;
    _init_beh_keys(&arg->beh_keys, bk);
    _init_arg_ap(&arg->arg_keys, ak);
}

/*---------------------------------------------------------------------------*/

void DEINIT_ARGS(struct cmd_args * arg)
{
    arg->beh_keys._deinit(&arg->beh_keys);
    arg->arg_keys._deinit(&arg->arg_keys);
}

/*---------------------------------------------------------------------------*/

extern void find_args(struct cmd_args * args, int argc, char ** argv)
{
    args->state = NOT_FOUND;

    /* when behavior keys were found */
    if (args->beh_keys._find(&args->beh_keys, argc, argv))
    {
        args->state |= BEH_KEYS;
    }

    /*-----------------------------------------------------------------------*/

    /* when arguments keys were found */
    if (args->arg_keys._find(&args->arg_keys, argc, argv))
    {
        args->state |= ARG_AP;
    }
}

/*---------------------------------------------------------------------------*/
