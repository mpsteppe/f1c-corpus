// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C850
// Canonical corpus name: PerElementArrayReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerElementArrayReset_0045c850.c

void UnknownObject::PerElementArrayReset()
{
    // Reset one indexed element (index a2) of a per-element array held in this: zero two 32-bit elements (this[a2+5], this[a2+109]), two bytes (this+a2+852, this+a2+956), a 32-byte block (this[8*a2+265]), a 16-bit element (word index a2+2402), and store -1082130432 into 32-bit element this[a2+1097]; returns 0. Called from ArrayInitializationLoop (0x0045C8B0) and NetCommPlayerSlotSync (0x0045FC50).
    // ASSIGNMENT: Zero the 32-bit element this[a2+5]. [source:raw]
    // ASSIGNMENT: Zero the 32-bit element this[a2+109]. [source:raw]
    // ASSIGNMENT: Zero the byte at this + a2 + 852. [source:raw]
    // ASSIGNMENT: Zero the byte at this + a2 + 956. [source:raw]
    // ASSIGNMENT: result = 0. [source:raw]
    // CALL: memset(&this[8*a2 + 265], 0, 0x20u) clears the 32-byte per-element block. [source:raw]
    // ASSIGNMENT: Zero the 16-bit element at word index a2+2402. [source:raw]
    // ASSIGNMENT: Store -1082130432 into the 32-bit element this[a2+1097]. [source:raw]
    // RETURN: Return result, which is 0. [source:raw]

    // Conservative worker pseudocode:
    //   this[a2 + 5] = 0;
    //   this[a2 + 109] = 0;
    //   *((_BYTE *)this + a2 + 852) = 0;
    //   *((_BYTE *)this + a2 + 956) = 0;
    //   memset(&this[8 * a2 + 265], 0, 0x20u);
    //   *((_WORD *)this + a2 + 2402) = 0;
    //   this[a2 + 1097] = -1082130432;
    //   return 0;
    // UNRESOLVED: memset has no callee address evidence reference in the packet.
    // UNRESOLVED: Parameter a2 is an element index; the containing per-element array layout, element count and size are unknown.
    // UNRESOLVED: The owning class/object type is unknown.
}
