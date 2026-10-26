// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AD00
// Canonical corpus name: LateralForceTorqueCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LateralForceTorqueCalculation_0042ad00.c

void UnknownObject::LateralForceTorqueCalculation()
{
    // Vehicle physics torque helper: computes the lateral torque output from an input force by multiplying the input by the stored lateral force coefficient and a fixed 0.01 scaling constant, then writes the product back into the torque output field. Unconditional single-expression body; runs on the per-frame tick.
    // CALCULATION: Compute the scaled lateral torque: multiply input force a2 by the lateral force coefficient read from this+0x44F4 and by the scaling constant 0.0099999998. [source:raw, field:this:0x000044F4]
    // ASSIGNMENT: Store the computed product into the lateral torque output field this+0x453C (recalculated every frame; an external poke does not persist). [source:raw, field:this:0x0000453C]
    // RETURN: Void __thiscall; implicit return after the store. [source:raw, function:0x0042AD00]

    // Conservative worker pseudocode:
    //   void LateralForceTorqueCalculation(float *this, int a2) {
    //     this[4431] = (double)a2 * this[4413] * 0.0099999998f;
    //   }
    // UNRESOLVED: Global 0x0059E444 (flt_59E444) is reported as a read-only reference inside this function by static analysis, but the raw source shows only literal 0.0099999998; the exact role of the global (e.g. storage behind the scaling constant, or frame delta) is not deterministically tied.
    // UNRESOLVED: Vehicle owner (which physics object holds the 0x44F4 / 0x453C fields) is unknown; the two callers are 00424080 and AIDriverRandomSelector (0042AE20).
    // UNRESOLVED: Whether a2 is a raw force value or a pre-scaled input depends on the callers' contracts.
}
