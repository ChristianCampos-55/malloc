#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

#define C getP_S()
#define H sizeof(size_t)
#define CENT sizeof(void *)
#define P_S sysconf(_SC_P_S)
#define SS sizeof(void *)
#define JIM 0xfffffffffffffffe
#define centup(num, align) (((num) + ((align) - 1)) & ~((align) - 1))
#define SG(p) (((block_info *)(p))->size)
#define SGG(p) ((((block_info *)(p))->size) & JIM)
#define GP(p) ((((block_info *)(p))->prev) & JIM)
#define MON sizeof(block_info)

/**
 * struct heap_info_s - HEAP INFORMATION
 * @heap_start: BEGINING OF HEAP
 * @heap_end: END OF HEAP (PRETTY SELF EXPLANATORY)
 */
typedef struct heap_info_s
{
	void *heap_start;
	void *heap_end;
} heap_info;

/**
 * struct block_info_s - BLOCK OF INFORMATION
 * @prev: PREVIOUS BLOCK
 * @size: BLOCK SIZE
 */
typedef struct block_info_s
{
	size_t prev;
	size_t size;
} block_info;

void *naive_malloc(size_t size);
void *_malloc(size_t size);
void *s_b(size_t size);
void h_adder(void *addr, size_t size, size_t prev);
void *transc(size_t size);
void printer(void);

#endif
