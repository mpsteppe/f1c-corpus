// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A46F0
// Canonical corpus name: sub_4A46F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A46F0_004a46f0.c

void UnknownObject::Indexed_Field_Setter_with_Flag()
{
    // __thiscall setter on `this` (_DWORD array): reads an index from the object a2 at offset +4, then conditionally writes either a2 or NULL into `this[index]` depending on flag a3. Returns a2 unchanged. No fields, globals, guards or callees.
    // CALCULATION: v5 = *(DWORD*)(a2 + 4): reads the slot index from the object a2. [source:raw]
    // GUARD: Branch on flag a3: if nonzero, register the object; otherwise clear the slot. [source:raw]
    // ASSIGNMENT: this[v5] = a2: stores a2 into the indexed slot of `this`. [source:raw]
    // ASSIGNMENT: this[v5] = 0: clears the indexed slot of `this`. [source:raw]
    // RETURN: Returns a2 (the object passed in). [source:raw]

    // Conservative worker pseudocode:
    //   v5 = *(DWORD*)(a2 + 4);
    //   this[v5] = a3 ? a2 : 0;
    //   return a2;
    // UNRESOLVED: Argument a4 is unused by the body; its role is unknown.
    // UNRESOLVED: Field semantics of a2 + 4 (the index source) are unknown; callers AICommandMessageQueueDispatcher, sub_426430 and AISpeedDeltaSetter imply AI message/slot bookkeeping but no owner is proven.
    // UNRESOLVED: ABI lead names Indexed_Field_Setter_with_Flag at LEGACY trust; used only as the proposed function name, not as an owner claim.
}
