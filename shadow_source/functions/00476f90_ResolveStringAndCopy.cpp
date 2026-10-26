// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476F90
// Canonical corpus name: SingleFunctionDispatch_6f90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionDispatch_6f90_00476f90.c

void UnknownObject::ResolveStringAndCopy()
{
    // Selects the string to copy: when the global guard dword_7D0398 is nonzero and dword_7D0410 is not 5, the incoming string pointer a1 is replaced with the global default path byte_5EA438; otherwise a1 is kept. The selected string is then passed to StringCopyWithBufferRealloc and its result is returned. Called from the frontend loading display handler and sub_4A0AF0.
    // GUARD: Guard: if dword_7D0398 is nonzero and dword_7D0410 is not equal to 5, replace the incoming string pointer a1 with the global default string byte_5EA438. [global:0x007D0398, global:0x007D0410, global:0x005EA438, source:raw]
    // CALL: Call StringCopyWithBufferRealloc on the selected string pointer (a1 or the substituted default) to produce the copied string. [source:raw, function:0x00476F90]
    // RETURN: Return the copied-string result produced by StringCopyWithBufferRealloc. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_476F90(char *a1) {
    //     if (dword_7D0398 && dword_7D0410 != 5)
    //       a1 = byte_5EA438;
    //     return StringCopyWithBufferRealloc(a1);
    //   }
    // UNRESOLVED: Semantics of the guard dword_7D0410 != 5 (mode selector) are unknown; the value 5 is an unexplained mode constant.
    // UNRESOLVED: byte_5EA438 is treated as a default string/path pointer but its exact contents are not established here.
    // UNRESOLVED: StringCopyWithBufferRealloc callee address is not present in the packet and is only referenced by name from the raw source.
    // UNRESOLVED: Why callers FrontendScreenLoadingDisplayHandler (0x00476250) and sub_4A0AF0 route through this dispatch is unresolved.
}
