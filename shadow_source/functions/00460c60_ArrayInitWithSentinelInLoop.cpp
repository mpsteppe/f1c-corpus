// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00460C60
// Canonical corpus name: ArrayInitWithSentinelInLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayInitWithSentinelInLoop_00460c60.c

void UnknownObject::ArrayInitWithSentinelInLoop()
{
    // Bulk reinitializer: runs 104 iterations, each writing the -1 sentinel into one element of a DWORD array starting at this+3974 dwords (byte offset 0x3E18), reinitializing a 140-byte struct array element at this+229 via StructFieldZeroInitWithDefaults, and a 218-dword struct element at this+4192 dwords via ThunkWithStructInitSubCalls. Pointers advance by their per-iteration strides. Returns the result of the last ThunkWithStructInitSubCalls call. Called by SynchronizeWithServer.
    // ASSIGNMENT: Initialize pointers: v3 = this + 3974 dwords (sentinel array, byte offset 0x3E18), v2 = this + 229 bytes (struct array), v1 = this + 4192 dwords (struct array), and counter v4 = 104. [source:raw, field:this:0x00003E18]
    // LOOP: do-while loop that runs exactly 104 iterations, counted down by v4. [source:raw]
    // ASSIGNMENT: Write the sentinel value -1 into the current element *v3 of the array at this+3974 dwords (byte offset 0x3E18). [source:raw, field:this:0x00003E18]
    // CALL: Call StructFieldZeroInitWithDefaults(v2) to zero-init one 140-byte struct array element. [source:raw, callee:0x00461480]
    // CALL: Call ThunkWithStructInitSubCalls(v1) to init one 218-dword struct element; store its return value as result. [source:raw, callee:0x004FFFA0]
    // CALCULATION: Advance all three pointers by their per-iteration strides (++v3, v2 += 140, v1 += 218) and decrement the counter. [source:raw]
    // RETURN: Return result, the return value of the last ThunkWithStructInitSubCalls call. [source:raw]

    // Conservative worker pseudocode:
    //   int ArrayInitWithSentinelInLoop(_DWORD* this) {
    //     _DWORD* v1 = this + 4192;   // 218-dword struct, advanced per iteration
    //     _BYTE*  v2 = this + 229;    // 140-byte struct, advanced per iteration
    //     _DWORD* v3 = this + 3974;   // sentinel array, byte offset 0x3E18
    //     int v4 = 104;
    //     int result;
    //     do {
    //       *v3 = -1;
    //       StructFieldZeroInitWithDefaults(v2);
    //       result = ThunkWithStructInitSubCalls(v1);
    //       ++v3; v2 += 140; v1 += 218; --v4;
    //     } while (v4);
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the 104-element -1 sentinel array at byte offset 0x3E18 is unknown; -1 plausibly marks inactive/unused slots but is not proven.
    // UNRESOLVED: The parallel 140-byte and 218-dword struct arrays and their relationship to the sentinel array are unknown.
    // UNRESOLVED: Why the last ThunkWithStructInitSubCalls return value is surfaced is unknown; caller SynchronizeWithServer likely does not depend on it.
    // UNRESOLVED: Owner object type is unidentified; packet owner evidence is empty.
}
