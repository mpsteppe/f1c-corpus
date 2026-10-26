// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485A70
// Canonical corpus name: DestructorWithConditionalFree_5a70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFree_5a70_00485a70.c

void UnknownObject::DestructorWithConditionalFree_5a70()
{
    // Scalar deleting-destructor wrapper (MSVC pattern): always runs the object teardown via ShortComputation_6140(this), then, when the low bit of flag a2 is set, frees the object memory via FreeWrapper_7bcf(this). Returns this. The a2 & 1 test is the standard compiler-generated deleting-destructor 'free memory' flag; the function itself contains no field or global access.
    // CALL: Invoke ShortComputation_6140(this) unconditionally as the object teardown body. [callee:0x00466140, source:raw]
    // GUARD: Test whether the low bit of the deleting-destructor flag is set: (a2 & 1) != 0. [source:raw]
    // CALL: When the flag bit is set, call FreeWrapper_7bcf(this) to free the object allocation. [callee:0x00587BCF, source:raw]
    // RETURN: Return this as the result of the wrapper. [function:0x00485A70, source:raw]

    // Conservative worker pseudocode:
    //   void* DestructorWithConditionalFree_5a70(void* this, char a2) {
    //     ShortComputation_6140(this);
    //     if (a2 & 1)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The concrete teardown performed by ShortComputation_6140 and the object's class/type are not evidenced by this packet.
    // UNRESOLVED: a2 higher bits (only bit 0 is tested here) may carry other deleting-destructor flags for callers that pass them.
    // UNRESOLVED: FreeWrapper_7bcf is a decompiler-named allocator; whether it is the global operator delete is not evidenced here.
}
