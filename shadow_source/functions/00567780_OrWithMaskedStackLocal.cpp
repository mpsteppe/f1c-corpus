// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567780
// Canonical corpus name: EmptyStub_7780
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EmptyStub_7780_00567780.c

void UnknownObject::OrWithMaskedStackLocal()
{
    // Combines the __int16 argument a1 with the 16-bit stack local v2: returns a1 | (v2 & 0xFCFF). The mask 0xFCFF clears bits 8 and 9 of v2 before the OR, so those two result bits come only from a1. v2 is read before any write, so its origin is not evidenced; the function is called from tire-model and rigid-body physics initialization and integration paths.
    // CALCULATION: Bitwise AND of the 16-bit stack local v2 with 0xFCFF, clearing bits 8 and 9. [source:raw, function:0x00567780]
    // CALCULATION: Bitwise OR of argument a1 with the masked v2 value. [source:raw, function:0x00567780]
    // RETURN: Return the combined 16-bit value. [source:raw, function:0x00567780]
    // CALL: On the frame path; invoked by tire model, rigid-body and physics integration routines. [caller:0x0043E050, caller:0x0043E4B0, caller:0x0043E6A0, caller:0x00441650, caller:0x004D7660]

    // Conservative worker pseudocode:
    //   __int16 sub_567780(__int16 a1) { return a1 | (v2 & 0xFCFF); }
    // UNRESOLVED: v2 is read uninitialized in the decompiled source; it is likely leftover stack state (possibly a control word whose bits 8 and 9 the mask strips), but no packet evidence grounds that.
    // UNRESOLVED: The purpose of forcing bits 8 and 9 from a1 while ORing the remaining bits is not established.
    // UNRESOLVED: The canonical label 'EmptyStub_7780' describes this as a stub, but the raw source performs a real bitwise operation.
}
