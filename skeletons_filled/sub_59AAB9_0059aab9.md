## sub_59AAB9_0059aab9 — Encoding singleton lazy initializer

**Summary:** Lazily initializes encoding singleton at dword_8D4650. On first call, allocates 40-byte object, constructs it via ObjectConstructorWithVTableAndStringInit, sets code page ID at offset 0x10 to 63, copies a string from dword_5B9D44 into buffer at offset 0x18, links it to global manager pointers, and increments reference count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LocaleRefcountAcquireUnderLock (00598c1c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ab83 | loc_59AB83 | R | Boolean conversion landing pad |
| 0059d4ea | loc_59D4EA | R | SEH continuation address |
| 0059d4fc | loc_59D4FC | R | SEH continuation address |
| 005b9d44 | dword_5B9D44 | R | Unknown_Struct_CRT [DERIVED] |
| 008d4648 | dword_8D4648 | RW | ModuleInstancePtr [DERIVED] |
| 008d464c | dword_8D464C | RW | GlobalObjManagerPtr [DERIVED] |
| 008d4650 | dword_8D4650 | RW | EncodingSingletonPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587b3e | BooleanToIntConversion | Convert bool to int for landing pad |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 40-byte heap object |
| 0058a5d8 | SEHHandlerInit | Initialize SEH handler frame on stack |
| 0058e1b0 | Strlen | Compute length of source string |
| 00598c4a | CounterIncrementThreadSafe | Thread-safe reference count increment |
| 00598c88 | RefcountDecrementWithLock | Lock-protected refcount decrement |
| 00599615 | BufferWriteWithNullTerminate | Copy string with null terminator |
| 0059a54d | sub_59A54D | CRT init prologue |
| 0059a5e9 | sub_59A5E9 | CRT cleanup epilogue |
| 0059abcd | ObjectConstructorWithVTableAndStringInit | Construct locale facet with vtable and string init |

**Guard conditions:** `if (!dword_8D4650)` — PASSES (singleton uninitialized) → allocates and constructs. BLOCKED (already initialized) → skips construction, returns existing pointer.
