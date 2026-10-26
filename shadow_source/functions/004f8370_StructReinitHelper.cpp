// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8370
// Canonical corpus name: ArithmeticComparison_8370
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_8370_004f8370.c

void UnknownObject::StructReinitHelper()
{
    // Resets a struct: frees the double-buffered arrays via DoubleBufferFree, reinitializes sub-structs via sub_4F70C0, resets the counter arrays at this+0x654 and this+0x698 through ArrayNonZeroCounter, clears this+0x94 to 0, sets the active flag this+0x4 to 1, and returns 0. Called from VehgenScnFileLoader (0x004C6C40).
    // CALL: Call DoubleBufferFree(this) to destroy and free the double-buffered object arrays and clear the active flag this+0x4. [callee:0x004F83B0, source:raw]
    // CALL: Call sub_4F70C0(this) to reinitialize the per-slot sub-structs. [callee:0x004F70C0, source:raw]
    // CALL: Call ArrayNonZeroCounter(this + 0x654) to reset the counter array at offset 0x654 (raw source writes this + 1624 as a pointer argument). [callee:0x004F6D60, source:raw]
    // CALL: Call ArrayNonZeroCounter(this + 0x698) to reset the counter array at offset 0x698 (raw source writes this + 1688 as a pointer argument). [callee:0x004F6D60, source:raw]
    // ASSIGNMENT: Write 0 to the dword at this+0x94, clearing the reset counter field. [field:this:0x00000094, source:raw]
    // ASSIGNMENT: Write 1 to the byte at this+0x4, setting the active flag. [field:this:0x00000004, source:raw]
    // CALL: Invoked from VehgenScnFileLoader (0x004C6C40) during scene/vehicle generation file loading. [caller:0x004C6C40]
    // RETURN: Return 0. [function:0x004F8370, source:raw]

    // Conservative worker pseudocode:
    //   int StructReinitHelper(int this) {
    //     DoubleBufferFree(this);
    //     sub_4F70C0((void*)this);
    //     ArrayNonZeroCounter((void*)(this + 0x654));
    //     ArrayNonZeroCounter((void*)(this + 0x698));
    //     *(int*)(this + 0x94) = 0;
    //     *(char*)(this + 0x4) = 1;
    //     return 0;
    //   }
    // UNRESOLVED: Offsets 0x654 and 0x698 (raw this + 1620 and this + 1688) are passed as pointer arguments to ArrayNonZeroCounter and are not in the packet's deterministic field list, so their array content semantics are unconfirmed.
    // UNRESOLVED: The exact container type is unknown; the fill's tire-slot interpretation is DERIVED.
    // UNRESOLVED: sub_4F70C0's role in reinitializing the slot sub-structs is DERIVED from its position in the reset sequence.
}
