#include "behavior_keys.h"

/*---------------------------------------------------------------------------*/

void _init_beh_keys(behavior_keys * arg, const char * cmd)
{
    arg->_found_count = 0;
    arg->_input_count = 0;
    arg->_output      = NULL;
    arg->_input       = NULL;
}

/*---------------------------------------------------------------------------*/
