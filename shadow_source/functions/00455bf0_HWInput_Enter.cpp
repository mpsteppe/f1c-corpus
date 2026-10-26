// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455BF0
// Canonical corpus name: HWInput_Enter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HWInput_Enter_00455bf0.c

void UnknownObject::HWInput_Enter()
{
    // HWInput game-state enter hook. Logs entry when the debug-log condition is met, performs cursor/timing setup via sub_44F4E0, hides the Windows cursor, registers input action bindings, and acquires the dual-source input device at this + 6928 when the render flag byte_7D13A0 equals 1. Called by Game_Enter. Returns 0.
    // GUARD: Debug-log guard: if StringSplitLoop(2, aDDevF119992002_13, 5205) is true, write the entry message DebugLogWrite(&dword_8AD25C, aEnteredHwinput). [callee:0x004D7A50, global:0x005C56A4, source:raw]
    // CALL: Write the 'entered HWInput' message to the debug log buffer dword_8AD25C. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C5688, source:raw]
    // CALL: Call sub_44F4E0, an unknown cursor/timing setup helper. [callee:0x0044F4E0, source:raw]
    // LOOP: Hide the cursor: repeatedly call ShowCursor(0) while its return value is >= 0. [global:0x0059E2C4, source:raw]
    // CALL: Register input action bindings: InputActionRegistration(). [callee:0x00455290, source:raw]
    // GUARD: If render flag byte_7D13A0 == 1, acquire the dual-source input device at this + 6928 via DualSourceAcquireWithFallback. [global:0x007D13A0, callee:0x004F8AE0, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_455BF0(char* this) {
    //     if (StringSplitLoop(2, aDDevF119992002_13, 5205)) DebugLogWrite(&dword_8AD25C, aEnteredHwinput);
    //     sub_44F4E0();
    //     while (ShowCursor(0) >= 0) { }
    //     InputActionRegistration();
    //     if (byte_7D13A0 == 1) DualSourceAcquireWithFallback(this + 6928);
    //     return 0;
    //   }
    // UNRESOLVED: Identity and purpose of sub_44F4E0 are unknown from this packet.
    // UNRESOLVED: StringSplitLoop is described as a debug-log enable check, but its exact condition semantics (constants 2 and 5205) are not defined here.
    // UNRESOLVED: Semantics of the ShowCursor(0) >= 0 busy loop (cursor hide counter) are inferred, not packet-stated.
}
