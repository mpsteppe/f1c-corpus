// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044A450
// Canonical corpus name: CollisionMaterialLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionMaterialLookup_0044a450.c

void UnknownObject::CollisionMaterialLookup()
{
    // Lookup collision material properties from global lookup tables keyed by material index a1. Basic materials (index 0..7) take the dword_7CA388 / unk_7CA3A4 path; extended materials (index >7) take the flt_7CA3C0 negative-index path with negated flt_7CA36C values. Returns the a3 output pointer.
    // GUARD: Branch on material index a1: values greater than 7 take the extended-material path; values 0..7 take the basic-material path. [function:0x0044A450, source:raw]
    // ASSIGNMENT: Extended path: store flt_7CA3C0[-a1] (negative index into the extended material table) into *a2. [global:0x007CA3C0, source:raw]
    // ASSIGNMENT: Extended path: store the negation of flt_7CA36C[a1] into *a3. [global:0x007CA36C, source:raw]
    // ASSIGNMENT: Basic path: store dword_7CA388[a1] into *a2, written as a dword. [global:0x007CA388, source:raw]
    // ASSIGNMENT: Basic path: store the value read backwards from the unk_7CA3A4 table by index a1 into *a3. [global:0x007CA3A4, source:raw]
    // RETURN: Return the a3 output pointer in eax. [source:raw]

    // Conservative worker pseudocode:
    //   if (a1 > 7) {
    //       *a2 = flt_7CA3C0[-a1];
    //       *a3 = -flt_7CA36C[a1];
    //   } else {
    //       *(DWORD*)a2 = dword_7CA388[a1];
    //       *a3 = ((float*)&unk_7CA3A4)[-a1];
    //   }
    //   return a3;
    // UNRESOLVED: Semantic role of the two output values (a2 and a3) is not independently confirmed; the existing analysis labels them friction and restitution but the raw source carries no naming.
    // UNRESOLVED: Whether the a1 index space represents a material ID enum or a bitmask is unverified.
}
