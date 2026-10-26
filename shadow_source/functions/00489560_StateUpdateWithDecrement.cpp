// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489560
// Canonical corpus name: StateUpdateWithDecrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateUpdateWithDecrement_00489560.c

void UnknownObject::StateUpdateWithDecrement()
{
    // Invokes the virtual notification callback at obj+0x2C (vtable slot offset +44) with argument 1, decrements the counter at this+0x14C by the step at this+0x164, clamps it to a minimum of 0, then refreshes visual state via sub_489D00 and FloatToIntConversion. Always returns 0.
    // CALL: Read the vtable pointer at this+0x0, index the virtual callback at offset +44 (obj+0x2C) and invoke it on this with argument 1 (notification/change handler). [field:this:0x00000000, field:obj:0x0000002C, source:raw]
    // CALCULATION: v2 = this[83] - this[89]: counter at this+0x14C decremented by the step size at this+0x164. [field:this:0x0000014C, field:this:0x00000164, source:raw]
    // ASSIGNMENT: Write the decremented value v2 back to the counter at this[83] (this+0x14C). [field:this:0x0000014C, source:raw]
    // GUARD: Clamp the counter at this+0x14C to a minimum of 0: when v2 is negative it is set to 0. [field:this:0x0000014C, source:raw]
    // CALL: sub_489D00 refreshes the scroll list visual state from the updated counter. [callee:0x00489D00, source:raw]
    // CALL: FloatToIntConversion converts the internal float position to an integer representation. [callee:0x00489E90, source:raw]
    // RETURN: Return 0 unconditionally; invoked by UIScrollbarThumbDragHandler (0048A650). [source:raw, function:0x00489560, caller:0x0048A650]

    // Conservative worker pseudocode:
    //   int sub_489560(int *this) {
    //     ((int (__thiscall *)(int *, int))(this[0] + 44))(this, 1);
    //     int v2 = this[83] - this[89];
    //     this[83] = v2 < 0 ? 0 : v2;
    //     sub_489D00(this);
    //     FloatToIntConversion(this);
    //     return 0;
    //   }
    // UNRESOLVED: The virtual callback invoked at offset +44 (obj+0x2C) is a change/notification handler, but the object identity of the obj base and the callback's side effects are unknown.
    // UNRESOLVED: The parameter contracts of sub_489D00 and FloatToIntConversion beyond taking this are not documented in this packet.
}
