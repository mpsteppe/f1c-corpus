// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0D30
// Canonical corpus name: GlobalStateSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateSetter_004a0d30.c

void UnknownObject::SetGlobalStateWithReset()
{
    // Global state setter (__stdcall, byte input a1). Captures a1 into result, and only when it differs from the current global byte_7CE254 writes the new value to byte_7CE254 and clears dword_7CE250 to 0. Always returns the requested state byte. Invoked by SessionScoringUpdate (0x004643C0), sub_4A0030 (0x004A0030), sub_4A00A0 (0x004A00A0), sub_4A0250 (0x004A0250) and SystemOSAPICall (0x004A03F0).
    // ASSIGNMENT: Capture the input byte a1 into result so the return value reports the requested state even when the state is unchanged. [source:raw]
    // GUARD: Guard on byte_7CE254 != a1; when the current global state already equals the requested byte, the update block is skipped. [global:0x007CE254, source:raw]
    // STATE_TRANSITION: Write a1 into byte_7CE254 to set the new global state value. [global:0x007CE254, source:raw]
    // ASSIGNMENT: Reset dword_7CE250 to 0 whenever the state value changes. [global:0x007CE250, source:raw]
    // CALL: State setter invoked by SessionScoringUpdate (0x004643C0), sub_4A0030 (0x004A0030), sub_4A00A0 (0x004A00A0), sub_4A0250 (0x004A0250) and SystemOSAPICall (0x004A03F0). [source:raw, caller:0x004643C0, caller:0x004A0030, caller:0x004A00A0, caller:0x004A0250, caller:0x004A03F0]
    // RETURN: Return result, the requested state byte. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4A0D30(char a1) {
    //     char result = a1;
    //     if (byte_7CE254 != a1) {
    //       byte_7CE254 = a1;
    //       dword_7CE250 = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The semantics of the byte_7CE254 state and the dword_7CE250 counter it resets are not documented in this function; callers suggest session/OSAPI context.
    // UNRESOLVED: Whether the write of a1 to byte_7CE254 is a full byte store or a masked flag update is not decidable from this function alone.
}
