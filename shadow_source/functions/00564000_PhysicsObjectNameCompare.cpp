// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564000
// Canonical corpus name: PhysicsObjectNameCompare
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsObjectNameCompare_00564000.c

void UnknownObject::PhysicsObjectNameCompare()
{
    // Resolves a value through helper sub_5644B0 applied to global byte_5EA438 and passes the result to strcmp twice (the decompiled body feeds the same expression to both operands), then returns the negated comparison when the dword at dword_8D46B4 + 132 is zero. Net effect is a signed comparison whose direction depends on a flag inside the object pointed to by dword_8D46B4; if sub_5644B0 is deterministic the two operands are identical and the comparison degenerates to zero.
    // CALL: Call sub_5644B0(byte_5EA438) and store the returned pointer as v0. [callee:0x005644B0, global:0x005EA438, source:raw]
    // CALL: Call strcmp(sub_5644B0(byte_5EA438), v0); both operands derive from the same helper call on the same global, so the result is zero unless sub_5644B0 is stateful or has side effects. [callee:0x005644B0, global:0x005EA438, source:raw]
    // GUARD: If the dword at dword_8D46B4 + 132 (offset 132 bytes into the object pointed to by the global) is zero, return the negated strcmp result. [global:0x008D46B4, source:raw]
    // RETURN: Return the strcmp result when the dword at dword_8D46B4 + 132 is non-zero. [global:0x008D46B4, source:raw]

    // Conservative worker pseudocode:
    //   int PhysicsObjectNameCompare() {
    //     const char *v0 = sub_5644B0(byte_5EA438);
    //     int result = strcmp(sub_5644B0(byte_5EA438), v0);
    //     if (*(unsigned int *)(dword_8D46B4 + 132) == 0)
    //       return -result;
    //     return result;
    //   }
    // UNRESOLVED: Identity and semantics of helper sub_5644B0 (name/string resolution?).
    // UNRESOLVED: Whether sub_5644B0 is deterministic; if so both strcmp operands are identical and the comparison always yields zero.
    // UNRESOLVED: Type and role of the object at dword_8D46B4 and of its field at offset 132.
    // UNRESOLVED: Purpose of the negated vs non-negated comparison direction.
}
