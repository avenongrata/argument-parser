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

#ifndef concontainer_of
# define container_of(ptr, type, member) \
     (type *) ((void *)ptr - offsetof(type, member))
#endif

/*---------------------------------------------------------------------------*/

#define foreach(item, list) \
    byte ** tmp = list; \
    for (byte_t * item = &tmp[0]; item; item++)

/*---------------------------------------------------------------------------*/

/* defined types */
typedef unsigned char byte_t;

/*===========================================================================*/

#endif // GLOBAL_H
