#pragma once

#include "MemoryHandler.hpp"
#include "iostream"

namespace mh {

    // Provides an interface to place in the memory pool. Follows the 
    // "First Fit" memory allocation strategy of finding the first available
    // chunk of memory that it can fit in.
    class Allocation : public MemoryHandler {
        public:
            Allocation();
            Allocation(Allocation& orig);

            // Returns pointer to area of pool the variable will start at
            template <typename T>
            T* reserve(size_t elements);
        
            // Returns start of buffer
            std::shared_ptr<std::byte*>& getBuffer();
            
            // Returns application level memoryList
            std::list<std::tuple<std::size_t, std::size_t, std::byte*>> getOrigMemoryList();

            // Prints Local Memory List for debugging purposes
            void printLocMemoryList();

            ~Allocation();
    };
}  // namespace mh