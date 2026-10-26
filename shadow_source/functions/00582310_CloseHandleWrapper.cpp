// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00582310
// Canonical corpus name: CloseHandleWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CloseHandleWrapper_00582310.c

void UnknownObject::CloseHandleWrapper()
{
    // Conditional handle-close helper on an owning object: reads a byte flag at this+0x18 and, when non-zero, calls CloseHandle on the handle field at this+0x10; on success the handle field is zeroed. Returns the CloseHandle result (or the flag value when skipped). Called by sub_57BCE0 and sub_583AE0.
    // GUARD: Read the byte flag v2 at this+0x18; when it is zero the handle is not closed and the flag value is returned. [field:this:0x00000018, source:raw]
    // CALL: Call CloseHandle(*(this+0x10)) through the imported CloseHandle pointer at 0x0059E1A8 when the flag is set. [field:this:0x00000010, global:0x0059E1A8, source:raw]
    // ASSIGNMENT: On CloseHandle success (non-zero return), zero the handle field at this+0x10. [field:this:0x00000010, source:raw]
    // RETURN: Return v2: the CloseHandle result when the close was attempted, otherwise the value of the flag at this+0x18. [source:raw]
    // CALL: Invoked by sub_57BCE0 (0x0057BCE0) and sub_583AE0 (0x00583AE0) to close an owned handle. [caller:0x0057BCE0, caller:0x00583AE0, source:raw]

    // Conservative worker pseudocode:
    //   char sub_582310(int this) {
    //     int v2;
    //     v2 = *(BYTE*)(this + 24);
    //     if (v2) {
    //       v2 = CloseHandle(*(HANDLE*)(this + 16));
    //       if (v2) *(DWORD*)(this + 16) = 0;
    //     }
    //     return v2;
    //   }
    // UNRESOLVED: Identity of the owning object and the meaning of the flag at this+0x18 are unknown; the flag may indicate handle ownership.
    // UNRESOLVED: CloseHandle is an imported API resolved through the global pointer at 0x0059E1A8 rather than a direct call target.
}
