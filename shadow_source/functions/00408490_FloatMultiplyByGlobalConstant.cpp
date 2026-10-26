// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408490
// Canonical corpus name: ShortComputation_8490
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8490_00408490.c

void UnknownObject::FloatMultiplyByGlobalConstant()
{
    // Scaling helper. Multiplies the first float field of this (offset 0x0) by the global float constant flt_5BE8F8 and returns the product. No guards or side effects.
    // CALCULATION: Multiplies the float at offset 0x0 of this by the global float constant flt_5BE8F8 [field:this:0x00000000, global:0x005BE8F8, source:raw]
    // RETURN: Returns the product [function:0x00408490, source:raw]
    // CALL: Used as a scaling utility by sub_49F870 and SteeringAckermannComputation [caller:0x0049F870, caller:0x004DB170, source:raw]

    // Conservative worker pseudocode:
    //   return flt_5BE8F8 * this[0];
    // UNRESOLVED: The semantic role of flt_5BE8F8 (a global float constant) is only DERIVED as a scale factor and is not confirmed by this packet
    // UNRESOLVED: The meaning of the first float field of this, and why the product is returned as a double, are defined elsewhere
}
