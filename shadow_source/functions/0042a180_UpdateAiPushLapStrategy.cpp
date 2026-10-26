// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042A180
// Canonical corpus name: AIPushLap
// Owner: AI_Push_Lap_Closing_Gap [DERIVED]
// Raw source: functions/AIPushLap_0042a180.c

void AI_Push_Lap_Closing_Gap::UpdateAiPushLapStrategy()
{
    // Per-frame AI qualifying strategy for the player's vehicle: when the car is on-track, adjusts the target lap time from grip and remaining laps (only outside session type 7), writes a performance scalar derived from track conditions, and when the call-to-box flag is clear selects a recommended tire compound against track-grip bands, forcing a pit exit on mismatch or when average tire wear drops below 0.89999998. Invoked from AIMainUpdate.
    // GUARD: Enter only while the vehicle is on-track: dereference the object pointer stored at this+0 and require the int at obj+0x32C8 (field obj 0x32C8) to equal 1. [guard:0, field:obj:0x000032C8, field:this:0x00000000, source:raw]
    // CALCULATION: Adjust the push-lap target time when session type (dword_7C56A4) is not 7: read the lap count at this+0x403C, cap the step at 10, sum track grip this+0x44F4 and remaining laps this+0x44D8; if that sum is at or above (step * 0.003) + this+0x453C, recompute the value as (step * 0.003) + this+0x453C; write the result to this+0x453C. [global:0x007C56A4, field:this:0x0000403C, field:this:0x000044D8, field:this:0x000044F4, field:this:0x0000453C, source:raw]
    // CALCULATION: Compute a performance scalar as 1.0 - flt_8AFEE8 * this+0x44C8, clamp it to a minimum of 0.5, and store it at this+0x4580. [global:0x008AFEE8, field:this:0x000044C8, field:this:0x00004580, source:raw]
    // GUARD: Proceed with tire strategy only while the call-to-box flag at this+0x454C is not equal to 1. [field:this:0x0000454C, source:raw]
    // GUARD: Pit-exit check on remaining tire life: read the tire-slot array entry this[4 * compound-id + 4452], where the compound id comes from this+0x45E0; if that value is not greater than the obj field at +16444, force a pit exit via ForcePitExit. [callee:0x0042A110, field:this:0x000045E0, field:this:0x0000403C, source:raw]
    // CALL: Resolve the currently equipped compound: read the tire name via TireNameAccessor(this+3) and map it to an id with TireCompoundNameIDMapping. [callee:0x004F1630, callee:0x004A4830, source:raw]
    // CALCULATION: Select the recommended compound against track-grip bands of flt_8AFEE8: below 0.0099999998 keep the stored next-chosen value (this+0x458C); below 0.33000001 prefer 4 but keep the stored value when it matches the equipped id and grip is below 0.2; at or above 0.66000003 prefer 6 unless the equipped id is 5; otherwise prefer 5. If the equipped id differs from the recommendation, force a pit exit with ForcePitExit. [global:0x008AFEE8, field:this:0x0000458C, callee:0x0042A110, source:raw]
    // GUARD: Tire-wear gate: average the four tire-wear values at this+0x363C, this+0x3734, this+0x382C and this+0x3924; when the mean is below 0.89999998, force a pit exit via ForcePitExit. [callee:0x0042A110, field:this:0x0000363C, field:this:0x00003734, field:this:0x0000382C, field:this:0x00003924, source:raw]
    // RETURN: Void per-frame strategy routine; called from AIMainUpdate while the car is on-track. [caller:0x00424E70, function:0x0042A180, source:raw]

    // Conservative worker pseudocode:
    //   if (*(*(int*)this + 0x32C8) != 1) return;
    //   if (session != 7) {
    //       step = min(this->lapCount, 10);
    //       target = this->trackGrip + this->remainingLaps;
    //       if (target >= step * 0.003 + this->targetLapTime) target = step * 0.003 + this->targetLapTime;
    //       this->targetLapTime = target;
    //   }
    //   scalar = 1.0 - grip * this->perfFactor; if (scalar < 0.5) scalar = 0.5; this->perfScalar = scalar;
    //   if (this->callToBox == 1) return;
    //   if (tireSlot[compoundId] <= obj + 0x403C) ForcePitExit(this);
    //   compound = TireCompoundNameIDMapping(TireNameAccessor(this + 3));
    //   if (grip < 0.01) choice = nextChosen;
    //   else if (grip < 0.33) { choice = 4; if (compound==5 && grip>0.2) skip; if (compound==nextChosen && grip<0.2) choice = nextChosen; }
    //   else if (grip >= 0.66) { choice = 6; if (compound != 5) eval_match; if (grip >= 0.9) pit_exit; }
    //   else { choice = 5; if (compound==4) { if (grip < 0.55) skip; pit_exit; } if (compound != 6) eval_match; if (grip <= 0.6) pit_exit; }
    //   eval_match: if (compound != choice && choice) pit_exit;
    //   if ((wear[0x3924] + wear[0x382C] + wear[0x3734] + wear[0x363C]) * 0.25 < 0.9) ForcePitExit(this);
    // UNRESOLVED: The eleven read-only float globals (flt_59E43C, flt_59E444, flt_59E450, flt_59E4E8, flt_59E7E8, flt_59E7F8, flt_59E824, flt_59E970, flt_59E974, flt_59E978, flt_59E97C) are listed as referenced but do not appear directly in the decompiled body; they are likely the threshold constants (0.003, 0.5, 0.0099999998, 0.2, 0.33000001, 0.55000001, 0.60000002, 0.66000003, 0.89999998, 0.9, 1.0) forwarded into the comparisons, but the exact mapping is unconfirmed.
    // UNRESOLVED: The tire-slot array base this+0x4590 (indexed by compound id at 0x45E0) and the obj+0x403C comparison target have no packet field evidence refs; offsets are taken directly from the raw source.
    // UNRESOLVED: Owner identity is DERIVED from the LEGACY ABI lead AI_Push_Lap_Closing_Gap; no confirmed class symbol is present in the packet.
}
