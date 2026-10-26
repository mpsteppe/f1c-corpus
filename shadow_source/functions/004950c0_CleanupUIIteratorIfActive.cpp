// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004950C0
// Canonical corpus name: ShortComputation_50c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_50c0_004950c0.c

void UnknownObject::CleanupUIIteratorIfActive()
{
    // Conditional one-shot UI iterator cleanup. Loads the global UI iterator handle dword_7CDE10; when it is non-zero, passes it to UICleanupIterator and returns that function's result, otherwise returns the loaded zero handle unchanged.
    // ASSIGNMENT: Load the global UI iterator handle dword_7CDE10 into the result value [global:0x007CDE10, source:raw]
    // GUARD: If dword_7CDE10 is zero, skip cleanup and return the loaded zero handle directly [global:0x007CDE10, source:raw]
    // CALL: When dword_7CDE10 is non-zero, invoke UICleanupIterator(dword_7CDE10) to clean up the active UI iterator and return its result [callee:0x00554D70, global:0x007CDE10, source:raw]
    // RETURN: Return the cleanup result (or the zero handle when no iterator was active) [function:0x004950C0, source:raw]

    // Conservative worker pseudocode:
    //   int result = dword_7CDE10;
    //   if (dword_7CDE10)
    //       return UICleanupIterator(dword_7CDE10);
    //   return result;
    // UNRESOLVED: The packet lists global dword_8B78A0 as referenced, but it does not appear in the raw source; its role in this function is unknown.
    // UNRESOLVED: The meaning of the integer returned by UICleanupIterator (success flag, iterator identity, or status) is not established.
    // UNRESOLVED: The lifecycle relationship between this cleanup wrapper and its callers sub_4A00A0 and ResourceFileLoader is not analyzed here.
}
