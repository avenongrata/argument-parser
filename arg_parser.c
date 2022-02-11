#include <stdarg.h>

#include "arg_parser.h"

/*---------------------------------------------------------------------------*/

void INIT_ARGS(struct cmd_args * arg,
               const char * bk,
               const char * ak)
{
    _init_beh_keys(&arg->beh_keys, bk);
    _init_arg_ap(&arg->arg_keys, ak);
    //arg->find = _find_args;
}

/*---------------------------------------------------------------------------*/

//byte_t ** _find_args(char ** argv, ...)
//{

//}

/*---------------------------------------------------------------------------*/
