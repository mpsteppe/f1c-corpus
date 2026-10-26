// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004612E0
// Canonical corpus name: TrackOpeningProgressTimer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackOpeningProgressTimer_004612e0.c

void UnknownObject::updateTrackOpeningProgress()
{
    // Per-frame decay of a track-opening progress timer. The function is skipped when the session/phase dword at this+0x3FC4 equals 2 or 1, or when the timer float at this+0x2C is negative. When the timer equals 5.0 a one-time utility call UtilityFunction_e570(this, (float)dbl_8AFEA0) fires. A dev-only debug log writes the string aApplyingFrameT via DebugLogWrite when dword_7C569C != 5 and StringSplitLoop(2, aDDevF119992002_1, 4958) is true. The decrement delta dbl_8AFE90 is clamped into [0.0099999998, 0.5], then subtracted from the timer at this+0x2C. When the timer reaches zero or below, the byte flag at this+0x29 is set to 1 and -1082130432 is written into the timer field.
    // GUARD: Skip the whole update when the dword at this+0x3FC4 is 2 or 1, or when the timer float at this+0x2C is negative. [field:this:0x00003FC4, field:this:0x0000002C, source:raw]
    // CALL: When the timer float at this+0x2C equals 5.0, call UtilityFunction_e570(this, v4) passing dbl_8AFEA0 (global 0x008AFEA0) cast to float as the second argument. [callee:0x0045E570, global:0x008AFEA0, source:raw]
    // CALL: Dev/debug logging: if dword_7C569C != 5 and StringSplitLoop(2, aDDevF119992002_1, 4958) is true, write the string aApplyingFrameT through DebugLogWrite(&dword_8AD25C, aApplyingFrameT). [global:0x007C569C, callee:0x004D7A50, global:0x005C5CE4, global:0x005C6134, callee:0x004D7AA0, global:0x008AD25C, source:raw]
    // CALCULATION: Clamp the decrement delta v5 (initialized from dbl_8AFE90, global 0x008AFE90) into [0.0099999998, 0.5]. [global:0x008AFE90, source:raw]
    // ASSIGNMENT: Subtract the clamped delta from the opening-progress timer: timer (this+0x2C float) becomes timer - v5. [field:this:0x0000002C, source:raw]
    // STATE_TRANSITION: On timer expiry (new value <= 0.0): set the byte flag at this+0x29 to 1 and write -1082130432 into this+0x2C. [field:this:0x00000029, field:this:0x0000002C, source:raw]

    // Conservative worker pseudocode:
    //   v2 = *(this + 16324);
    //   if (v2 != 2 && v2 != 1 && *(float*)(this + 44) >= 0.0) {
    //     if (*(float*)(this + 44) == 5.0) UtilityFunction_e570(this, (float)dbl_8AFEA0);
    //     v5 = dbl_8AFE90;
    //     if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_1, 4958))
    //       DebugLogWrite(&dword_8AD25C, aApplyingFrameT);
    //     if (v5 < 0.0099999998) v5 = 0.0099999998;
    //     else if (v5 > 0.5) v5 = 0.5;
    //     v3 = *(float*)(this + 44) - v5;
    //     *(float*)(this + 44) = v3;
    //     if (v3 <= 0.0) {
    //       *(this + 41) = 1;
    //       *(this + 44) = -1082130432;
    //     }
    //   }
    // UNRESOLVED: The read-only globals flt_59E440, flt_59E444, flt_59E450 and flt_59F0B4 are listed as packet evidence but do not appear in the raw decompiled source of this function.
    // UNRESOLVED: The meaning of the byte flag at this+0x29 and of the expiry value -1082130432 stored into the timer float is not established by the packet; the field names come from skeleton prose only.
    // UNRESOLVED: The semantic role of the value dbl_8AFEA0 passed to UtilityFunction_e570 is unknown.
    // UNRESOLVED: The owner object is unknown; the function is invoked by SessionScoringUpdate (0x004643C0).
}
