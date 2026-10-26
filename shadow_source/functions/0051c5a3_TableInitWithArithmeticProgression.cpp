// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C5A3
// Canonical corpus name: TableInitWithArithmeticProgression
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TableInitWithArithmeticProgression_0051c5a3.c

void UnknownObject::TableInitWithArithmeticProgression()
{
    // Allocates four 1024-DWORD lookup tables by dispatching four allocation calls through vtable slot 0 on the object at a1, storing the returned pointers into the sub-struct at *(a1 + 0x1A0) offsets 0x8/0xC/0x10/0x14. It then fills all four tables in a single loop: table 0 with an ascending arithmetic sequence (v9 += 91881, stored as v9 >> 16), table 1 with a second ascending sequence (v8 += 116130, stored as v8 >> 16), table 2 with pointer-derived dwords marching downward from global unk_5B6900 (v4 -= 46802), and table 3 with a descending sequence (i -= 22554). Returns a pointer one dword past the last written element.
    // ASSIGNMENT: Load the table sub-struct pointer v2 = *(_DWORD **)(a1 + 0x1A0); the four allocation results are stored into its first DWORDs. [field:this:0x000001A0, source:raw]
    // CALL: Dispatch four identical allocation calls through vtable slot 0 at *(a1 + 4) with arguments (a1, 1, 1024); each result is stored into the sub-struct DWORD at offset 0x8 (v2[2]). [field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(this+0x1A0):0x00000008, source:raw]
    // CALL: Same vtable-slot-0 allocation call with (a1, 1, 1024); result stored into the sub-struct DWORD at offset 0xC (v2[3]). [field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(this+0x1A0):0x0000000C, source:raw]
    // CALL: Same vtable-slot-0 allocation call with (a1, 1, 1024); result stored into the sub-struct DWORD at offset 0x10 (v2[4]). [field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(this+0x1A0):0x00000010, source:raw]
    // CALL: Same vtable-slot-0 allocation call with (a1, 1, 1024); result stored into the sub-struct DWORD at offset 0x14 (v2[5]). [field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(this+0x1A0):0x00000014, source:raw]
    // LOOP: Single fill loop from i = 2919680 down to i >= -2831590 step -22554: table 0 (offset 0x8) gets v9 >> 16 with v9 += 91881, table 1 (offset 0xC) gets v8 >> 16 with v8 += 116130, table 2 (offset 0x10) gets the marching dword v4 read from unk_5B6900 with v4 -= 46802, table 3 (offset 0x14) gets the running index i; result advances by 4 bytes per iteration. [field:*(this+0x1A0):0x00000008, field:*(this+0x1A0):0x0000000C, field:*(this+0x1A0):0x00000010, field:*(this+0x1A0):0x00000014, global:0x005B6900, source:raw]
    // RETURN: Return result, the byte offset one past the final written DWORD across all four tables. [function:0x0051C5A3, source:raw]

    // Conservative worker pseudocode:
    //   v2 = *(a1 + 0x1A0);
    //   v2[2] = vtable0(a1, 1, 1024);
    //   v2[3] = vtable0(a1, 1, 1024);
    //   v2[4] = vtable0(a1, 1, 1024);
    //   v2[5] = vtable0(a1, 1, 1024);
    //   v4 = &unk_5B6900; v8 = -14831872; v9 = -11728000;
    //   for (i = 2919680; i >= -2831590; i -= 22554) {
    //       v9 += 91881; v2[2][k] = v9 >> 16;
    //       v8 += 116130; v2[3][k] = v8 >> 16;
    //       v2[4][k] = v4;  v4 -= 46802;
    //       v2[5][k] = i;
    //       result += 4;
    //   }
    //   return result;
    // UNRESOLVED: The vtable-slot-0 callable at *(a1 + 4) is not resolved; its parameter meaning (a1, 1, 1024) is interpreted as allocator(size 1024) from the existing analysis, which is DERIVED.
    // UNRESOLVED: The intended semantic content of the four arithmetic sequences (fixed-point values from >>16, pointer-derived values from unk_5B6900) is unknown; the existing analysis guesses wheel/suspension data, unconfirmed.
    // UNRESOLVED: The sub-struct at *(a1 + 0x1A0) and its owning object type are unknown.
    // UNRESOLVED: The loop trip count is derived only from the arithmetic progression bounds; the exact number of entries is not a packet literal.
}
