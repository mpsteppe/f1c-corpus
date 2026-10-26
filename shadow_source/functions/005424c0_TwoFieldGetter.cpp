// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005424C0
// Canonical corpus name: TwoFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoFieldGetter_005424c0.c

void UnknownObject::TwoFieldGetter()
{
    // Gets two this-fields (offsets 0x6C and 0x70) and writes them through two output pointers a2 and a3, each independently null-guarded; returns a3.
    // GUARD: The field at 0x6C is written only when output pointer a2 is non-null [field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Write this[27] (byte offset 0x6C) through output pointer a2 [field:this:0x0000006C, source:raw]
    // GUARD: The field at 0x70 is written only when output pointer a3 is non-null [field:this:0x00000070, source:raw]
    // ASSIGNMENT: Write this[28] (byte offset 0x70) through output pointer a3 [field:this:0x00000070, source:raw]
    // RETURN: Return a3 (the second output pointer); the function is invoked by sub_5550E0 (0x005550E0) [function:0x005424C0, caller:0x005550E0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = this[27];
    //   if (a3) *a3 = this[28];
    //   return a3;
    // UNRESOLVED: Field types are not certain: the prototype is _DWORD* (reads through dword pointers), while the prior analysis labels 0x6C and 0x70 as floats; either interpretation is unverified from this packet
    // UNRESOLVED: Caller sub_5550E0 (0x005550E0) is recorded but the role of these two output fields in that caller is not documented
}
