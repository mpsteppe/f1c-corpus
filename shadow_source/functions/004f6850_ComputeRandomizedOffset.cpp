// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6850
// Canonical corpus name: RandomOffsetCalculator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomOffsetCalculator_004f6850.c

void UnknownObject::ComputeRandomizedOffset()
{
    // Computes a scale+bias offset (a2 * scale + bias) with an optional randomization step. Reads the enable byte at this+0x56C; when it is zero it calls the randomization helper sub_5881F0(a2) and scales a2 by the double at this+0x578, otherwise uses a2 unscaled. Adds the bias double at this+0x570 and returns the result. Called per-frame by sub_43C250 and SuspensionAndWheelPhysics for stochastic variation of physics parameters.
    // GUARD: Read the enable byte at this+0x56C; when it is zero, run the randomization path: call sub_5881F0(a2) then set v2 = a2 * (double at this+0x578); otherwise leave v2 = a2 unscaled. [field:this:0x0000056C, callee:0x005881F0, field:this:0x00000578, source:raw]
    // CALCULATION: Add the bias double at this+0x570 to the (possibly scaled) v2 to form the result. [field:this:0x00000570, source:raw]
    // RETURN: Return the computed double. Called per-frame by sub_43C250 and SuspensionAndWheelPhysics for stochastic variation of physics parameters. [caller:0x0043C250, caller:0x004E5F60, function:0x004F6850]

    // Conservative worker pseudocode:
    //   if (!this->enable /* +0x56C * /) { sub_5881F0(a2); a2 = a2 * this->scale /* +0x578 * /; }
    //   return a2 + this->bias /* +0x570 * /;
    // UNRESOLVED: The return value of sub_5881F0 is not captured in the decompiled body (a2 is used unchanged after the call), so it is unresolved whether the helper randomizes via side effect or via a return value lost by the decompiler.
    // UNRESOLVED: Owner identity is unknown: the LEGACY ABI lead 'RandomOffsetCalculator' names the routine, not a class.
}
