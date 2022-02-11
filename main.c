#include <stdio.h>

#include "global.h"
#include "arg_parser.h"

/*---------------------------------------------------------------------------*/

int main(int argc, char ** argv)
{
    /* create object */
    struct cmd_args args;

    /* set default values */
    INIT_ARGS(&args, "-a -b -c -d", "-g -f -j");

    /* find arguments */
    //args.find(argv);



    return 0;
}
