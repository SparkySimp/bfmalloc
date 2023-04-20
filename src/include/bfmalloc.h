/*
 * bfmalloc.h - brute force malloc
 * Copyright (C) 2023 K. C. Öztürk - D. Hatipoğlu
 */

#ifndef BF_MALLOC_H
#define BF_MALLOC_H

#include <stddef.h>

void *bfmalloc(size_t size);

void *bfmalloc_async(size_t size);

#endif