// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA980
// Canonical corpus name: sub_4BA980
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BA980_004ba980.c

void UnknownObject::AllocateElementArrayWithHeader()
{
    // Allocates a count-prefixed array of fixed-size (884-byte) elements and stores the element-array pointer into this. The element count v3 is 2 when a2 is 0 and 0 otherwise. Allocates 884*v3 + 4 bytes via OperatorNewNhMallocWrapper (0x00587C03); on success the leading 4-byte header receives v3, each element is initialized via PassthroughWrapper_f670 (0x004FF670) and *this becomes the array pointer (header + 1). On allocation failure *this is set to 0. Returns this in both branches.
    // CALCULATION: Select the element count: v3 = (a2 != 0) ? 0 : 2, so a2 == 0 requests 2 elements and any non-zero a2 requests 0 elements. [source:raw]
    // CALL: Allocate the backing block: OperatorNewNhMallocWrapper(884 * v3 + 4), 4 bytes of count header plus 884 bytes per element. [callee:0x00587C03, source:raw]
    // GUARD: Branch on the allocation result: a non-null block takes the populate path; a null block takes the failure path. [source:raw]
    // ASSIGNMENT: Write the element count v3 into the leading 4-byte header of the block (*v4). [source:raw]
    // LOOP: do-while over v3 elements using a countdown counter seeded from v3; the pre-check v3 - 1 >= 0 skips the body entirely when v3 == 0. [source:raw]
    // CALL: Initialize each element in turn via the __thiscall constructor PassthroughWrapper_f670(element). [callee:0x004FF670, source:raw]
    // CALCULATION: Advance the element pointer by the per-element stride: v6 += 221 (221 dwords = 884 bytes per element). [source:raw]
    // ASSIGNMENT: Success path: *this = v5 = block + 1, pointing just past the count header at the first element. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Failure path: *this = 0 when the allocation returned null. [field:this:0x00000000, source:raw]
    // RETURN: Return this (the object pointer) in both the success and failure branches. [source:raw]

    // Conservative worker pseudocode:
    //   void* sub_4BA980(char a2) {
    //     int count = (a2 != 0) ? 0 : 2;
    //     int* block = OperatorNewNhMallocWrapper(884 * count + 4);
    //     if (block) {
    //       block[0] = count; /* 4-byte count header * /
    //       int* elem = block + 1;
    //       if (count - 1 >= 0) {
    //         do { PassthroughWrapper_f670(elem); elem += 221; --count; } while (count);
    //       }
    //       *this = block + 1;
    //       return this;
    //     }
    //     *this = 0;
    //     return this;
    //   }
    // UNRESOLVED: Element type and the meaning of the 884-byte (221 dword) size, and the behavior of the initializer PassthroughWrapper_f670, are not evidenced here.
    // UNRESOLVED: Semantics of the a2 selector (2 elements vs 0 elements) and how the caller NetworkMessageDispatch (0x004B54E0) consumes the allocated array are unknown.
    // UNRESOLVED: Only *this (offset 0) is written; the rest of the object this points to is unknown. The prelabel flags a structural twin relationship to ObjectAllocator (0045bb90) at DERIVED trust, which is not adopted beyond that label.
}
