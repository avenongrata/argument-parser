#include "global.h"
#include "arg_ap.h"

/*---------------------------------------------------------------------------*/

void _init_arg_ap(arg_ap * arg, const char * cmd)
{
    arg->_found_count = 0;
    arg->_input_count = 0;
    arg->_output      = NULL;
    arg->_input       = NULL;
    arg->params       = NULL;
}

/*---------------------------------------------------------------------------*/
