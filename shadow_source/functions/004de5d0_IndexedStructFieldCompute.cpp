// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DE5D0
// Canonical corpus name: sub_4DE5D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DE5D0_004de5d0.c

void UnknownObject::IndexedStructFieldCompute()
{
    // Computes the address of an indexed element within a structure. Reads the base pointer stored at a1+8, dereferences it at +12 to obtain an array base, reads a 16-bit index from the table at a1 + 2*a2, and returns array_base + 48*index. A pure calculation with no guards, globals, or callees; used by sub_4DE610 and sub_4DF110.
    // CALCULATION: Read the 16-bit index entry at a1 + 2*a2 (2-byte table stride). [source:raw]
    // CALCULATION: Multiply the 16-bit index by 48 to form the byte offset within the element array. [source:raw]
    // CALCULATION: Dereference the pointer at a1+8 and read the element-array base pointer stored at the result + 12. [source:raw]
    // RETURN: Return the element-array base plus 48*index, i.e. the address of the indexed element. [source:raw]
    // CALL: Invoked by sub_4DE610 (0x004DE610) and sub_4DF110 (0x004DF110) to resolve an indexed struct element address. [caller:0x004DE610, caller:0x004DF110]

    // Conservative worker pseudocode:
    //   int IndexedStructFieldCompute(int a1, int a2) {
    //     DWORD* base = *(DWORD*)(*(DWORD*)(a1 + 8) + 12);
    //     unsigned short index = *(unsigned short*)(a1 + 2 * a2);
    //     return base + 48 * index;
    //   }
    // UNRESOLVED: The element stride 48 implies an array of fixed-size records, but the record layout is not evidenced by the packet.
    // UNRESOLVED: The purpose of the base pointer double-dereference (a1+8 then +12) and the meaning of the 16-bit index table are not evidenced.
    // UNRESOLVED: The owning class is unknown; packet marks owner as UnknownObject/UNKNOWN.
}
