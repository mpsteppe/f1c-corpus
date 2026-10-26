// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A8BC
// Canonical corpus name: SubCallConditionalFree_a8bc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SubCallConditionalFree_a8bc_0059a8bc.c

void UnknownObject::subCallConditionalFree_a8bc()
{
    // userpurge helper that unconditionally runs ObjectDestructorWithRefCountDecrement on a2, then conditionally calls FreeWrapper_7bcf on a1 when the low bit of a3 is set, and returns a1. Pattern resembles a destruction-and-optional-free cleanup path.
    // CALL: Call ObjectDestructorWithRefCountDecrement unconditionally with a2. [callee:0x0059A86C, source:raw]
    // GUARD: Branch on whether the low bit of a3 (a3 & 1) is non-zero. [source:raw]
    // CALL: Call FreeWrapper_7bcf with a1 when the guarded bit is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return a1 in eax. [function:0x0059A8BC, source:raw]

    // Conservative worker pseudocode:
    //   void* subCallConditionalFree_a8bc(void* a1, int a2, char a3) {
    //       ObjectDestructorWithRefCountDecrement(a2);
    //       if ((a3 & 1) != 0)
    //           FreeWrapper_7bcf(a1);
    //       return a1;
    //   }
    // UNRESOLVED: Relationship between a1 (freed) and a2 (destroyed) is unknown; they may be separate objects.
    // UNRESOLVED: Semantics of the a3 bit-0 flag and the destructor/free contract are unknown.
}
