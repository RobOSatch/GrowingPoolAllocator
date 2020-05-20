// GrowingPoolAllocator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

#include "Allocator.h"

struct Bullet
{
    float x, y, z;
};

int main()
{
    std::vector<Bullet*> bullets;
    Allocator* allocator = new Allocator(1024, 32);

    Bullet* first = static_cast<Bullet*>(allocator->Allocate());
    Bullet* second = static_cast<Bullet*>(allocator->Allocate());

    std::cout << first << " AND " << second << std::endl;

    //std::cout << "Hello World!\n";

    //// Example calls
    //Freelist freelist(memory, memory + 1024, 32, 8, 0);
    //void* object0 = freelist.Obtain();
    //void* object1 = freelist.Obtain();
    //freelist.Return(object1);
    //freelist.Return(object0);

    //size_t bufferSize = 5 * 1024 * 1024;
    //unsigned char* buffer = new unsigned char[bufferSize];

    //char memory[1024] = {};
    //Allocator allocator(totalSize, chunkSize);

    //int* num0 = allocator.Allocate();
    //int* num1 = allocator.Allocate();

    //std::vector<int*> nums = { num0, num1 };

    //allocator.Free(testPtr1);
    //allocator.Free(testPtr0);


    //// *************
    //// LOW-LEVEL API
    //// ************* 

    //Allocator allocator(start, totalSize, chunkSize);

    

}