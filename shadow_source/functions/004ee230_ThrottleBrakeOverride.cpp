// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EE230
// Canonical corpus name: ThrottleBrakeOverride
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThrottleBrakeOverride_004ee230.c

void UnknownObject::ThrottleBrakeOverride()
{
    // Computes a brake-ratio override value (ratio cubed times a cooling-effectiveness factor, halved) and, per throttle/brake channel, replaces the channel's reference value with that override when the reference equals the -789.0 sentinel meaning 'no reference supplied'. Otherwise the raw reference value is copied through.
    // CALCULATION: ratio = field[0x3994] / field[0x3998] (brake-bias ratio) [field:this:0x00003994, field:this:0x00003998, source:raw]
    // CALCULATION: overrideValue = ratio * ratio * ratio * field[0x3570] * 0.5 (cubic ratio scaled by brake cooling effectiveness factor, halved) [field:this:0x00003570, field:this:0x00003994, field:this:0x00003998, source:raw]
    // ASSIGNMENT: outputChannel0 = referenceChannel0 (copy the raw reference value) [field:this:0x0000077C, field:this:0x00003D48, source:raw]
    // GUARD: if referenceChannel0 == -789.0 (uninitialized-reference sentinel, value stored at global 0x005AD1F8) then outputChannel0 = overrideValue [field:this:0x00003D48, field:this:0x0000077C, global:0x005AD1F8, source:raw]
    // ASSIGNMENT: outputChannel1 = referenceChannel1 (copy the raw reference value) [field:this:0x00000790, field:this:0x00003D4C, source:raw]
    // GUARD: if referenceChannel1 == -789.0 (sentinel) then outputChannel1 = overrideValue [field:this:0x00003D4C, field:this:0x00000790, global:0x005AD1F8, source:raw]
    // ASSIGNMENT: outputChannel2 = referenceChannel2 (copy the raw reference value) [field:this:0x000007A4, field:this:0x00003D50, source:raw]
    // GUARD: if referenceChannel2 == -789.0 (sentinel) then outputChannel2 = overrideValue [field:this:0x00003D50, field:this:0x000007A4, global:0x005AD1F8, source:raw]

    // Conservative worker pseudocode:
    //   float ratio = this[0x3994] / this[0x3998];
    //   float overrideValue = ratio * ratio * ratio * this[0x3570] * 0.5f;
    //   this[0x77C] = this[0x3D48]; if (this[0x3D48] == -789.0f) this[0x77C] = overrideValue;
    //   this[0x790] = this[0x3D4C]; if (this[0x3D4C] == -789.0f) this[0x790] = overrideValue;
    //   this[0x7A4] = this[0x3D50]; if (this[0x3D50] == -789.0f) this[0x7A4] = overrideValue;
    // UNRESOLVED: Global flt_59E450 (0x0059E450, DegreesToRadians per skeleton fill) is listed as a read global but no reference to it is visible in the raw decompiled source; its role in this function is unexplained.
}
