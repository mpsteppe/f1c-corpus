// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BA30
// Canonical corpus name: sub_49BA30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49BA30_0049ba30.c

void UnknownObject::SessionModeGuardCheck()
{
    // Guard-style boolean predicate: reads the dword at the object referenced by global dword_7C54E0 plus offset 13392, then returns true only when that value is greater than 0 and less than or equal to 3 (i.e. in the range 1..3); otherwise returns false.
    // CALCULATION: Read the dword value at dword_7C54E0 plus offset 13392 (object pointed to by the global, member at offset 13392). [global:0x007C54E0, source:raw]
    // GUARD: Test whether the read value is greater than 0. [global:0x007C54E0, source:raw]
    // GUARD: When the value is greater than 0, additionally test whether it is less than or equal to 3. [global:0x007C54E0, source:raw]
    // RETURN: Return true when the value is in the range 1..3, false otherwise (false is the initial result when the first guard fails). [global:0x007C54E0, source:raw]

    // Conservative worker pseudocode:
    //   BOOL sessionModeGuardCheck() {
    //     int v0 = *(_DWORD*)(dword_7C54E0 + 13392);
    //     return v0 > 0 && v0 <= 3;
    //   }
    // UNRESOLVED: The object referenced by global dword_7C54E0 and the meaning of the dword member at offset 13392 are unidentified; the packet supplies no field evidence ref for that offset.
    // UNRESOLVED: The semantics of the 1..3 value range (e.g. a session-mode enum) are not confirmed, despite the legacy ABI hint 'Session_Mode_Guard_Check'.
    // UNRESOLVED: The caller-specific purpose (HUDFlagRendererMain, UIMessageCompose, sub_49D4C0) is not established.
}
