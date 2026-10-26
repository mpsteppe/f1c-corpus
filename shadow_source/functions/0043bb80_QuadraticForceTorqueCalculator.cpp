// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043BB80
// Canonical corpus name: QuadraticForceTorqueCalculator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadraticForceTorqueCalculator_0043bb80.c

void UnknownObject::QuadraticForceTorqueCalculator()
{
    // Stores the input value a2 into this+0x1C38, then evaluates two quadratics a2^2*cA + a2*cB + cC (coefficients this+0x17E8/0x17E0/0x17D8 and this+0x1800/0x17F8/0x17F0) and stores the results at this+0x1A0C and this+0x1ABC, forming force and torque outputs for a vehicle dynamics evaluation.
    // ASSIGNMENT: Store the input value a2 into this+0x1C38. [field:this:0x00001C38, source:raw]
    // CALCULATION: Evaluate first quadratic a2*this+0x17E8*a2 + a2*this+0x17E0 + this+0x17D8 and store the result at this+0x1A0C. [field:this:0x000017D8, field:this:0x000017E0, field:this:0x000017E8, field:this:0x00001A0C, source:raw]
    // CALCULATION: Evaluate second quadratic a2*this+0x1800*a2 + a2*this+0x17F8 + this+0x17F0 and store the result at this+0x1ABC. [field:this:0x000017F0, field:this:0x000017F8, field:this:0x00001800, field:this:0x00001ABC, source:raw]

    // Conservative worker pseudocode:
    //   void QuadraticForceTorqueCalculator(double* this, double a2) {
    //     this[0x1C38 / 8] = a2;
    //     *(double*)((char*)this + 0x1A0C) = a2 * this[0x17E8 / 8] * a2 + a2 * this[0x17E0 / 8] + this[0x17D8 / 8];
    //     *(double*)((char*)this + 0x1ABC) = a2 * this[0x1800 / 8] * a2 + a2 * this[0x17F8 / 8] + this[0x17F0 / 8];
    //   }
    // UNRESOLVED: The semantic meaning of the two output values (this+0x1A0C and this+0x1ABC as force/torque) is a DERIVED interpretation; the packet labels the coefficients only as quadratic terms.
    // UNRESOLVED: The full structure context behind the coefficient fields (this+0x17D8 through this+0x1800) is not established by the packet alone.
}
