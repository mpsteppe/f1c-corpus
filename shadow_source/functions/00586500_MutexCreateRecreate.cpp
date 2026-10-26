// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586500
// Canonical corpus name: MutexCreateRecreate
// Owner: MutexObject [DERIVED]
// Raw source: functions/MutexCreateRecreate_00586500.c

void MutexObject::MutexCreateRecreate()
{
    // Mutex wrapper method that conditionally closes a previously created mutex handle, then creates a new unnamed mutex via CreateMutexA and records validity. If the byte flag at this+0xC is set and CloseHandle succeeds, the handle at this+0x4 is cleared to 0. A fresh handle is always created with SECURITY_ATTRIBUTES (nLength=12, no descriptor, inherit=1) and stored at this+0x4; on success the flag at this+0xC is set to 1. The function returns the flag value.
    // GUARD: If byte flag at this+0xC is non-zero AND CloseHandle(handle at this+0x4) succeeds, the old mutex is considered closed. [field:this:0x0000000C, field:this:0x00000004, global:0x0059E1A8]
    // ASSIGNMENT: Conditionally clear the handle field at this+0x4 to 0 after the previous handle was closed. [field:this:0x00000004, field:this:0x0000000C]
    // ASSIGNMENT: Initialize stack SECURITY_ATTRIBUTES: nLength=12, lpSecurityDescriptor=0, bInheritHandle=1. [source:raw]
    // CALL: Call CreateMutexA with the SECURITY_ATTRIBUTES, initial owner 0 and name 0; store the returned handle in this+0x4. [global:0x0059E1AC, field:this:0x00000004]
    // ASSIGNMENT: If CreateMutexA returned a non-null handle, set the byte flag at this+0xC to 1. [global:0x0059E1AC, field:this:0x0000000C]
    // RETURN: Return the byte flag at this+0xC. [field:this:0x0000000C]

    // Conservative worker pseudocode:
    //   if (flag(this+0xC) && CloseHandle(handle(this+0x4)))
    //       handle(this+0x4) = 0;
    //   SECURITY_ATTRIBUTES sa = { nLength=12, lpSecurityDescriptor=0, bInheritHandle=1 };
    //   handle(this+0x4) = CreateMutexA(&sa, 0, 0);
    //   if (handle(this+0x4))
    //       flag(this+0xC) = 1;
    //   return flag(this+0xC);
    // UNRESOLVED: Global write refs byte_FF00000000005450, byte_FF00000000005451, byte_FF00000000005452 appear in the fact table as writes but are absent from the raw C; likely decompiler artifacts, purpose unknown.
    // UNRESOLVED: The owning class identity is DERIVED from the legacy ABI name and Win32 mutex usage; not confirmed by callers.
}
