// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E540
// Canonical corpus name: CollisionTableInit51
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionTableInit51_0044e540.c

void UnknownObject::CollisionTableInit51()
{
    // Unconditional one-time initializer for a contiguous block of six collision-table globals starting at 0x007CD0E0. Sets a table type tag (81) and a UI stat value (27000), zeroes the four intervening state fields, and returns 0.
    // ASSIGNMENT: Set dword_7CD0E0 to 81 (collision table type tag). [global:0x007CD0E0, source:raw]
    // ASSIGNMENT: Zero dword_7CD0E4. [global:0x007CD0E4, source:raw]
    // ASSIGNMENT: Zero dword_7CD0E8. [global:0x007CD0E8, source:raw]
    // ASSIGNMENT: Zero dword_7CD0EC. [global:0x007CD0EC, source:raw]
    // ASSIGNMENT: Zero dword_7CD0F0. [global:0x007CD0F0, source:raw]
    // ASSIGNMENT: Set dword_7CD0F4 to 27000 (UI stat value). [global:0x007CD0F4, source:raw]
    // RETURN: Return 0. [function:0x0044E540, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionTableInit51(void) {
    //     dword_7CD0E0 = 81;
    //     dword_7CD0E4 = 0;
    //     dword_7CD0E8 = 0;
    //     dword_7CD0EC = 0;
    //     dword_7CD0F0 = 0;
    //     dword_7CD0F4 = 27000;
    //     return 0;
    //   }
    // UNRESOLVED: Semantic role of each global in the 0x007CD0E0 block is not packet-evidenced; the DERIVED names in existing analysis (CollisionCellCount, UIStatValue) are unverified proposals, not facts.
    // UNRESOLVED: Relationship of this table block to other collision-table init blocks is unknown.
}
