// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041ED20
// Canonical corpus name: IndexedFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedFieldGetter_0041ed20.c

void UnknownObject::ReadIndexedDwordField()
{
    // Fastcall getter that returns the dword at a1 + 4*a2 + 216: an indexed field read on the object a1 using a2 as a dword-array index with a fixed base offset of 216 bytes. Returns 0 when the object pointer a1 is null.
    // ASSIGNMENT: Initialize result to 0; this default is returned when the object pointer a1 is null. [source:raw]
    // GUARD: Guard on a1 being nonzero: when a1 is null the function returns the default result 0 without dereferencing. [source:raw]
    // RETURN: Return the dword at a1 + 4*a2 + 216, i.e. the element a2 (dword stride) of a field array located 216 bytes into the object a1. [source:raw]

    // Conservative worker pseudocode:
    //   int __fastcall sub_41ED20(int a1, int a2)
    //   {
    //     int result = 0;
    //     if (a1)
    //       return *(int*)(a1 + 4*a2 + 216);
    //     return result;
    //   }
    // UNRESOLVED: Owner struct type is unknown; the indexed dword field at base offset 216 with a2 as a dword index depends on the caller's array layout. Callers cluster around scoring and championship aggregation.
}
