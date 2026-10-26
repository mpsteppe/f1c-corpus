// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9280
// Canonical corpus name: EqualityStateCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EqualityStateCheck_004c9280.c

void UnknownObject::EqualityStateCheck()
{
    // Compares argument a2 against the state index stored at this+0x1C. On match, calls StateIndexedFieldGetter(this) to obtain an indexed field object; returns 0 if null or if a virtual call at vtable+0x1C (offset 28) on that object returns 2. Returns 1 only when the field value is present and its equality marker is not 2.
    // GUARD: If a2 does not equal the state index at this+0x1C, return 0. [field:this:0x0000001C, source:raw, function:0x004C9280]
    // CALL: Call StateIndexedFieldGetter(this); store returned object pointer in v2. [callee:0x004C9260, source:raw]
    // GUARD: If v2 is null, return 0. [source:raw, function:0x004C9280]
    // CALL: Invoke virtual method at vtable+28 on v2; set v3 to (result == 2). [source:raw]
    // RETURN: Return 0 if v3 (virtual result equals 2), otherwise return 1. [source:raw, function:0x004C9280]

    // Conservative worker pseudocode:
    //   if (a2 != this->state_index) return 0;
    //   obj = StateIndexedFieldGetter(this);
    //   if (!obj) return 0;
    //   return (obj->vtable[7](obj) != 2);
    // UNRESOLVED: Semantic meaning of the vtable+28 call result equal to 2 is unknown; treated as an equality marker check only.
    // UNRESOLVED: Owner object type for this pointer is unknown.
}
