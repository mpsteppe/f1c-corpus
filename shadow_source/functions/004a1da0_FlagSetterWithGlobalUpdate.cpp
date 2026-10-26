// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1DA0
// Canonical corpus name: FlagSetterWithGlobalUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagSetterWithGlobalUpdate_004a1da0.c

void UnknownObject::FlagSetterWithGlobalUpdate()
{
    // Flag setter with global synchronization: writes the byte flag a3 into the object at offset +0x10, derives result as a1 (object pointer) when a3 is non-zero or NULL when zero, stores that into the global dword_7CE2E8, and returns it. Argument a2 is unused. Called from PlayerOptionsInitializer (004aa270).
    // ASSIGNMENT: Write the caller-supplied byte flag a3 into the field at offset +0x10. [field:this:0x00000010]
    // CALCULATION: result = (a3 != 0) ? a1 : 0: mirror the flag into an object pointer or NULL. [source:raw]
    // ASSIGNMENT: Synchronize the global dword_7CE2E8 with the derived result. [global:0x007CE2E8]
    // RETURN: Return the derived result (object pointer when a3 non-zero, else NULL). [source:raw]

    // Conservative worker pseudocode:
    //   int FlagSetterWithGlobalUpdate(int obj, int unused, char flag) {
    //     *(BYTE*)(obj + 16) = flag;
    //     int result = flag ? obj : 0;
    //     dword_7CE2E8 = result;
    //     return result;
    //   }
    // UNRESOLVED: Argument a2 appears in the signature but is never read in the raw source; purpose unknown.
    // UNRESOLVED: The byte field at +0x10 and the meaning of the synchronized global dword_7CE2E8 are not evidenced beyond the write itself; the global also gates LinkedListAppend_1dc0 in ShortComputation_1b70 (004a1b70).
}
