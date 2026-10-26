// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BBED0
// Canonical corpus name: AccumulatorWithFixedArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AccumulatorWithFixedArray_004bbed0.c

void UnknownObject::AccumulatorWithFixedArray()
{
    // Accumulates byte values from an input object into a fixed-size accumulator array with a four-entry capacity. Reads the entry count at this+0x3C (this[15]); when the count is at least 4 it adds the input byte (a2+8) into the existing slot at this[2*count+15], otherwise it stores a literal 3 as a type marker at this[2*count+16], stores the input byte at this[2*count+17], and increments the count. Concludes by invoking a comparison helper on the object reached through *this plus 13004 with argument 1 and returning its result.
    // CALCULATION: Reads the entry count this[15] (dword at this+0x3C) into v2. [field:this:0x0000003C, source:raw]
    // GUARD: Branches on whether the accumulator is full (v2 >= 4). [source:raw]
    // CALCULATION: When full, adds the byte at a2+8 into the existing slot at this[2*v2+15]. [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: When not full, stores the literal 3 (type marker) into the slot at this[2*v2+16]. [source:raw]
    // CALCULATION: When not full, stores the byte at a2+8 into the slot at this[2*this[15]++ + 17] and post-increments the entry count at this+0x3C. [field:this:0x0000003C, source:raw]
    // CALL: Invokes a comparison helper on the object reached through *this plus 13004, passing 1 as the comparison argument. [field:this:0x00000000, source:raw]
    // RETURN: Returns the comparison helper's result. [function:0x004BBED0, source:raw]

    // Conservative worker pseudocode:
    //   int AccumulatorWithFixedArray(_DWORD* this, int a2) {
    //       int v2 = this[15];
    //       if (v2 >= 4) {
    //           this[2*v2 + 15] += *(char*)(a2 + 8);
    //       } else {
    //           this[2*v2 + 16] = 3;
    //           this[2*this[15]++ + 17] = *(char*)(a2 + 8);
    //       }
    //       return ArithmeticComparison_5660((_DWORD*)(*this + 13004), 1);
    //   }
    // UNRESOLVED: The comparison helper called on *this + 13004 is not recorded in the packet's callee list, so its address and contract are unknown here.
    // UNRESOLVED: The slot layout (type marker at even indices, accumulated value at odd indices) is inferred from the indexing pattern and not directly evidenced.
    // UNRESOLVED: The meaning of the literal 3 stored as a type marker is unverified.
    // UNRESOLVED: The byte at a2+8 is read as a signed char; its signedness semantics are unclear.
}
