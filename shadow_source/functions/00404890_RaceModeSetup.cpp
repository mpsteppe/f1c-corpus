// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404890
// Canonical corpus name: RaceModeSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaceModeSetup_00404890.c

void UnknownObject::RaceModeSetup()
{
    // Session race-mode transition setup. Always calls PathStringUtility on the session object first, then branches on the session-mode field at this+0x20. Race-mode path (==1): saves the previous scoring-enable flag (dword_7D2E44) into this+0x50 and the previous race-mode value (dword_7D0410) into this+0x54, forces dword_7D2E44 to 1 and dword_7D0410 to 2, applies timeout-override clamping from dword_7D0418/dword_7D041C back into dword_7D0410, sets a session transition global flag via SetGlobalFlag, runs ShortComputation_d360(1, 15), and computes a float scale into flt_7D0798 by defaulting to 0.050000001 then preferring flt_7D07A0 or dword_7D07A4 when they are not below the same threshold; both paths finally set the byte/word flag at this+0x14 to 1, and the non-race path additionally zeroes this+0x15.
    // CALL: PathStringUtility invoked unconditionally on the session object as the first step [callee:0x00404850, source:raw]
    // GUARD: Race-mode full setup only when the dword mode field at this+0x20 equals 1 [guard:0, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Saves the previous scoring-enable flag: writes dword_7D2E44 into this+0x50, then sets dword_7D2E44 to 1 [field:this:0x00000050, global:0x007D2E44, source:raw]
    // ASSIGNMENT: Saves the previous race mode: writes dword_7D0410 into this+0x54, then sets dword_7D0410 to 2 [field:this:0x00000054, global:0x007D0410, source:raw]
    // ASSIGNMENT: Timeout-override clamp on dword_7D0410: when dword_7D0418 is at most 2 it becomes dword_7D041C if that is below 2, otherwise dword_7D0418; when dword_7D0418 is above 2 it becomes dword_7D0418 [global:0x007D0418, global:0x007D041C, global:0x007D0410, source:raw]
    // CALL: SetGlobalFlag raised on the session-transition flag global unk_7CE24D [callee:0x004A0D90, global:0x007CE24D, source:raw]
    // CALL: ShortComputation_d360 invoked with literal arguments 1 and 15 [callee:0x0040D360, source:raw]
    // ASSIGNMENT: Scaling factor defaulted to 0.050000001 into flt_7D0798, then overridden to flt_7D07A0 when that exceeds the threshold [global:0x007D0798, global:0x007D07A0, source:raw]
    // ASSIGNMENT: When flt_7D07A0 is not above the threshold and the float stored in dword_7D07A4 is below 0.050000001, flt_7D0798 is set to that float; otherwise the word flag at this+0x14 is set to 1 [global:0x007D07A4, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Activation flag: word-write of 1 to this+0x14 at the end of the race-mode path [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Non-race path sets the byte at this+0x14 to 1 and the byte at this+0x15 to 0 [field:this:0x00000014, field:this:0x00000015, source:raw]
    // CALL: Invoked by the session setup driver sub_404B60 [caller:0x00404B60, source:raw]

    // Conservative worker pseudocode:
    //   PathStringUtility(this);
    //   if (*(dword*)(this + 0x20) == 1) {
    //     *(dword*)(this + 0x50) = dword_7D2E44; dword_7D2E44 = 1;
    //     *(dword*)(this + 0x54) = dword_7D0410; dword_7D0410 = 2;
    //     if (dword_7D0418 <= 2) {
    //       if (dword_7D041C < 2) dword_7D0410 = dword_7D041C;
    //     } else { dword_7D0410 = dword_7D0418; }
    //     SetGlobalFlag(&unk_7CE24D);
    //     ShortComputation_d360(1, 15);
    //     flt_7D0798 = 0.050000001;
    //     if (flt_7D07A0 > 0.050000001) { flt_7D0798 = flt_7D07A0; }
    //     else if (*(float*)&dword_7D07A4 >= 0.050000001) { }
    //     else { *(float*)&flt_7D0798 = *(float*)&dword_7D07A4; }
    //     *(word*)(this + 0x14) = 1;
    //   } else {
    //     *(byte*)(this + 0x14) = 1;
    //     *(byte*)(this + 0x15) = 0;
    //   }
    // UNRESOLVED: flt_59E448 and dword_5EA510 appear in packet facts but nowhere in the raw decompiled source
    // UNRESOLVED: The exact semantics of the float scaling (flt_7D0798/flt_7D07A0/dword_7D07A4 against 0.050000001) are not established from this packet alone
    // UNRESOLVED: dword_7D0410 carries both race-mode and championship-mode labels in prior analysis; the packet cannot confirm which semantic applies
}
