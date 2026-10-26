// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB550
// Canonical corpus name: UILayoutDispatchWithDataPrep
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UILayoutDispatchWithDataPrep_004db550.c

void UnknownObject::UILayoutDispatchWithDataPrep()
{
    // HUD layout dispatcher: selects a speed-magnitude variant based on global byte_7D0474 (SpeedMagnitude when set, SpeedMagnitude_b950 otherwise), reads engine RPM via EngineRevValueAccessor, then dispatches to three HUD element renderers with the layout parameter a1 and per-element constants 20, 68 and 10: PositionOrderNameDisplay(rpm, a1, 20), UtilityFunction_b9a0(speed, a1, 68), and returns sub_4DB7F0(sub_49B7A0(&unk_7CE234), a1, 10).
    // GUARD: Guard on global byte_7D0474: when non-zero compute speed via SpeedMagnitude(), otherwise via SpeedMagnitude_b950(). [global:0x007D0474, callee:0x0049B900, callee:0x0049B950]
    // ASSIGNMENT: Store the selected double speed magnitude as float v5 for the HUD element call. [source:raw]
    // CALL: v2 = EngineRevValueAccessor() retrieves the current engine RPM value for display. [callee:0x0049B8F0]
    // CALL: PositionOrderNameDisplay(v2, a1, 20) renders the position/name HUD element at constant 20. [callee:0x004DB6F0, source:raw]
    // CALL: UtilityFunction_b9a0(v5, a1, 68) renders the speed-related HUD element at constant 68. [callee:0x004DB9A0]
    // CALL: v3 = sub_49B7A0(&unk_7CE234) processes global unk_7CE234 (driver appearance flag) into a value for the final element. [callee:0x0049B7A0, global:0x007CE234]
    // RETURN: Return sub_4DB7F0(v3, a1, 10), the final HUD element render at constant 10. [callee:0x004DB7F0]

    // Conservative worker pseudocode:
    //   int sub_4DB550(int a1) {
    //     double v1 = byte_7D0474 ? (double)SpeedMagnitude() : (double)SpeedMagnitude_b950();
    //     float v5 = (float)v1;
    //     int v2 = EngineRevValueAccessor();
    //     PositionOrderNameDisplay(v2, a1, 20);
    //     UtilityFunction_b9a0(v5, a1, 68);
    //     int v3 = sub_49B7A0(&unk_7CE234);
    //     return sub_4DB7F0(v3, a1, 10);
    //   }
    // UNRESOLVED: Semantics of the per-call constants 20, 68 and 10 (interpreted as HUD Y positions by existing analysis, but not proven).
    // UNRESOLVED: What global unk_7CE234 represents and what sub_49B7A0 computes from it.
    // UNRESOLVED: Purpose of global byte_7D0474 in selecting the speed-magnitude variant.
}
