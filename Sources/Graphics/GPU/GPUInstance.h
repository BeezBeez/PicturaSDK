#pragma once
#include "Core/CoreFramework.h"
#include "Core/Exceptions/Exceptions.h"

namespace Pictura::Graphics
{
    class GPUInstance
    {
    public:
        GPUInstance() {}
        virtual ~GPUInstance() {}

    public:
        virtual void InitInstance() = 0;
    };
} // namespace Pictura::Graphics