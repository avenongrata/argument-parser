#include "behavior_keys.h"

/*---------------------------------------------------------------------------*/

static int arg_find(char * _tmp, char ** argv)
{
    return 0;
}

/*---------------------------------------------------------------------------*/

behavior_keys_var behavior_keys =
{
    .input   = NULL,
    ._output = NULL,
    ._input_count = 0,
    ._found_count = 0,
    .find = arg_find
};

/*---------------------------------------------------------------------------*/
