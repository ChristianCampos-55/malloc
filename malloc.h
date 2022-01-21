#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

#define C getpagesize()
#define H sizeof(size_t)

void *naive_malloc(size_t size);

#endif
