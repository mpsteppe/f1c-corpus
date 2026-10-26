// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BFD0
// Canonical corpus name: BoundedArrayAccessor_bfd0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundedArrayAccessor_bfd0_0055bfd0.c

void UnknownObject::BoundedArrayAccessor_bfd0()
{
    // Bounded array accessor: returns element a2 of a dword array that follows a count field. The count at this+0x4 is the upper bound on a2; out-of-range access returns 0, otherwise it returns this[a2+2] (the dword at this + 8 + 4*a2). Used by two callers, one of which (UtilityFunction_9160) may belong to a different class.
    // GUARD: Bounds guard: when a2 >= this[1] (element count at this+0x4) the accessor fails closed and returns 0. Function sub_55BFD0 (ABI lead Bounded_Array_Accessor). [abi:lead, field:this:0x00000004, function:0x0055BFD0, source:raw]
    // RETURN: Return this[a2+2], the 32-bit element at this + 8 + 4*a2; the array of dwords begins right after the count field at +0x4. [field:this:0x00000004, source:raw]
    // RETURN: Return 0 when the requested index a2 is out of range. Called from UtilityFunction_9160 (0x004F9160) and sub_55F0D0 (0x0055F0D0). [caller:0x004F9160, caller:0x0055F0D0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_55BFD0(_DWORD *this, int a2) {
    //     if (a2 >= this[1])
    //       return 0;
    //     return this[a2 + 2];
    //   }
    // UNRESOLVED: Element type and semantics of the dword array are unknown; only the count at +0x4 constrains the index.
    // UNRESOLVED: Whether caller 004F9160 and caller 0055F0D0 share this object layout is not established.
}
