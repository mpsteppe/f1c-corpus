// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054B420
// Canonical corpus name: TripleFieldQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleFieldQuery_0054b420.c

void UnknownObject::TripleFieldQuery()
{
    // Reads fields at this+0x20, this+0x24, this+0x28 and writes each to its corresponding output pointer (a2, a3, a4) when non-null; returns a4.
    // GUARD: Proceed with the first write only if a2 is non-null. [source:raw]
    // ASSIGNMENT: Write field at this+0x20 into *a2. [field:this:0x00000020, source:raw]
    // GUARD: Proceed with the second write only if a3 is non-null. [source:raw]
    // ASSIGNMENT: Write field at this+0x24 into *a3. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Set result to a4. [source:raw]
    // GUARD: Proceed with the third write only if a4 is non-null. [source:raw]
    // ASSIGNMENT: Write field at this+0x28 into *a4. [field:this:0x00000028, source:raw]
    // RETURN: Return result, which is a4. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = this[8];
    //   if (a3) *a3 = this[9];
    //   result = a4;
    //   if (a4) *a4 = this[10];
    //   return result;
    // UNRESOLVED: Semantic meaning of the three read fields (0x20, 0x24, 0x28) and of the returned pointer a4 is unknown; owning object type is unknown.
}
