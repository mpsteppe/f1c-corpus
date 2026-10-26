// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463C40
// Canonical corpus name: NullTerminatedStringLengthAt0x11c
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NullTerminatedStringLengthAt0x11c_00463c40.c

void UnknownObject::GetNonEmptyStringAt0x11c()
{
    // Getter: reads pointer field at this+0, returns pointer+0x11C (284) when the null-terminated string there is non-empty, otherwise returns NULL.
    // CALCULATION: Read the pointer field at this+0 and add 284 (0x11C) to form the string pointer. [field:this:0x00000000, source:raw]
    // CALL: Test the string for emptiness via strlen on the string at the computed pointer. [source:raw]
    // GUARD: Branch on the non-zero result of the string length test. [source:raw]
    // RETURN: Return the computed string pointer when non-empty, otherwise return 0. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   char *GetNonEmptyStringAt0x11c(void *this) {
    //       char *s = *(char **)this + 284;
    //       return strlen(s) ? s : 0;
    //   }
    // UNRESOLVED: Semantics of the object pointed to by this+0 and the string at +0x11C (284) are unknown.
    // UNRESOLVED: Caller sub_4B0B20's use of the returned pointer is unknown.
}
