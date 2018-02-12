#if !__has_extension(c_atomic) || !__has_include(<stdatomic.h>)
#error libdispatch requires C11 with <stdatomic.h>
#endif

#include <stdatomic.h>

static inline int32_t
os_atomic_increment32(volatile int32_t *var)
{
  return __c11_atomic_fetch_add((_Atomic(int)*)var, 1, __ATOMIC_RELAXED)+1;
}

static inline int32_t
os_atomic_increment32_barrier(volatile int32_t *var)
{
    return __c11_atomic_fetch_add((_Atomic(int)*)var, 1, __ATOMIC_SEQ_CST)+1;
}

static inline int32_t
os_atomic_add32(int32_t val, volatile int32_t *var)
{
    return __c11_atomic_fetch_add((_Atomic(int)*)var, val, __ATOMIC_RELAXED)+val;
}