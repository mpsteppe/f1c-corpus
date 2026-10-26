// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597359
// Canonical corpus name: CodePointerValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CodePointerValidation_00597359.c

void UnknownObject::CodePointerValidation()
{
    // Trivial code-pointer validity check. Calls IsBadCodePtr on the passed FARPROC lpfn and returns its logical negation, so the caller receives TRUE when the code pointer is valid and readable. Invoked from two call sites (005939F9, 005972BD).
    // CALL: Invokes the Win32 IsBadCodePtr import (0x0059E07C) on the passed FARPROC lpfn to test whether the code pointer can be dereferenced [global:0x0059E07C, source:raw, abi:lead]
    // RETURN: Returns the Boolean negation of the IsBadCodePtr result, yielding TRUE when the pointer is valid [source:raw, function:0x00597359]
    // CALL: Called by sub_5939F9, one of the two validation call sites [caller:0x005939F9, source:raw]
    // CALL: Called by sub_5972BD, the second validation call site [caller:0x005972BD, source:raw]

    // Conservative worker pseudocode:
    //   return !IsBadCodePtr(lpfn);
}
