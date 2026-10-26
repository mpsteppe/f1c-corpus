// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052E550
// Canonical corpus name: BoundsCheckedByteSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundsCheckedByteSetter_0052e550.c

void UnknownObject::BoundsCheckedByteSetter()
{
    // Bounds-checked byte store helper: given a byte-array receiver, an unsigned index and a byte value, writes the value only when the index is within the fixed bound (index <= 8), and always returns the original index. Called by BufferInitZero (0052E577) to fill individual bytes of a small fixed-size buffer without allowing an out-of-range write.
    // ASSIGNMENT: Seed result with a2 before any check so the return value is the original index regardless of the guard outcome. [source:raw]
    // GUARD: Guard on a2 <= 8; the byte write is skipped when the index exceeds the fixed 9-element bound. [source:raw]
    // ASSIGNMENT: Write the byte a3 into the receiver array at index a2 (this[a2] = a3) only when the guard passes. [source:raw]
    // RETURN: Return the original index a2. [source:raw]
    // CALL: Invoked from BufferInitZero (0052E577) as the per-byte fill step of a small buffer init sequence. [caller:0x0052E577, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_52E550(unsigned char *buf, unsigned int index, char value) {
    //     if (index <= 8)
    //       buf[index] = value;
    //     return index;
    //   }
    // UNRESOLVED: The fixed bound index <= 8 implies a 9-byte (or 9-element) receiver buffer, but the buffer size and element type are defined by the caller BufferInitZero, not this function.
    // UNRESOLVED: The receiver is used as a raw byte array via __thiscall; no enclosing object layout or member semantics is available from this packet.
}
