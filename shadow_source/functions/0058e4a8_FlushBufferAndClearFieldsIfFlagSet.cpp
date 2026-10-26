// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058E4A8
// Canonical corpus name: ClearStructFieldsIfFlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClearStructFieldsIfFlagSet_0058e4a8.c

void UnknownObject::FlushBufferAndClearFieldsIfFlagSet()
{
    // If guard a1 is nonzero and the byte flag at a2+13 has bit 0x10 set, flush the buffer object a2 via BufferFlushWrite and reset several of its fields: clear the 0x10 bit from the byte at a2+13, and zero the dwords at a2+24, a2+0 and a2+8. Returns the result of BufferFlushWrite on that path.
    // GUARD: if (a1 != 0) gate the whole flush/reset sequence [source:raw]
    // GUARD: test (byte at a2+13) & 0x10; if clear, do nothing [source:raw]
    // CALL: call BufferFlushWrite(a2) to flush the buffer object [callee:0x0058A05A, source:raw]
    // ASSIGNMENT: clear flag bit 0x10: byte at a2+13 &= 0xEE [source:raw]
    // ASSIGNMENT: dword at a2+24 = 0 [source:raw]
    // ASSIGNMENT: dword at a2+0 = 0 [source:raw]
    // ASSIGNMENT: dword at a2+8 = 0 [source:raw]
    // RETURN: return result of BufferFlushWrite on the flush path [source:raw]

    // Conservative worker pseudocode:
    //   if (a1 != 0 && ((byte)a2[13] & 0x10) != 0) {
    //     int r = BufferFlushWrite((dword*)a2);
    //     (byte)a2[13] &= 0xEE;
    //     *(dword*)(a2 + 24) = 0;
    //     *(dword*)(a2 + 0) = 0;
    //     *(dword*)(a2 + 8) = 0;
    //     return r;
    //   }
    // UNRESOLVED: Return value is uninitialized when either guard fails; the caller-visible contract on those paths is unknown.
    // UNRESOLVED: Field layout of the a2 object (offset 13 flag byte, offsets 0/8/24 dwords) and what the 0x10 flag means is unproven.
    // UNRESOLVED: Relationship of the four known callers to the a2 buffer object type is not established.
}
