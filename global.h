#ifndef GLOBAL_H
#define GLOBAL_H

/*===========================================================================*/

#ifndef NULL
# define NULL (void *) 0
#endif

/*---------------------------------------------------------------------------*/

#ifndef offsetof
# define offsetof(type, member) \
     (size_t) &((type *)0)->member
#endif

/*---------------------------------------------------------------------------*/

#ifndef container_of
# define container_of(ptr, type, member) \
     (type *) ((void *)ptr - offsetof(type, member))
#endif

/*---------------------------------------------------------------------------*/

#define foreach(item, list) \
    int

/*---------------------------------------------------------------------------*/

typedef unsigned char byte_t;

/*---------------------------------------------------------------------------*/

/* get from cmd all keys */
extern int _parse_cmd(byte_t ** arr, const char * cmd);

/*===========================================================================*/

#endif // GLOBAL_H
