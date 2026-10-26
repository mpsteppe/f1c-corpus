// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005504D0
// Canonical corpus name: IndexedArrayLookupWithBoundsCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedArrayLookupWithBoundsCheck_005504d0.c

void UnknownObject::IndexedArrayLookupWithBoundsCheck()
{
    // Bounds-checked lookup into a frame array. Index a3 is validated against the count at this+0xA4; the entry base is this+0xA8 + 148*a3. For terminal frame types (entry field 18 <= 1), optionally resets the Bink video decoder via BinkVideoFrameDecoder when both the entry flag at field 36 and global dword_8B6AC4 are non-zero, clearing bit 0x400 on the decoder buffer, then returns the frame pointer at entry field 35. For non-terminal frames, a2 == -1 returns the frame pointer directly; otherwise a sub-indexed lookup against the list at entry field 19 (offset by entry field 20) yields a frame offset computed as 96 times the selected list entry.
    // ASSIGNMENT: Initialize result to 0 as the default (out-of-bounds) return value. [source:raw]
    // GUARD: Proceed only when a3 < this[0xA4] (element count); otherwise return 0. [field:this:0x000000A4]
    // CALCULATION: Compute the frame entry pointer as this[0xA8] + 148*a3 (148-byte element stride). [field:this:0x000000A8, source:raw]
    // GUARD: Terminal-frame path taken when the entry's field 18 is <= 1. [source:raw]
    // GUARD: Bink reset runs only when the entry's field 36 is non-zero AND global dword_8B6AC4 is non-zero. [global:0x008B6AC4, source:raw]
    // CALL: Call BinkVideoFrameDecoder on the decoder object at *(entry field 35 + 84) with arguments (0, 0, 32). [callee:0x00551DD0, source:raw]
    // ASSIGNMENT: Clear bit 0x400 at byte offset 24 of the decoder object at *(entry field 35 + 84). [source:raw]
    // RETURN: Return the frame pointer stored at entry field 35 (terminal-frame path and the a2 == -1 path). [source:raw]
    // GUARD: For non-terminal frames, a2 == -1 selects the base frame pointer directly. [source:raw]
    // CALCULATION: For a2 < entry field 20, look up entry field 19[abs(a2)]; otherwise entry field 19[abs(a2) - field 20]. Scale the selected list value by 96 and add it to the frame pointer at entry field 35. [source:raw]
    // RETURN: Return the frame pointer at entry field 35 plus the 96-scaled sub-index contribution. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5504D0(int *this, int a2, int a3) {
    //     if (a3 >= this[0xA4 / 4]) return 0;
    //     int *entry = (int *)(this[0xA8 / 4] + 148 * a3);
    //     if (entry[18] <= 1) {
    //       if (entry[36] && dword_8B6AC4) {
    //         int *decoder = *(int **)(entry[35] + 84);
    //         BinkVideoFrameDecoder(decoder, 0, 0, 32);
    //         decoder[24 / 4] &= ~0x400;
    //       }
    //       return entry[35];
    //     }
    //     if (a2 == -1) return entry[35];
    //     int idx = a2 < entry[20] ? abs(a2) : abs(a2) - entry[20];
    //     return entry[35] + 96 * *(int *)(entry[19] + 4 * idx);
    //   }
    // UNRESOLVED: The frame entry layout (fields 18, 19, 20, 35, 36 of the 148-byte stride entry) is not in the packet field list; their concrete meaning is unknown.
    // UNRESOLVED: Semantics of the constants 32 (BinkVideoFrameDecoder argument) and the 96 scale factor are not established.
    // UNRESOLVED: The meaning of the 0x400 bit cleared on the decoder object is unknown.
}
