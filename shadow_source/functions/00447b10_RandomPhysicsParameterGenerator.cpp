// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00447B10
// Canonical corpus name: RandomPhysicsParameterGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomPhysicsParameterGenerator_00447b10.c

void UnknownObject::RandomPhysicsParameterGenerator()
{
    // Generates a randomized physics parameter in [0.0, 1.0]. Returns 0.0 when the active flag byte this[0x1C59] is unset or when the input parameter this[0x19C] <= 0.0, and 1.0 when this[0x19C] >= 0.9. Otherwise interpolates between this[0x19C] + 0.1 and this[0x19C] + 1.6 using a trig-table pseudo-random value from TrigTableLookup(this), clamping the result to a maximum of 1.0.
    // GUARD: Disabled guard: if the active flag byte this[0x1C59] is zero, return 0.0. [field:this:0x00001C59, source:raw]
    // GUARD: Upper clamp guard: if input this[0x19C] >= 0.9, return 1.0 (threshold from a compiler-folded global double). [field:this:0x0000019C, global:0x0059EBA0, source:raw]
    // GUARD: Lower clamp guard: if input this[0x19C] <= 0.0, return 0.0 (zero from a compiler-folded global double). [field:this:0x0000019C, global:0x0059E430, source:raw]
    // CALCULATION: Build the interpolation range from the input parameter: v2 = this[0x19C] + 0.1 (lower bound) and v3 = this[0x19C] + 1.6 (upper bound); the 0.1 and 1.6 offsets are compiler-folded globals. [field:this:0x0000019C, global:0x0059EB38, global:0x0059EEF8, source:raw]
    // CALL: Draw a pseudo-random value from the trig table: TrigTableLookup((double *)this). [callee:0x00447AB0, source:raw]
    // CALCULATION: Interpolate and clamp: result = TrigTableLookup(this) * (v3 - v2) + v2; if result > 1.0, return 1.0 (the 1.0 clamp from a compiler-folded global double). [global:0x0059E420, source:raw]
    // RETURN: Return the clamped randomized parameter in [0.0, 1.0]. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_447B10(int self) {
    //     if (!*(_BYTE *)(self + 7257)) return 0.0;
    //     if (*(double *)(self + 412) >= 0.9) return 1.0;
    //     if (*(double *)(self + 412) <= 0.0) return 0.0;
    //     double v2 = *(double *)(self + 412) + 0.1;
    //     double v3 = *(double *)(self + 412) + 1.6;
    //     double result = TrigTableLookup((double *)self) * (v3 - v2) + v2;
    //     if (result > 1.0) return 1.0;
    //     return result;
    //   }
    // UNRESOLVED: The five referenced globals (dbl_59E420, dbl_59E430, dbl_59EB38, dbl_59EBA0, dbl_59EEF8) correspond to the five folded literals 0.9/0.0/1.0/0.1/1.6; the exact one-to-one binding is not established by the packet.
    // UNRESOLVED: The caller (Gearbox at 0x00443B70) and the interpretation of the trig-table value as a pseudo-random source are DERIVED from naming, not proven by the packet.
}
