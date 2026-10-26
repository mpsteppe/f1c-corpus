// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E88B0
// Canonical corpus name: TireGripCoefficient
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireGripCoefficient_004e88b0.c

void UnknownObject::TireGripCoefficient()
{
    // Computes a per-corner tire grip coefficient with an anti-roll bar cross-coupling term. Dispatches on the mode selector this+0x39B4: mode 0 and mode 2 use a 0.5 anti-roll factor (this+0x39C8 x this+0x39A8 x 0.5) over the four corner products (corner0 +0x35CC/+0x3610/+0x3618, corner1 +0x36C4/+0x3708/+0x3710, corner2 +0x37BC/+0x3800/+0x3808, corner3 +0x38B4/+0x38F8/+0x3900), mode 1 uses a 0.25 factor, and values above 2 fall through to a default path. The result is selected by paired min/max comparisons across the axle pairs, then clamped to [0.0, 1.0] and returned. Called from AIRacingLine (00425920) and AISteeringCorrection (00426CF0).
    // GUARD: Mode dispatch on the selector this+0x39B4: value 0 enters the axle-pair average path with a 0.5 anti-roll factor, value 1 enters the all-four path with a 0.25 factor, value 2 enters the individual-corner path with a 0.5 factor, and higher values fall through to the default this+0x39C8 result path [field:this:0x000039B4, source:raw]
    // CALCULATION: Mode 0 (v1 == 0) per-corner products with anti-roll coupling: v10 = this+0x39C8 * this+0x39A8 * 0.5; v14 = (this+0x38F8*this+0x38B4 + v10)*this+0x3900; result = (v10 + this+0x3800*this+0x37BC)*this+0x3808; v17 = this+0x3710*this+0x3708*this+0x36C4; v11 = this+0x3618*this+0x3610*this+0x35CC [field:this:0x000039C8, field:this:0x000039A8, field:this:0x000038F8, field:this:0x000038B4, field:this:0x00003900, field:this:0x00003800, field:this:0x000037BC, field:this:0x00003808, field:this:0x00003710, field:this:0x00003708, field:this:0x000036C4, field:this:0x00003618, field:this:0x00003610, field:this:0x000035CC, source:raw]
    // CALCULATION: Mode 2 (v1 == 2) per-corner products with 0.5 anti-roll coupling: v3 = this+0x39C8 * this+0x39A8 * 0.5; v18 = this+0x3900*this+0x38F8*this+0x38B4; v15 = this+0x3808*this+0x3800*this+0x37BC; v14 = (this+0x3708*this+0x36C4 + v3)*this+0x3710; result = (v3 + this+0x3610*this+0x35CC)*this+0x3618 [field:this:0x000039C8, field:this:0x000039A8, field:this:0x00003900, field:this:0x000038F8, field:this:0x000038B4, field:this:0x00003808, field:this:0x00003800, field:this:0x000037BC, field:this:0x00003708, field:this:0x000036C4, field:this:0x00003710, field:this:0x00003610, field:this:0x000035CC, field:this:0x00003618, source:raw]
    // CALCULATION: Mode 1 (v1 == 1) per-corner products with 0.25 anti-roll coupling: v7 = this+0x39C8 * this+0x39A8 * 0.25; v14 = (this+0x38F8*this+0x38B4 + v7)*this+0x3900; v16 = (this+0x3800*this+0x37BC + v7)*this+0x3808; v18 = (this+0x3708*this+0x36C4 + v7)*this+0x3710; result = (v7 + this+0x3610*this+0x35CC)*this+0x3618 [field:this:0x000039C8, field:this:0x000039A8, field:this:0x000038F8, field:this:0x000038B4, field:this:0x00003900, field:this:0x00003800, field:this:0x000037BC, field:this:0x00003808, field:this:0x00003708, field:this:0x000036C4, field:this:0x00003710, field:this:0x00003610, field:this:0x000035CC, field:this:0x00003618, source:raw]
    // STATE_TRANSITION: Selection: the returned coefficient is picked among the corner/axle-pair candidates (result, v14, v16, v17, v18) by paired <=/greater-than comparisons; the comparison topology differs per mode [source:raw]
    // GUARD: Clamp to [0.0, 1.0]: if the selected result is below 0.0 the function returns 0.0, if above 1.0 it returns 1.0, otherwise the value is returned unchanged [source:raw]
    // RETURN: Returns the clamped per-corner tire grip coefficient; called by AIRacingLine (00425920) and AISteeringCorrection (00426CF0) [function:0x004E88B0, caller:0x00425920, caller:0x00426CF0, source:raw]

    // Conservative worker pseudocode:
    //   mode = this[0x39B4/4];
    //   factor = (mode == 1) ? 0.25 : 0.5;
    //   antiroll = this[0x39C8/4] * this[0x39A8/4] * factor;
    //   c0 = this[0x3618/4] * (antiroll + this[0x3610/4]*this[0x35CC/4]);
    //   c1 = this[0x3710/4] * (antiroll + this[0x3708/4]*this[0x36C4/4]);
    //   c2 = this[0x3808/4] * (antiroll + this[0x3800/4]*this[0x37BC/4]);
    //   c3 = this[0x3900/4] * (antiroll + this[0x38F8/4]*this[0x38B4/4]);
    //   result = select_min_max(c0, c1, c2, c3, mode);
    //   return clamp(result, 0.0, 1.0);
    // UNRESOLVED: Four read-only globals (flt_59E43C, flt_59E440, flt_59E450, flt_59E7F8) are flagged by packet facts but never referenced in the raw decompiled source
    // UNRESOLVED: Mode selector values beyond 0/1/2 fall through to the default v18 result path; the intended meaning of those modes is not documented here
}
