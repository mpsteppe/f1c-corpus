## CustomMemoryPoolAllocatorInit_004906e0 — CustomPoolAllocInit

**Summary:** Initializes a custom memory pool allocator system: allocates pool struct, creates 32-entry memory pool with thunk-initialized entries, builds free list, and stores pool descriptor and allocator handle in globals. Registers teardown callback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Accessor (00490920), GlobalDataRead (00490930)

**Struct fields accessed:**

(None — operates on heap-allocated memory, not a pre-existing struct)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00490850 | ResourceLinkedListTeardown | R | Teardown callback address registered via BooleanToIntConversion |
| 007cd9c8 | byte_7CD9C8 | RW | CodecModuleInitFlag — init guard flag |
| 007cd9cc | dword_7CD9CC | RW | PoolDescriptorPtr — pointer to allocated pool struct |
| 007cd9d0 | dword_7CD9D0 | W | AllocatorHandle — handle/object for allocator |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004912f0 | ThunkToFUN00491330 | Initializes one pool entry (thunk/constructor) |
| 00491710 | ObjectConstructor_1710 | Creates allocator handle object |
| 00587b3e | BooleanToIntConversion | Registers teardown/resource cleanup callback |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocation (32, 4, 516, 12 bytes) |

**Guard conditions:** Checks `byte_7CD9C8 & 1` — BLOCKED (skips entire init) if already initialized (bit 0 set). PASSES (performs full initialization) when bit 0 is clear, sets bit 0 to mark initialized.
