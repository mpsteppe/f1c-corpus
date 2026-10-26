// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004661B0
// Canonical corpus name: GameObjectUpdateFrame
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameObjectUpdateFrame_004661b0.c

void UnknownObject::GameObjectUpdateFrame()
{
    // Per-frame update for a game object: optionally registers the object in a tracking list, runs a float timer countdown that triggers an expired-state transition plus a vtable callback, then runs two physics sub-updates and two trailing vtable callbacks. Returns 0.
    // GUARD: If the DWORD flag at this+0xE8 is non-zero, register the object in a tracking list. [field:this:0x000000E8]
    // CALL: DoublyLinkedListAppend_6750(*(this+0x40), this, 0) appends the object; the node pointers live in the sub-object at *(this+0x40) at offsets 0xA8 and 0xAC. [callee:0x00496750, field:this:0x00000040, field:obj:0x000000A8, field:obj:0x000000AC]
    // GUARD: If the float timer at this+0x124 is >= 0.0, run the countdown. [field:this:0x00000124]
    // CALCULATION: v2 = *(float*)(this+0x124) - FloatFieldAccessor(*(this+0x40)): subtract the sub-object float field 0x2C from the timer. [field:this:0x00000124, field:this:0x00000040, callee:0x00498730, field:obj:0x0000002C]
    // ASSIGNMENT: Write the decremented value v2 back to the timer at this+0x124. [field:this:0x00000124]
    // GUARD: If the decremented timer v2 has gone below 0.0, run the expiry path. [field:this:0x00000124]
    // STATE_TRANSITION: FieldSetterCall(*(this+0x40), 1) sets a state field on the sub-object, marking the timer as expired. [callee:0x004988A0, field:this:0x00000040]
    // CALL: Virtual dispatch at vtable offset 172 (0xAC) on the this object's vtable (this+0x0). [field:this:0x00000000]
    // GUARD: If either flag byte at this+0xF4 or this+0xF5 is set, run the primary sub-update. [field:this:0x000000F4, field:this:0x000000F5]
    // CALL: sub_466350(this) runs the conditional position/velocity sub-update. [callee:0x00466350]
    // CALL: sub_466650(this) runs the secondary physics sub-update unconditionally. [callee:0x00466650]
    // CALL: Virtual dispatch at vtable offset 44 (0x2C) with arguments (this, 1). [field:this:0x00000000]
    // CALL: Virtual dispatch at vtable offset 168 (0xA8) on the this object's vtable. [field:this:0x00000000]
    // RETURN: Return 0. [function:0x004661B0, source:raw]

    // Conservative worker pseudocode:
    //   if (*(DWORD*)(this+0xE8))
    //       DoublyLinkedListAppend_6750(*(DWORD*)(this+0x40), this, 0);
    //   if (*(float*)(this+0x124) >= 0.0f) {
    //       v2 = *(float*)(this+0x124) - FloatFieldAccessor(*(DWORD*)(this+0x40));
    //       *(float*)(this+0x124) = v2;
    //       if (v2 < 0.0f) {
    //           FieldSetterCall(*(DWORD*)(this+0x40), 1);
    //           vtable[172](this);
    //       }
    //   }
    //   if (*(BYTE*)(this+0xF4) || *(BYTE*)(this+0xF5))
    //       sub_466350(this);
    //   sub_466650(this);
    //   vtable[44](this, 1);
    //   vtable[168](this);
    //   return 0;
    // UNRESOLVED: Global flt_59E440 is listed as a read global by the skeleton but is not referenced by the raw source in this packet; its zero-threshold role is unverified.
    // UNRESOLVED: Semantics of the sub-object at this+0x40 and its fields 0x2C / 0xA8 / 0xAC are inferred from the DoublyLinkedListAppend / FloatFieldAccessor call sites, not independently grounded.
    // UNRESOLVED: The vtable callbacks at offsets 44 / 168 / 172 are not resolved to concrete functions in this packet.
}
