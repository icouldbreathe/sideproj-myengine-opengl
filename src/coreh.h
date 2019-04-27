#ifndef COREH_H
#define COREH_H

#include <stdio.h>

#ifdef __APPLE__
#define E_DEBUG_BREAK __asm volatile ("int3");
#elif defined _WIN32
    #error "Windows not supported yet!"
#endif

#define E_DEBUG

#ifdef E_DEBUG
    #define E_ENABLE_ASSERTS
#endif

#ifdef E_ENABLE_ASSERTS
    #define E_CORE_ASSERT(x, ...) { if(!(x)) { E_DEBUG_BREAK; } }
#else
    #define E_CORE_ASSERT(x, ...)
#endif



#define GLCall(x)   GLClearError();\
                    x;\
                    E_CORE_ASSERT(GLLogCall(#x, __FILE__, __LINE__))


#include <stdint.h>

#endif // COREH_H
