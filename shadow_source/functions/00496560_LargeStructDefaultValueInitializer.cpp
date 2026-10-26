// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00496560
// Canonical corpus name: sub_496560
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_496560_00496560.c

void UnknownObject::LargeStructDefaultValueInitializer()
{
    // One-time default initializer for a large float-backed structure (vehicle or pit-crew state). Clears a broad spread of float fields to 0.0, sets a small set of scalar constants (0.5, 0.25, 2.5, a -1.0 sentinel), zeroes byte flags at several byte offsets, writes a fixed pointer-like bit pattern (unk_888888) into two dword slots, clears a 64-entry array of 20-byte byte records, and finally seeds the structure with random values via FloatArrayInitWithRandom. Linear, branch-free; invoked by LargeStructZeroInit (00495190).
    // ASSIGNMENT: Set float slot this+0x1918 (this[1606]) to 0.0. [field:this:0x00001918, source:raw]
    // ASSIGNMENT: Zero the contiguous float block this+0x14 .. this+0x20 (this[5]..this[8]). [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Clear byte flag at this+0x25 to 0. [field:this:0x00000025, source:raw]
    // ASSIGNMENT: Zero the float block this+0x2C .. this+0x34 (this[11]..this[13]). [field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Set this+0x44 (this[17]) to the -1.0 sentinel value. [field:this:0x00000044, source:raw]
    // ASSIGNMENT: Zero float at this+0x38 (this[14]). [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Zero the float block this+0xC0 .. this+0xCC (this[48]..this[51]). [field:this:0x000000C0, field:this:0x000000C4, field:this:0x000000C8, field:this:0x000000CC, source:raw]
    // ASSIGNMENT: Set constants: this+0xD0 (this[52]) to 0.5 and this+0xD4 (this[53]) to 0.25. [field:this:0x000000D0, field:this:0x000000D4, source:raw]
    // ASSIGNMENT: Set dword flag/count at this+0x28 (dword index 10) to 1. [field:this:0x00000028, source:raw]
    // ASSIGNMENT: Set byte flag at this+0x18F5 to 1. [field:this:0x000018F5, source:raw]
    // ASSIGNMENT: Set float this+0xD8 (this[54]) to 2.5 and zero this+0xDC (this[55]). [field:this:0x000000D8, field:this:0x000000DC, source:raw]
    // ASSIGNMENT: Clear byte flag at this+0xE0 to 0. [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Zero the float block this+0xE4 .. this+0xEC (this[57]..this[59]). [field:this:0x000000E4, field:this:0x000000E8, field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Clear byte flags at this+0x1518, this+0x166C and this+0x1538 to 0. [field:this:0x00001518, field:this:0x0000166C, field:this:0x00001538, source:raw]
    // ASSIGNMENT: Zero floats at this+0x108 (this[66]) and this+0x110 (this[68]). [field:this:0x00000108, field:this:0x00000110, source:raw]
    // ASSIGNMENT: Zero float at this+0x1514 (this[1349]). [field:this:0x00001514, source:raw]
    // ASSIGNMENT: Clear byte flag at this+0x18F4 to 0. [field:this:0x000018F4, source:raw]
    // ASSIGNMENT: Zero the float block this+0x98 .. this+0xA4 (this[38]..this[41]). [field:this:0x00000098, field:this:0x0000009C, field:this:0x000000A0, field:this:0x000000A4, source:raw]
    // LOOP: Counted loop: zero the first byte of 64 records at base this+0x114 (this + 69), advancing 20 bytes per iteration. [field:this:0x00000114, source:raw]
    // ASSIGNMENT: Zero floats at this+0x104 (this[65]) and this+0x10C (this[67]). [field:this:0x00000104, field:this:0x0000010C, source:raw]
    // ASSIGNMENT: Zero the float block this+0x1560 .. this+0x1570 (this[1368]..this[1372]). [field:this:0x00001560, field:this:0x00001564, field:this:0x00001568, field:this:0x0000156C, field:this:0x00001570, source:raw]
    // ASSIGNMENT: Zero floats at this+0x1578 (this[1374]) and this+0x157C (this[1375]). [field:this:0x00001578, field:this:0x0000157C, source:raw]
    // ASSIGNMENT: Zero float at this+0x18A8 (this[1578]). [field:this:0x000018A8, source:raw]
    // ASSIGNMENT: Clear byte flag at this+0x18EC to 0. [field:this:0x000018EC, source:raw]
    // ASSIGNMENT: Zero the float block this+0x48 .. this+0x54 (this[18]..this[21]). [field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, source:raw]
    // ASSIGNMENT: Zero floats at this+0xAC (this[43]) and this+0xB0 (this[44]). [field:this:0x000000AC, field:this:0x000000B0, source:raw]
    // ASSIGNMENT: Set byte flag at this+0x1574 to 1. [field:this:0x00001574, source:raw]
    // ASSIGNMENT: Set byte flags at this+0x1588 and this+0x1589 to 1. [field:this:0x00001588, field:this:0x00001589, source:raw]
    // ASSIGNMENT: Write the global unk_888888 address into dword slots this+0xB4 and this+0xB8, and store the equivalent float bit patterns 2.0375234e-38 and 1.5673257e-38 into the same two float slots (this[45], this[46]). [field:this:0x000000B4, field:this:0x000000B8, global:0x00888888, source:raw]
    // CALL: Seed the structure with random values via FloatArrayInitWithRandom(this). [source:raw]
    // CALL: Invoked by LargeStructZeroInit (00495190) as part of the wider zero-init sequence. [caller:0x00495190, source:raw]

    // Conservative worker pseudocode:
    //   void sub_496560(float *this) {
    //     this[1606] = 0.0f; this[5] = 0.0f; this[6] = 0.0f; this[7] = 0.0f; this[8] = 0.0f;
    //     *(byte*)this + 37 = 0; this[11] = 0.0f; this[13] = 0.0f; this[12] = 0.0f;
    //     this[17] = -1.0f; this[14] = 0.0f;
    //     this[48]=this[49]=this[50]=this[51] = 0.0f; this[52] = 0.5f; this[53] = 0.25f;
    //     ((dword*)this)[10] = 1; *(byte*)this + 6389 = 1; this[54] = 2.5f; this[55] = 0.0f;
    //     *(byte*)this + 224 = 0; this[57]=this[58]=this[59] = 0.0f;
    //     *(byte*)this + 5400 = 0; *(byte*)this + 5740 = 0; *(byte*)this + 5432 = 0;
    //     this[66] = 0.0f; this[68] = 0.0f; this[1349] = 0.0f; *(byte*)this + 6388 = 0;
    //     this[38]=this[39]=this[40]=this[41] = 0.0f;
    //     for (p = this + 69, n = 64; n; --n, p += 20) *(byte*)p = 0;
    //     this[65] = 0.0f; this[67] = 0.0f;
    //     this[1368]=this[1369]=this[1370]=this[1371]=this[1372] = 0.0f;
    //     this[1374] = 0.0f; this[1375] = 0.0f; this[1578] = 0.0f; *(byte*)this + 6380 = 0;
    //     this[19]=this[18]=this[21]=this[20] = 0.0f; this[43] = 0.0f; this[44] = 0.0f;
    //     *(byte*)this + 5492 = 1; *(byte*)this + 5512 = 1; *(byte*)this + 5513 = 1;
    //     ((dword*)this)[45] = &unk_888888; ((dword*)this)[46] = &unk_888888;
    //     FloatArrayInitWithRandom(this);
    //   }
    // UNRESOLVED: Global dword_5AC98C is flagged by packet facts as read, but it does not appear in the raw decompiled source for this function; its role is unverifiable from this packet.
    // UNRESOLVED: The owning structure is unnamed; it is a large float-backed aggregate, but the class that owns this initializer is unknown.
    // UNRESOLVED: unk_888888 is treated by the raw source as an address literal written into dword slots 45/46, overlapping float slots 45/46; the intended type (pointer vs float bit pattern) is ambiguous.
}
