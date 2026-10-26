// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466160
// Canonical corpus name: FunctionCallWrapper_6160
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_6160_00466160.c

void UnknownObject::ComputeAngleRatioAndStore()
{
    // Computes sqrt(this[62]^2 - this[70]^2), stores it to this[71], then computes the ratio this[70] / this[62] and stores it to this[72] after a float-conversion wrapper call. Begins with a no-op/logging wrapper call and always returns 0.
    // CALL: Invoke WrapperReturn0 (no-op/logging wrapper) at function entry. [callee:0x0048E6A0]
    // CALCULATION: Compute sqrt(this[62] * this[62] - this[70] * this[70]) and store the result to this[71] (offset 0x11C). [field:this:0x000000F8, field:this:0x00000118, field:this:0x0000011C, source:raw]
    // CALCULATION: Compute the ratio this[70] / this[62] into a temporary double v2. [field:this:0x000000F8, field:this:0x00000118, source:raw]
    // CALL: Invoke FloatConvertWrapper (float format conversion wrapper) between computing and storing the ratio. [callee:0x00588570]
    // ASSIGNMENT: Store the ratio v2 to this[72] (offset 0x120). [field:this:0x00000120, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_466160(float *this) {
    //     WrapperReturn0();
    //     this[71] = sqrt(this[62] * this[62] - this[70] * this[70]);
    //     double ratio = this[70] / this[62];
    //     FloatConvertWrapper();
    //     this[72] = ratio;
    //     return 0;
    //   }
    // UNRESOLVED: Field semantics are unproven: the stored this[71] and this[72] are consistent with a length and an angle ratio (opposite/hypotenuse), but that interpretation is DERIVED from prose, not independently confirmed.
    // UNRESOLVED: Effects of WrapperReturn0 and FloatConvertWrapper are unknown; they are treated as opaque wrappers.
}
