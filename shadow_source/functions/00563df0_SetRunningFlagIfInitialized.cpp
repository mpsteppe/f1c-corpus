// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563DF0
// Canonical corpus name: SetFlagIfPointerNonNull
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetFlagIfPointerNonNull_00563df0.c

void UnknownObject::SetRunningFlagIfInitialized()
{
    // Conditionally raises an activity flag: if the pointer stored at this+0x0 is non-null, writes 1 to the flag at this+0x74 (this[29]); otherwise does nothing. Always returns 0.
    // GUARD: Test the pointer stored at this+0x0; the flag write happens only when it is non-null. [field:this:0x00000000]
    // ASSIGNMENT: Write 1 to the flag field at this+0x74 (this[29]) when the this+0x0 pointer is non-null. [field:this:0x00000074]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_563DF0(_DWORD* this) {
    //     if (this[0])
    //       this[29] = 1;
    //     return 0;
    //   }
    // UNRESOLVED: The object at this+0x0 is a sub-object pointer whose non-null state is read as the initialization signal; its exact type is unknown.
    // UNRESOLVED: The flag at this+0x74 is read as running/active based only on the caller StartNetworkUpdate; no write-back of the flag is observed here.
    // UNRESOLVED: The function always returns 0; the meaning of that return value to its callers is not established.
}
