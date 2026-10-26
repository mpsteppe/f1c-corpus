// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042DD72
// Canonical corpus name: VTableArrayIndexedLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableArrayIndexedLookup_0042dd72.c

void UnknownObject::VTableArrayIndexedLookup()
{
    // Single-expression indexed table lookup. Given an object pointer a2 and an index a1 (passed in ecx and eax respectively under the __userpurge convention), reads the pointer stored at a2 + 12 (an array base), then returns the dword at that base + 8 * a1. The 8-byte stride indicates the array holds fixed 8-byte records (consistent with a vtable-entry or 2-dword-slot table). Argument a3 is declared but unused. No fields, globals, guards, or recorded callers are present in the packet.
    // ASSIGNMENT: Read the pointer at a2 + 12; this is the base address of the indexed array [source:raw]
    // CALCULATION: Compute the element offset as 8 * a1 (8-byte record stride times the index) [source:raw]
    // RETURN: Return the dword at (*(a2 + 12)) + 8 * a1 [source:raw]

    // Conservative worker pseudocode:
    //   int VTableArrayIndexedLookup(int a1, int a2, int a3) {
    //       return *(_DWORD *)(*(_DWORD *)(a2 + 12) + 8 * a1);
    //   }
    // UNRESOLVED: The 8-byte stride means each record is two dwords; whether these are vtable entries, (pointer, parameter) pairs, or some other record type is not evidenced by the packet
    // UNRESOLVED: The __userpurge register convention (a1 in eax, a2 in ecx) and the unused a3 make the intended calling contract ambiguous
    // UNRESOLVED: The layout of the object at a2 (with an array-base pointer at +12) is not defined by any field table in this packet
}
