// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A44C
// Canonical corpus name: ConditionalCallbackWithNullCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalCallbackWithNullCheck_0059a44c.c

void UnknownObject::ConditionalCallbackWithNullCheck()
{
    // Close a stored file handle with status reporting. If the handle field this[20] (byte offset 0x50) is null, or the close call succeeds, return null (success). Otherwise report an error through ObjectInitWithBufferDataPointerAssignment(0, 2) and return this to signal failure. Structurally identical to sub_599495 except for the error-reporting helper used.
    // GUARD: Guard on the stored file handle this[20] (byte offset 0x50, read): a null handle short-circuits to the success path without calling the closer. [field:this:0x00000050]
    // CALL: Close the file handle by calling FileCloseWithLock(this[20]); the return value contributes to the guard that decides success versus error reporting. [callee:0x00587D02]
    // RETURN: Success path: when the handle is null or the close call succeeds, return 0. [source:raw]
    // CALL: Failure path: report the error by calling ObjectInitWithBufferDataPointerAssignment with arguments (0, 2). [callee:0x0059A473]
    // RETURN: Failure path: return this (non-null) so callers can detect that closing failed. [source:raw]

    // Conservative worker pseudocode:
    //   int *sub_59A44C(int *this) {
    //     if (!this[20] || FileCloseWithLock(this[20]))
    //       return 0;
    //     ObjectInitWithBufferDataPointerAssignment(0, 2);
    //     return this;
    //   }
    // UNRESOLVED: What error state ObjectInitWithBufferDataPointerAssignment(0, 2) raises (exception, error flag, or other) is not established here.
    // UNRESOLVED: The meaning of the literal 2 argument to ObjectInitWithBufferDataPointerAssignment is unresolved.
    // UNRESOLVED: Whether the returned non-null pointer is itself consumed as an error object or merely used as a boolean is unresolved.
}
