#include "malloc.h"

/**
 * naive_malloc - naive malloc that is presented in the concept page
 * @size: size needed to be allocated for the user
 * Return: pointer to the allocated memory
 */

void *naive_malloc(size_t size)
{
	void *m = NULL;
	void *l = NULL;
	void *p = NULL;
	size_t r = 0, i = 0, a = 0, clut = 0;
	static void *s;
	static size_t bits;

	if (size == 0)
		return (NULL);
	if (!s)
	{
		l = sbrk(C);
		if (l == ((void *) -1))
			return (NULL);
		s = l;
		memset(l, 0, C);
		*((size_t *) ((char *) s)) = C - H;
	}
	for (i = 0, p = s; i < bits; i++)
		p = ((char *) p) + *((size_t *) ((char *) p));

	r = *((size_t *) ((char *) p));
	a = H + size;
	clut = (H - (a % H)) % H;
	a += clut;
	while (((int) r) - ((int) a) < 0)
	{
		l = sbrk(C);
		if (l == ((void *) -1))
			return (NULL);
		memset(l, 0, C);
		r += C;
	}
	*((size_t *) ((char *) p)) = a;
	m = (void *) (((char *) p) + H);
	*((size_t *) (((char *) p) + a)) = r - a;
	bits++;
	return (m);
}
