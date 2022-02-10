#ifndef ARG_PARSER_H
#define ARG_PARSER_H

/*===========================================================================*/

#include "global.h"
#include "behavior_keys.h"
#include "arg_ap.h"

/*---------------------------------------------------------------------------*/

struct cmd_args
{
    behavior_keys beh_keys;
    arg_ap arg_keys;

    /*-----------------------------------------------------------------------*/

//    byte_t ** (*find)(char ** argv, ...);
};

/*---------------------------------------------------------------------------*/

extern void INIT_ARGS(struct cmd_args * arg,
                      const char * bk,
                      const char * ak);

//extern byte_t ** _find_args(char ** argv, ...);

/*===========================================================================*/

#endif // ARG_PARSER_H
