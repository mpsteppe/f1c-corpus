// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497250
// Canonical corpus name: ShortComputation_7250
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_7250_00497250.c

void UnknownObject::ByteFieldSetter()
{
    // Trivial __thiscall byte-field setter: copies parameter a2 into the byte field at offset 0x25 of this and returns the stored value. No guards, globals, or callees. Called by seven callers including CarCrashDamageProcessing (00496030) and LinkedListSearchWithAction (004974A0), so it serves as a shared state/flag write path.
    // ASSIGNMENT: Copy the incoming byte parameter a2 into the local result value. [source:raw]
    // ASSIGNMENT: Store a2 into the byte field at offset 0x25 of this. [source:raw, field:this:0x00000025]
    // RETURN: Return the stored byte value (result == a2). [source:raw]

    // Conservative worker pseudocode:
    //   char __thiscall sub_497250(_BYTE *this, char a2) {
    //     char result = a2;
    //     this[0x25] = a2;
    //     return result;
    //   }
    // UNRESOLVED: Semantic role of the byte field at offset 0x25 (state flag vs. mode selector) is not determinable from this function alone; it is written unconditionally and read elsewhere.
    // UNRESOLVED: Which of the seven callers' object types own this setter is unknown; equal 0x25 offset does not imply identical class across callers.
}
