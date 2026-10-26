// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9B70
// Canonical corpus name: ThunkToFUN004ce820
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN004ce820_004c9b70.c

void UnknownObject::InitGlobalDefaults()
{
    // Initializes a global defaults block whose base is dword_8ACEA0 (0x008ACEA0): writes 0 to the thirteen leading 32-bit fields (dword_8ACEA0 through unk_8ACECC), then writes 1.0 to flt_8ACED0, 0.80000001 to flt_8ACED4, and -1 to dword_8ACED8. Returns the address of the block base dword_8ACEA0. No callers are recorded in the packet.
    // ASSIGNMENT: Store 0 into the block base dword_8ACEA0 and into the twelve following 32-bit fields (dword_8ACEA8, dword_8ACEAC, unk_8ACEB0, unk_8ACEB4, dword_8ACEB8, dword_8ACEBC, unk_8ACEC0, unk_8ACEC4, unk_8ACEC8, unk_8ACECC, plus flt_8ACEA4 used as an int), zeroing the leading thirteen fields. [global:0x008ACEA0, source:raw]
    // ASSIGNMENT: Store 1.0 into flt_8ACED0, the fourteenth field of the block. [source:raw]
    // ASSIGNMENT: Store 0.80000001 into flt_8ACED4, the fifteenth field of the block. [source:raw]
    // ASSIGNMENT: Store -1 into dword_8ACED8, the trailing sentinel field of the block. [source:raw]
    // RETURN: Return the address of the block base dword_8ACEA0 (0x008ACEA0). [global:0x008ACEA0, function:0x004C9B70, source:raw]

    // Conservative worker pseudocode:
    //   dword_8ACEA0 = 0; flt_8ACEA4 = 0; dword_8ACEA8 = 0; dword_8ACEAC = 0;
    //   unk_8ACEB0 = 0; unk_8ACEB4 = 0; dword_8ACEB8 = 0; dword_8ACEBC = 0;
    //   unk_8ACEC0 = 0; unk_8ACEC4 = 0; unk_8ACEC8 = 0; unk_8ACECC = 0;
    //   flt_8ACED0 = 1.0;
    //   flt_8ACED4 = 0.80000001;
    //   dword_8ACED8 = -1;
    //   return &dword_8ACEA0;
    // UNRESOLVED: The semantic identity of the defaults block and its consumer are unknown; no callers are recorded.
    // UNRESOLVED: The packet supplies an address only for the block base dword_8ACEA0; byte offsets of the sibling fields are not evidenced and are intentionally not asserted.
    // UNRESOLVED: The canonical name ThunkToFUN004ce820 suggests a link to another routine, but no callee evidence is present in the packet to confirm it.
    // UNRESOLVED: The decompiler shows the base field stored into the returned local; the caller's use of that pointer is outside this packet.
}
