// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D91E0
// Canonical corpus name: IDToValueMapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IDToValueMapper_004d91e0.c

void UnknownObject::IDToValueMapper()
{
    // Pure integer ID-to-value lookup table. Takes an index a1 and returns a constant via a switch dispatch: 0 -> 100, {1,3,4,5,6,9,10,11,12,14,15,16,18,20,21,22,23,24} -> 50, {2,13} -> 49, {7,8,19} -> 51, 17 -> 52, and 0 for any other value. Uses a jump table at 0x004D921C for dispatch and has no side effects.
    // ASSIGNMENT: Initialize result to 0 before the switch dispatch. [source:raw]
    // GUARD: Switch dispatch on a1 via the read-only jump table at 0x004D921C; any value not handled by a case falls through to default. [global:0x004D921C, source:raw]
    // ASSIGNMENT: Case 0 maps the ID to value 100. [source:raw]
    // ASSIGNMENT: Cases {1,3,4,5,6,9,10,11,12,14,15,16,18,20,21,22,23,24} map the ID to value 50. [source:raw]
    // ASSIGNMENT: Cases {2,13} map the ID to value 49. [source:raw]
    // ASSIGNMENT: Cases {7,8,19} map the ID to value 51. [source:raw]
    // ASSIGNMENT: Case 17 maps the ID to value 52. [source:raw]
    // RETURN: Return the mapped value; the default path returns the initial value 0. [source:raw]

    // Conservative worker pseudocode:
    //   int IDToValueMapper(int a1) {
    //     int result = 0;
    //     switch (a1) {
    //       case 0:                result = 100; break;
    //       case 1: case 3: case 4: case 5: case 6: case 9:
    //       case 10: case 11: case 12: case 14: case 15: case 16:
    //       case 18: case 20: case 21: case 22: case 23: case 24:
    //                              result = 50;  break;
    //       case 2: case 13:       result = 49;  break;
    //       case 7: case 8: case 19: result = 51; break;
    //       case 17:               result = 52;  break;
    //       default:               return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the input ID and the returned values (per-vehicle configuration values, scores, or categories) is caller-dependent and unknown here.
}
