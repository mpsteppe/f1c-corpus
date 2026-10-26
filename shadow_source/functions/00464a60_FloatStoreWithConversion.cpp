// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464A60
// Canonical corpus name: FloatStoreWithConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatStoreWithConversion_00464a60.c

void UnknownObject::FloatStoreWithConversion()
{
    // Stores an input value to this+0x220, maps it through a cascading threshold chain (625000 / 28800 / 7200 / 2975) to pick a conversion divisor (32.0 / 20.0 / 16.0 / 10.0 / 6.0), computes 1.0 / divisor / 0.0049999999, truncates via CRTFtol, stores the byte at this+0x22A and returns it. Called by ShortComputation_5430 (0x00465430).
    // ASSIGNMENT: Store the input dword a2 at this+0x220. [field:this:0x00000220, source:raw]
    // GUARD: Cascading tier selection reading threshold/divisor float constants from the constant pool referenced by the packet globals (0x0059E5FC, 0x0059E8EC, 0x0059E940, 0x0059EC20, 0x0059EED0, 0x0059F138): if a2 >= 625000 divisor = 32.0; else if a2 >= 28800 divisor = 20.0; else if a2 >= 7200 divisor = 16.0; else if a2 >= 2975 divisor = 10.0; else divisor = 6.0. [global:0x0059E5FC, global:0x0059E8EC, global:0x0059E940, global:0x0059EC20, global:0x0059EED0, global:0x0059F138, source:raw]
    // CALCULATION: Compute 1.0 / divisor / 0.0049999999; the 1.0 constant is carried at global dbl_59E420. [global:0x0059E420, source:raw]
    // CALL: Convert the floating-point result to an integer with CRTFtol (truncation). [callee:0x00587BDC, source:raw]
    // ASSIGNMENT: Store the computed byte result at this+0x22A. [field:this:0x0000022A, source:raw]
    // RETURN: Return the converted byte result. [source:raw]

    // Conservative worker pseudocode:
    //   this[0x220] = a2;
    //   if (a2 < 625000) {
    //     if (a2 < 28800) {
    //       if (a2 < 7200) {
    //         if (a2 < 2975) v3 = 6.0; else v3 = 10.0;
    //       } else v3 = 16.0;
    //     } else v3 = 20.0;
    //   } else v3 = 32.0;
    //   result = CRTFtol(1.0 / v3 / 0.0049999999);
    //   this[0x22A] = result;
    //   return result;
    // UNRESOLVED: Exact mapping of the tier threshold/divisor literals to the seven named constant globals (0x0059E420, 0x0059E5FC, 0x0059E8EC, 0x0059E940, 0x0059EC20, 0x0059EED0, 0x0059F138) is not evidenced by the raw source, which shows only the literals.
    // UNRESOLVED: The semantic meaning of the thresholds (prior analysis reads them as speed/RPM tiers) is DERIVED, not confirmed by this packet.
}
