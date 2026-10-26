// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00511F70
// Canonical corpus name: LargeStructPartialReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LargeStructPartialReset_00511f70.c

void UnknownObject::LargeStructPartialReset()
{
    // Partial reset of a large object. Optionally pre-processes two argument pointers through ShortComputation_3d2f, then releases embedded sub-resources: six unconditional callback releases (ConditionalCall_7ec8 on pointers at 0x9C, 0xD8, 0xDC, 0x138, 0x174, 0x178), one guarded callback release keyed on flag bit 0x10 of the byte at 0x5D (SafeDeleteGuardForThunkFUN00517ec8 on pointer at 0x104), one guarded callback release keyed on flag bit 0x20 (ConditionalCall_7ec8 on pointer at 0x15C), and a counted array release: when the pointer at 0x144 is non-null, iterate 1 << (8 - byte at 0x12C) elements of the pointer array at 0x144 with ConditionalCall_7ec8, then release the array base itself. Runs sub_5179A2 on the sub-object at this+100, then zeroes 0x19C bytes of the structure while preserving the first 0x40 bytes and the DWORDs at 0x40, 0x44, 0x48. Called by ThreeObjectCleanupChain (00512093). Returns the preserved DWORD at 0x48.
    // CALL: When a2 is non-zero, call ShortComputation_3d2f(a1, a2). [callee:0x00513D2F, source:raw]
    // CALL: When a3 is non-zero, call ShortComputation_3d2f(a1, a3). [callee:0x00513D2F, source:raw]
    // CALL: Release six unconditional sub-resources by calling ConditionalCall_7ec8(a1, *(LPVOID*)(a1 + 0x9C)) and likewise for offsets 0xDC, 0xD8, 0x174, 0x178 and 0x138. [callee:0x00517EC8, field:this:0x0000009C, field:this:0x000000DC, field:this:0x000000D8, field:this:0x00000174, field:this:0x00000178, field:this:0x00000138, source:raw]
    // GUARD: If byte at 0x5D has flag bit 0x10 set, call SafeDeleteGuardForThunkFUN00517ec8(a1, *(LPVOID*)(a1 + 0x104)). [callee:0x00513CD3, field:this:0x0000005D, field:this:0x00000104, source:raw]
    // GUARD: If byte at 0x5D has flag bit 0x20 set, call ConditionalCall_7ec8(a1, *(LPVOID*)(a1 + 0x15C)). [callee:0x00517EC8, field:this:0x0000005D, field:this:0x0000015C, source:raw]
    // LOOP: If the DWORD at 0x144 is non-null, compute count = 1 << (8 - byte at 0x12C) and loop ConditionalCall_7ec8(a1, element) over the pointer array at 0x144 (stride 4 bytes), then release the array base pointer at 0x144 itself. [callee:0x00517EC8, field:this:0x00000144, field:this:0x0000012C, source:raw]
    // CALL: Call sub_5179A2 on the sub-object at a1 + 100. [callee:0x005179A2, source:raw]
    // ASSIGNMENT: Save the DWORDs at 0x40, 0x44, 0x48 and the first 0x40 bytes into scratch, zero 0x19C bytes of the structure, then restore the first 0x40 bytes and the DWORDs at 0x44, 0x40, 0x48. [field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, source:raw]
    // RETURN: Return the preserved DWORD at 0x48 (the value saved before the memset and restored after it). [field:this:0x00000048, source:raw]

    // Conservative worker pseudocode:
    //   int sub_511F70(int self, int opt1, int opt2) {
    //     if (opt1) ShortComputation_3d2f(self, opt1);
    //     if (opt2) ShortComputation_3d2f(self, opt2);
    //     ConditionalCall_7ec8(self, *(LPVOID*)(self + 0x9C));
    //     ConditionalCall_7ec8(self, *(LPVOID*)(self + 0xDC));
    //     ConditionalCall_7ec8(self, *(LPVOID*)(self + 0xD8));
    //     ConditionalCall_7ec8(self, *(LPVOID*)(self + 0x174));
    //     ConditionalCall_7ec8(self, *(LPVOID*)(self + 0x178));
    //     ConditionalCall_7ec8(self, *(LPVOID*)(self + 0x138));
    //     if (*(BYTE*)(self + 0x5D) & 0x10) SafeDeleteGuardForThunkFUN00517ec8(self, *(LPVOID*)(self + 0x104));
    //     if (*(BYTE*)(self + 0x5D) & 0x20) ConditionalCall_7ec8(self, *(LPVOID*)(self + 0x15C));
    //     if (*(DWORD*)(self + 0x144)) {
    //       int n = 1 << (8 - *(BYTE*)(self + 0x12C));
    //       for (int k = 0; k < n; ++k)
    //         ConditionalCall_7ec8(self, *(LPVOID*)(*(DWORD*)(self + 0x144) + 4 * k));
    //       ConditionalCall_7ec8(self, *(LPVOID*)(self + 0x144));
    //     }
    //     sub_5179A2(self + 100);
    //     BYTE saved[0x40]; qmemcpy(saved, self, sizeof(saved));
    //     save40 = *(DWORD*)(self + 0x40);
    //     save44 = *(DWORD*)(self + 0x44);
    //     save48 = *(DWORD*)(self + 0x48);
    //     memset(self, 0, 0x19C);
    //     qmemcpy(self, saved, 0x40);
    //     *(DWORD*)(self + 0x44) = save44;
    //     *(DWORD*)(self + 0x40) = save40;
    //     *(DWORD*)(self + 0x48) = save48;
    //     return save48;
    //   }
    // UNRESOLVED: Identity and layout of the object a1 are unknown; sub-resource pointers are released through generic callbacks whose target semantics are caller-defined.
    // UNRESOLVED: The two ShortComputation_3d2f arguments a2/a3 depend on caller context (ThreeObjectCleanupChain, 00512093) and are not described here.
    // UNRESOLVED: The flag bits at 0x5D and the exponent byte at 0x12C are semantics-only; their meaning is not documented in this function.
}
