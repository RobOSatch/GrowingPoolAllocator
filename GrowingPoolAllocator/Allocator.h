#pragma once
#include "Freelist.h"

#include <vector>

class Allocator
{
public:
	Allocator(const size_t totalSize, const size_t chunkSize);
	~Allocator();

	void* Allocate();
	void Free(void*);

private:
	void InitFreelist();

	size_t m_chunkSize, m_totalSize;
	Freelist* m_freeList;
	void* m_start_ptr;
};

