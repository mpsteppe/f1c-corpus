## MemoryObjectAllocator_00562b50 — CreateNetworkSessionObject

**Summary:** Allocates and initializes a 1464-byte network session/connection structure with string configuration strings, an array of elements, callback function pointers, and the default application directory path. Calls NetworkStartup to initialize networking.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkReplayBufferInit (0045d260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005640f0 | sub_5640F0 | R | callback for creating inner sub-struct at offset +4 |
| 005645a0 | sub_5645A0 | R | element factory for the array allocator at offset +148 |
| 00564600 | IndirectDwordCompare | R | comparison callback for array sorting/lookup |
| 00564630 | sub_564630 | R | additional callback for array management |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00564660 | NetworkStartup | initialize Winsock/networking subsystem |
| 005646d0 | AllocateIntArrayViaFactory | create typed dynamic array with factory/comparison callbacks |
| 00564810 | Malloc0x18ByteStructWithInnerBuffer | allocate 0x18-byte sub-structure containing an inner buffer |
| 0058a935 | MallocWrapperForNhMalloc | heap memory allocation wrapper |

**Guard conditions:** none — unconditional allocation and initialization.

