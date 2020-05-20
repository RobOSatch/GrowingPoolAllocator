#pragma once


class Freelist
{
public:
	Freelist(void* start, void* end, size_t chunkSize, size_t alignment, size_t offset);

	void* Obtain(void);
	void Return(void* ptr);

	struct Node
	{
		void* address;
		Node* next;
	};

	
private:
	Freelist* m_next;
	Node* m_head;
};

