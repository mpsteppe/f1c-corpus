// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F88A0
// Canonical corpus name: SoundEffectTrigger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SoundEffectTrigger_004f88a0.c

void UnknownObject::UpdateSoundEffectIntensity()
{
    // Computes a clamped ratio of two sub-struct floats (obj+0x39A0 over obj+0x39A4), mixes in two noise-table samples and a random pick, then calls HUDElementConfig with the resulting intensity parameters to configure an indexed HUD/sound element.
    // CALCULATION: Dereference *this to the sub-struct obj and compute v2 = obj+0x39A0 / obj+0x39A4. [field:this:0x00000000, field:obj:0x000039A0, field:obj:0x000039A4, source:raw]
    // GUARD: Clamp the ratio v2 into [0, 1]: values below zero clamp to 0 and values above 1 clamp to 1. [source:raw]
    // CALCULATION: Sample noise v4 = flt_8AB274[(byte)dword_8AAE70++] and compute v12 = ratio * 0.85 + 0.15 + v4 * 0.05. [global:0x008AAE70, global:0x008AB274, source:raw]
    // CALL: Call RatioComputationWithClamping(obj+12) for a second clamped ratio value. [callee:0x004F1B10, source:raw]
    // CALCULATION: Sample a second noise value, pick an element index from the random result of RandLCGRandomNumberGenerator (12, 13, or 14 depending on ranges 10922/21844), and compute v11 = noise * 0.05 + (ratio - 0.25) * 0.5 + 1.0. [callee:0x005884ED, global:0x008AAE70, global:0x008AB274, source:raw]
    // RETURN: Return HUDElementConfig(this, picked index, 1, v12, v11). [callee:0x004F87C0, source:raw]

    // Conservative worker pseudocode:
    //   obj = *this;
    //   v2 = obj->flt_0x39A0 / obj->flt_0x39A4;
    //   v2 = clamp(v2, 0.0, 1.0);
    //   v4 = flt_8AB274[dword_8AAE70++];
    //   v12 = v2 * 0.85 + 0.15 + v4 * 0.05;
    //   v5 = RatioComputationWithClamping(obj + 12);
    //   v6 = flt_8AB274[dword_8AAE70++];
    //   v8 = RandLCGRandomNumberGenerator();
    //   v9 = (v8 < 10922) ? 14 : (v8 < 21844 ? 13 : 12);
    //   v11 = v6 * 0.05 + (v5 - 0.25) * 0.5 + 1.0;
    //   return HUDElementConfig(this, v9, 1, v12, v11);
    // UNRESOLVED: Global literals flt_59E43C, flt_59E440, flt_59E448, flt_59E450, flt_59E7F8, flt_59E868, flt_59E908 are listed in the packet's globals table but do not appear in the raw source; their role here is unclear.
    // UNRESOLVED: The sub-struct behind *this (holding the ratio fields at obj+0x39A0/0x39A4 and extra data at obj+12) has an unknown type.
    // UNRESOLVED: The mapping of the picked index (12/13/14) to a concrete HUD/sound element is unknown; the two callers are PositionLapStateUpdate (0x00447E00) and RaceStartCountdownStateUpdate (0x004EF930).
}
