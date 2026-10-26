// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC2E8
// Canonical corpus name: StateFlagSetter_c2e8
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateFlagSetter_c2e8_004bc2e8.c

void UnknownObject::SetStateToOne()
{
    // Unconditional setter: writes the literal 1 to the state/mode field at this+0x60. No parameters beyond this, no guard, no callees, no return value.
    // ASSIGNMENT: Write literal 1 to this+0x60 (element this[24]); interpreted as a state/mode field set to one. [field:this:0x00000060, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4BC2E8(void) {
    //     *(int *)((char *)this + 0x60) = 1;
    //   }
    // UNRESOLVED: The state semantics of field 0x60 (which state machine, which enum value 1 denotes) are not grounded in this packet.
    // UNRESOLVED: No static callers or callees; owner object type is unknown.
}
