// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586560
// Canonical corpus name: MutexCreateReplaceWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexCreateReplaceWrapper_00586560.c

void UnknownObject::MutexCreateReplaceWrapper()
{
    // __thiscall on an unknown object: if the byte flag at this+0x5C is set and CloseHandle succeeds on the current handle at this+0x54, clears the handle to 0. Then builds a SECURITY_ATTRIBUTES (length 12, no descriptor, inheritable) and calls CreateMutexA to make an unnamed mutex, stores the new handle at this+0x54, sets the flag at this+0x5C to 1 when the handle is non-null, and returns the flag value. Called by sub_5837F0.
    // GUARD: Guard: if flag byte at this+0x5C is non-zero and CloseHandle on the handle at this+0x54 returns true, enter the close-and-clear branch. [field:this:0x0000005C, field:this:0x00000054, global:0x0059E1A8, source:raw]
    // ASSIGNMENT: Clear the mutex handle at this+0x54 to 0 after the previous handle was closed. [field:this:0x00000054, source:raw]
    // ASSIGNMENT: Initialize MutexAttributes: nLength=12, lpSecurityDescriptor=NULL, bInheritHandle=1. [source:raw]
    // CALL: Call CreateMutexA(&MutexAttributes, NULL, NULL) to create an unnamed mutex. [global:0x0059E1AC, source:raw]
    // ASSIGNMENT: Store the CreateMutexA result as the new handle at this+0x54. [field:this:0x00000054, global:0x0059E1AC, source:raw]
    // GUARD: Guard: if the new handle is non-null, set the flag byte at this+0x5C to 1. [field:this:0x0000005C, source:raw]
    // RETURN: Return the flag byte at this+0x5C as the mutex-valid indicator. [field:this:0x0000005C, source:raw]

    // Conservative worker pseudocode:
    //   char __thiscall sub_586560(void* this) {
    //     if (*(BYTE*)((char*)this + 0x5C) && CloseHandle(*(HANDLE*)((char*)this + 0x54)))
    //       *(DWORD*)((char*)this + 0x54) = 0;
    //     SECURITY_ATTRIBUTES sa = { 12, NULL, TRUE };
    //     HANDLE h = CreateMutexA(&sa, NULL, NULL);
    //     *(DWORD*)((char*)this + 0x54) = (DWORD)h;
    //     if (h) *(BYTE*)((char*)this + 0x5C) = 1;
    //     return *(BYTE*)((char*)this + 0x5C);
    //   }
    // UNRESOLVED: Enclosing object type unknown; owner is UNKNOWN and unproposed.
    // UNRESOLVED: The three byte globals byte_FF00000000005450..byte_FF00000000005452 are decompiler aliases of the byte-wise DWORD write to this+0x54; no independent global exists.
    // UNRESOLVED: Caller sub_5837F0 context is not in this packet, so the object's role and the reuse semantics of the mutex are not established.
}
