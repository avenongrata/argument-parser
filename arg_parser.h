#ifndef ARG_PARSER_H
#define ARG_PARSER_H

/*===========================================================================*/

#include "global.h"
#include "behavior_keys.h"
#include "arg_ap.h"

/*---------------------------------------------------------------------------*/

enum State
{
    NOT_FOUND = 1,
    BEH_KEYS  = 2,
    ARG_AP    = 4
};

/*---------------------------------------------------------------------------*/

struct cmd_args
{
    behavior_keys beh_keys;
    arg_ap arg_keys;

    enum State state;
};

/*---------------------------------------------------------------------------*/

extern void INIT_ARGS(struct cmd_args * arg,
                      const char * bk,
                      const char * ak);

/*---------------------------------------------------------------------------*/

extern void DEINIT_ARGS(struct cmd_args * arg);

/*---------------------------------------------------------------------------*/

extern void find_args(struct cmd_args * args, int argc, char ** argv);

/*===========================================================================*/

#endif // ARG_PARSER_H
