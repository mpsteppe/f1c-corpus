// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043BB30
// Canonical corpus name: QuadFunctionEval
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadFunctionEval_0043bb30.c

void UnknownObject::QuadFunctionEval()
{
    // Evaluates two quadratic curves y = a*x^2 + b*x + c at the input value a2 using per-curve coefficients stored on the owner object, and writes both the input and the two results back to the owner. The first curve reads its constant, linear and quadratic terms from bytes 0x17A8, 0x17B0 and 0x17B8 and stores its result at 0x1930; the second curve reads from 0x17C0, 0x17C8 and 0x17D0 and stores its result at 0x19E8. The input value a2 is stored at 0x1C00. No branches, globals or calls.
    // ASSIGNMENT: Store the input value a2 at byte 0x1C00 of the owner object. [field:this:0x00001C00, source:raw]
    // ASSIGNMENT: Evaluate the first curve at a2 and store the result at byte 0x1930: result = a2 * (coefficient at 0x17B8) * a2 + a2 * (coefficient at 0x17B0) + (coefficient at 0x17A8), i.e. a*x^2 + b*x + c. [field:this:0x00001930, field:this:0x000017B8, field:this:0x000017B0, field:this:0x000017A8, source:raw]
    // ASSIGNMENT: Evaluate the second curve at a2 and store the result at byte 0x19E8: result = a2 * (coefficient at 0x17D0) * a2 + a2 * (coefficient at 0x17C8) + (coefficient at 0x17C0). [field:this:0x000019E8, field:this:0x000017D0, field:this:0x000017C8, field:this:0x000017C0, source:raw]

    // Conservative worker pseudocode:
    //   void QuadFunctionEval(double* this, double a2) {
    //       this[896] = a2;                                    // byte 0x1C00
    //       this[806] = a2 * this[759] * a2 + a2 * this[758] + this[757];  // byte 0x1930, coeffs 0x17B8/0x17B0/0x17A8
    //       this[829] = a2 * this[762] * a2 + a2 * this[761] + this[760];  // byte 0x19E8, coeffs 0x17D0/0x17C8/0x17C0
    //   }
    // UNRESOLVED: The owner object identity is not established by the packet; coefficients and results are reached through the this pointer only.
    // UNRESOLVED: The physical meaning of the two evaluated curves (e.g. two spring-rate curves) is inferred from the physics callers, not proven by packet evidence.
}
