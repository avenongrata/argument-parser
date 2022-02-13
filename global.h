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

#define _foreach(var, set) \
    for (typeof (set) t_set = set; (var = *t_set++); )

/*---------------------------------------------------------------------------*/

/* get all keys from cmd */
extern int _parse_cmd(char *** arr, const char * cmd);

/*===========================================================================*/

#endif // GLOBAL_H
