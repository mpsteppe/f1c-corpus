// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566DF0
// Canonical corpus name: NetworkOperationDispatchByFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkOperationDispatchByFlag_00566df0.c

void UnknownObject::NetworkOperationDispatchByFlag()
{
    // Conditional dispatch helper: reads a flag at this+0x10 and the object pointer at this+0x0, then forwards the second argument a2 (with a constant third argument of 1) to either AudioStreamBufferRead or sub_587F64 depending on the flag. Returns the chosen callee's result.
    // ASSIGNMENT: Load the flag field this+0x10 into a local; it selects the call path. [field:this:0x00000010]
    // ASSIGNMENT: Load the object pointer at this+0x0; it is passed as the first argument to both callees. [field:this:0x00000000]
    // GUARD: If the flag at this+0x10 is non-zero, take the AudioStreamBufferRead path; otherwise take the sub_587F64 path. [field:this:0x00000010]
    // CALL: Call AudioStreamBufferRead(obj, a2, 1) when the flag is set. [callee:0x00535390, field:this:0x00000000]
    // CALL: Call sub_587F64(obj, a2, 1) when the flag is clear. [callee:0x00587F64, field:this:0x00000000]
    // RETURN: Return the return value of whichever callee was dispatched to. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_566DF0(int* this, int a2) {
    //     int v2 = this[4];   /* flag at +0x10 * /
    //     int v3 = this[0];   /* object at +0x0 * /
    //     if (v2)
    //       return AudioStreamBufferRead(v3, a2, 1);
    //     else
    //       return sub_587F64(v3, a2, 1);
    //   }
    // UNRESOLVED: What the flag at this+0x10 selects between AudioStreamBufferRead and sub_587F64 is unknown.
    // UNRESOLVED: Meaning and purpose of the second argument a2 (and the constant third argument 1) depend on the two callees.
    // UNRESOLVED: Object identity and the semantics of sub_587F64 are unknown.
    // UNRESOLVED: Caller FileFormatHeaderReader (0x004B43E0) supplies a2; the field layout of this is unresolved.
}
