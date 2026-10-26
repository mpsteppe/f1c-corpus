// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F2430
// Canonical corpus name: ConstructorZeroInitSubCalls
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorZeroInitSubCalls_004f2430.c

void UnknownObject::zeroInitSubCalls()
{
    // Thiscall constructor-style initializer: runs ConstantsStructInit over six regions of the object (two direct calls plus two loop-expanded blocks of 7-dword constants structs), zeroes 20 dword fields via straight-line and loop writes, and returns this. No reads, no globals, no guards.
    // CALL: Call ConstantsStructInit on this+12 (dword index 12). [callee:0x0040E6A0, source:raw]
    // CALL: Call ConstantsStructInit on this+24 (dword index 24). [callee:0x0040E6A0, source:raw]
    // LOOP: Loop 4 times: call ConstantsStructInit on the current pointer (starting this+34) then advance it by 7 dwords, covering four 7-dword constants structs. [callee:0x0040E6A0, source:raw]
    // LOOP: Loop 8 times: call ConstantsStructInit on the current pointer (starting this+102) then advance it by 7 dwords, covering eight 7-dword constants structs. [callee:0x0040E6A0, source:raw]
    // ASSIGNMENT: Zero dword fields this[0] through this[11] (12 consecutive dwords). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // ASSIGNMENT: Zero dword fields this[19] through this[23] (5 consecutive dwords). [field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C]
    // ASSIGNMENT: Zero dword fields this[31] through this[33] (3 consecutive dwords). [field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084]
    // LOOP: Loop 8 times: zero the dword at (v6-8) and the dword at v6, then zero dwords at (v7-2), (v7-1) and v7; v6 starts at this+70 and advances by 1 dword per iteration, v7 starts at this+80 and advances by 3 dwords per iteration. [field:this:0x00000118, field:this:0x00000140, source:raw]
    // RETURN: Return the this pointer. [function:0x004F2430]

    // Conservative worker pseudocode:
    //   ConstantsStructInit(this + 12);
    //   ConstantsStructInit(this + 24);
    //   for (p = this + 34, n = 4; n; --n, p += 7) ConstantsStructInit(p);
    //   for (p = this + 102, n = 8; n; --n, p += 7) ConstantsStructInit(p);
    //   for (i = 0; i < 12; ++i) this[i] = 0;
    //   for (i = 19; i < 24; ++i) this[i] = 0;
    //   for (i = 31; i < 34; ++i) this[i] = 0;
    //   for (a = this + 70, b = this + 80, n = 8; n; --n, ++a, b += 3) { *(a - 8) = 0; *a = 0; *(b - 2) = 0; *(b - 1) = 0; *b = 0; }
    //   return this;
    // UNRESOLVED: Object type is unknown; the two callers (PhysicsTireSystemConstructor and TireModelDataInit) suggest a tire physics/data model, but no packet evidence names the type.
    // UNRESOLVED: Intermediate offsets written inside the final zeroing loop (the v6-8 and v6 targets, and the v7-2, v7-1, v7 targets at each 3-dword step) are not enumerated in the packet field list; only dwords 70 and 80 carry explicit field evidence.
    // UNRESOLVED: Semantic role of the 7-dword constants structs initialized via ConstantsStructInit is not described by any packet evidence.
}
