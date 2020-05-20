#include "Freelist.h"


Freelist::Freelist(void* start, void* end, size_t chunkSize)
{
    union
    {
        void* as_void;
        char* as_char;
        Freelist* as_self;
    };

    const size_t nChunks = (static_cast<char*>(end) - start) / chunkSize;

    // first chunk points to the start of the pool
    as_void = start;
    m_next = as_self;
    as_char += chunkSize;

    // initialize the free list - make every m_next of each chunk point to the next chunk in the list
    Freelist* runner = m_next;
    for (size_t i = 1; i < nChunks; ++i)
    {
        runner->m_next = as_self;
        runner = as_self;
        as_char += chunkSize;
    }

    runner->m_next = nullptr;
}

void* Freelist::Obtain(void)
{
	if (m_next == nullptr)
	{
		return nullptr;
	}

	Freelist* head = m_next;
	m_next = head->m_next;
	return head;
}

void Freelist::Return(void* ptr)
{
	Freelist* head = static_cast<Freelist*>(ptr);
	head->m_next = m_next;
	m_next = head;
}
