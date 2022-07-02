#ifndef EternallyAscend_Cdks_ERROR_H
#define EternallyAscend_Cdks_ERROR_H
// Error Definitions for C Development Toolkits.

#ifndef False
#define False 0
#endif

#ifndef True
#define True 1
#endif

enum Error {
    ErrorHead = 8192,
    ErrorEmptyPointer,
    ErrorEmptyStruct,
};

#endif