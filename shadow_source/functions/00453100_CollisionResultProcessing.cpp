// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00453100
// Canonical corpus name: CollisionResultProcessing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionResultProcessing_00453100.c

void UnknownObject::CollisionResultProcessing()
{
    // Processes a collision result object selected by the type field at this+0x0. A conditional flag from ConditionalFlagReturn(&dword_5EA43C), combined with dword_7C569C == 5, forces the outputs (this+0x24 activation state, this+0x28 magnitude) to zero. Otherwise type 0 reads a packed flag via PackedFlagRead(byte_7CA594, this+0x4), type 1 dereferences the object pointer at this+0x1C and reads a dword at +0x10, and type 2 takes the absolute value of a float at *(this+0x20)+4, storing it as the magnitude and deriving a 0/1 activation state from a 0.5 threshold. Returns the resulting activation value.
    // CALL: Call ConditionalFlagReturn(&dword_5EA43C) and treat its return value as the early-out condition flag. [callee:0x00404F10, global:0x005EA43C]
    // GUARD: If the conditional flag is set and dword_7C569C equals 5, take the early zero-output path. [global:0x007C569C, source:raw]
    // ASSIGNMENT: Clear the activation state this[9] (offset 0x24) and magnitude this[10] (offset 0x28) to 0.0. [field:this:0x00000024, field:this:0x00000028]
    // RETURN: Return the conditional flag value on the early-out path. [source:raw]
    // GUARD: Select the packed-flag path when the type field at this+0x0 is 0. [field:this:0x00000000]
    // CALL: Call PackedFlagRead(byte_7CA594, *(this+0x4)) using the parameter field as index/mask. [callee:0x0044F460, global:0x007CA594, field:this:0x00000004]
    // ASSIGNMENT: Shared result store: write the activation value to this[9] (offset 0x24) and set this[10] (offset 0x28) to 1.0 if nonzero, else 0.0. [field:this:0x00000024, field:this:0x00000028, source:raw]
    // RETURN: Return the activation value after the shared result store. [source:raw]
    // GUARD: Select the object-field path when the type field at this+0x0 equals 1. [guard:0, field:this:0x00000000]
    // CALCULATION: Read the activation dword from the dereferenced object at *(this+0x1C) plus offset 0x10, then fall through to the shared result store. [field:this:0x0000001C, field:*(this+0x1C):0x00000010]
    // GUARD: Select the axis path when the type field at this+0x0 equals 2. [guard:1, field:this:0x00000000]
    // CALCULATION: Compute the magnitude as the absolute value of the float at *(this+0x20) plus 4. [field:this:0x00000020, field:*(this+0x20):0x00000004]
    // ASSIGNMENT: Store the computed absolute value into the magnitude output this[10] (offset 0x28). [field:this:0x00000028]
    // CALCULATION: Threshold the magnitude: if it is <= 0.5 the activation state this[9] (offset 0x24) becomes 0, otherwise it becomes 1. [field:this:0x00000024, source:raw]
    // RETURN: Return the activation state (0 or 1) from the axis path. [source:raw]

    // Conservative worker pseudocode:
    //   char CollisionResultProcessing(float *this) {
    //     int result = ConditionalFlagReturn(&dword_5EA43C);
    //     if (result && dword_7C569C == 5) {
    //       this[9] = 0.0f;   // offset 0x24
    //       this[10] = 0.0f;  // offset 0x28
    //       return result;
    //     }
    //     if (*(DWORD *)this == 0) {
    //       result = PackedFlagRead(byte_7CA594, *((DWORD *)this + 1));
    //     } else if (*(DWORD *)this == 1) {
    //       result = *(DWORD *)(*((DWORD *)this + 7) + 0x10);
    //     } else {
    //       result = *(DWORD *)this - 2;
    //       if (*(DWORD *)this == 2) {
    //         long double mag = fabs(*(float *)(*((DWORD *)this + 8) + 4));
    //         this[10] = mag;
    //         result = (mag <= 0.5) ? 0 : 1;
    //         this[9] = result;
    //       }
    //     }
    //     if (result) { *((DWORD *)this + 9) = result; this[10] = 1.0f; }
    //     else { *((DWORD *)this + 9) = 0; this[10] = 0.0f; }
    //     return result;
    //   }
    // UNRESOLVED: The globals flt_59E43C, flt_59E440 and dbl_59E880 are listed in the packet as read but do not appear in the raw decompiled source text; they may be the physical constants backing the 0.5 threshold or related physics data, but their role is unresolved.
    // UNRESOLVED: The semantic meaning of the type enum (0=packed flag, 1=object field, 2=axis) and of the magic session value 5 in dword_7C569C is not established by this packet alone.
}
