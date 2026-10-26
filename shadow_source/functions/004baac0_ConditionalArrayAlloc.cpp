// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BAAC0
// Canonical corpus name: ConditionalArrayAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalArrayAlloc_004baac0.c

void UnknownObject::ConditionalArrayAlloc()
{
    // Allocates an array whose element count depends on the char flag a2: 64 elements when a2 is non-zero, otherwise 32. Requests 12 * count bytes from OperatorNewNhMallocWrapper (00587C03). On success runs a loop that calls WrapperPassThrough (004B4450) on each 12-byte element before storing the array pointer into this+0x0; on failure stores a null pointer into this+0x0. Returns this in both paths. Called by CarPhysicsStateInitializer (004B57F0) and sub_4B7860.
    // CALCULATION: v3 = a2 != 0 ? 64 : 32 chooses the element count from the char flag [source:raw]
    // CALL: OperatorNewNhMallocWrapper(12 * v3) requests an array of 12-byte elements; 12 is the element stride [callee:0x00587C03, source:raw]
    // GUARD: If v4 (allocation result) is null, skip the initialization loop and store a null pointer into this+0x0 [source:raw]
    // LOOP: Iterates v3 times starting at v5 = v4: calls WrapperPassThrough(v5), advances v5 by 12 bytes and decrements v3 until v3 reaches zero [callee:0x004B4450, source:raw]
    // ASSIGNMENT: *this = v4 stores the allocated array pointer on success, or *this = 0 on allocation failure [field:this:0x00000000, source:raw]
    // RETURN: Returns this on both the success and failure paths [source:raw]
    // CALL: Called by CarPhysicsStateInitializer (004B57F0) and sub_4B7860, both plausibly construction paths for the owning object [caller:0x004B57F0, caller:0x004B7860]

    // Conservative worker pseudocode:
    //   int count = a2 != 0 ? 64 : 32;
    //   char* block = OperatorNewNhMallocWrapper(12 * count);
    //   if (block) {
    //     char* p = block;
    //     do { WrapperPassThrough(p); p += 12; --count; } while (count);
    //     *this = block;
    //   } else {
    //     *this = 0;
    //   }
    //   return this;
    // UNRESOLVED: The meaning of the 12-byte element stride and the 64/32 element counts is not documented; 32 may be a base grid size and 64 an expanded variant
    // UNRESOLVED: WrapperPassThrough (004B4450) semantics are unknown; the loop likely performs default construction or zero-initialization of each element
    // UNRESOLVED: The owner type is unknown; the prelabel only claims a structural twin of ObjectAllocator (0045bb90) at DERIVED trust
    // UNRESOLVED: The a2 flag's source enum or meaning is not recoverable from this function alone
}
