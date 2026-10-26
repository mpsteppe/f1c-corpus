// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567F10
// Canonical corpus name: F_9PointerArrayCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_9PointerArrayCleanup_00567f10.c

void UnknownObject::NinePointerArrayCleanup()
{
    // Iterates over nine dword slots of the receiver (this) and, for each non-null slot, calls sub_567CC0 with the stored pointer and then nulls the slot. Returns the result of the last processed slot.
    // LOOP: Iterate index i from 0 to 8 over the nine dword slots of the receiver array this. [source:raw]
    // GUARD: Skip processing and only clear the slot when the stored pointer this[i] is null. [source:raw]
    // CALL: Call sub_567CC0 with the pointer stored at this[i]; the returned value becomes result. [callee:0x00567CC0, source:raw]
    // ASSIGNMENT: Null out the slot: set this[i] = 0 after each slot has been processed. [source:raw]
    // RETURN: Return the result produced by the last processed slot. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_567F10(_DWORD *this) {
    //     int result;
    //     for (int i = 0; i < 9; ++i) {
    //       result = this[i];
    //       if (result) result = sub_567CC0((_DWORD *)this[i]);
    //       this[i] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of sub_567CC0 are not present in the packet; it may release or reinitialize the object stored in each slot.
}
