// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551F80
// Canonical corpus name: ConditionalFreeWithBinkClose
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFreeWithBinkClose_00551f80.c

void UnknownObject::ConditionalFreeWithBinkClose()
{
    // Conditional cleanup wrapper for a Bink video object. When the object pointer a1 is non-null, closes the Bink video via BinkVideoClose, runs the empty stub, then frees the object via FreeWrapper_7bcf and returns the free result. On a null pointer the guard is skipped and the decompiled body returns the uninitialized result register.
    // GUARD: Guard on a1: the close/stub/free sequence only runs when the object pointer a1 is non-null. [function:0x00551F80, source:raw]
    // CALL: BinkVideoClose(a1): close the Bink video owned by a1; return value unused. [callee:0x00551CE0, source:raw]
    // CALL: EmptyStub_7470(a1): invoke the empty stub on a1 (no visible work in its own body); return value unused. [callee:0x00557470, source:raw]
    // RETURN: FreeWrapper_7bcf(a1): free the wrapper/object and return its result as the function value. Invoked from screen/sound/font resource loader and file-load paths (sub_48E0D0, UIScreenSoundResourceLoader, UtilityFunction_e360, FontResourceLoader, FileLoadWithRetryLoop). [callee:0x00587BCF, caller:0x0048E0D0, caller:0x0048E110, caller:0x0048E360, caller:0x0048E3A0, caller:0x004F9B70, function:0x00551F80, source:raw]
    // RETURN: Null path: when a1 is null the guard is skipped and the function returns the uninitialized result variable (decompiler artifact). [source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalFreeWithBinkClose(_DWORD *a1) {
    //     int result; // eax
    //     if (a1) {
    //       BinkVideoClose(a1);
    //       EmptyStub_7470(a1);
    //       return FreeWrapper_7bcf(a1);
    //     }
    //     return result; // uninitialized in decompilation
    //   }
    // UNRESOLVED: The null-branch 'return result' reads an uninitialized variable in the decompilation; effective behavior on null input is undefined in the raw source.
    // UNRESOLVED: EmptyStub_7470 performs no visible work; its purpose relative to the close/free sequence is unknown.
    // UNRESOLVED: The LEGACY ABI lead provides no owner identity or additional semantic signal.
}
