#ifndef TLP_HDR_H
#define TLP_HDR_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h> /*Prototypes of commonly used library functions,plus EXIT_SUCCESS and EXIT_FAILURE constants*/

#include <unistd.h> /*许多系统调用的原型*/
#include <errno.h>
#include <string.h>

#include <get_num.h>
#include <error_functions.h>

typedef enum { FALSE, TRUE } Boolean;

#define min(m,n) ((m) < (n) ? (m) : (n))
#define max(m,n) ((m) > (n) ? (m) : (n))

#endif