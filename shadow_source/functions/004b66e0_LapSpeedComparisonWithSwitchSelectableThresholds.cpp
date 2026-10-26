// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B66E0
// Canonical corpus name: LapSpeedComparisonWithSwitchSelectableThresholds
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LapSpeedComparisonWithSwitchSelectableThresholds_004b66e0.c

void UnknownObject::LapSpeedComparisonWithSwitchSelectableThresholds()
{
    // Compares two floats (a2, a3) against difficulty-scaled thresholds selected by a switch on (this[0x9AC] - 1). Reads the selector field, dispatches through jump table jpt_4B66EC to choose a base tolerance, returns 1 immediately when |a2| is within it, then clamps |a3| into [2.0, 7.5] and dispatches a second scaled threshold through jpt_4B6755, returning |a2| <= scaled * clamped. Returns 0 when |a3| is below 2.0 or |a2| exceeds the scaled bound.
    // CALCULATION: Read the selector field this[619] (byte offset 0x9AC) and subtract 1 to form the switch index. [field:this:0x000009AC, source:raw]
    // CALCULATION: First switch (dispatched via jump table jpt_4B66EC) selects the base threshold v4: 0.045 for index 0, 0.022 for 1, 0.01 for 2, 0.007 for 3, default 0.066. [global:0x004B67AC, source:raw]
    // CALCULATION: Compute v5 = fabs(a2) and cache it into v9. [source:raw]
    // GUARD: Early accept: when |a2| <= base threshold v4, return 1. [source:raw]
    // CALCULATION: Compute v7 = fabs(a3). [source:raw]
    // GUARD: Clamp |a3| into [2.0, 7.5]: below 2.0 returns 0 immediately; above 7.5 is clamped to 7.5. [source:raw]
    // CALCULATION: Second switch (dispatched via jump table jpt_4B6755) selects the scaled threshold v8: 0.03 for index 0, 0.015 for 1, 0.008 for 2, 0.005 for 3, default 0.045. [global:0x004B67BC, source:raw]
    // RETURN: Return whether cached |a2| <= v8 * v7 (scaled threshold times the clamped |a3|). [source:raw]
    // CALL: Invoked by sub_4B6360 as part of the multi-stage alignment comparison. [caller:0x004B6360, source:raw]

    // Conservative worker pseudocode:
    //   bool LapSpeedComparisonWithSwitchSelectableThresholds(int this, float a2, float a3) {
    //     int idx = this[619] - 1;
    //     float base;
    //     switch (idx) {
    //       case 0: base = 0.045f; break;
    //       case 1: base = 0.022f; break;
    //       case 2: base = 0.01f; break;
    //       case 3: base = 0.007f; break;
    //       default: base = 0.066f; break;
    //     }
    //     float abs2 = fabs(a2);
    //     if (abs2 <= base) return true;
    //     float abs3 = fabs(a3);
    //     if (abs3 < 2.0f) return false;
    //     if (abs3 > 7.5f) abs3 = 7.5f;
    //     float scaled;
    //     switch (idx) {
    //       case 0: scaled = 0.03f; break;
    //       case 1: scaled = 0.015f; break;
    //       case 2: scaled = 0.008f; break;
    //       case 3: scaled = 0.005f; break;
    //       default: scaled = 0.045f; break;
    //     }
    //     return abs2 <= scaled * abs3;
    //   }
    // UNRESOLVED: The 11 flt_ float globals are recorded as read in the packet but do not appear in the decompiled body; they likely back the threshold literals or hold calibration constants, but the exact linkage is not established.
    // UNRESOLVED: The meaning of a2 and a3 (candidate speed/velocity differences) is caller-dependent; only the tolerance-comparison role is evidenced.
    // UNRESOLVED: The selector field this[0x9AC] is read as a difficulty/assist level index per the fill, but that semantic role is DERIVED, not confirmed.
}
