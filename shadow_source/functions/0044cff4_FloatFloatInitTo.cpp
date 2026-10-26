// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CFF4
// Canonical corpus name: FloatFloatInitTo
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatFloatInitTo_0044cff4.c

void UnknownObject::FloatFloatInitTo()
{
    // Straight-line initializer for two adjacent 4-byte globals at 0x007CC9F4: sets the float flt_7CC9F4 to 0.0 and the dword dword_7CC9F8 to 1065353216, the raw integer spelling for the float 1.0. Likely seeds a (zero, one) pair used as a float-scale baseline.
    // ASSIGNMENT: Write 0.0 to the float global flt_7CC9F4. [global:0x007CC9F4, source:raw]
    // ASSIGNMENT: Write 1065353216 to the adjacent dword global dword_7CC9F8. [global:0x007CC9F8, source:raw]

    // Conservative worker pseudocode:
    //   void FloatFloatInitTo() {
    //     flt_7CC9F4 = 0.0;
    //     dword_7CC9F8 = 1065353216;
    //   }
    // UNRESOLVED: Interpretation of 1065353216 as the float 1.0 is DERIVED; the packet only states the raw integer literal.
    // UNRESOLVED: Meaning of the (flt_7CC9F4, dword_7CC9F8) pair and which object owns the globals is unknown.
}
