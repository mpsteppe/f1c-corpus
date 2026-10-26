// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050B244
// Canonical corpus name: ShortComputation_b244
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_b244_0050b244.c

void UnknownObject::ShortComputation_b244()
{
    // Mixed teardown helper with an unusual __userpurge ABI (a1 in ECX, a2 in EBP, a3 on the stack). Runs ComplexDestructorWithLoop (0x00506FD9) over a2, then conditionally frees a1 through FreeWrapper_7bcf (0x00587BCF) when bit 0 of a3 is set, and returns a1.
    // CALL: Invoke ComplexDestructorWithLoop (0x00506FD9) with a2, which is passed via EBP under the __userpurge convention. [callee:0x00506FD9, source:raw]
    // GUARD: Guard on (a3 & 1) != 0; the ownership/free step only runs when the low flag bit of a3 is set. [function:0x0050B244, source:raw]
    // CALL: Conditionally release a1 through FreeWrapper_7bcf (0x00587BCF) when the guarded flag is set. [callee:0x00587BCF, function:0x0050B244, source:raw]
    // RETURN: Return a1 (the object passed in ECX), regardless of whether the free ran. [function:0x0050B244, source:raw]

    // Conservative worker pseudocode:
    //   void *sub_50B244(void *a1, int a2, char a3) {
    //     ComplexDestructorWithLoop(a2);
    //     if ((a3 & 1) != 0) FreeWrapper_7bcf(a1);
    //     return a1;
    //   }
    // UNRESOLVED: Relation between a1 and a2 is unclear; a2 may be a separate sub-object or container destroyed before a1 is conditionally freed.
    // UNRESOLVED: Meaning of the a3 flag bit (ownership / last-reference signal) is not established.
}
