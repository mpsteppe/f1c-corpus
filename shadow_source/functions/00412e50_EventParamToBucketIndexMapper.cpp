// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00412E50
// Canonical corpus name: sub_412E50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_412E50_00412e50.c

void UnknownObject::EventParamToBucketIndexMapper()
{
    // Maps an event parameter a3 to a bucket index written to a1+8, plus a secondary value from sub_414180(a2) written to a1+12. Dispatch mode a2 selects one of two switch jump tables (a2=0 via jpt_412E78 covering cases 1-26; a2=1 via jpt_413097 covering cases 1-24); each case selects a base value that the flag a4 adjusts to one of two variants. Special cases a3=23 (a2=1) and a3=26 (a2=0) compute the index as (a4 != 0 ? 0xFFFFFFE8 : 0) + 265. On a valid mapping writes both fields and returns 1; invalid a2 or a3 returns -1. Called from RaceEventMessageDispatcher and SoundEventDispatcher.
    // ASSIGNMENT: Initialize result to -1 before validating inputs. [source:raw]
    // GUARD: Guard on a2: only a2 == 0 or a2 == 1 enter a switch; any other value returns -1 immediately. [source:raw]
    // CALCULATION: Dispatch on a3 through the a2==0 jump table jpt_412E78 (cases 1-26). [global:0x004132E4, source:raw]
    // CALCULATION: Dispatch on a3 through the a2==1 jump table jpt_413097 (cases 1-24). [global:0x00413344, source:raw]
    // CALCULATION: Each ordinary case selects a bucket-index base; the flag a4 picks one of two variants (a4 != 0 selects the lower base, otherwise the base is offset by 24 for a2==1 or 26 for a2==0). [source:raw]
    // CALCULATION: Special cases a3=23 (a2==1) and a3=26 (a2==0) compute v5 = (a4 != 0 ? 0xFFFFFFE8 : 0) + 265. [source:raw]
    // GUARD: Guard on the computed index v5 >= 0; a negative index leaves result at -1 without writing. [source:raw]
    // ASSIGNMENT: Write the mapped bucket index v5 to a1+8. [field:this:0x00000008, source:raw]
    // CALL: Write the secondary value returned by sub_414180(a2) to a1+12. [callee:0x00414180, field:this:0x0000000C, source:raw]
    // STATE_TRANSITION: Mark the mapping successful: result = 1. [source:raw]
    // RETURN: Return 1 on success, -1 on invalid a2/a3 or negative index. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_412E50(int out, int mode, int param, char flag) {
    //     int v5, v6;
    //     int result = -1;
    //     if (mode) {
    //       if (mode != 1) return result;
    //       switch (param) {
    //         case 1: v5 = flag ? 219 : 243; break;
    //         ...
    //         case 22: v5 = flag ? 240 : 264; break;
    //         case 23: v6 = flag ? 0xFFFFFFE8 : 0; v5 = v6 + 265; break;
    //         case 24: v5 = flag ? 242 : 266; break;
    //         default: return result;
    //       }
    //     } else {
    //       switch (param) {
    //         case 1: v5 = flag ? 214 : 240; break;
    //         ...
    //         case 26: v6 = flag ? 0xFFFFFFE6 : 0; v5 = v6 + 265; break;
    //         default: return result;
    //       }
    //     }
    //     if (v5 >= 0) {
    //       *(int *)(out + 8) = v5;
    //       *(int *)(out + 12) = sub_414180(mode);
    //       result = 1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The semantics of the bucket index range (214-266) and which event buckets it selects are unknown; the flag a4's exact meaning (variant selection) is ungrounded.
    // UNRESOLVED: The purpose of sub_414180(mode)'s return value stored at a1+12 is unknown.
    // UNRESOLVED: Owner object is unidentified; a1 is an output buffer whose struct type is unknown.
}
