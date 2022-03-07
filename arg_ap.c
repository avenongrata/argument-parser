#include <string.h>
#include <malloc.h>

#include "global.h"
#include "arg_ap.h"

/*---------------------------------------------------------------------------*/

void _init_arg_ap(arg_ap * arg, const char * cmd)
{
    arg->found_count  = 0;
    arg->found        = NULL;
    arg->param        = NULL;
    arg->_deinit      = _deinit_arg_ap;
    arg->_find        = _ap_find;

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

void _deinit_arg_ap(arg_ap * arg)
{
    unsigned int i;

    if (arg->_input_count)
    {
        /* delete keys */
        for (i = 0; i < arg->_input_count; i++)
            free(arg->_input[i]);
    }

    /* delete array for keys */
    if (arg->_input)
    {
        free(arg->_input);
        arg->_input = NULL;
    }

    /* delete array of found keys */
    if (arg->found)
    {
        free(arg->found);
        arg->found = NULL;
    }

    /* delete array of found params */
    if (arg->param)
    {
        free(arg->param);
        arg->param = NULL;
    }

    /* set value to zero to prevent multiple deinitialization */
    arg->_input_count = 0;
}

/*---------------------------------------------------------------------------*/

unsigned int _ap_find(arg_ap * ctx, int argc, char ** argv)
{
    int i;
    char * key = NULL;

    /* when keys are not specified or set incorrect number of params */
    if (!ctx->_input || argc < 3)
        return 0;

    ctx->found_count = 0;
    /* it's not the right way, but i can't suggest smth better yet */
    ctx->found = (char **) malloc((argc/2) * sizeof (char *));
    ctx->param = (char **) malloc((argc/2) * sizeof (char *));
    for (i = 1; i < argc; i++)
    {
        _foreach(key, ctx->_input)
        {
            if (!strcmp(argv[i], key))
            {
                if (i + 1 != argc)   /* argument has param */
                {
                    ctx->found[ctx->found_count] = argv[i];
                    ctx->param[ctx->found_count] = argv[i + 1];    /* next */
                    ctx->found_count++;

                    ++i;    /* pass param for arg because have already added */
                    break;
                }
                else    /* error, param for argument isn't specified */
                {
                    return 0;
                }
            }
        }
    }

    return ctx->found_count;
}

/*---------------------------------------------------------------------------*/
