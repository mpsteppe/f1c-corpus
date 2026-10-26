// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004977E0
// Canonical corpus name: sub_4977E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4977E0_004977e0.c

void UnknownObject::ConfigureStateWithMode()
{
    // Configures a state field and a float threshold from a caller-supplied value and mode. When the mode argument a3 is not -1: stores a2 at this+0x157C, invokes sub_496E90(this, 1) twice, then dispatches on a3 through the jump table jpt_497810 (0x0049787C). Cases 0-3 store the mode into this+0x1578 and set the float at this+0xDC to 1008981770 (0.01f); case 4 sets only the float, leaving the mode field unchanged; the default case returns without writing either field. Returns the result of the second sub_496E90 call.
    // GUARD: If a3 equals -1, skip the entire body and return without touching any field. [source:raw]
    // ASSIGNMENT: Store parameter a2 into this[1375] (byte offset 0x157C). [field:this:0x0000157C]
    // CALL: Call sub_496E90(this, 1) a first time after storing a2. [callee:0x00496E90]
    // CALL: Call sub_496E90(this, 1) a second time; its return value becomes the function result. [callee:0x00496E90]
    // STATE_TRANSITION: Dispatch on a3 through the jump table jpt_497810 at 0x0049787C: cases 0, 1, 2, 3, and 4 lead to state writes. [global:0x0049787C]
    // ASSIGNMENT: Cases 0-3: write the mode value (0, 1, 2, or 3) into this[1374] (byte offset 0x1578) and set the float at this[55] (byte offset 0xDC) to 1008981770 (0.01f). [field:this:0x00001578, field:this:0x000000DC]
    // ASSIGNMENT: Case 4 (and the fall-through tail of case 3): set only the float at this[55] (byte offset 0xDC) to 1008981770 (0.01f), leaving the mode field at 0x1578 unchanged. [field:this:0x000000DC]
    // RETURN: Default switch case returns early without writing either field; the normal path returns the result of the second sub_496E90 call. [source:raw]

    // Conservative worker pseudocode:
    //   int ConfigureStateWithMode(void* this, int a2, int a3) {
    //     if (a3 == -1) return result;
    //     *(int*)(this + 0x157C) = a2;
    //     sub_496E90(this, 1);
    //     int result = sub_496E90(this, 1);
    //     switch (a3) {
    //       case 0: *(int*)(this + 0x1578) = 0; *(int*)(this + 0xDC) = 1008981770; break;
    //       case 1: *(int*)(this + 0x1578) = 1; *(int*)(this + 0xDC) = 1008981770; break;
    //       case 2: *(int*)(this + 0x1578) = 2; *(int*)(this + 0xDC) = 1008981770; break;
    //       case 3: *(int*)(this + 0x1578) = 3;
    //       case 4: *(int*)(this + 0xDC) = 1008981770; break;
    //       default: return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The purpose and side effects of sub_496E90 (called twice with the same argument 1) are unknown; whether the double call is deliberate or redundant is not established.
    // UNRESOLVED: What the mode value at this+0x1578 selects, and what the 0.01f threshold at this+0xDC governs, is not visible in this function.
    // UNRESOLVED: The relationship between the byte-indexed offsets (1374, 1375, 55 in raw source) and the byte offsets used here (0x1578, 0x157C, 0xDC) is a plain dword-index multiplication, not independently evidenced.
}
