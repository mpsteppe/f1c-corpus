// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D520
// Canonical corpus name: CollisionStateInit17
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStateInit17_0044d520.c

void UnknownObject::CollisionStateInit17()
{
    // Initializes a collision state block: writes type literal 17 to dword_7CCD20, zeroes five adjacent dword fields (7CCD24 through 7CCD34), and returns 0. Unconditional, no arguments, no callees.
    // ASSIGNMENT: Set dword_7CCD20 to type literal 17 (0x11), marking this collision state block variant. [global:0x007CCD20]
    // ASSIGNMENT: Zero dword_7CCD24. [global:0x007CCD24]
    // ASSIGNMENT: Zero dword_7CCD28. [global:0x007CCD28]
    // ASSIGNMENT: Zero dword_7CCD2C. [global:0x007CCD2C]
    // ASSIGNMENT: Zero dword_7CCD30. [global:0x007CCD30]
    // ASSIGNMENT: Zero dword_7CCD34. [global:0x007CCD34]
    // RETURN: Return integer 0. [function:0x0044D520]

    // Conservative worker pseudocode:
    //   int CollisionStateInit17() {
    //     dword_7CCD20 = 17;
    //     dword_7CCD24 = 0;
    //     dword_7CCD28 = 0;
    //     dword_7CCD2C = 0;
    //     dword_7CCD30 = 0;
    //     dword_7CCD34 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Whether dword_7CCD20..dword_7CCD34 form a contiguous initialized block or one record is unproven; equal spacing (0x4) suggests an array stride but no packet evidence shows a loop or shared base pointer.
    // UNRESOLVED: Semantic purpose of the five zeroed dwords is unknown; labels are DERIVED at best and left unclaimed.
}
