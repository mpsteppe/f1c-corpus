// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BAA50
// Canonical corpus name: FixedSizeContainerConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FixedSizeContainerConstructor_004baa50.c

void UnknownObject::FixedSizeContainerConstructor()
{
    // Constructor for a fixed-size element container. Computes an element count v3 = (a2 == 0) ? 2 : 0, allocates 1016 * v3 + 4 bytes via OperatorNewNhMallocWrapper, stores the count into the 4-byte header dword, then runs DualCallWrapper_4f50 over each 1016-byte element as an initializer. On success *this receives the element-array pointer (header + 1); on allocation failure *this is set to 0. The prelabel cluster marks it a structural twin of ObjectAllocator. Subsystem: ai. Not on the per-frame path.
    // ASSIGNMENT: Select the element count: v3 = 2 when a2 is zero, otherwise v3 = 0. [source:raw]
    // CALL: Allocate 1016 * v3 + 4 bytes through OperatorNewNhMallocWrapper (0x00587C03): 4 header bytes plus v3 elements of 1016 bytes each. [callee:0x00587C03, source:raw]
    // GUARD: If the allocation succeeded, store the element count v3 into the header dword *v4 and set the element-array pointer to v4 + 1. [source:raw]
    // LOOP: Run DualCallWrapper_4f50 (0x004B4F50) on each element pointer v6, advancing by the 1016-byte stride and counting down until all v3 elements are initialized. [callee:0x004B4F50, source:raw]
    // ASSIGNMENT: On the success path store the element-array pointer into the container field at this+0x00. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: On allocation failure set the container field at this+0x00 to the init literal 0. [field:this:0x00000000, source:raw]
    // RETURN: Return the container pointer this on both the success and the failure paths. [source:raw]
    // CALL: Called by VehicleInstanceListBuilder (0x004B5C50) to construct the fixed-size vehicle element container. [caller:0x004B5C50, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* FixedSizeContainerConstructor(DWORD* this, char a2) {
    //     int count = (a2 != 0) ? 0 : 2;
    //     int* block = (int*)OperatorNewNhMallocWrapper(1016 * count + 4);
    //     if (block) {
    //       *block = count;
    //       char* p = (char*)(block + 1);
    //       if (count - 1 >= 0) { do { DualCallWrapper_4f50(p); p += 1016; --count; } while (count); }
    //       *this = (DWORD*)(block + 1);
    //     } else {
    //       *this = 0;
    //     }
    //     return this;
    //   }
    // UNRESOLVED: Element type and meaning of the 1016-byte element stride are unknown; DualCallWrapper_4f50 is an element initializer whose exact contract is not established.
    // UNRESOLVED: Why the count is 2 when a2 == 0 and 0 otherwise is caller-dependent (a2 may select between a populated and an empty container).
    // UNRESOLVED: Owner class of the container is unknown (packet owner trust UNKNOWN).
}
