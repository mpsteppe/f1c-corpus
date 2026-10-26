// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9BA0
// Canonical corpus name: SortComparatorSpeedSum
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SortComparatorSpeedSum_004c9ba0.c

void UnknownObject::SortComparatorSpeedSum()
{
    // qsort-style comparator. Each argument is a pointer to an object pointer (arg+0x0). Sums the float at obj+0x738 and the float at obj+0x740 for both operands and returns -1/0/1 ordering by the larger total speed sum.
    // CALCULATION: Load object pointer stored at a1+0x0, then compute v2 = float[obj+0x740] + float[obj+0x738] (offsets 1856 and 1848 in decimal). [field:this:0x00000000, field:obj:0x00000740, field:obj:0x00000738, source:raw]
    // CALCULATION: Load object pointer stored at a2+0x0, then compute v3 = float[obj+0x740] + float[obj+0x738]. [field:this:0x00000000, field:obj:0x00000740, field:obj:0x00000738, source:raw]
    // GUARD: If v2 > v3, comparator yields positive ordering. [source:raw]
    // RETURN: Return 1 when the first operand's speed sum is strictly greater. [source:raw]
    // GUARD: If v2 >= v3 (equality case), comparator yields neutral ordering. [source:raw]
    // RETURN: Return 0 when the two speed sums are equal. [source:raw]
    // RETURN: Return -1 when the second operand's speed sum is strictly greater. [source:raw]

    // Conservative worker pseudocode:
    //   v2 = *(float*)(**(DWORD**)a1 + 0x740) + *(float*)(**(DWORD**)a1 + 0x738);
    //   v3 = *(float*)(**(DWORD**)a2 + 0x740) + *(float*)(**(DWORD**)a2 + 0x738);
    //   if (v2 > v3) return 1;
    //   if (v2 >= v3) return 0;
    //   return -1;
    // UNRESOLVED: Semantic meaning of the two summed float fields (0x738, 0x740) is not established; 'speed' is a legacy naming hint, not evidence.
    // UNRESOLVED: No static callers identified; comparator is invoked indirectly (e.g. via qsort), so its call context is unknown.
}
