#include <string.h>
#include <malloc.h>

#include "behavior_keys.h"
#include "global.h"

/*---------------------------------------------------------------------------*/

void _init_beh_keys(behavior_keys * arg, const char * cmd)
{
    arg->found_count  = 0;
    arg->found        = NULL;
    arg->_deinit      = _deinit_beh_keys;
    arg->_find        = _bh_find;

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

void _deinit_beh_keys(behavior_keys * arg)
{
    unsigned int i;

    if (!arg->_input_count)
        return ;

    /* delete keys */
    for (i = 0; i < arg->_input_count; i++)
    {
        free(arg->_input[i]);
    }

    /* delete array for keys */
    free(arg->_input);

    /* delete array of found keys */
    free(arg->found);

    /* set value to zero to prevent multiple deinitialization */
    arg->_input_count = 0;
}

/*---------------------------------------------------------------------------*/

unsigned int _bh_find(behavior_keys * ctx, int argc, char ** argv)
{
    int i;
    char * key = NULL;

    /* there are no params in cmd */
//    if (argc < 2)
//        return 0;

    ctx->found_count = 0;
    /* it's not the right way, but i can't suggest smth better yet */
    ctx->found = (char **) malloc((argc - 1) * sizeof (char *));
    for (i = 1; i < argc; i++)
    {
        _foreach(key, ctx->_input)
        {
            if (!strcmp(argv[i], key))
            {
                ctx->found[ctx->found_count] = argv[i];
                ctx->found_count++;
            }
        }
    }

    return ctx->found_count;
}

/*---------------------------------------------------------------------------*/
