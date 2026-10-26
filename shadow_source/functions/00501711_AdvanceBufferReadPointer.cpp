// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00501711
// Canonical corpus name: BufferPointerAdjust
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferPointerAdjust_00501711.c

void UnknownObject::AdvanceBufferReadPointer()
{
    // Buffer read-tracking advance: loads the buffer tracking struct pointer stored at a1+0x14, increments its first dword (current read position) by a2, decrements its second dword (remaining byte count) by a2, and returns the tracking pointer. No guards, no calls; pure stateful pointer arithmetic on the caller-supplied tracking struct.
    // ASSIGNMENT: Load result = *(a1 + 0x14), the pointer to the buffer tracking struct. [field:this:0x00000014, source:raw]
    // CALCULATION: Advance the current read position: result[0] += a2. [field:*(this+0x14):0x00000000, source:raw]
    // CALCULATION: Decrease the remaining byte count: result[1] -= a2. [field:*(this+0x14):0x00000004, source:raw]
    // RETURN: Return result, the buffer tracking pointer. [function:0x00501711, source:raw]

    // Conservative worker pseudocode:
    //   int* sub_501711(int* tracking, int amount) {
    //     int* result = *(int**)((char*)tracking + 0x14);
    //     result[0] += amount;
    //     result[1] -= amount;
    //     return result;
    //   }
    // UNRESOLVED: a1's owner object and the exact layout of the buffer tracking struct at *(a1+0x14) are not established by the packet; the two dwords are conventionally a current position and a remaining count.
    // UNRESOLVED: Units of a2 (bytes vs elements) and any bounds validation are caller responsibilities; this function performs no checks.
}
