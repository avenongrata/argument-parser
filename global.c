#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

#include "global.h"

/*---------------------------------------------------------------------------*/

static void _get_key(const char ** str)
{
    while (!isspace(**str) && **str)
        ++*str;
}

/*---------------------------------------------------------------------------*/

static int _str_len(const char * str)
{
    int len = 0;

    while (!isspace(str[len]) && str[len])
        len++;

    return len;
}

/*---------------------------------------------------------------------------*/

static int _get_keys_cnt(const char * str)
{
    const char * tmp_ch = str;
    int key_cnt = 0;

    while (*tmp_ch)
    {
        if (!isspace(*tmp_ch))
        {
            key_cnt++;
            _get_key(&tmp_ch);

            continue;
        }

        tmp_ch++;
    }

    return key_cnt;
}

/*---------------------------------------------------------------------------*/

int _parse_cmd(byte_t *** r_arr, const char * cmd)
{
    const char * cur_ch = cmd;
    unsigned int key_len = 0;
    int key_cnt = 0;
    int cur_key = 0;
    byte_t ** arr;

    /* get count of keys */
    key_cnt = _get_keys_cnt(cmd);
    if (!key_cnt)
        return -1;

    /* allocate array of keys */
    arr = (byte_t **) malloc((key_cnt + 1) * sizeof (byte_t *));
    arr[key_cnt] = NULL;    /* make it possible to parse in foreach-cycle */

    while (*cur_ch)
    {
        /* pass line sep */
        if (isspace(*cur_ch))
        {
            cur_ch++;
            continue;
        }

        key_len = _str_len(cur_ch);     /* get len of the key */
        arr[cur_key] = (byte_t *) malloc(key_len + 1);
        strncpy((char *)arr[cur_key], cur_ch, key_len);
        arr[cur_key][key_len] = '\0';

        cur_key++;
        cur_ch += key_len;
    }

    *r_arr = arr;

    return key_cnt;
}

/*---------------------------------------------------------------------------*/
