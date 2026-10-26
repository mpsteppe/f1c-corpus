// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00512334
// Canonical corpus name: DriverStateFlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DriverStateFlagSet_00512334.c

void UnknownObject::DriverStateFlagSet()
{
    // When the state byte at this+0x117 is below 8, OR bit 4 (value 4) into the flags DWORD at this+0x60 and write 8 to the driver-state byte at this+0x118. Always returns the input a1. Conditionally elevates driver state once the byte at 0x117 has not yet reached 8.
    // ASSIGNMENT: result = a1: capture the object/context pointer for the return value. [source:raw]
    // GUARD: Guard: only proceed when the unsigned byte at this+0x117 is less than 8 (state threshold); when it is 8 or greater, no modification occurs. [field:this:0x00000117, guard:0, source:raw]
    // ASSIGNMENT: *(this+0x60) |= 4u: OR bit 4 into the flags DWORD at offset 0x60. [field:this:0x00000060, source:raw]
    // ASSIGNMENT: *(this+0x118) = 8: write the byte 8 into the state byte at offset 0x118. [field:this:0x00000118, source:raw]
    // RETURN: Return the original a1 value. [function:0x00512334, source:raw]
    // CALL: Called by sub_50210E (0x0050210E) as a state-advancing helper that flags the object and promotes its state byte to 8. [caller:0x0050210E, source:raw]

    // Conservative worker pseudocode:
    //   int DriverStateFlagSet(int a1) {
    //     if (*(unsigned char*)(a1 + 0x117) < 8u) {
    //       *(unsigned int*)(a1 + 0x60) |= 4u;
    //       *(unsigned char*)(a1 + 0x118) = 8;
    //     }
    //     return a1;
    //   }
    // UNRESOLVED: Meaning of the 8-valued state threshold at 0x117, the bit-4 flag at 0x60, and the state byte value 8 at 0x118 depends on the enclosing driver/object state machine, whose definition is not in this function.
}
