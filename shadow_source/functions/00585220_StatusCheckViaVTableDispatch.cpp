// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585220
// Canonical corpus name: StatusCheckViaVTableDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StatusCheckViaVTableDispatch_00585220.c

void UnknownObject::StatusCheckViaVTableDispatch()
{
    // Status query with dual condition check. Optionally writes the status byte at this+0x5D through output pointer a2, then computes the boolean v4 = (vtable-slot-0xA4 result on this) < (threshold at this+0x60), optionally writes v4 through output pointer a3, and returns true only when both the status byte and v4 hold. The threshold comparison result comes from an indirect vtable dispatch, not a static callee. Called by sub_57BF00 and sub_584230.
    // GUARD: If output pointer a2 is non-NULL, write the status byte into it; otherwise leave it untouched. [source:raw]
    // ASSIGNMENT: Write the status byte at this+0x5D (this[93]) through a2. [field:this:0x0000005D, source:raw]
    // CALL: Indirect call through vtable slot at this+0x0 displaced by +0xA4 (offset 164), dispatched on this; the call target is not statically resolvable from this packet. [field:this:0x00000000, field:obj:0x000000A4, source:raw]
    // CALCULATION: Compare the value returned by the vtable-dispatched call against the threshold dword at this+0x60 (this[24]); result v4 is the strict less-than comparison. [field:this:0x00000060, source:raw]
    // GUARD: If output pointer a3 is non-NULL, write the comparison result v4 into it; otherwise leave it untouched. [source:raw]
    // ASSIGNMENT: Write v4 (vtable result < this+0x60 threshold) through a3. [source:raw]
    // RETURN: Return the conjunction of the status byte at this+0x5D being non-zero and v4 being true; both conditions must hold. [field:this:0x0000005D, source:raw]

    // Conservative worker pseudocode:
    //   BOOL StatusCheckViaVTableDispatch(this, out_status, out_less) {
    //     if (out_status) *out_status = this->statusByte; // +0x5D
    //     bool less = VTableDispatch(this, 0xA4) < this->threshold; // +0x60
    //     if (out_less) *out_less = less;
    //     return this->statusByte && less;
    //   }
    // UNRESOLVED: The indirect vtable dispatch target at slot +0xA4 is unknown; no concrete callee evidence exists in the packet.
    // UNRESOLVED: The meaning of the status byte at +0x5D and the threshold at +0x60 (status flags, counters, or capability values) is not established by this packet.
}
