#include <stdio.h>
#include <string.h>

#include "global.h"
#include "arg_parser.h"

/*---------------------------------------------------------------------------*/

int main(int argc, char ** argv)
{
    /* create object */
    struct cmd_args args;
    unsigned int i;

    /* set default values */
    INIT_ARGS(&args, "-a -b", "-c -d");

    /* find arguments */
    find_args(&args, argc, argv);
    if (args.state & BEH_KEYS)
    {
        for (i = 0; i < args.beh_keys.found_count; i++)
        {
            printf("%s\n", args.beh_keys.found[i]);
        }
    }

    if (args.state & ARG_AP)
    {
        for (i = 0; i < args.arg_keys.found_count; i++)
        {
            printf("%s : %s\n", args.arg_keys.found[i],
                                args.arg_keys.param[i]);
        }
    }

    /* delete memory for allocated memory */
    DEINIT_ARGS(&args);

    return 0;
}
