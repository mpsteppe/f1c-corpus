// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00454C20
// Canonical corpus name: EnumToIDMappingWithDefaultFallthrough
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EnumToIDMappingWithDefaultFallthrough_00454c20.c

void UnknownObject::EnumToIDMappingWithDefaultFallthrough()
{
    // Maps a single integer enum argument to an ID via a jump table with a default fallthrough. Case 1 maps to ID 89; a large group of cases maps to -1; any other value passes through unchanged.
    // ASSIGNMENT: result = a1; the incoming enum value is used as the fallthrough result. [abi:lead, function:0x00454C20, source:raw]
    // GUARD: Switch dispatch on a1 through the jump table jpt_454C36. [function:0x00454C20, global:0x00454C4C, source:raw]
    // ASSIGNMENT: case 1: result = 89. [function:0x00454C20, source:raw]
    // ASSIGNMENT: cases 2-13, 42, 54, 58-83, 87, 88, 156, 183, 197, 199, 201, 207, 209, 210, 211: result = -1. [function:0x00454C20, source:raw]
    // RETURN: Return result; non-listed values fall through and return the original a1 unchanged. [function:0x00454C20, source:raw]

    // Conservative worker pseudocode:
    //   int EnumToIDMappingWithDefaultFallthrough(int a1) {
    //     int result = a1;
    //     switch (a1) {
    //       case 1: result = 89; break;
    //       case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    //       case 9: case 10: case 11: case 12: case 13: case 42: case 54:
    //       case 58: case 59: case 60: case 61: case 62: case 63: case 64:
    //       case 65: case 66: case 67: case 68: case 69: case 70: case 71:
    //       case 72: case 73: case 74: case 75: case 76: case 77: case 78:
    //       case 79: case 80: case 81: case 82: case 83: case 87: case 88:
    //       case 156: case 183: case 197: case 199: case 201: case 207:
    //       case 209: case 210: case 211: result = -1; break;
    //       default: return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the enum-to-ID mapping (which enum this consumes and what ID 89 / -1 signify) is not established.
    // UNRESOLVED: Role of byte_454C58, read-only data adjacent to the jump table, is unclear.
}
