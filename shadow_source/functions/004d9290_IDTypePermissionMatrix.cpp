// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D9290
// Canonical corpus name: IDTypePermissionMatrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IDTypePermissionMatrix_004d9290.c

void UnknownObject::IDTypePermissionMatrix()
{
    // Permission predicate returning 1 (permitted) or 0 (denied) for an index a1 (range 0-24) under a mode a2 (range 1-5). The outer switch on a2 is dispatched through jump table jpt_4D929C (0x004D92E4). Mode 1 permits only the subset {1,3,6,7,9,10,11,12,20,21,22,23}, dispatched via jpt_4D92C6 (0x004D9318). Mode 2 permits {0,1,6,7,8,9,10,11,12,13,14,15,16,17,18,19,24}, dispatched via jpt_4D92B6 (0x004D92F8) and byte_4D9300 (0x004D9300). Modes 3-5 permit every index 0-24, dispatched via jpt_4D92D6 (0x004D937C). Modes outside 1-5, and indices outside the permitted subset for the active mode, return 0.
    // ASSIGNMENT: Initialize the result to 0 (denied default). [source:raw]
    // GUARD: Dispatch on mode a2 through the outer jump table jpt_4D929C (0x004D92E4); modes outside 1-5 return 0 immediately. [global:0x004D92E4, source:raw]
    // GUARD: For mode a2 == 1, dispatch on index a1 through jpt_4D92C6 (0x004D9318); only indices {1,3,6,7,9,10,11,12,20,21,22,23} proceed to the permitted outcome, all others return 0. [global:0x004D9318, source:raw]
    // GUARD: For mode a2 == 2, dispatch on index a1 through jpt_4D92B6 (0x004D92F8) and byte_4D9300 (0x004D9300); only indices {0,1,6,7,8,9,10,11,12,13,14,15,16,17,18,19,24} proceed to the permitted outcome, all others return 0. [global:0x004D92F8, global:0x004D9300, source:raw]
    // GUARD: For modes a2 == 3, 4 and 5, dispatch on index a1 through jpt_4D92D6 (0x004D937C); every index in 0-24 is permitted, indices outside that range return 0. [global:0x004D937C, source:raw]
    // STATE_TRANSITION: On a permitted index/mode combination, set the result to 1 (permitted). [source:raw]
    // RETURN: Return the permission result: 1 permitted, 0 denied. [source:raw]

    // Conservative worker pseudocode:
    //   char IDTypePermissionMatrix(int index, int mode) {
    //     char result = 0;
    //     switch (mode) {
    //       case 1:
    //         switch (index) {
    //           case 1: case 3: case 6: case 7: case 9: case 10: case 11: case 12:
    //           case 20: case 21: case 22: case 23: result = 1; break;
    //           default: return result;
    //         }
    //         break;
    //       case 2:
    //         switch (index) {
    //           case 0: case 1: case 6: case 7: case 8: case 9: case 10: case 11:
    //           case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
    //           case 24: result = 1; break;
    //           default: return result;
    //         }
    //         break;
    //       case 3:
    //       case 4:
    //       case 5:
    //         switch (index) {
    //           case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
    //           case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
    //           case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23:
    //           case 24: result = 1; break;
    //           default: return result;
    //         }
    //         break;
    //       default:
    //         return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The semantic meaning of index a1 (0-24) and mode a2 (1-5) is not confirmed; the 'race mode' interpretation in prior analysis is DERIVED.
    // UNRESOLVED: The dispatch globals are jump-table data; their exact encoding is not independently verified.
    // UNRESOLVED: The use of the permission result by caller sub_4D88D0 (0x004D88D0) is outside this packet.
}
