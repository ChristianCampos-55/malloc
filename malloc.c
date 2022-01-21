#include "malloc.h"

static heap_info heap;

/**
 * _malloc - function that allocates space in the heap
 * @size: size needed to be allocated for the user
 * Return: pointer to the allocated memory
 */

void *_malloc(size_t size)
{
	char *griffin;

	size = centup(size, CENT);
	if (size == 0)
		return (NULL);
	griffin = s_b(size);
	if (!griffin)
		griffin = transc(size);
	if (!griffin)
		return (NULL);
	return (griffin + MON);
}

/**
 * s_b - Finds a usable memory block
 * @size: Size specified
 * Return: Pointer to mem block
 */

void *s_b(size_t size)
{
	char *b_p = heap.heap_start, *holder;
	size_t piggy_r = size + MON;

	if (!b_p)
		return (NULL);

	while (SGG(b_p) >= MON + SS)
	{
		b_p += SGG(b_p);
		if ((SG(b_p) & 1) && SGG(b_p - GP(b_p)) >= piggy_r)
		{
			holder = b_p - GP(b_p);
			if (SGG(holder) >= piggy_r + MON + SS)
			{
				h_adder(holder + piggy_r, SGG(holder) - piggy_r - MON, 0);
				((block_info *)holder)->size = piggy_r;
				((block_info *)b_p)->prev = SGG(holder + piggy_r);
			}
			else
			{
				((block_info *)b_p)->size &= JIM;
				((block_info *)b_p)->prev = 0;
			}
			return (holder);
		}
	}
	return (NULL);
}

/**
 * h_adder - Adds info
 * @addr: Adress in memory
 * @size: Of mem block
 * @prev: Previous mem block
 */

void h_adder(void *addr, size_t size, size_t prev)
{
	block_info *b;

	b = addr;
	b->size = prev ? size + MON + 1 : size + MON;
	b->prev = prev;
}

/**
 * transc - transc heap by calling sbrk()
 * @size: size needed by user
 * Return: pointer to memory block header
 */

void *transc(size_t size)
{
	size_t piggy_s;
	char *holder;
	char peter;

	piggy_s = 2 * MON + SS + size;
	piggy_s += heap.heap_start ? 0 : MON;
	piggy_s = centup(piggy_s, P_S);
	peter = sbrk(piggy_s);
	if (peter == (void *)-1 && errno == ENOMEM)
		return (NULL);
	if (heap.heap_start == NULL)
	{
		heap.heap_start = peter;
		h_adder(peter, size, 0);
		h_adder(peter + SGG(peter), piggy_s - size - 3 * MON, 0);
		h_adder(peter + piggy_s - MON, 0, piggy_s - size - 2 * MON);
		return (peter);
	}
	else
	{
		peter -= MON;
		holder = peter;
		h_adder(peter, size, GP(peter));
		peter += SGG(peter);
		h_adder(peter, piggy_s - size - 2 * MON, 0);
		h_adder(peter + SGG(peter), 0, piggy_s - size - MON);
		return (holder);
	}
}

/**
 * printer - Prints what's in heap
 */

void printer(void)
{
	char *h_p = heap.heap_start;
	size_t countula = 0;

	if (!h_p)
		return;
	while (SGG(h_p) >= MON + SS)
	{
		h_p += SGG(h_p);
		++countula;
	}
	if (h_p + MON != sbrk(0))
		exit(1);
}
