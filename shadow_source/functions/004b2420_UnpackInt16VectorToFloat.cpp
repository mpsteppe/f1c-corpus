// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2420
// Canonical corpus name: ArithmeticComparison_2420
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_2420_004b2420.c

void UnknownObject::UnpackInt16VectorToFloat()
{
    // Unpacks a compact vector record: copies three raw dwords from this+0x0/+0x4/+0x8 into a2, then converts three int16 values at this+0xC/+0xE/+0x10 to floats by multiplying by 1/2048 (0.00048828125), writing them into a3. Returns a3. Companion to the packing routine sub_4B2310; used by physics and telemetry code that store position/direction data in short precision.
    // ASSIGNMENT: Copy three dwords from this+0x0, this+0x4, this+0x8 into a2[0], a2[1], a2[2]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Convert the int16 at this+0xC to float by multiplying by 0.00048828125 (1/2048) and store into a3[0]. [field:this:0x0000000C, global:0x0059E77C, source:raw]
    // CALCULATION: Convert the int16 at this+0xE to float by multiplying by 0.00048828125 (1/2048) and store into a3[1]. [field:this:0x0000000E, global:0x0059E77C, source:raw]
    // CALCULATION: Convert the int16 at this+0x10 to float by multiplying by 0.00048828125 (1/2048) and store into a3[2]. [field:this:0x00000010, global:0x0059E77C, source:raw]
    // RETURN: Return a3 (the output float vector). [source:raw]

    // Conservative worker pseudocode:
    //   float* sub_4B2420(_DWORD* this, _DWORD* a2, float* a3) {
    //     a2[0] = this[0]; a2[1] = this[1]; a2[2] = this[2];
    //     a3[0] = (float)*(short*)(this + 0xC/4) * 0.00048828125f;
    //     a3[1] = (float)*(short*)(this + 0xE/4) * 0.00048828125f;
    //     a3[2] = (float)*(short*)(this + 0x10/4) * 0.00048828125f;
    //     return a3;
    //   }
    // UNRESOLVED: Global flt_59E77C (0x0059E77C) is identified in the existing analysis as the short-to-float scale (DERIVED); the raw source inlines the 0.00048828125 literal, so the global's own read site is not visible here.
    // UNRESOLVED: The meaning of the copied three dwords (this+0x0..+0x8) versus the three scaled int16s (this+0xC..+0x10) is interpreted as a packed position/direction pair by the existing analysis; that is DERIVED.
    // UNRESOLVED: The exact record layout and which caller field maps to which component are unresolved.
}
