/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:06:47 by lzima             #+#    #+#             */
/*   Updated: 2022/01/10 22:49:53 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Calloc : Contiguous Allocation
	The calloc() function contiguously allocates eof space for count
     objects that are size bytes of memory each and returns a pointer to the
     allocated memory.  The allocated memory is filled with bytes of value
     zero.

Malloc C dynamique memory allocation
	In C, the library function malloc is used to allocate a block of memory 
	 on the heap. The program accesses this block of memory via a pointer that 
	 malloc returns. When the memory is no longer needed, the pointer is 
	 passed to free which deallocates the memory so that it can be used for 
	 other purposes.
	
	How does malloc work internally?
	When one calls malloc , memory is taken from the large heap cell, which is 
	 returned by malloc . The rest is formed into a new heap cell that consists 
	 of all the rest of the memory. When one frees memory, the heap cell is 
	 added to the end of the heap's free list.
	
	When you call malloc(), you specify the amount of memory to allocate. 
	 The amount of memory actually used is slightly more than this, and includes 
	 extra information that records (at least) how big the block is. 
	 You can't (reliably) access that other information - and nor should you :-).
	 When you call free(), it simply looks at the extra information to find out 
	 how big the block is.

void	*ft_calloc(size_t count, size_t size)
{
	char	*memoryallocation;
	// memoryallocation => allocation is the act of associating a memory 
	// space with certain data or with a program for its execution.
	memoryallocation = malloc(count * size);
	// malloc can be used here, as the subject utils say.
	// why malloc multiplies count by size ?
	// 'count' is an object, and 'size' of those objects.
	// Allocating, for example : 3 char *str of size 10 like 
	// char s1[10]
	// char s2[10]
	// char s3[10]
	// It will create 3 pointers for 3 strings with 10 spaces.
	if (memoryallocation == NULL)
	// 
		return (memoryallocation);
	ft_memset(memoryallocation, 0, count * size);
	// ft_memset or ft_bzero could be use here
	// here ft_memset will use memoryallocation, and filling up with 0's.
	return (memoryallocation);
}
*/

#include "../../utils/inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memoryallocation;

	memoryallocation = malloc(count * size);
	if (memoryallocation == NULL)
		return (memoryallocation);
	ft_memset(memoryallocation, 0, count * size);
	return (memoryallocation);
}
