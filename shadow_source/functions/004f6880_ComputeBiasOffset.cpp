// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6880
// Canonical corpus name: BiasValueComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BiasValueComputation_004f6880.c

void UnknownObject::ComputeBiasOffset()
{
    // Second variant of the randomized scale+bias computation. Computes a2 * scale + bias with an optional randomization step, using the parameter pair at this+0x588 (bias) and this+0x590 (scale). Reads the enable byte at this+0x56C; when it is zero it calls the randomization helper sub_5881F0(a2) and scales a2 by the double at this+0x590, otherwise uses a2 unscaled. Adds the bias double at this+0x588 and returns the result. Called per-frame by sub_43C250 and SuspensionAndWheelPhysics.
    // GUARD: Read the enable byte at this+0x56C; when it is zero, run the randomization path: call sub_5881F0(a2) then set v2 = a2 * (double at this+0x590); otherwise leave v2 = a2 unscaled. [field:this:0x0000056C, callee:0x005881F0, field:this:0x00000590, source:raw]
    // CALCULATION: Add the bias double at this+0x588 to the (possibly scaled) v2 to form the result. [field:this:0x00000588, source:raw]
    // RETURN: Return the computed double. Called per-frame by sub_43C250 and SuspensionAndWheelPhysics. [caller:0x0043C250, caller:0x004E5F60, function:0x004F6880]

    // Conservative worker pseudocode:
    //   if (!this->enable /* +0x56C * /) { sub_5881F0(a2); a2 = a2 * this->scale /* +0x590 * /; }
    //   return a2 + this->bias /* +0x588 * /;
    // UNRESOLVED: The return value of sub_5881F0 is not captured in the decompiled body (a2 is used unchanged after the call), so it is unresolved whether the helper randomizes via side effect or via a return value lost by the decompiler.
    // UNRESOLVED: Owner identity is unknown: the LEGACY ABI lead is the failure marker FAIL_4f6880 and provides no owner class.
}
