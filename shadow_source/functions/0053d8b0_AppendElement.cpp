// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D8B0
// Canonical corpus name: sub_53D8B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53D8B0_0053d8b0.c

void UnknownObject::AppendElement()
{
    // Bounded append of a 0x43C-byte record into a fixed-capacity array embedded in this. Reads the current element count from this+8 (this[2]); when it is below the 4-slot capacity, copies 0x43C bytes from a2 into the element slot at this + 3 dwords + 271 dwords * count, then increments the count. No-op once the capacity is reached. Returns this.
    // CALCULATION: Read the element count v3 from the count field at this+8 (this[2]); it selects the destination slot [field:this:0x00000008, source:raw]
    // GUARD: Append only proceeds while the count is below the fixed 4-slot capacity; once the count reaches 4 the function returns this unchanged [field:this:0x00000008, source:raw]
    // CALL: qmemcpy copies 0x43C bytes from the source record a2 into the slot at this + 3 dwords + 271 dwords * count (record stride 271 dwords = 0x43C bytes), after the 3-dword header this[0..2] [source:raw]
    // ASSIGNMENT: Increment the element count at this+8 after the copy succeeds [field:this:0x00000008, source:raw]
    // RETURN: Return this, allowing the append result to be chained by the caller [function:0x0053D8B0, source:raw]
    // CALL: Invoked by sub_53D970 (0053D970) as the record-append path of the surrounding object [caller:0x0053D970, source:raw]

    // Conservative worker pseudocode:
    //   count = this[2];
    //   if (count < 4) {
    //       qmemcpy(&this[3 + 271 * count], a2, 0x43C);
    //       ++this[2];
    //   }
    //   return this;
    // UNRESOLVED: The meaning of the 3-dword header at this[0..2] (count is this[2], the first two dwords are unread here) is not documented in the packet
    // UNRESOLVED: The record layout of the 0x43C-byte elements and the identity of the container class are not documented in the packet
}
