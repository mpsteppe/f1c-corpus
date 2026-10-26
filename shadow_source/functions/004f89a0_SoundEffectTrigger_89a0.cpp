// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F89A0
// Canonical corpus name: SoundEffectTrigger_89a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SoundEffectTrigger_89a0_004f89a0.c

void UnknownObject::SoundEffectTrigger_89a0()
{
    // Randomized sound/HUD trigger variant. Reads a pointer from this+0 and twice calls RatioComputationWithClamping on the sub-object 12 bytes into it to obtain clamped ratio values. Two sequential noise samples are pulled from the weather-noise table flt_8AB274 using the advancing byte counter dword_8AAE70. An LCG random value picks one of three HUD base indices (17 for rand < 10922, 16 for 10922 <= rand < 21844, 15 otherwise), and HUDElementConfig(this, base, 1, v11, v10) writes the two computed intensities to the HUD element. Called on the frame path by PositionLapStateUpdate (00447E00) and RaceStartCountdownStateUpdate (004EF930).
    // CALL: First call to RatioComputationWithClamping with the pointer read from this+0 advanced by 12 bytes, yielding a clamped ratio v2 [callee:0x004F1B10, field:this:0x00000000, source:raw]
    // CALCULATION: Noise sample v3 = flt_8AB274[(unsigned byte of dword_8AAE70)++] * 0.050000001; intensity v11 = v3 + v2 * 0.85000002 + 0.15000001 [global:0x008AB274, global:0x008AAE70, source:raw]
    // CALL: Second call to RatioComputationWithClamping on the same 12-byte-advanced sub-object, yielding a clamped ratio v4 [callee:0x004F1B10, field:this:0x00000000, source:raw]
    // CALCULATION: Second noise sample v5 = flt_8AB274[(unsigned byte of dword_8AAE70)++] and LCG value v7 = RandLCGRandomNumberGenerator [global:0x008AB274, global:0x008AAE70, callee:0x005884ED, source:raw]
    // GUARD: Index selection: if v7 >= 10922 then v8 = (v7 < 21844) + 15 (yielding 16 or 15), else v8 = 17 [callee:0x005884ED, source:raw]
    // CALCULATION: Intensity v10 = v5 * 0.050000001 + (v4 - 0.25) * 0.5 + 1.0 [source:raw]
    // CALL: HUDElementConfig(this, v8, 1, v11, v10) writes both computed intensities to the indexed HUD element and its result is returned [callee:0x004F87C0, source:raw]
    // CALL: Invoked on the frame path by PositionLapStateUpdate (00447E00) and RaceStartCountdownStateUpdate (004EF930) [caller:0x00447E00, caller:0x004EF930, source:raw]

    // Conservative worker pseudocode:
    //   ratio1 = RatioComputationWithClamping(*(this + 0) + 12);
    //   noise1 = flt_8AB274[byte(dword_8AAE70++)] * 0.050000001;
    //   v11 = noise1 + ratio1 * 0.85000002 + 0.15000001;
    //   ratio2 = RatioComputationWithClamping(*(this + 0) + 12);
    //   noise2 = flt_8AB274[byte(dword_8AAE70++)];
    //   rand = RandLCGRandomNumberGenerator();
    //   base = rand < 10922 ? 17 : (rand < 21844 ? 16 : 15);
    //   v10 = noise2 * 0.050000001 + (ratio2 - 0.25) * 0.5 + 1.0;
    //   return HUDElementConfig(this, base, 1, v11, v10);
    // UNRESOLVED: Six read-only float globals (flt_59E43C, flt_59E448, flt_59E450, flt_59E7F8, flt_59E868, flt_59E908) are flagged by packet facts but appear nowhere in the raw decompiled source; they likely back the inlined float literals, but which literal each supplies cannot be tied from this packet
    // UNRESOLVED: The sub-object at pointer(this+0) + 12 is reached by a constant offset that is not declared as a packet field; its layout is unknown
    // UNRESOLVED: The uninitialized value v6 passed in ecx to RandLCGRandomNumberGenerator is a decompiler artifact of a prior caller state; the actual seed/source of randomness is not visible
}
