// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC2D0
// Canonical corpus name: sub_4BC2D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BC2D0_004bc2d0.c

void UnknownObject::PitTrackerStateInit()
{
    // Initializes three pit-timer state fields on the receiver: zeroes the counter field this[3] (this+0xC), stores the passed index a2 into this[25] (this+0x64), and sets the state/mode field this[24] (this+0x60) to literal 2. Returns the stored index a2 unchanged. Called by PitTimerStateInit (004D23D0).
    // ASSIGNMENT: Hold the incoming index a2 in result for the return value. [source:raw]
    // ASSIGNMENT: Zero the counter field this[3] (this+0xC). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store the index a2 into this[25] (this+0x64). [field:this:0x00000064, source:raw]
    // ASSIGNMENT: Set the state/mode field this[24] (this+0x60) to literal 2. [field:this:0x00000060, source:raw]
    // RETURN: Return the original index a2. [source:raw]
    // CALL: Invoked by PitTimerStateInit (004D23D0) as its state-initialization step. [caller:0x004D23D0, source:raw]

    // Conservative worker pseudocode:
    //   int PitTrackerStateInit(int* this, int index) {
    //     this[3] = 0;
    //     this[25] = index;
    //     this[24] = 2;
    //     return index;
    //   }
    // UNRESOLVED: Meaning of the state value 2 written to this+0x60 (mode/state enum not defined in the packet).
    // UNRESOLVED: The counter field this+0xC is zeroed but never read in this function; its role in the pit-timer state machine is outside this packet.
    // UNRESOLVED: Whether this+0x64 holds a driver or a vehicle index is inferred from the skeleton fill, not grounded in packet evidence.
}
