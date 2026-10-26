// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB420
// Canonical corpus name: sub_4DB420
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DB420_004db420.c

void UnknownObject::InstantReplayObjectFactory()
{
    // Factory that allocates and initializes a 24-byte replay object selecting one of three vtables from the type ID carried in the `this` argument: type 0 (this == 0) installs vtable off_5AD088 and copies the 'Instant Replay' label via StringCopyWithBufferRealloc, type 1 (this == 1) installs off_5AD0A4, type 2 (this == 2) installs off_5AD0C0. All three variants zero the fields at +4, +8 (byte), +12, +16 and set +20 to -1. Returns 0 on allocation failure or for any other type ID.
    // GUARD: Dispatch on the type ID carried in `this`: null (0) selects type 0, 1 selects type 1, 2 selects type 2; any other value falls through and returns 0. [function:0x004DB420, source:raw]
    // CALL: Allocate a 24-byte object via OperatorNewNhMallocWrapper(24) for the type-0 (this == 0) branch. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the type-0 object: zero the dwords at +4, +12, +16 and the byte at +8, set +20 to -1, and install the vtable pointer off_5AD088 at +0. [global:0x005AD088, source:raw]
    // CALL: Copy the 'Instant Replay' label into the type-0 object via StringCopyWithBufferRealloc(aInstantReplay_0). [callee:0x00566650, global:0x005D4B88, source:raw]
    // RETURN: Return the initialized type-0 object, or 0 when the allocation failed. [source:raw]
    // CALL: Allocate a 24-byte object via OperatorNewNhMallocWrapper(24) for the type-1 (this == 1) branch, then zero +4, +8 (byte), +12, +16, set +20 to -1, and install the vtable off_5AD0A4. [callee:0x00587C03, global:0x005AD0A4, source:raw]
    // CALL: Allocate a 24-byte object via OperatorNewNhMallocWrapper(24) for the type-2 (this == 2) branch, then zero +4, +8 (byte), +12, +16, set +20 to -1, and install the vtable off_5AD0C0. [callee:0x00587C03, global:0x005AD0C0, source:raw]
    // RETURN: Return 0 for invalid type IDs and for allocations that returned null. [source:raw]

    // Conservative worker pseudocode:
    //   if (this == 0) {
    //       p = OperatorNewNhMallocWrapper(24);
    //       if (p) {
    //           *(int*)(p+4) = 0; *(char*)(p+8) = 0; *(int*)(p+12) = 0; *(int*)(p+16) = 0;
    //           *(int*)(p+20) = -1;
    //           *(int*)p = &off_5AD088;
    //           StringCopyWithBufferRealloc(&aInstantReplay_0);
    //           return p;
    //       }
    //   } else if (this == 1) {
    //       p = OperatorNewNhMallocWrapper(24);
    //       if (p) {
    //           *(int*)(p+4) = 0; *(char*)(p+8) = 0; *(int*)(p+12) = 0; *(int*)(p+16) = 0;
    //           *(int*)(p+20) = -1;
    //           *(int*)p = &off_5AD0A4;
    //           return p;
    //       }
    //   } else if (this == 2) {
    //       p = OperatorNewNhMallocWrapper(24);
    //       if (p) {
    //           *(int*)(p+4) = 0; *(char*)(p+8) = 0; *(int*)(p+12) = 0; *(int*)(p+16) = 0;
    //           *(int*)(p+20) = -1;
    //           *(int*)p = &off_5AD0C0;
    //           return p;
    //       }
    //   }
    //   return 0;
    // UNRESOLVED: The type ID is carried in the `this` pointer of a char* signature; whether this is a factory keyed on a type parameter rather than a genuine method call on an object is not established.
    // UNRESOLVED: The three vtable targets off_5AD088 / off_5AD0A4 / off_5AD0C0 and the 'Instant Replay' label tie the objects to the replay subsystem, but the concrete owning class is unnamed in the corpus.
    // UNRESOLVED: Only caller is sub_4D88D0; no frame path confirmed.
}
