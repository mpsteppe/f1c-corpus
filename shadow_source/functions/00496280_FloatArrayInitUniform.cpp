// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00496280
// Canonical corpus name: FloatArrayInitWithRandom
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatArrayInitWithRandom_00496280.c

void UnknownObject::FloatArrayInitUniform()
{
    // Fills the 16 consecutive floats starting at this + 1419 (offset 0x162C) with the uniformly spaced sequence 0.0, 0.0625, ..., 0.9375, computed as (double)v4 * 0.0625 for v4 = 0..15. Each computed value is passed to sub_5881F0 before being stored. Despite the packet ABI lead name (Float_Array_Init_with_Random), the source performs no randomization; it writes a fixed uniform step table.
    // ASSIGNMENT: Initialize the loop counter v1 and its copy v4 to 0, and set v2 to this + 1419 (start of the 16-float array at offset 0x162C). [field:this:0x0000162C, source:raw]
    // LOOP: Repeat while v1 < 16, writing one element per iteration and advancing v2 and v1. [source:raw]
    // CALCULATION: Compute v3 = (double)v4 * 0.0625; the packet lists the double constant dbl_5AC9C8 as a read global, which the existing analysis (DERIVED) identifies as this 0.0625 multiplier. [global:0x005AC9C8, source:raw]
    // CALL: Pass the computed v3 to sub_5881F0 before it is stored. [callee:0x005881F0, source:raw]
    // ASSIGNMENT: Store v3 into the current element *v2 of the float array at offset 0x162C. [field:this:0x0000162C, source:raw]

    // Conservative worker pseudocode:
    //   void FloatArrayInitUniform(float *this) {
    //       int v1 = 0;
    //       float *v2 = this + 1419;
    //       do {
    //           double v3 = (double)v1 * 0.0625;
    //           sub_5881F0(v3);
    //           *v2 = (float)v3;
    //           v1++;
    //           v2++;
    //       } while (v1 < 16);
    //   }
    // UNRESOLVED: The packet global flt_59E9E0 is not referenced by name in the raw source text; the existing analysis (DERIVED) attributes it to sub_5881F0 as a scale factor, but that role is not established by this function's own source.
    // UNRESOLVED: The ABI lead name Float_Array_Init_with_Random implies randomization, but the source writes a fixed uniform sequence; no random source appears in the packet.
    // UNRESOLVED: The purpose of the produced lookup/noise table and the contract of sub_5881F0 are not documented in this packet.
}
