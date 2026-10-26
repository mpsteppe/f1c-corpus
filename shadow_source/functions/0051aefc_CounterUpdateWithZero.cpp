// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051AEFC
// Canonical corpus name: CounterUpdateWithZero
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CounterUpdateWithZero_0051aefc.c

void UnknownObject::CounterUpdateWithZero()
{
    // Accumulates the consumed byte count into an output total, zeroes the byte counter, then invokes an indirect callback; on a nonzero callback result it resets decode-counter state: zeroes per-channel counters, clears a ready flag and a counter field, and stores a reference value.
    // ASSIGNMENT: Load the internal decode state pointer v1 = a1[101] (this+0x194). [field:this:0x00000194]
    // CALCULATION: Accumulate consumed bytes into the output total: *(this+0x190 + 88) += *(state + 20) / 8. [field:this:0x00000190, field:this:0x000001A8, field:this:0x000001E8]
    // ASSIGNMENT: Zero the byte counter at state+20 (this+0x1A8). [field:this:0x000001A8]
    // CALL: Invoke the indirect callback stored at *(this+0x190 + 8) with the object pointer; its return value selects the counter-reset path. [field:this:0x00000190]
    // GUARD: If the callback result is nonzero, reset the decode-counter state; otherwise return the callback result unchanged. [source:raw]
    // GUARD: Channel-count guard: only zero the per-channel counter array when a1[72] (this+0x120) is greater than 0. [field:this:0x00000120, guard:0]
    // LOOP: Zero this->0x120 consecutive DWORDs starting at state+36 (this+0x1B8), one per channel. [field:this:0x00000120, field:this:0x000001B8]
    // ASSIGNMENT: Zero the counter field at state+32 (this+0x1B4). [field:this:0x000001B4]
    // ASSIGNMENT: Copy the reference value this->0xFC (a1[63]) into state+52 (this+0x1C8). [field:this:0x000000FC, field:this:0x000001C8]
    // ASSIGNMENT: Clear the ready flag byte at state+24 (this+0x1AC). [field:this:0x000001AC]
    // RETURN: Return 1 after a successful counter reset; otherwise propagate the callback return value. [function:0x0051AEFC]

    // Conservative worker pseudocode:
    //   state = this->0x194;
    //   *(this->0x190 + 88) += *(state + 20) / 8;
    //   *(state + 20) = 0;
    //   if (!(*(this->0x190 + 8))(this)) return result;
    //   for (i = 0; i < this->0x120; ++i) *(state + 36 + 4*i) = 0;
    //   *(state + 32) = 0; *(state + 52) = this->0xFC; *(state + 24) = 0;
    //   return 1;
    // UNRESOLVED: The read-only field this+0x198 (a1[102]) is listed by the fact extractor but is not referenced anywhere in this function body; its role is unknown.
    // UNRESOLVED: The indirect callback target at *(this+0x190 + 8) is not statically resolvable from this packet.
}
