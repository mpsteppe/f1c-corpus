// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466110
// Canonical corpus name: sub_466110
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_466110_00466110.c

void UnknownObject::GetByteField3C()
{
    // Trivial byte getter with no side effects: reads and returns the single byte at offset 0x3C (this[60]) of this. Consistent with the prelabel's 'getter' category; the byte's semantic meaning is unknown and the packet records no callers.
    // ASSIGNMENT: Read the byte field at offset 0x3C of this (this[60]). [field:this:0x0000003C, source:raw]
    // RETURN: Return the byte value read from field 0x3C. [source:raw]
    // UNKNOWN: Call-context: no callers are recorded in the packet, so the consumption site of the returned byte is unknown. [function:0x00466110]

    // Conservative worker pseudocode:
    //   char sub_466110(_BYTE *this) {
    //       return this[60];  // single byte field at offset 0x3C
    //   }
    // UNRESOLVED: The meaning of the byte at field 0x3C (state flag, type selector, or other) is unknown.
    // UNRESOLVED: No callers are recorded in the packet, so the usage context is unknown.
    // UNRESOLVED: Owner class is unknown; no ownership evidence is present in the packet.
}
