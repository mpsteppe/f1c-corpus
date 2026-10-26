// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005864E0
// Canonical corpus name: ConditionalListNodeCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalListNodeCleanup_005864e0.c

void UnknownObject::conditionalListCleanupAndFree()
{
    // Conditional list-node destructor helper (structural twin of 004081e0): reads a flag byte at offset 8; when set, runs SEHGuardedFunctionWithExceptionHandling on the object pointer at offset 0 and then frees it through FreeWrapper_7bcf. Returns the original flag byte value. Called by sub_583F50 (0x00583F50).
    // ASSIGNMENT: Read flag byte at offset 8 into result [field:this:0x00000008, source:raw]
    // GUARD: Guard on the flag byte at offset 8: when zero, return immediately without any cleanup [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Capture the object pointer stored at offset 0 into v2 [field:this:0x00000000, source:raw]
    // GUARD: Guard on the pointer at offset 0: when null, skip the guarded call and free, returning the flag byte [field:this:0x00000000, source:raw]
    // CALL: Call SEHGuardedFunctionWithExceptionHandling on the pointer read from offset 0 to run exception-guarded cleanup [callee:0x005867B0, field:this:0x00000000, source:raw]
    // CALL: Call FreeWrapper_7bcf on the captured pointer v2 to free the memory block [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // RETURN: Return the flag byte value on the guard paths; the cleanup path returns the FreeWrapper_7bcf result [source:raw]
    // CALL: Invoked by sub_583F50 (0x00583F50) as part of list-node teardown [caller:0x00583F50]

    // Conservative worker pseudocode:
    //   result = this[8];
    //   if (result != 0) {
    //     v2 = *(void **)this;
    //     if (*(_DWORD *)this != 0) {
    //       SEHGuardedFunctionWithExceptionHandling(*(_DWORD *)this);
    //       return FreeWrapper_7bcf(v2);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: The semantics of the flag byte at offset 8 are not documented in this function
    // UNRESOLVED: The exact cleanup contract and exception behavior of SEHGuardedFunctionWithExceptionHandling are not established here
    // UNRESOLVED: Whether the pointer at offset 0 is a list node, a resource, or a method-bearing object is not established (structural twin of 004081e0 only)
}
