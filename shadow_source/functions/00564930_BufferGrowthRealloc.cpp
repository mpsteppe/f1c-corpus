// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564930
// Canonical corpus name: AccumulatorWithReallocOnGrowth
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AccumulatorWithReallocOnGrowth_00564930.c

void UnknownObject::BufferGrowthRealloc()
{
    // Grows a dynamic buffer. Computes the new capacity as this[3] (growth increment) plus this[1] (current capacity), stores it back to this+0x4, calls sub_58B5D4 with the old buffer pointer (this[5]) and the byte size new_capacity times this[2] (element stride), then stores the returned pointer into this+0x14 and returns it.
    // CALCULATION: New capacity v2 computed as this[3] (growth increment) plus this[1] (current capacity) [field:this:0x0000000C, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Stores the new capacity v2 back into this[1] at offset 0x4 [field:this:0x00000004, source:raw]
    // CALL: Calls sub_58B5D4 with the old buffer pointer (this[5]) and byte size v2 times this[2] (element stride) [callee:0x0058B5D4, field:this:0x00000014, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Stores the realloc result as the new buffer pointer at this+0x14 [field:this:0x00000014, source:raw]
    // RETURN: Returns the new buffer pointer from sub_58B5D4 [function:0x00564930, source:raw]
    // STATE_TRANSITION: Invoked by AudioStackPushWithOverflowRealloc when the buffer is full and must grow [caller:0x005648D0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = this[3] + this[1];
    //   v3 = (void*)this[5];
    //   this[1] = v2;
    //   result = sub_58B5D4(v3, v2 * this[2]);
    //   this[5] = result;
    //   return result;
    // UNRESOLVED: sub_58B5D4 exact realloc semantics (and whether it frees the old block) are defined outside this packet
    // UNRESOLVED: The element-size interpretation of this[2] and whether the growth increment this[3] is signed are not confirmed by this packet alone
}
