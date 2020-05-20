#include "Allocator.h"

#include <assert.h>
#include <stdlib.h>

Allocator::Allocator(const size_t totalSize, const size_t chunkSize)
{
	assert(chunkSize >= 8 && "Chunk size must be greater or equal to 8?????");
	assert(totalSize % chunkSize == 0 && "Total size must be divisible by chunk size");

	this->m_totalSize = totalSize;
	this->m_chunkSize = chunkSize;

	m_start_ptr = malloc(m_totalSize);
	InitFreelist();
	//Allocator(m_start_ptr, totalSize, chunkSize);
}

//Allocator::Allocator(const void* start, const size_t totalSize, const size_t chunkSize)
//{
//	assert(chunkSize >= 8 && "Chunk size must be greater or equal to 8?????");
//	assert(totalSize % chunkSize == 0 && "Total size must be divisible by chunk size");
//
//	this->m_totalSize = totalSize;
//	this->m_chunkSize = chunkSize;
//
//	m_start_ptr = malloc(m_totalSize);
//	InitFreelist();
//}

Allocator::~Allocator()
{
	free(m_start_ptr);
}

void* Allocator::Allocate()
{
	return m_freeList->Obtain();
}

void Allocator::Free(void* ptr)
{
	m_freeList->Return(ptr);
}

void Allocator::InitFreelist()
{
	m_freeList = new Freelist(m_start_ptr, reinterpret_cast<char*>(m_start_ptr) + m_totalSize, m_chunkSize, 0, 0);
}
