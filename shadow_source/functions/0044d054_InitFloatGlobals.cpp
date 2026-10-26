// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D054
// Canonical corpus name: InitFloatGlobals_d054
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitFloatGlobals_d054_0044d054.c

void UnknownObject::InitFloatGlobals()
{
    // Straight-line initializer for two adjacent 4-byte globals at 0x007CA3E0: writes the dword dword_7CA3E0 to -1082130432, the raw integer spelling for the float -1.0, and sets the float flt_7CA3E4 to 0.0. Likely seeds a (minus-one, zero) pair used as a float-range default.
    // ASSIGNMENT: Write -1082130432 to the dword global dword_7CA3E0. [global:0x007CA3E0, source:raw]
    // ASSIGNMENT: Write 0.0 to the adjacent float global flt_7CA3E4. [global:0x007CA3E4, source:raw]

    // Conservative worker pseudocode:
    //   void InitFloatGlobals() {
    //     dword_7CA3E0 = -1082130432;
    //     flt_7CA3E4 = 0.0;
    //   }
    // UNRESOLVED: Interpretation of -1082130432 as the float -1.0 is DERIVED; the packet only states the raw integer literal.
    // UNRESOLVED: Meaning of the (dword_7CA3E0, flt_7CA3E4) pair and which object owns the globals is unknown.
}
