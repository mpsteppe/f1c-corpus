// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543960
// Canonical corpus name: DisplayModeSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DisplayModeSetter_00543960.c

void UnknownObject::DisplayModeSetter()
{
    // __thiscall setter that records a display mode value at this+0x19C (this[103]): a2 of 0x20000, 0x40000 or 0x80000 is stored as-is, any other value stores 0. In every path it ORs the 0x10000 flag into this+0xEC (this[59]) to signal that a UI update is needed, and returns the resulting flag word. Called by sub_4FCC30.
    // GUARD: When a2 equals 0x20000, store 0x20000 into this+0x19C. [field:this:0x0000019C, source:raw]
    // GUARD: When a2 equals 0x40000, store 0x40000 into this+0x19C. [field:this:0x0000019C, source:raw]
    // ASSIGNMENT: In the else path, store 0x80000 into this+0x19C when a2 equals 0x80000, otherwise store 0. [field:this:0x0000019C, source:raw]
    // CALCULATION: In every path, OR the 0x10000 flag into this+0xEC (this[59]) and return the combined value, signaling that a UI update is needed. [field:this:0x000000EC, source:raw]
    // RETURN: Returns the OR'd flag value held in result. [function:0x00543960, source:raw]
    // CALL: Called by sub_4FCC30 to set the display mode on its owning object. [caller:0x004FCC30, source:raw]

    // Conservative worker pseudocode:
    //   int sub_543960(int *this, int a2) {
    //     int result = this[59] | 0x10000;
    //     if (a2 == 0x20000) this[103] = 0x20000;
    //     else if (a2 == 0x40000) this[103] = 0x40000;
    //     else this[103] = (a2 == 0x80000) ? 0x80000 : 0;
    //     this[59] = result;
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the mode constants 0x20000/0x40000/0x80000 in this+0x19C and the exact role of the 0x10000 flag in this+0xEC are not established from this packet
    // UNRESOLVED: Object type is unknown; the fields are known only by offset and behavior
}
