// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B21C0
// Canonical corpus name: SingleCallWrapper_21c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleCallWrapper_21c0_004b21c0.c

void UnknownObject::InitPointerBlock()
{
    // Straight-line initializer that clears dword_83EE60 to zero and points three adjacent globals (dword_8AAE64, dword_8AAE68, dword_8AAE6C) at unk_83EE64, the slot immediately after dword_83EE60. Returns the address of dword_83EE60.
    // ASSIGNMENT: dword_8AAE64 = (int)&unk_83EE64; pointer into the storage right after dword_83EE60 [source:raw, function:0x004B21C0]
    // ASSIGNMENT: dword_8AAE68 = (int)&unk_83EE64; same target as the previous pointer slot [source:raw, function:0x004B21C0]
    // ASSIGNMENT: dword_8AAE6C = (int)&unk_83EE64; same target as the previous pointer slot [source:raw, function:0x004B21C0]
    // ASSIGNMENT: dword_83EE60 = 0; zeroes the head dword of the block [source:raw, global:0x0083EE60]
    // RETURN: return &dword_83EE60; hands the caller the base address of the initialized block [source:raw, global:0x0083EE60]

    // Conservative worker pseudocode:
    //   dword_8AAE64 = (int)&unk_83EE64;
    //   dword_8AAE68 = (int)&unk_83EE64;
    //   dword_8AAE6C = (int)&unk_83EE64;
    //   dword_83EE60 = 0;
    //   return &dword_83EE60;
    // UNRESOLVED: unk_83EE64 and dword_8AAE64/8AAE68/8AAE6C are referenced by the raw source but absent from the packet evidence; their purpose (likely a small linked-list or cursor block whose head is dword_83EE60) is unknown.
    // UNRESOLVED: Callers are unknown; no caller evidence was supplied, so the init-time vs runtime nature of this reset is unverified.
}
