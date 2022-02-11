#include "behavior_keys.h"
#include "global.h"

/*---------------------------------------------------------------------------*/

void _init_beh_keys(behavior_keys * arg, const char * cmd)
{
    arg->_found_count = 0;
    arg->found        = NULL;

    if (cmd != NULL)
    {
        arg->_input_count = _parse_cmd(&arg->_input, cmd);
    }
    else
    {
        arg->_input_count = 0;
        arg->_input       = NULL;
    }
}

/*---------------------------------------------------------------------------*/

byte_t ** _bh_find(behavior_keys * ctx, char ** argv)
{
    const char * cur_key;



    return NULL;
}

/*---------------------------------------------------------------------------*/
