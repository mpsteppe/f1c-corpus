// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499EB0
// Canonical corpus name: AbsValueFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AbsValueFieldSetter_00499eb0.c

void UnknownObject::AbsValueFieldSetter()
{
    // Clamps two input values to non-negative and stores them at this+0x60 (dword index 24) and this+0x64 (dword index 25), each clamp applied independently (negative input becomes 0). Returns the original a3 value unchanged. Called by sub_493060 (0x00493060).
    // GUARD: a2 is tested for negativity; a negative a2 is replaced by 0 before storage [field:this:0x00000060, source:raw]
    // ASSIGNMENT: this+0x60 is set to max(a2, 0) [field:this:0x00000060, source:raw]
    // GUARD: a3 is tested for negativity; a negative a3 is replaced by 0 before storage [field:this:0x00000064, source:raw]
    // ASSIGNMENT: this+0x64 is set to max(a3, 0) [field:this:0x00000064, source:raw]
    // RETURN: Returns the original a3 value, not the clamped one [source:raw]
    // CALL: Invoked by sub_493060 (0x00493060) [caller:0x00493060, source:raw]

    // Conservative worker pseudocode:
    //   this[24] = a2 < 0 ? 0 : a2;
    //   this[25] = a3 < 0 ? 0 : a3;
    //   return a3;
    // UNRESOLVED: The semantic role of the two fields (offsets 0x60 and 0x64) and the caller's intent for returning the raw a3 value are not established from this packet
}
