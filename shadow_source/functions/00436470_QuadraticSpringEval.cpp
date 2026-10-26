// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00436470
// Canonical corpus name: QuadraticSpringEval
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadraticSpringEval_00436470.c

void UnknownObject::QuadraticSpringEval()
{
    // Evaluates two quadratic spring functions at a given input a2 on a double-coefficient object: result0 = a*x^2 + b*x + c for the force set (c=+0x4, b=+0xC, a=+0x14) and the same shape for the derivative set (c=+0x1C, b=+0x24, a=+0x2C), writing the force result to +0x34 and the derivative result to +0x3C. Part of the suspension spring model, evaluated per frame on the frame path and called by SolverDispatch (0043b930) and sub_43BC20 (0043bc20).
    // CALCULATION: Force polynomial evaluated at a2: force = a2 * this+0x14 * a2 + a2 * this+0xC + this+0x4 (quadratic coefficient from +0x14, linear from +0xC, constant from +0x4) [field:this:0x00000004, field:this:0x0000000C, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Store the evaluated force polynomial into this+0x34 (the computed force result) [field:this:0x00000034, source:raw]
    // CALCULATION: Derivative polynomial evaluated at a2: derivative = a2 * this+0x2C * a2 + a2 * this+0x24 + this+0x1C (quadratic coefficient from +0x2C, linear from +0x24, constant from +0x1C) [field:this:0x0000001C, field:this:0x00000024, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Store the evaluated derivative polynomial into this+0x3C (the computed derivative result) [field:this:0x0000003C, source:raw]
    // RETURN: Function returns void; both results are side effects written to the this object [function:0x00436470, source:raw]
    // CALL: Invoked on the frame path by SolverDispatch (0043b930) and by sub_43BC20 (0043bc20) to obtain spring force and damping at a given travel input [caller:0x0043B930, caller:0x0043BC20]

    // Conservative worker pseudocode:
    //   this[0x34] = a2 * this[0x14] * a2 + a2 * this[0xC] + this[0x4];
    //   this[0x3C] = a2 * this[0x2C] * a2 + a2 * this[0x24] + this[0x1C];
    // UNRESOLVED: The exact meaning of the second quadratic set (+0x1C/+0x24/+0x2C -> +0x3C) as 'derivative' is taken from prior fill prose and is not derivable from this function alone
    // UNRESOLVED: No guard or control flow exists; both stores always execute for any a2
}
