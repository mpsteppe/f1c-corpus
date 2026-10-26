// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0CB0
// Canonical corpus name: sub_4A0CB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0CB0_004a0cb0.c

void UnknownObject::RestartMenuModeGuard()
{
    // Conditionally invokes SessionMenuModeSwitch after a session restart. Requires the qualifying-DSQ flag and the HUD-disable flag to be clear, the session-mode identifier to be unset (-1), and the player vehicle field at offset 16484 to equal 1; otherwise does nothing and always returns 0.
    // GUARD: Qualifying DSQ flag dword_7CE814 must equal 0 (feature disabled) before proceeding. [global:0x007CE814]
    // GUARD: HUD-disable flag byte_7CE254 must equal 0 (HUD enabled) before proceeding. [global:0x007CE254]
    // GUARD: Session-mode identifier dword_8AD298 must equal -1 (unset) before proceeding. [global:0x008AD298]
    // GUARD: Player vehicle reached through pointer dword_7C54E8 must have the dword at offset 16484 equal to 1 before proceeding. [global:0x007C54E8]
    // CALL: When all four guards pass, call SessionMenuModeSwitch to transition the session into post-race menu mode. [callee:0x004A0C60]
    // RETURN: Return 0 in every path, whether or not SessionMenuModeSwitch was invoked. [source:raw, function:0x004A0CB0]

    // Conservative worker pseudocode:
    //   if (dword_7CE814 == 0 && byte_7CE254 == 0 && dword_8AD298 == -1 && *(_DWORD *)(dword_7C54E8 + 16484) == 1)
    //       SessionMenuModeSwitch();
    //   return 0;
    // UNRESOLVED: Identity and meaning of the player-vehicle field at offset 16484 is not evidenced; only the equality-to-1 check is observed.
    // UNRESOLVED: Purpose of the exact guard combination (DSQ disabled, HUD enabled, session mode unset, player field == 1) is not explained by packet evidence.
    // UNRESOLVED: Function name is reused from existing analysis (RestartMenuModeGuard); it is a semantic label, not recovered original source text.
}
