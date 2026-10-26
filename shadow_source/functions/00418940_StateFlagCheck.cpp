// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418940
// Canonical corpus name: StateFlagCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateFlagCheck_00418940.c

void UnknownObject::StateFlagCheck()
{
    // Boolean state query: returns true if the object pointer at this+0xAF4 is non-null and its vfunc at vtable+8 (offset 0x8) returns non-zero, OR if the active slot index at this+0x864 is not -1. Returns false only when the object is null or ready AND the slot index is -1.
    // CALCULATION: Load the overlay/display object pointer v2 from this+0xAF4. [field:this:0x00000AF4, source:raw]
    // CALL: Indirect __thiscall through the object vtable at offset 0x8: (*(int (**)(int))*v2 + 8)(v2). Non-zero return indicates busy/active. [field:*(this+0xAF4):0x00000008, field:this:0x00000AF4, abi:lead, source:raw]
    // GUARD: Guard on the active slot index at this+0x864: non -1 (0xFFFFFFFF) contributes true to the OR result. [guard:0, field:this:0x00000864, function:0x00418940, source:raw]
    // RETURN: Return (v2 != null && vfunc8(v2) != 0) || (this+0x864 != -1). [function:0x00418940, source:raw]

    // Conservative worker pseudocode:
    //   bool sub_418940(int *this) {
    //     int *obj = (int *)this[0xAF4 / 4];
    //     return (obj && (*(int (**)(int))*(int *)obj + 8)((int)obj)) || this[0x864 / 4] != -1;
    //   }
    // UNRESOLVED: Meaning of the vfunc at offset 0x8 of the this+0xAF4 object is unknown.
    // UNRESOLVED: Meaning of the active slot index at this+0x864 (-1 sentinel) is unknown.
}
