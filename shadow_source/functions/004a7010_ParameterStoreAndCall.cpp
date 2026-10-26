// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A7010
// Canonical corpus name: FunctionCallWrapper_7010
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_7010_004a7010.c

void UnknownObject::ParameterStoreAndCall()
{
    // Stores two integer parameters a3 and a4 as mirrored pairs at +0xC/+0x14 and +0x10/+0x18 of the this object, copies the caller-supplied string a2 into an allocated buffer via StringCopyWithBufferRealloc, then delegates to ShortComputation_1b70 and returns its result. Part of player options initialization.
    // CALL: Copy the input string a2 into a buffer via StringCopyWithBufferRealloc. [source:raw, callee:0x00566650]
    // ASSIGNMENT: Store parameter a3 at this + 0xC. [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Store duplicate of parameter a3 at this + 0x14. [source:raw, field:this:0x00000014]
    // ASSIGNMENT: Store parameter a4 at this + 0x10. [source:raw, field:this:0x00000010]
    // ASSIGNMENT: Store duplicate of parameter a4 at this + 0x18. [source:raw, field:this:0x00000018]
    // CALL: Delegate the initialized this object to ShortComputation_1b70 for further option initialization. [source:raw, callee:0x004A1B70]
    // RETURN: Return the result of ShortComputation_1b70. [source:raw]

    // Conservative worker pseudocode:
    //   void* ParameterStoreAndCall(int* this, int a2, int a3, int a4) {
    //     StringCopyWithBufferRealloc(a2);
    //     this[0xC / 4] = a3;
    //     this[0x14 / 4] = a3;
    //     this[0x10 / 4] = a4;
    //     this[0x18 / 4] = a4;
    //     return ShortComputation_1b70(this);
    //   }
    // UNRESOLVED: Why a3 and a4 are stored twice at mirrored offsets; exact semantics of the duplicated fields.
    // UNRESOLVED: Relationship between the copied string a2 and the stored option values.
}
