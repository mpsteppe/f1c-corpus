// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455DA0
// Canonical corpus name: HWInput_Restart
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HWInput_Restart_00455da0.c

void UnknownObject::HWInput_Restart()
{
    // Restart routine for the HWInput object. Conditionally logs an entry when the session type dword_7C569C is not 5 and StringSplitLoop(2, aDDevF119992002_13, 5269) returns nonzero; sets up the frustum viewport at this+0xCBC from screen dimensions dword_5D6D60/dword_5D6D64; initializes a BVH tree-node array at this+4; optionally re-initializes the audio subsystem at this+0x1580 when dword_7D1FFC is nonzero; clears the active flag byte at this+0x2428; then scans the device array at this+0x1F98 (11-DWORD stride) for an entry whose second DWORD differs from 89, and if found sets the active flag byte at this+0x2428 to 1. Invoked by Game_Restart (0042D7A0).
    // GUARD: If dword_7C569C != 5 and StringSplitLoop(2, aDDevF119992002_13, 5269) returns nonzero, proceed to write the debug log entry [global:0x007C569C, callee:0x004D7A50, global:0x005C56A4, source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, aEnteredHwinput_2) writes the debug entry when the logging guard passes [callee:0x004D7AA0, global:0x008AD25C, global:0x005C5700, source:raw]
    // CALL: FrustumViewportSetup((float *)(this + 3260), 0, 0, dword_5D6D60, dword_5D6D64) sets up the viewport at this+0xCBC from the screen width/height globals [callee:0x0044F680, global:0x005D6D60, global:0x005D6D64, source:raw]
    // CALL: BVHTreeNodeArrayInit((_DWORD *)(this + 4)) initializes the tree-node array at this+4 [callee:0x0044F0A0, source:raw]
    // GUARD: If dword_7D1FFC is nonzero, sub_44FF50((int *)(this + 5504)) re-initializes the audio subsystem at this+0x1580 [global:0x007D1FFC, callee:0x0044FF50, source:raw]
    // ASSIGNMENT: *(_BYTE *)(this + 9256) = 0, clearing the active flag byte at this+0x2428 before scanning [field:this:0x00002428, source:raw]
    // LOOP: Scan the device array at this+0x1F98 with 11-DWORD stride: while !*result and result[1] == 89, advance result by 11 DWORDs and increment v2; if v2 exceeds 0x21 (33) return the current result pointer without setting the active flag [field:this:0x00001F98, field:this:0x00001F9C, guard:0, source:raw]
    // STATE_TRANSITION: If the loop exits with an entry found (non-zero first DWORD or second DWORD != 89), set *( _BYTE *)(this + 9256) = 1, marking the active flag at this+0x2428 [field:this:0x00002428, source:raw]
    // RETURN: Return result, the pointer at which the scan stopped (either the early-return array position or the found entry) [function:0x00455DA0, source:raw]
    // CALL: Invoked by Game_Restart (0042D7A0) [caller:0x0042D7A0]

    // Conservative worker pseudocode:
    //   if (dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(2, aDDevF119992002_13, 5269))
    //     DebugLogWrite(&dword_8AD25C, aEnteredHwinput_2);
    //   FrustumViewportSetup((float *)(this + 3260), 0, 0, dword_5D6D60, dword_5D6D64);
    //   BVHTreeNodeArrayInit((_DWORD *)(this + 4));
    //   if (dword_7D1FFC) sub_44FF50((int *)(this + 5504));
    //   *(_BYTE *)(this + 9256) = 0;
    //   v2 = 26;
    //   result = (_DWORD *)(this + 8088);
    //   while (!*result && result[1] == 89) {
    //     ++v2;
    //     result += 11;
    //     if (v2 > 0x21) return result;
    //   }
    //   *(_BYTE *)(this + 9256) = 1;
    //   return result;
    // UNRESOLVED: Semantics of the device-array scan guard (second DWORD == 89) and the array entry layout (11 DWORDs) are inferred from the fill analysis, not proven by an external contract
    // UNRESOLVED: The sub_44FF50 target at this+0x1580 is labelled audio re-initialization by the fill only; the exact subsystem is unverified
    // UNRESOLVED: StringSplitLoop return semantics and literal 5269 (0x1495) purpose are undocumented
    // UNRESOLVED: The active-flag early return path (v2 > 0x21) leaves the flag cleared; the meaning of that outcome is not documented
}
