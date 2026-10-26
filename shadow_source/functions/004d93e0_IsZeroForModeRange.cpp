// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D93E0
// Canonical corpus name: RangeCheck_93e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RangeCheck_93e0_004d93e0.c

void UnknownObject::IsZeroForModeRange()
{
    // Free __stdcall predicate: for a2 in {1,2,3,4,5} returns whether a1 equals 0; for any other a2 the default path returns false. The switch dispatch reads the jump table at 0x004D9400, and the a1==0 result is computed only for the five accepted mode values. Returns false when a2 is outside the accepted range.
    // ASSIGNMENT: Initialize result to false before the switch dispatch. [source:raw]
    // STATE_TRANSITION: Switch on a2 via the jump table at 0x004D9400; cases 1 through 5 set result = (a1 == 0), all other values take the default path. [global:0x004D9400, source:raw]
    // RETURN: Default case returns false immediately without evaluating a1. [source:raw]
    // RETURN: Return result after the switch; true only when a2 was in 1..5 and a1 was zero. [source:raw]
    // CALL: Invoked by sub_4D88D0, whose calling context determines the meaning of the mode values and of the zero test. [caller:0x004D88D0]

    // Conservative worker pseudocode:
    //   bool IsZeroForModeRange(int a1, int a2) {
    //     bool result = false;
    //     switch (a2) {
    //       case 1: case 2: case 3: case 4: case 5:
    //         result = (a1 == 0);
    //         break;
    //       default:
    //         return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The semantic meaning of the five accepted a2 values (1..5) and of the a1==0 test depends on the caller sub_4D88D0.
    // UNRESOLVED: The jump table global 0x004D9400 is a compiler artifact of the switch; its layout is implied by the cases but not directly evidenced here.
}
