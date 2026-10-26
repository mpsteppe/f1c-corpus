// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004560C0
// Canonical corpus name: RectViewportDimensionGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RectViewportDimensionGetter_004560c0.c

void UnknownObject::RectViewportDimensionGetter()
{
    // Copies two struct fields (offset 0x54 and offset 0x58, elements 21 and 22) to caller-provided output pointers a2 and a3. Each output write is guarded on its pointer being non-null. Returns a3 (the second output pointer).
    // GUARD: Guard on a2 being non-null; the first field is only copied when a2 is a valid pointer. [source:raw]
    // ASSIGNMENT: Write the struct field at offset 0x54 (element 21) into *a2. [source:raw, field:this:0x00000054]
    // GUARD: Guard on a3 being non-null; the second field is only copied when a3 is a valid pointer. [source:raw]
    // ASSIGNMENT: Write the struct field at offset 0x58 (element 22) into *a3. [source:raw, field:this:0x00000058]
    // RETURN: Return a3 as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = this[21];
    //   if (a3) *a3 = this[22];
    //   return a3;
    // UNRESOLVED: Semantic meaning of the two read fields (0x54, 0x58) is unknown; callers include rendering/transform helpers but no owning class is established.
    // UNRESOLVED: The enclosing object is unknown; no class or purpose is derivable from this function alone.
}
