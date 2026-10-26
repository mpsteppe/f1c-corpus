// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0490
// Canonical corpus name: sub_4A0490
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0490_004a0490.c

void UnknownObject::SessionScoringCleanupAndReset()
{
    // Session-level scoring and state cleanup. Sets the session init state for server mode (session type 5), dispatches a per-mode handler (profile icon/name string loading for mode 4, a computation on the game module manager for mode 5, mode fallback clamping for mode 6), resets the sound interface via an indirect vtable call, reinitializes a float buffer, resets season scoring, and finally dispatches the main menu. Returns 0.
    // GUARD: Guard: when dword_7C569C (session type) equals 5, enter the server-mode init block. [global:0x007C569C, source:raw]
    // ASSIGNMENT: Set dword_5CC9E8 to 3 (session init state) inside the server-mode block. [global:0x005CC9E8, global:0x007C569C]
    // CALL: Call sub_42D210 with the address of dword_7C569C and argument 0 to complete the server-mode init sequence. [callee:0x0042D210, global:0x007C569C]
    // GUARD: Switch on dword_7D0410 (race/championship mode) selecting the per-mode handler. [global:0x007D0410]
    // CALL: Mode 4: call sub_4B0770 with argument 0. [callee:0x004B0770]
    // ASSIGNMENT: Mode 4: pick the string source v0 = dword_7CE630 when non-null, else the default byte_5EA438. [global:0x007CE630, global:0x005EA438]
    // GUARD: Mode 4: only proceed when the selected string is non-empty (*v0). [source:raw]
    // CALL: Mode 4: resolve the string pair v1 = ConditionalDispatch_40b0(v0). [callee:0x004C40B0]
    // GUARD: Mode 4: only copy strings when the resolved pair v1 is non-null. [source:raw]
    // CALL: Mode 4: copy the first string of the pair (or default byte_5EA438 when empty) with StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005EA438]
    // CALL: Mode 4: copy the second string at pair index 47 (v2 + 47) with StringCopyWithBufferRealloc. [callee:0x00566650]
    // CALL: Mode 5: call ShortComputation_3140 with dword_7CD25C (game module manager pointer). [callee:0x00463140, global:0x007CD25C]
    // STATE_TRANSITION: Mode 6: fallback clamp. Set dword_7D0410 to 1; if dword_7D0418 is at most 1 then, when dword_7D041C is below 1, set dword_7D0410 to dword_7D041C; otherwise set dword_7D0410 to dword_7D0418. [global:0x007D0410, global:0x007D0418, global:0x007D041C]
    // GUARD: Guard: only invoke the sound/engine interface when dword_5EB10C is non-null. [global:0x005EB10C]
    // CALL: Indirect __thiscall through the vtable of dword_5EB10C at entry offset +12 (vtable index 3), passing dword_5EB10C as this. [global:0x005EB10C, source:raw]
    // CALL: Call BufferInitWith10fDefaults with flt_5EA618 to reinitialize the float buffer. [callee:0x004186A0, global:0x005EA618]
    // CALL: Call SeasonScoringReset with no arguments. [callee:0x0042BD60]
    // CALL: Call LookupDispatch with dword_7CD8C0 (dispatch interface), aMainMenu string, and -1. [callee:0x00497940, global:0x007CD8C0, global:0x005BE708]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A0490() {
    //     if (dword_7C569C == 5) {
    //       dword_5CC9E8 = 3;
    //       sub_42D210(&dword_7C569C, 0);
    //     }
    //     switch (dword_7D0410) {
    //     case 4:
    //       sub_4B0770(0);
    //       path = dword_7CE630 ? (char*)dword_7CE630 : byte_5EA438;
    //       if (*path) {
    //         pair = (char**)ConditionalDispatch_40b0(path);
    //         if (pair) {
    //           first = *pair ? *pair : byte_5EA438;
    //           StringCopyWithBufferRealloc(first);
    //           StringCopyWithBufferRealloc(pair + 47);
    //         }
    //       }
    //       break;
    //     case 5:
    //       ShortComputation_3140(dword_7CD25C);
    //       break;
    //     case 6:
    //       dword_7D0410 = 1;
    //       if (dword_7D0418 <= 1) {
    //         if (dword_7D041C < 1)
    //           dword_7D0410 = dword_7D041C;
    //       } else {
    //         dword_7D0410 = dword_7D0418;
    //       }
    //       break;
    //     }
    //     if (dword_5EB10C)
    //       (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
    //     BufferInitWith10fDefaults(flt_5EA618);
    //     SeasonScoringReset();
    //     LookupDispatch((_DWORD *)dword_7CD8C0, aMainMenu, -1);
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the dword_7D0410 mode values 4/5/6 and the exact fallback rule in case 6 are not grounded beyond the raw source.
    // UNRESOLVED: Identity and layout of the pair returned by ConditionalDispatch_40b0 and the meaning of the two copied strings (index 0 and index 47) are unknown; likely profile-related display strings.
    // UNRESOLVED: Purpose of sub_42D210(&dword_7C569C, 0) and of the dword_5CC9E8 = 3 assignment in the server-mode init block is unknown.
    // UNRESOLVED: What the indirect vtable call on dword_5EB10C at offset +12 resets (existing analysis suggests the sound system) is DERIVED, not confirmed.
    // UNRESOLVED: Globals unk_5EC6D0, byte_7CE498, dword_7CE64C, dword_7CE668 and unk_8AC388 are present in packet evidence but are not referenced by the raw source of this function.
    // UNRESOLVED: Caller SessionScoringUpdate (0x004643C0) is recorded but its call context is not part of this packet.
}
