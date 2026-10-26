// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D640
// Canonical corpus name: CollisionTableInit14
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionTableInit14_0044d640.c

void UnknownObject::CollisionTableInit14()
{
    // Initializes a collision table block: writes type literal 20 to dword_7CCC68, zeroes five adjacent dword fields (7CCC6C through 7CCC7C), and returns 0. Unconditional, no arguments, no callees.
    // ASSIGNMENT: Set dword_7CCC68 to type literal 20 (0x14), marking this collision table entry variant. [global:0x007CCC68]
    // ASSIGNMENT: Zero dword_7CCC6C. [global:0x007CCC6C]
    // ASSIGNMENT: Zero dword_7CCC70. [global:0x007CCC70]
    // ASSIGNMENT: Zero dword_7CCC74. [global:0x007CCC74]
    // ASSIGNMENT: Zero dword_7CCC78. [global:0x007CCC78]
    // ASSIGNMENT: Zero dword_7CCC7C. [global:0x007CCC7C]
    // RETURN: Return integer 0. [function:0x0044D640]

    // Conservative worker pseudocode:
    //   int CollisionTableInit14() {
    //     dword_7CCC68 = 20;
    //     dword_7CCC6C = 0;
    //     dword_7CCC70 = 0;
    //     dword_7CCC74 = 0;
    //     dword_7CCC78 = 0;
    //     dword_7CCC7C = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Whether dword_7CCC68..dword_7CCC7C form a contiguous initialized block or one record is unproven; equal spacing (0x4) suggests an array stride but no packet evidence shows a loop or shared base pointer.
    // UNRESOLVED: Semantic purpose of the five zeroed dwords is unknown; labels are DERIVED at best and left unclaimed.
}
