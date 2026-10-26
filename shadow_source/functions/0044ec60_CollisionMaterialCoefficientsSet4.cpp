// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044EC60
// Canonical corpus name: CollisionMaterialCoefficientsSet4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionMaterialCoefficientsSet4_0044ec60.c

void UnknownObject::CollisionMaterialCoefficientsSet4()
{
    // Straight-line initializer for a block of six consecutive global dwords (0x007CA4A0-0x007CA4B4). Sets the first dword to 100, clears the next four to 0, sets the last to 18000, then returns 0. No branches and no calls.
    // ASSIGNMENT: Write 100 to dword_7CA4A0 (block tag / material ID). [global:0x007CA4A0, source:raw]
    // ASSIGNMENT: Write 0 to dword_7CA4A4. [global:0x007CA4A4]
    // ASSIGNMENT: Write 0 to dword_7CA4A8. [global:0x007CA4A8]
    // ASSIGNMENT: Write 0 to dword_7CA4AC. [global:0x007CA4AC]
    // ASSIGNMENT: Write 0 to dword_7CA4B0. [global:0x007CA4B0]
    // ASSIGNMENT: Write 18000 to dword_7CA4B4 (collision world range). [global:0x007CA4B4]
    // RETURN: Return 0. [function:0x0044EC60, source:raw]

    // Conservative worker pseudocode:
    //   dword_7CA4A0 = 100;
    //   dword_7CA4A4 = 0;
    //   dword_7CA4A8 = 0;
    //   dword_7CA4AC = 0;
    //   dword_7CA4B0 = 0;
    //   dword_7CA4B4 = 18000;
    //   return 0;
    // UNRESOLVED: The specific role of each dword in the collision/material block is not proven; names are inherited DERIVED proposals.
    // UNRESOLVED: Whether this function is one case of a per-block coefficient initializer series is not proven (no caller evidence).
}
