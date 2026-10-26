// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004569B0
// Canonical corpus name: SteeringInputSmoothingWithSaturation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SteeringInputSmoothingWithSaturation_004569b0.c

void UnknownObject::SteeringInputSmoothingWithSaturation()
{
    // Accumulates a steering input step into two float state fields on a float-array object. Chooses a multiplier of 2.0 when argument a3 equals 1, else 0.5, and negates it when the low byte of the float input a2 is zero. The signed product of the multiplier and input delta a4 is added to field this[40] (this+0xA0) and then to field this[47] (this+0xBC); after each update the value is passed to InterruptDispatch (0058957A) and written back to the same field. No early-return guards.
    // CALCULATION: Multiplier selection: base 0.5, raised to 2.0 when a3 == 1, and negated when the low byte of a2 is zero [source:raw, function:0x004569B0]
    // CALCULATION: Scaled input delta computed as multiplier * a4 [source:raw]
    // ASSIGNMENT: Primary accumulator: adds the scaled delta to the float at this+0xA0 (element [40]), passes the sum to InterruptDispatch (0058957A), then writes the (possibly clamped) result back to this+0xA0 [field:this:0x000000A0, callee:0x0058957A, source:raw]
    // ASSIGNMENT: Secondary accumulator: adds the same scaled delta to the float at this+0xBC (element [47]), passes the sum to InterruptDispatch (0058957A), then writes the (possibly clamped) result back to this+0xBC [field:this:0x000000BC, callee:0x0058957A, source:raw]

    // Conservative worker pseudocode:
    //   mult = 0.5;
    //   if (a3 == 1) mult = 2.0;
    //   if (lowByte(a2) == 0) mult = -mult;
    //   delta = mult * a4;
    //   this[0xA0/4] = InterruptDispatch(this[0xA0/4] + delta);
    //   this[0xBC/4] = InterruptDispatch(this[0xBC/4] + delta);
    // UNRESOLVED: Four read-only globals (flt_59E670, flt_59EF84, flt_59EF88, flt_59EFA8) are flagged by the packet but appear nowhere in the raw decompiled source; their role (likely multipliers or saturation constants) is unverifiable from this packet
    // UNRESOLVED: InterruptDispatch (0058957A) is read from raw source as a plain call; whether it clamps, saturates or dispatches is not determinable here
    // UNRESOLVED: Interpreting the low byte of the float a2 as a direction sign flag is DERIVED
}
