// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D1A0
// Canonical corpus name: UtilityFunction_d1a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_d1a0_0048d1a0.c

void UnknownObject::ListIndexStep()
{
    // Thiscall list-index stepper: computes the max valid index as item count minus one (this+0x328 - 1), steps the target index at this+0x338 by +1 when a2==1 (forward) or -1 otherwise (backward), writes the direction flag byte a2==1 to this+0x33C, wraps the index into [0, count-1] (negative wraps to last, overflow wraps to 0), then invokes the vtable+0x2C update callback with argument 1 and finally dispatches via vtable+0xBC with the direction argument and the new index.
    // CALCULATION: v3 = this[202] - 1: max valid index is item count at this+0x328 minus one. [field:this:0x00000328]
    // CALCULATION: v4 = 2 * (a2 == 1) - 1 + this[206]: step +1 when a2==1 (forward), -1 otherwise (backward), added to the target index at this+0x338. [field:this:0x00000338, source:raw]
    // ASSIGNMENT: Store the stepped index v4 back into the target index at this+0x338. [field:this:0x00000338]
    // ASSIGNMENT: Write direction flag byte (a2 == 1) to this+0x33C: 1 for forward, 0 for backward. [field:this:0x0000033C]
    // GUARD: When the stepped index v4 is negative, clamp to the max index v3 (wrap to last item). [field:this:0x00000338, field:this:0x00000328]
    // ASSIGNMENT: Store the wrapped index back into this+0x338. [field:this:0x00000338]
    // ASSIGNMENT: When the index exceeds the max index v3, reset it to 0 (wrap to first item); otherwise keep it. Result stored at this+0x338. [field:this:0x00000338, field:this:0x00000328]
    // CALL: Virtual call through the vtable pointer at this+0x0: entry +0x2C with argument 1, the post-change update callback. [field:this:0x00000000, field:obj:0x0000002C]
    // CALL: Virtual call through the vtable pointer at this+0x0: entry +0xBC with (this, a2, this[206]) — action dispatch carrying the direction and the new target index. [field:this:0x00000000, field:obj:0x000000BC, field:this:0x00000338]
    // RETURN: Return the result of the vtable+0xBC dispatch call. [function:0x0048D1A0]

    // Conservative worker pseudocode:
    //   int ListIndexStep(_DWORD* this, int a2) {
    //     int max_index = this[202] - 1;
    //     int stepped_index = 2 * (a2 == 1) - 1 + this[206];
    //     this[206] = stepped_index;
    //     *((_BYTE*)this + 0x33C) = (a2 == 1);
    //     if (stepped_index < 0)
    //       stepped_index = max_index;
    //     this[206] = stepped_index;
    //     this[206] = stepped_index > max_index ? 0 : stepped_index;
    //     (*(void (__thiscall **)(_DWORD*, int))(*this + 0x2C))(this, 1);
    //     return (*(int (__thiscall **)(_DWORD*, int, _DWORD))(*this + 0xBC))(this, a2, this[206]);
    //   }
    // UNRESOLVED: Concrete list object type owning this+0x328 (item count), this+0x338 (target index) and this+0x33C (direction flag) is not identified.
    // UNRESOLVED: The two vtable callbacks (+0x2C update, +0xBC dispatch) resolve to unknown callees because both are indirect through the vtable pointer.
}
