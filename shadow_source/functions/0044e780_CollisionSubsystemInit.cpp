// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E780
// Canonical corpus name: CollisionSubsystemInit_e780
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionSubsystemInit_e780_0044e780.c

void UnknownObject::CollisionSubsystemInit()
{
    // Unconditional one-time initialization of a six-word collision block at globals 0x007CCFEC..0x007CD000. Writes the block tag 87 to dword_7CCFEC, zeroes four grid/effect state words (dword_7CCFF0, dword_7CCFF4, dword_7CCFF8, dword_7CCFFC), sets render state dword_7CD000 to 9000, and returns 0. No branches, no calls.
    // ASSIGNMENT: result = 0; initialize the return value that is returned unchanged at the end of the function. [function:0x0044E780, source:raw]
    // ASSIGNMENT: dword_7CCFEC = 87; write the block tag/literal to the first word of the collision block. [global:0x007CCFEC, function:0x0044E780, source:raw]
    // ASSIGNMENT: dword_7CCFF0 = 0; zero the first collision state field. [global:0x007CCFF0, function:0x0044E780, source:raw]
    // ASSIGNMENT: dword_7CCFF4 = 0; zero the second collision state field. [global:0x007CCFF4, function:0x0044E780, source:raw]
    // ASSIGNMENT: dword_7CCFF8 = 0; zero the third collision state field. [global:0x007CCFF8, function:0x0044E780, source:raw]
    // ASSIGNMENT: dword_7CCFFC = 0; zero the fourth collision state field. [global:0x007CCFFC, function:0x0044E780, source:raw]
    // ASSIGNMENT: dword_7CD000 = 9000; write the render state literal to the last word of the block. [global:0x007CD000, function:0x0044E780, source:raw]
    // RETURN: return result; return the initialized 0. [function:0x0044E780, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   dword_7CCFEC = 87;
    //   dword_7CCFF0 = 0;
    //   dword_7CCFF4 = 0;
    //   dword_7CCFF8 = 0;
    //   dword_7CCFFC = 0;
    //   dword_7CD000 = 9000;
    //   return result;
    // UNRESOLVED: The exact meaning of the literals 87 and 9000 (block tag vs render state) is DERIVED from the existing analysis, not proven by the packet.
    // UNRESOLVED: The owning subsystem object is unidentified; the packet owner is UNKNOWN.
    // UNRESOLVED: The six globals form a contiguous block, but their per-field semantics beyond the tag and render state are not evidenced.
}
