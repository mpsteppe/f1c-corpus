// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477080
// Canonical corpus name: SubCallFieldZero
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SubCallFieldZero_00477080.c

void UnknownObject::SubCallFieldZero()
{
    // Calls UIDimensionCapture on this object to capture/save UI element dimensions, then clears a byte flag at this+0x17C to 0. Always returns 0.
    // CALL: Call UIDimensionCapture((int*)this) to capture/save UI element dimensions from this object. [callee:0x0048EBD0]
    // ASSIGNMENT: Write 0 to the byte flag at this+0x17C, clearing it after the dimension capture. [field:this:0x0000017C, source:raw]
    // RETURN: Return 0. [source:raw, function:0x00477080]

    // Conservative worker pseudocode:
    //   int SubCallFieldZero(void *this) {
    //     UIDimensionCapture((int *)this);
    //     *(unsigned char *)((char *)this + 0x17C) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Object type and the meaning of the flag at this+0x17C are unknown.
    // UNRESOLVED: Exact semantics of UIDimensionCapture (0x0048EBD0) are outside this packet.
}
