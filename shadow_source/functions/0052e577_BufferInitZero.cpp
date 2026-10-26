// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052E577
// Canonical corpus name: BufferInitZero
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferInitZero_0052e577.c

void UnknownObject::BufferInitZero()
{
    // Initializes the global buffer dword_8B0118 to zero: writes 0 to elements [0] and [1], clears the low byte of element [2], then calls BoundsCheckedByteSetter(dword_8B0118, 0, 1) to store value 1 at index 0. Returns the buffer pointer.
    // ASSIGNMENT: Write 0 to dword_8B0118[0]. [global:0x008B0118, source:raw]
    // ASSIGNMENT: Write 0 to dword_8B0118[1]. [global:0x008B0118, source:raw]
    // ASSIGNMENT: Clear the low byte of dword_8B0118[2]. [global:0x008B0118, source:raw]
    // CALL: Call BoundsCheckedByteSetter(dword_8B0118, 0, 1): a bounds-checked byte write of value 1 at index 0 into the buffer. [global:0x008B0118, source:raw]
    // RETURN: Return the buffer pointer dword_8B0118. [global:0x008B0118, source:raw]

    // Conservative worker pseudocode:
    //   DWORD *sub_52E577() {
    //     dword_8B0118[0] = 0;
    //     dword_8B0118[1] = 0;
    //     LOBYTE(dword_8B0118[2]) = 0;
    //     BoundsCheckedByteSetter(dword_8B0118, 0, 1);
    //     return dword_8B0118;
    //   }
    // UNRESOLVED: BoundsCheckedByteSetter is named in the raw source but has no callee entry in the packet; its identity and bounds-check semantics are unverified.
    // UNRESOLVED: Packet marks dword_8B0118 as read-only (rw R) although the raw source writes it; the buffer's role (flags, header, small record) is unknown.
}
