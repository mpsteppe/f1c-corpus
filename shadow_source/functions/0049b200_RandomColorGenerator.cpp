// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B200
// Canonical corpus name: RandomColorGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomColorGenerator_0049b200.c

void UnknownObject::RandomColorGenerator()
{
    // Computes a packed color-like 32-bit integer from a time-driven triangular wave. Adds the session-time global (dbl_8AFEA0) to a float argument, runs a side-effect call (InterruptDispatch) on the sum, folds the value into [0,1] with a triangle wave (around 0.5), clamps it to [0,1], and packs three CRTFtol conversions of the clamped value into an integer result.
    // CALCULATION: Sum the session-time global dbl_8AFEA0 and the float argument a3 into v3. [global:0x008AFEA0]
    // CALL: Side-effect call InterruptDispatch with the time sum. [callee:0x0058957A]
    // CALCULATION: Triangle wave: when v3 >= 0.5, v4 = 1.0 - ((v3 - 0.5) + (v3 - 0.5)); otherwise v4 = v3 + v3. [function:0x0049B200]
    // CALCULATION: Clamp v4 into [0,1]: below 0 becomes 0.0, above 1 becomes 1.0. [function:0x0049B200]
    // CALCULATION: Convert the clamped value to an integer three times via CRTFtol and assemble the conversions into a packed 32-bit integer. [callee:0x00587BDC]
    // RETURN: Return the packed integer value. [callee:0x00587BDC]

    // Conservative worker pseudocode:
    //   int RandomColorGenerator(float a3) {
    //     double v3 = dbl_8AFEA0 + a3;
    //     InterruptDispatch(v3);
    //     double v4 = (v3 >= 0.5) ? 1.0 - ((v3 - 0.5) + (v3 - 0.5)) : v3 + v3;
    //     if (v4 < 0.0) v4 = 0.0;
    //     if (v4 > 1.0) v4 = 1.0;
    //     int c0 = (int)CRTFtol(v4);
    //     int c1 = (int)CRTFtol(v4);
    //     int c2 = (int)CRTFtol(v4);
    //     return (c0 << 24) | (c1 << 16) | (c2 << 8) | c2;
    //   }
    // UNRESOLVED: dbl_59E420, flt_59E43C, flt_59E440 and flt_59E450 are packet globals not referenced directly in the decompiled body; likely used inside callee subroutines (CRTFtol, InterruptDispatch). Their meaning is unresolved.
    // UNRESOLVED: Exact byte layout of the packed result is decompiler-artifact dependent (the low conversion is duplicated) and unverified.
    // UNRESOLVED: Purpose of the InterruptDispatch side-effect call is unknown.
}
