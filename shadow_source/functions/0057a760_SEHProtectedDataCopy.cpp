// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A760
// Canonical corpus name: SEHProtectedDataCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SEHProtectedDataCopy_0057a760.c

void UnknownObject::SEHProtectedDataCopy()
{
    // SEH-protected, bounded data copy with a validation gate. Reads the context value at this+0, initializes the SEH state buffer, and only when sub_5853B0(v6, v10) validates does it copy bounded data from *a3 into a2 via BoundedMemoryCopyWithSizeValidation, storing the resulting size into *a3 and a state dword (v10[1]) into *a4, returning 0. On validation failure it skips the copy and returns 11.
    // CALL: Initialize the SEH-protected stack state buffer v10 via SEHProtectedDirectXRenderStateSetup; the exception scope is tied to the dispatch table at 0x0059C778. [callee:0x00586700, global:0x0059C778]
    // ASSIGNMENT: v6 = *this: read the ULONG_PTR context value at this+0 that is handed to the validator. [field:this:0x00000000]
    // GUARD: Gate the copy on sub_5853B0(v6, v10) returning non-zero; a zero return blocks the copy. [callee:0x005853B0, field:this:0x00000000]
    // CALL: BoundedMemoryCopyWithSizeValidation(a2, *a3, &v9): copy bounded data from source *a3 into destination a2, recording the resulting size into v9. [callee:0x00586A10]
    // ASSIGNMENT: On the validated path store the state dword v10[1] into *a4 and the resulting size v9 into *a3; set the success flag v5 = 0. [source:raw]
    // CALL: Finalize the SEH scope via SEHGuardedFunctionWithExceptionHandling(v10). [callee:0x005867B0]
    // RETURN: Return v5: 0 on the validated-copy path, 11 on the validation-failed path. [source:raw]

    // Conservative worker pseudocode:
    //   int SEHProtectedDataCopy(ULONG_PTR *this, int a2, _DWORD *a3, _DWORD *a4) {
    //     int v5 = 11;
    //     int v9;
    //     int v10[21];
    //     SEHProtectedDirectXRenderStateSetup(v10);
    //     ULONG_PTR v6 = *this;
    //     if ((unsigned char)sub_5853B0(v6, (int)v10)) {
    //       v9 = 0;
    //       BoundedMemoryCopyWithSizeValidation(a2, *a3, &v9);
    //       *a4 = v10[1];
    //       *a3 = v9;
    //       v5 = 0;
    //     }
    //     SEHGuardedFunctionWithExceptionHandling(v10);
    //     return v5;
    //   }
    // UNRESOLVED: What sub_5853B0 actually validates (the state context read from this+0) is unproven; the packet gives it no name or contract.
    // UNRESOLVED: The meaning of the state dword stored into *a4 (v10[1]) is caller-dependent.
    // UNRESOLVED: Return code 11 is not grounded as a named error/status constant beyond its literal use.
}
