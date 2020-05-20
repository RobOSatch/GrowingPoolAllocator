#include "Freelist.h"


Freelist::Freelist(void* start, void* end, size_t chunkSize, size_t alignment, size_t offset)
{
	/*m_used = 0;
	m_peak = 0;


	const size_t nChunks = 0;
	
	m_head = start;
	Node* current_node = m_head;

	for (size_t i = 1; i < nChunks; ++i) 
	{
		current_node->next = current_node->address + chunkSize;
		current_node = current_node->next;
	}

	current_node->next = nullptr;*/

	const size_t nChunks = (static_cast<char*>(end) - start) / chunkSize;

	m_next = static_cast<Freelist*>(start);

	Freelist* current = m_next; // head

	
	for (size_t i = 1; i < nChunks; ++i)
	{
		Freelist* nextElement = current + chunkSize;
		current->m_next = nextElement;
		current = current->m_next;
	}

	current->m_next = nullptr;
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
