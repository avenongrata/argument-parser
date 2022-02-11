#include "global.h"
#include "arg_ap.h"

/*---------------------------------------------------------------------------*/

void _init_arg_ap(arg_ap * arg, const char * cmd)
{
    arg->_found_count = 0;
    arg->found        = NULL;
    arg->params       = NULL;

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

byte_t ** _ap_find(arg_ap * ctx, char ** argv)
{

    return NULL;
}

/*---------------------------------------------------------------------------*/
