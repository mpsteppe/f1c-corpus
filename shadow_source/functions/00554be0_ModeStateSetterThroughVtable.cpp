// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554BE0
// Canonical corpus name: ModeStateSetterThroughVtable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ModeStateSetterThroughVtable_00554be0.c

void UnknownObject::ModeStateSetterThroughVtable()
{
    // Sets the active mode state on a device object. Reads the current mode from this+0x13A0 and short-circuits when a2 already matches. On change, stores a2 at this+0x13A0, reads the device object pointer at this+0x1100, and dispatches property 14 through its vtable slot at +0xC8 with value 1 or 0 depending on a2. The dispatch result is stored back at this+0x0 and returned. Invoked by sub_53EB70, sub_5550E0 and sub_55CF50.
    // ASSIGNMENT: Initialize result to a2 before the change detection guard. [source:raw]
    // GUARD: Guard: skip the whole update when a2 == this[1256] (mode unchanged). [field:this:0x000013A0, source:raw]
    // ASSIGNMENT: Store the new mode state: this[1256] = a2. [field:this:0x000013A0, source:raw]
    // ASSIGNMENT: Read the device object pointer: v4 = this[1088] at offset 0x1100. [field:this:0x00001100, source:raw]
    // GUARD: Branch on a2: non-zero selects dispatch value 1, zero selects dispatch value 0. [source:raw]
    // CALL: Dispatch property 14 with value 1 through the device vtable slot at +0xC8: (*(vtable+0xC8))(v4, 14, 1). [field:*(this+0x1100):0x000000C8, source:raw]
    // CALL: Dispatch property 14 with value 0 through the device vtable slot at +0xC8: (*(vtable+0xC8))(v4, 14, 0). [field:*(this+0x1100):0x000000C8, source:raw]
    // ASSIGNMENT: Store the dispatch result at the head of the object: *this = result. [field:this:0x00000000, source:raw]
    // RETURN: Return the dispatch result (or the untouched a2 when the guard short-circuited). [source:raw]
    // CALL: Invoked by sub_53EB70, sub_5550E0 and sub_55CF50 to switch the active mode state. [caller:0x0053EB70, caller:0x005550E0, caller:0x0055CF50, source:raw]

    // Conservative worker pseudocode:
    //   result = a2;
    //   if (a2 != this[1256]) {
    //     this[1256] = a2;
    //     v4 = this[1088];
    //     if (a2) result = (*(vtable(v4) + 0xC8))(v4, 14, 1);
    //     else    result = (*(vtable(v4) + 0xC8))(v4, 14, 0);
    //     *this = result;
    //   }
    //   return result;
    // UNRESOLVED: Semantics of property 14 and the identity of the device object at this+0x1100 are not established here.
    // UNRESOLVED: Meaning of the stored dispatch result at this+0x0 depends on the owning object's layout.
}
