// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FC10
// Canonical corpus name: UtilityFunction_fc10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_fc10_0048fc10.c

void UnknownObject::CachedValueSyncDispatch()
{
    // Thiscall cache-sync with final dispatch: reads the referenced-object pointer at this+0xE0 (this[56]); when non-null, reads the external value at the packet-flagged field offset and compares it against the cached value at this+0xE4 (this[57]). On a difference it updates the cache and fires the vtable+0x2C change-notification callback with argument 1. Unconditionally fires the vtable+0xA8 final-dispatch callback with no arguments, then returns 0.
    // GUARD: Branch on the referenced-object pointer at this+0xE0 (this[56]) being non-null; the cache-compare block is skipped when it is null. [field:this:0x000000E0]
    // CALCULATION: v3 = read of the external value through the referenced object; raw source dereferences *(this[56] + 372) while the packet field fact places the read at field 0x254 (discrepancy flagged in unresolved). [field:this:0x00000254, source:raw]
    // GUARD: Branch when the cached value at this+0xE4 (this[57]) differs from the external value v3. [field:this:0x000000E4]
    // ASSIGNMENT: Update the cached value at this+0xE4 (this[57]) to the external value v3. [field:this:0x000000E4]
    // CALL: Virtual call through the vtable pointer at this+0x0: entry +0x2C with argument 1 — change-notification callback fired only when the cache was updated. [field:this:0x00000000, field:obj:0x0000002C]
    // CALL: Virtual call through the vtable pointer at this+0x0: entry +0xA8 with no arguments — unconditional final dispatch. [field:this:0x00000000, field:obj:0x000000A8]
    // RETURN: Return 0 (void-like tail). [abi:lead, function:0x0048FC10]

    // Conservative worker pseudocode:
    //   int CachedValueSyncDispatch(_DWORD* this) {
    //     int referenced_object = this[56];
    //     if (referenced_object) {
    //       int external_value = *(_DWORD*)(referenced_object + 372);
    //       if (this[57] != external_value) {
    //         this[57] = external_value;
    //         (*(void (__thiscall **)(_DWORD*, int))(*this + 0x2C))(this, 1);
    //       }
    //     }
    //     (*(void (__thiscall **)(_DWORD*))(*this + 0xA8))(this);
    //     return 0;
    //   }
    // UNRESOLVED: Offset discrepancy: the packet field fact lists the dereferenced external value at field this+0x254 (base 'this'), while the raw source reads *(this[56] + 372) which is 0x174 into the referenced object. Placement of the external field is unresolved.
    // UNRESOLVED: Concrete object type of this+0xE0 (referenced object) and the meaning of the external value are not identified.
    // UNRESOLVED: The vtable callbacks (+0x2C change notification, +0xA8 final dispatch) resolve to unknown callees because both are indirect through the vtable pointer.
}
