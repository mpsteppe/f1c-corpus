// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463EF0
// Canonical corpus name: sub_463EF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_463EF0_00463ef0.c

void UnknownObject::SeasonChampionshipStateInit()
{
    // Mode-dependent session state reset. When the init flag at obj+0x1D0 is not 1, clears obj+0x3FC4 to 0. When the global init guard byte_7CE260 is clear and dword_7D0410 equals 5 (championship mode), clamps the player count into dword_7D0A44 from dword_7D0A4C/dword_7D0A50 and the vehicle count into dword_7D0990 from dword_7D0998/dword_7D099C; otherwise the state at obj+0x3FC4 is reset to 0. Called by Game_Setup.
    // GUARD: If the field at obj+0x1D0 is NOT equal to 1, reset the state field obj+0x3FC4 to 0. [abi:lead, function:0x00463EF0, source:raw, guard:0, field:obj:0x000001D0, field:obj:0x00003FC4]
    // GUARD: Mode-dependent setup is skipped entirely when the global init-guard byte_7CE260 is non-zero. [global:0x007CE260]
    // GUARD: Enter the configuration branch only when global dword_7D0410 equals 5 (championship mode). [global:0x007D0410]
    // CALCULATION: Clamp the player count: dword_7D0A44 is set to 0, then to dword_7D0A4C when that is positive, else to dword_7D0A50 when dword_7D0A4C is not positive and dword_7D0A50 is negative. [global:0x007D0A44, global:0x007D0A4C, global:0x007D0A50]
    // CALCULATION: Clamp the vehicle count: dword_7D0990 is set to 0, then to dword_7D0998 when that is positive, else to dword_7D099C when dword_7D0998 is not positive and dword_7D099C is negative. [global:0x007D0990, global:0x007D0998, global:0x007D099C]
    // ASSIGNMENT: Else branch (mode not 5): reset the state field obj+0x3FC4 to 0. [field:obj:0x00003FC4, field:this:0x00000000]
    // RETURN: Return the object pointer read from this[0] (or the last clamp source value assigned to result). [field:this:0x00000000]

    // Conservative worker pseudocode:
    //   obj = this[0];
    //   if (*(obj + 0x1D0) != 1): *(obj + 0x3FC4) = 0;
    //   if (!byte_7CE260):
    //       if (dword_7D0410 == 5):
    //           dword_7D0A44 = 0;
    //           dword_7D0A44 = (dword_7D0A4C > 0) ? dword_7D0A4C : (dword_7D0A50 < 0 ? dword_7D0A50 : 0);
    //           dword_7D0990 = 0;
    //           dword_7D0990 = (dword_7D0998 > 0) ? dword_7D0998 : (dword_7D099C < 0 ? dword_7D099C : 0);
    //       else: *(obj + 0x3FC4) = 0;
    // UNRESOLVED: The ABI label 'Season_Championship_State_Init' is LEGACY and the actual object type behind this[0] is unnamed; owner stays UNKNOWN.
    // UNRESOLVED: Clamp semantics (which branch is the positive-pick and which the negative-pick) mirror the decompiled comparison structure exactly but their meaning as counts is DERIVED from context, not proven.
}
