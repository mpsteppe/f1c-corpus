// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487D70
// Canonical corpus name: sub_487D70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_487D70_00487d70.c

void UnknownObject::ToggleStateAndNotify()
{
    // Pointer-based state toggle. Retrieves a child object via virtual call vtable+172; if the pointer is null it short-circuits through vtable+56 with argument 1. Otherwise it clears state via vtable+56 with argument 0, computes a toggle value from the child object's first dword (inverted by the this+0xE4 flag: set means v4==0, clear means v4!=0), re-reads current state via ShortComputation_7720, and on a detected state change calls sub_487260 to set the state and notifies through vtable+44 with argument 1.
    // CALL: Virtual dispatch through the this vtable (this+0x0) at offset +172 (0xAC) to retrieve a child-object pointer into v2. [field:this:0x00000000, field:obj:0x000000AC, source:raw]
    // GUARD: Early-out: if the retrieved pointer v2 is null, dispatch vtable+56 (obj+0x38) with argument 1 and return its result. [field:obj:0x00000038, field:this:0x00000000, source:raw]
    // CALL: Virtual call vtable+56 (obj+0x38) with argument 0 to clear/disable the state before toggling. [field:obj:0x00000038, field:this:0x00000000, source:raw]
    // CALCULATION: Read the first dword v4 of the child object returned by the vtable+172 call. [field:obj:0x000000AC, source:raw]
    // CALCULATION: Compute toggle value v5: if the this+0xE4 flag is set then v5 = (v4 == 0), otherwise v5 = (v4 != 0). The flag inverts the comparison. [field:this:0x000000E4, source:raw]
    // CALL: Call ShortComputation_7720(this) to obtain the current state; result stored for change detection. [callee:0x00487720, source:raw]
    // GUARD: On detected state change (comparison against the uninitialized decompiler local v6; see unresolved), set state via sub_487260(this, v7) and dispatch vtable+44 (obj+0x2C) with argument 1, returning its result. [callee:0x00487260, field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // RETURN: Return the result of ShortComputation_7720 when no state change is detected. [callee:0x00487720, source:raw]

    // Conservative worker pseudocode:
    //   v2 = vtable(this)[172](this)
    //   if (!v2) return vtable(this)[56](this, 1)
    //   vtable(this)[56](this, 0)
    //   v4 = *v2
    //   v5 = this[0xE4] ? (v4 == 0) : (v4 != 0)
    //   result = ShortComputation_7720(this)
    //   if (result != v6) { /* v6 uninitialized in decompilation * /
    //       sub_487260(this, v5)
    //       return vtable(this)[44](this, 1)
    //   }
    //   return result
    // UNRESOLVED: Decompiler local v6 used in the change-detection comparison (result != v6) is uninitialized in the raw source; the exact trigger condition for the sub_487260 state-set branch cannot be determined from the packet.
    // UNRESOLVED: Semantics of the vtable+56 calls (argument 1 vs 0) are inferred as set/clear; not grounded by packet evidence.
    // UNRESOLVED: Meaning of the first dword (v4) of the child object returned by vtable+172 is unknown.
    // UNRESOLVED: The vtable+44 call result is propagated as the function return value on the state-change path; whether it is a boolean or status value is unknown.
}
