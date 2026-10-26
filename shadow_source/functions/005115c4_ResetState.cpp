// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005115C4
// Canonical corpus name: StateReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateReset_005115c4.c

void UnknownObject::ResetState()
{
    // State reset: unconditionally zeroes three DWORD fields of the this-object (command counter at 0x7C, slot lookup table pointer at 0xC4, current marker byte at 0x178), then via the sub-object pointer read from this+0x190 zeroes a byte at sub-object+0x50 (byte-stuffing mode flag), a byte at sub-object+0x51 (control flag), and a DWORD at sub-object+0x58 (byte counter, flattened to this+0x1E8). Returns the sub-object pointer. Existing analysis interprets the context as a JPEG decoder prepared for a fresh decode session. No conditional guards; every write is unconditional.
    // ASSIGNMENT: Reset command counter at this+0x7C to 0. [field:this:0x0000007C, source:raw]
    // ASSIGNMENT: Reset slot lookup table pointer at this+0xC4 to 0 (null). [field:this:0x000000C4, source:raw]
    // ASSIGNMENT: Reset current marker byte at this+0x178 to 0. [field:this:0x00000178, source:raw]
    // ASSIGNMENT: Reset byte-stuffing mode flag at sub-object (this+0x190)+0x50 to 0. [field:*(this+0x190):0x00000050, source:raw]
    // ASSIGNMENT: Reset control flag byte at sub-object (this+0x190)+0x51 to 0. [field:*(this+0x190):0x00000051, source:raw]
    // ASSIGNMENT: Reset byte counter at this+0x1E8 (sub-object +0x58) to 0. [field:this:0x000001E8, source:raw]
    // RETURN: Return the sub-object pointer read from this+0x190. [field:this:0x00000190, abi:lead, function:0x005115C4, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5115C4(_DWORD *a1) {
    //     a1[49] = 0;
    //     a1[31] = 0;
    //     a1[94] = 0;
    //     _BYTE *sub = (_BYTE *)a1[100];
    //     sub[80] = 0;
    //     sub[81] = 0;
    //     *(_DWORD *)(sub + 88) = 0;
    //     return (int)a1[100];
    //   }
    // UNRESOLVED: Object identity is unknown; the JPEG-decoder interpretation comes from existing analysis prose only and is not independently confirmed by the packet.
    // UNRESOLVED: The packet flattens the sub-object+0x58 write to this+0x1E8; whether the sub-object is genuinely offset 0x58 past this+0x190 or a separately allocated heap object is unresolved.
}
