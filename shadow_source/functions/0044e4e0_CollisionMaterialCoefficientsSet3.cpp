// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E4E0
// Canonical corpus name: CollisionMaterialCoefficientsSet3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionMaterialCoefficientsSet3_0044e4e0.c

void UnknownObject::CollisionMaterialCoefficientsSet3()
{
    // Unconditional init of a six-dword collision material coefficients block: sets dword_7CD0C8 to 80 (material count/identifier), zeroes dword_7CD0CC through dword_7CD0D8, sets dword_7CD0DC to 18000 (range threshold literal), and returns 0. No calls and no guards.
    // ASSIGNMENT: dword_7CD0C8 = 80 (material count/identifier). [global:0x007CD0C8, source:raw]
    // ASSIGNMENT: dword_7CD0CC = 0. [global:0x007CD0CC, source:raw]
    // ASSIGNMENT: dword_7CD0D0 = 0. [global:0x007CD0D0, source:raw]
    // ASSIGNMENT: dword_7CD0D4 = 0. [global:0x007CD0D4, source:raw]
    // ASSIGNMENT: dword_7CD0D8 = 0. [global:0x007CD0D8, source:raw]
    // ASSIGNMENT: dword_7CD0DC = 18000 (range threshold literal). [global:0x007CD0DC, source:raw]
    // RETURN: Return 0 (no calls, no guards; all writes unconditional). [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionMaterialCoefficientsSet3() {
    //     dword_7CD0C8 = 80;
    //     dword_7CD0CC = 0; dword_7CD0D0 = 0; dword_7CD0D4 = 0; dword_7CD0D8 = 0;
    //     dword_7CD0DC = 18000;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of the literal 80 and the meaning of the 18000 threshold are not established; the existing analysis labels dword_7CD0C8 material count and dword_7CD0DC range threshold (DERIVED) with no consumer evidence.
    // UNRESOLVED: The 'Set 3' association comes from the ABI name Collision_Material_Coefficients_Set_3; no callers or callees are recorded statically (top-level or indirect-only).
}
