#pragma once

#include <cstddef>
#include <list>
#include <memory>
#include <tuple>

namespace mh
{
    // Base class for derived classes inherit properties. Memory allocation
    // strategy is implemented by derived classes
    class MemoryHandler {
    protected:
        bool isCopy_;
        std::size_t bufferSize_;
        std::size_t allocatedSize_;
        std::shared_ptr<std::byte*> buffer;
        std::list<std::tuple<std::size_t, std::size_t, std::byte*>> poolMemoryList;

    public:
        virtual ~MemoryHandler();
    };

} // namespace mh