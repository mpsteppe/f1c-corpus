// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040A890
// Canonical corpus name: MultiFieldMembershipCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldMembershipCheck_0040a890.c

void UnknownObject::MultiFieldMembershipCheck()
{
    // Membership check on a multi-slot object: returns 1 when the input a2 matches any of the eight fixed entry slots (this+0x10..0x1C and this+0x24..0x30) or lies on the stride-200 grid of the variable-length array whose base is this+0x20 within the entry count this+0x38; returns 0 otherwise (including a non-positive count).
    // ASSIGNMENT: Initialize result to 0, the default not-found value. [source:raw]
    // GUARD: Fixed-entry comparison guard: when a2 is non-null AND differs from all eight fixed entries (this[4..7] at +0x10..+0x1C and this[9..12] at +0x24..+0x30), or when a2 is null, fall through to the variable-array scan; an equality against any fixed entry skips the block and returns 1. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Load the variable-array entry count v3 from this[14] (offset +0x38) and start the scan index v4 at 0. [field:this:0x00000038, source:raw]
    // GUARD: Count guard: if the entry count v3 is not positive, return result (0). [field:this:0x00000038, source:raw]
    // LOOP: Linear scan of the variable-length array whose base is this[8] (offset +0x20): advance the address cursor by 200 bytes per entry and compare the cursor to a2, treating a2 as an address that must fall exactly on the stride-200 grid. [field:this:0x00000020, source:raw]
    // GUARD: Scan bound: increment the index v4; if it reaches the entry count v3, return result (0). [field:this:0x00000038, source:raw]
    // RETURN: Return 1 once a2 matches a fixed entry or an array grid position; return 0 (default result) otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (!a2 || (a2 != this[4] && a2 != this[5] && a2 != this[6] && a2 != this[7]
    //               && a2 != this[9] && a2 != this[10] && a2 != this[11] && a2 != this[12])) {
    //     v3 = this[14];
    //     v4 = 0;
    //     if (v3 <= 0) return result;
    //     for (i = this[8]; i != a2; i += 200) {
    //       if (++v4 >= v3) return result;
    //     }
    //   }
    //   return 1;
    // UNRESOLVED: Whether a2 is a raw address (grid-position membership check) or a stored entry id is not resolvable from this packet alone; the fixed-entry compares are plain dword equality on entry pointers.
    // UNRESOLVED: The 200-byte array entry layout is a structural fact; no per-entry field documentation exists in this packet.
}
