## MemoryAllocation_9a50_004c9a50 — ParticleEmitterFactoryByType

**Summary:** Factory that allocates and initializes particle emitter objects of different types (1,2,5,6,7), each with distinct allocation size, lifetime parameter, and vtable pointer. Called from network message dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkMessageReceiveAndDispatch (004c7ca0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004c9af4 | jpt_4C9A5C | R | Jump table for switch on emitter type ID |
| 005ace18 | flt_5ACE18 | R | ObjectFactoryParamType5 [DERIVED] (also: ` — global param for type 5) |
| 005ace6c | off_5ACE6C | R | Vtable pointer for emitter type 7 |
| 005ace7c | off_5ACE7C | R | VTable pointer for emitter type 5 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c8f10 | ParticleEmitterInit | Initializes newly allocated particle emitter with lifetime parameter |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation for emitter objects (sizes 28-44 bytes) |

**Guard conditions:** Switch on type ID (function's `this` parameter used as unsigned int). Types 1,2,5,6,7 allocate and initialize; types 3,4, and unknown return null. Each allocation checks for null and returns null on alloc failure.
