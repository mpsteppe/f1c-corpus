// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587730
// Canonical corpus name: sub_587730
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587730_00587730.c

void UnknownObject::AppendFieldsToBuffer()
{
    // Encodes fields from an input object a2 into a growing buffer tracked at this+0x400, with a capacity guard against *(*(this+0x414)+0x80). Computes a byte count from a2[9] (bit field sized to whole bytes), copies a2[5] data via qmemcpy, appends the original encoded value byte, then copies a data pointer from UtilityFunction_6a90 (00586A90). On the first call (counter this+0x408 was 0) stores the bitmask from BitmaskGenerationFromBitArray (00586DE0) at this+0x40C. When the input value exceeds 255, diverts to VTableDispatchWithConditionalCall (00585380). Overflow invokes sub_5878A0 (005878A0).
    // CALL: SingleFunctionCallWrapper_6a80 (00586A80) is called with a2 to obtain the initial encoded value v3; v3 is kept as byte v11 [callee:0x00586A80, source:raw]
    // GUARD: If v3 is greater than 255, the function diverts to VTableDispatchWithConditionalCall (00585380) with a2 and returns its result [callee:0x00585380, source:raw]
    // CALCULATION: Computes byte count v9 from the bit field a2[9]: (a2[9] >> 3) rounded up when a2[9] is not a multiple of 8 [source:raw]
    // CALL: FieldGetterAt0x400 (00587880) is called to obtain the current accumulated size; together with v9 and v3 it is checked against capacity v5 read from *(*(this+0x414)+0x80) [callee:0x00587880, field:*(this+0x414):0x00000080, field:this:0x00000414, source:raw]
    // GUARD: If v9 + v3 + current size reaches the capacity limit v5, overflow handling sub_5878A0 (005878A0) is invoked with 0 [callee:0x005878A0, source:raw]
    // ASSIGNMENT: Writes byte v9 into the buffer at current position *(this+0x400), then advances this+0x400 by one [field:this:0x00000400, source:raw]
    // ASSIGNMENT: Copies v9 bytes from payload v10 (a2[5]) into the buffer via qmemcpy and advances this+0x400 by v9 [field:this:0x00000400, source:raw]
    // ASSIGNMENT: Appends the encoded value byte v11 to the buffer and advances this+0x400 by one [field:this:0x00000400, source:raw]
    // CALL: UtilityFunction_6a90 (00586A90) is called with a2 to obtain the final data pointer, and v12 bytes are copied into the buffer via qmemcpy; this+0x400 advances by v12 [callee:0x00586A90, field:this:0x00000400, source:raw]
    // GUARD: If the previous call counter this+0x408 was zero (first call), the bitmask from BitmaskGenerationFromBitArray (00586DE0) over a2 is stored at this+0x40C [callee:0x00586DE0, field:this:0x00000408, field:this:0x0000040C, source:raw]
    // STATE_TRANSITION: Increments the call counter this+0x408 and returns the new counter value [field:this:0x00000408, source:raw]
    // RETURN: Returns the incremented call counter this+0x408; on the v3 > 255 path returns the VTableDispatchWithConditionalCall result [callee:0x00585380, field:this:0x00000408, source:raw]

    // Conservative worker pseudocode:
    //   v3 = SingleFunctionCallWrapper_6a80(a2);
    //   if (v3 > 255) return VTableDispatchWithConditionalCall(*(int**)(this+0x414), a2);
    //   payload = a2[5];
    //   bytecount = (a2[9] >> 3) + ((a2[9] & 7) != 0);
    //   size = bytecount + v3 + FieldGetterAt0x400(this);
    //   capacity = *(int*)(*(int*)(this+0x414) + 0x80);
    //   if (size >= capacity) sub_5878A0(0);
    //   buffer[this+0x400++] = bytecount;
    //   memcpy(buffer + this+0x400, payload, bytecount); this+0x400 += bytecount;
    //   buffer[this+0x400++] = v3;
    //   memcpy(buffer + this+0x400, UtilityFunction_6a90(a2), (byte)v3); this+0x400 += (byte)v3;
    //   if (*(int*)(this+0x408) == 0) *(int*)(this+0x40C) = BitmaskGenerationFromBitArray(a2);
    //   result = *(int*)(this+0x408) + 1;
    //   *(int*)(this+0x408) = result;
    //   return result;
    // UNRESOLVED: The exact meaning of a2[9] bit layout and why a2[5] payload and the UtilityFunction_6a90 data copy differ is not established
    // UNRESOLVED: The sub-struct at this+0x414 with capacity at +0x80 is described only through this single read
    // UNRESOLVED: Whether the alternate path (v3 > 255) shares the same receiver as the buffer path is not evidenced
    // UNRESOLVED: The caller relationship to sub_584130 is recorded but the semantics of that call site are outside this packet
}
