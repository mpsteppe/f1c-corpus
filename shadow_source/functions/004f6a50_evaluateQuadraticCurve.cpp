// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6A50
// Canonical corpus name: QuadraticForceTorqueCurveEvaluation
// Owner: WheelCurveEvaluator [DERIVED]
// Raw source: functions/QuadraticForceTorqueCurveEvaluation_004f6a50.c

void WheelCurveEvaluator::evaluateQuadraticCurve()
{
    // Evaluates a quadratic force/torque curve guarded by an enable flag: if the byte at this+0x4D4 is nonzero, writes a2*a2*(double at this+0x4E8) + a2*(double at this+0x4F0) + a2*(double at this+0x4E0) + (double at this+0x4D8) into *a3; otherwise writes 0.0 into *a3. Returns the flag value. On the per-frame wheel/suspension physics path.
    // ASSIGNMENT: result = *(_BYTE*)(this + 1236), reading the enable flag at this+0x4D4. [field:this:0x000004D4, source:raw]
    // GUARD: Branch on the enable flag at this+0x4D4: nonzero computes the quadratic output, zero forces the output to 0.0. [field:this:0x000004D4, source:raw]
    // CALCULATION: If enabled, write *a3 = a2*a2*(double at this+0x4E8) + a2*(double at this+0x4F0) + a2*(double at this+0x4E0) + (double at this+0x4D8): a quadratic curve with two linear coefficients. [field:this:0x000004E8, field:this:0x000004F0, field:this:0x000004E0, field:this:0x000004D8, source:raw]
    // ASSIGNMENT: If disabled, write *a3 = 0.0. [source:raw]
    // RETURN: Return result, the enable flag value at this+0x4D4. [source:raw]

    // Conservative worker pseudocode:
    //   result = *(_BYTE*)(this + 1236);
    //   if (result)
    //     *a3 = a2*a2* *(double*)(this + 1256) + a2* *(double*)(this + 1264) + a2* *(double*)(this + 1248) + *(double*)(this + 1240);
    //   else
    //     *a3 = 0.0;
    //   return result;
    // UNRESOLVED: The physical meaning of the four coefficients (C0 at 0x4D8, C1 at 0x4E0, C2 at 0x4E8, C3 at 0x4F0) as force vs torque, and the meaning of the input a2, are DERIVED from callers, not proven by the packet.
    // UNRESOLVED: Why the linear term is split across two coefficients (this+0x4E0 and this+0x4F0) is not explained by the packet.
}
