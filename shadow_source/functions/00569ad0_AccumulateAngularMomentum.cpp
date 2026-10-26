// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00569AD0
// Canonical corpus name: AccumulateAngularMomentum
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AccumulateAngularMomentum_00569ad0.c

void UnknownObject::AccumulateAngularMomentum()
{
    // Accumulates an impulse vector a3 into linear momentum (this+0x134/0x13C/0x144), then accumulates cross-product components of the lever-arm vector a2 and impulse a3 into angular momentum (this+0x14C/0x154/0x15C). Returns the impulse vector pointer a3.
    // RETURN: Return the impulse vector pointer a3 as the function result. [source:raw]
    // ASSIGNMENT: Add a3[0], a3[1], a3[2] into the linear momentum components this+0x134, this+0x13C, this+0x144. [field:this:0x00000134, field:this:0x0000013C, field:this:0x00000144, source:raw]
    // CALCULATION: Compute v5 = a2[2]*a3[0] - a3[2]*a2[0], the y component of the cross product a2 x a3. [source:raw]
    // CALCULATION: Compute v6 = a3[1]*a2[0] - a3[0]*a2[1], the negated z component of the cross product a2 x a3. [source:raw]
    // ASSIGNMENT: Add a3[2]*a2[1] - a3[1]*a2[2] (the negated x component of the cross product) into the angular momentum component this+0x14C. [field:this:0x0000014C, source:raw]
    // ASSIGNMENT: Add v5 (cross-product y component) into the angular momentum component this+0x154. [field:this:0x00000154, source:raw]
    // ASSIGNMENT: Add v6 (negated cross-product z component) into the angular momentum component this+0x15C. [field:this:0x0000015C, source:raw]

    // Conservative worker pseudocode:
    //   double* AccumulateAngularMomentum(char* this, double* a2, double* a3) {
    //     *(double*)(this + 0x134) += a3[0];
    //     *(double*)(this + 0x13C) += a3[1];
    //     *(double*)(this + 0x144) += a3[2];
    //     double v5 = a2[2] * a3[0] - a3[2] * a2[0];
    //     double v6 = a3[1] * a2[0] - a3[0] * a2[1];
    //     *(double*)(this + 0x14C) += a3[2] * a2[1] - a3[1] * a2[2];
    //     *(double*)(this + 0x154) += v5;
    //     *(double*)(this + 0x15C) += v6;
    //     return a3;
    //   }
    // UNRESOLVED: The mixed signs of the cross-product accumulation (x and z components negated, y positive) are not explained by the packet; they may reflect a coordinate-frame convention or a cross-product order (a2 x a3 vs a3 x a2) that the packet cannot disambiguate.
    // UNRESOLVED: The interpretation of a2 as a pre-computed lever-arm vector and of this+0x134..0x15C as linear/angular momentum is DERIVED from the arithmetic shape; the packet does not name the fields.
}
