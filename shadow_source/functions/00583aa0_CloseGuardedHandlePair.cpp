// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583AA0
// Canonical corpus name: CloseHandlePairWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CloseHandlePairWrapper_00583aa0.c

void UnknownObject::CloseGuardedHandlePair()
{
    // Closes two kernel handles guarded by per-handle validity flags. First: if flag at this+0x24 is non-zero and CloseHandle on the handle at this+0x1C succeeds, clear the handle field to 0. Second: if flag at this+0x14 is non-zero and CloseHandle on the handle at this+0xC succeeds, clear that handle field to 0. Returns the result of the second CloseHandle attempt.
    // GUARD: First handle is only closed when the validity flag at this+0x24 is non-zero. [field:this:0x00000024]
    // CALL: Call CloseHandle (imported via global at 0x0059E1A8) on the first handle at this+0x1C; the returned success value gates the field clear. [global:0x0059E1A8, field:this:0x0000001C]
    // ASSIGNMENT: Clear the first handle field at this+0x1C to 0 when the CloseHandle call succeeds. [field:this:0x0000001C]
    // GUARD: Second handle is only closed when the validity flag at this+0x14 is non-zero. [field:this:0x00000014]
    // CALL: Call CloseHandle (imported via global at 0x0059E1A8) on the second handle at this+0xC; the returned success value gates the field clear. [global:0x0059E1A8, field:this:0x0000000C]
    // ASSIGNMENT: Clear the second handle field at this+0xC to 0 when the CloseHandle call succeeds. [field:this:0x0000000C]
    // RETURN: Return the result of the second CloseHandle attempt (or the flag value when the second close is skipped). [function:0x00583AA0, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   if (*(uint8_t*)this + 0x24 && CloseHandle(*(HANDLE*)(this + 0x1C)))
    //       *(uint32_t*)(this + 0x1C) = 0;
    //   result = *(uint8_t*)(this + 0x14);
    //   if (result && CloseHandle(*(HANDLE*)(this + 0xC))) {
    //       *(uint32_t*)(this + 0xC) = 0;
    //       result = 1;
    //   }
    //   return result;
    // UNRESOLVED: The kernel object type the two handles refer to is unknown; the flag fields at this+0x14 and this+0x24 gate each close individually.
}
