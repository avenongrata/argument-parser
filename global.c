#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

#include "global.h"

/*---------------------------------------------------------------------------*/

static void _avoid_multiple_sep(const char ** str)
{
    while (isspace(**str))
    {
        ++*str;
    }
}

/*---------------------------------------------------------------------------*/

static int _get_keys_cnt(const char *str)
{
    const char * tmp_ch = str;
    int key_cnt = 0;
    bool digit = false;

    while (*tmp_ch)
    {
        if (isspace(*tmp_ch))
        {
            if (digit)
                key_cnt++;

            _avoid_multiple_sep(&tmp_ch);
            continue;
        }
        else if (!digit)
        {
            digit = true;
        }

        tmp_ch++;
    }

    /* to avoid missing first or last param */
    if (digit)
        key_cnt++;

    return key_cnt;
}

/*---------------------------------------------------------------------------*/

int _parse_cmd(byte_t ** arr, const char * cmd)
{
    const char * tmp_ch = cmd;
    unsigned int key_len = 0;
    int key_cnt = 0;

    key_cnt = _get_keys_cnt(cmd);   /* get count of keys */
    if (!key_cnt)
        return -1;

    arr = malloc(key_cnt);          /* allocate array of string */

    while (*tmp_ch)
    {
        if (!isspace(*tmp_ch))
        {
            key_len = strlen(tmp_ch);
            ++key_len;

            *arr = (byte_t *) malloc(key_len);
            strncpy((char *)*arr, tmp_ch, key_len - 1);
            *arr[key_len - 1] = '\0';
            arr++;
        }

        tmp_ch++;
    }

    return 0;
}

/*---------------------------------------------------------------------------*/
