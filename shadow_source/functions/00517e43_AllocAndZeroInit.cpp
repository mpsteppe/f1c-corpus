// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517E43
// Canonical corpus name: AllocAndZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AllocAndZeroInit_00517e43.c

void UnknownObject::AllocAndZeroInit()
{
    // Size-parameterized zero-initializing allocator. Dispatches on a single request code a1: value 2 selects a 64-byte block, value 1 selects a 412-byte block, and any other value returns NULL without allocating. The selected size is handed to MallocWrapperForNhMalloc and the returned block is zeroed with memset when allocation succeeds. The function returns the allocated (and zeroed) block pointer.
    // GUARD: Dispatch on the request code a1: only values 1 and 2 are accepted; any other value falls through to an immediate NULL return. [function:0x00517E43, source:raw]
    // ASSIGNMENT: Select allocation size v1 = 64 when a1 == 2. [source:raw]
    // ASSIGNMENT: Select allocation size v1 = 412 when a1 == 1. [source:raw]
    // RETURN: Return 0 when a1 is neither 1 nor 2. [source:raw]
    // CALL: Allocate the selected size by calling MallocWrapperForNhMalloc(v1). [callee:0x0058A935, source:raw]
    // GUARD: Guard on a successful allocation (v2 non-null) before zeroing the block. [source:raw]
    // CALL: Zero-initialize the block with memset(v2, 0, v1) when the allocation succeeded. [source:raw]
    // RETURN: Return the allocated (and zeroed) block pointer, or NULL on a rejected request code or failed allocation. [source:raw]

    // Conservative worker pseudocode:
    //   void *AllocAndZeroInit(int request) {
    //     unsigned int size;
    //     void *p;
    //     if (request == 2) size = 64;
    //     else if (request == 1) size = 412;
    //     else return 0;
    //     p = MallocWrapperForNhMalloc(size);
    //     if (p) memset(p, 0, size);
    //     return p;
    //   }
    // UNRESOLVED: Meaning of request codes 1 and 2 and their sizes 412/64 is caller-specific; both callers (0x005118E6, 0x00513D3D) must be read to confirm which objects these blocks back.
    // UNRESOLVED: Owner object type is not evidenced in this packet.
}
