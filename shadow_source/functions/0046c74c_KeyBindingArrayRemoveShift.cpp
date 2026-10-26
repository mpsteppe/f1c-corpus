// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046C74C
// Canonical corpus name: KeyBindingArrayRemoveShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/KeyBindingArrayRemoveShift_0046c74c.c

void UnknownObject::KeyBindingArrayRemoveShift()
{
    // Key-binding array removal with shift-down. Selects one of two key-binding arrays (dword_7CD2B8 or dword_7CD470) based on bit 2 of a1, ORs a2 into the dword at (a3 + 1149960185), reads the binding slot v5[a5], then removes it: when a5 >= 103 the slot is just reset to -1, otherwise the tail of the array is shifted down one slot (qmemcpy) and the last slot v5[103] is reset to -1. Returns the previously stored binding value.
    // ASSIGNMENT: OR a2 into the dword at (a3 + 1149960185) and store the result back. [source:raw]
    // ASSIGNMENT: Default the array base v5 to &dword_7CD2B8. [global:0x007CD2B8, source:raw]
    // GUARD: When (a1 & 4) == 0, re-select the alternate array base v5 = &dword_7CD470; otherwise keep dword_7CD2B8. [global:0x007CD470, abi:lead, source:raw]
    // ASSIGNMENT: Read result = v5[a5], the binding value currently stored at the slot being removed. [source:raw]
    // GUARD: When a5 >= 103, clear the slot directly: v5[a5] = -1, with no shift. [source:raw]
    // CALCULATION: Otherwise shift the array tail down: qmemcpy(&v5[a5], &v5[a5 + 1], 4 * (103 - a5)) moves the trailing slots toward the head to close the removed slot. [function:0x0046C74C, source:raw]
    // ASSIGNMENT: After the shift, reset the last array slot to the empty sentinel: v5[103] = -1. [source:raw]
    // RETURN: Return result, the binding value that was removed from slot a5. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_46C74C(char a1, int a2, int a3, int a4, int a5) {
    //     *(int*)(a3 + 1149960185) |= a2;
    //     int* v5 = &dword_7CD2B8;
    //     if ((a1 & 4) == 0) v5 = &dword_7CD470;
    //     int result = v5[a5];
    //     if (a5 >= 103) {
    //       v5[a5] = -1;
    //     } else {
    //       qmemcpy(&v5[a5], &v5[a5 + 1], 4 * (103 - a5));
    //       v5[103] = -1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The OR target offset literal 1149960185 (0x448AFFF9 as a u32) is unusually large for a struct dword offset; it may be a decompiler artifact of a negative offset, but no alternate spelling is evidenced in the packet.
    // UNRESOLVED: Semantics of a1 bit 2 and which binding set each global array (dword_7CD2B8 / dword_7CD470) represents are not evidenced.
    // UNRESOLVED: Meaning of the value ORed in via a2 is not evidenced.
    // UNRESOLVED: The packet tags both globals as read-only (rw R) while the raw source writes array slots through v5; the write classification is left to static/runtime review.
}
