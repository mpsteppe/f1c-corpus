// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005528B0
// Canonical corpus name: ConditionalFreeByFlag_28b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFreeByFlag_28b0_005528b0.c

void UnknownObject::conditionalFreeByFlag()
{
    // thiscall guard-conditional surface cleanup: if the flag word at this+0x24 (this[9]) has bit 0x20000 set, reset the object pointer at this+0xC (this[3]) through ObjectResetWithVirtualRelease passing the global dword_8B78A0 as the manager/context argument, free the heap block via FreeWrapper_7bcf if non-null, then zero the pointer field. Returns 0 regardless.
    // GUARD: Test the flag word at this+0x24 (this[9]) for bit 0x20000; if clear, skip the entire body and fall through to the return. [source:raw, field:this:0x00000024]
    // CALL: Reset/release the surface object pointer at this+0xC (this[3]) through ObjectResetWithVirtualRelease, passing the global dword_8B78A0 as the first argument. [source:raw, callee:0x00540EB0, global:0x008B78A0]
    // GUARD: Check that the pointer at this+0xC (this[3]) is non-null before freeing it. [source:raw, field:this:0x0000000C]
    // CALL: Free the heap block at this+0xC (this[3]) via FreeWrapper_7bcf. [source:raw, callee:0x00587BCF]
    // ASSIGNMENT: Invalidate the pointer field: this+0xC (this[3]) = 0. [source:raw, field:this:0x0000000C]
    // RETURN: Return 0 unconditionally; the function reports no error or status value. [function:0x005528B0, source:raw]

    // Conservative worker pseudocode:
    //   int conditionalFreeByFlag(int* this) {
    //     if (this[9] & 0x20000) {
    //       ObjectResetWithVirtualRelease(dword_8B78A0, this[3]);
    //       if (this[3]) FreeWrapper_7bcf(this[3]);
    //       this[3] = 0;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The meaning of flag bit 0x20000 at this+0x24 (existing analysis interprets it as a surface/texture mode gate) is DERIVED, not confirmed by this packet.
    // UNRESOLVED: The exact object type held at this+0xC, and whether it is a render-target surface, is not established by the packet; owner is UnknownObject.
    // UNRESOLVED: The argument roles of ObjectResetWithVirtualRelease (which parameter is the owning object) are not proven by the packet.
    // UNRESOLVED: The role of the global dword_8B78A0 (existing analysis labels it a manager/sound-manager pointer) is DERIVED.
}
