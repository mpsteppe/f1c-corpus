// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004980C0
// Canonical corpus name: ConditionalSetter0x30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalSetter0x30_004980c0.c

void UnknownObject::ConditionalSetter0x30()
{
    // Conditional __thiscall setter: stores the incoming parameter a2 into dword field at offset 0x30 of this (this[12]) only when a2 is non-zero, and always returns a2 (0 when the write was skipped). No globals or callees. Called by sub_492160 (0x00492160), likely passing a handle or pointer that is left unchanged when null.
    // ASSIGNMENT: Copy the incoming parameter a2 into the local result value. [source:raw]
    // GUARD: Guard on a2: when a2 is zero the write to this[12] is skipped and the field stays unchanged. [source:raw]
    // ASSIGNMENT: Store a2 into the dword field at offset 0x30 of this (this[12]), executed only on the non-zero branch. [source:raw, field:this:0x00000030]
    // RETURN: Return the value a2 (0 on the skipped branch, the stored value on the write branch). [source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_4980C0(_DWORD *this, int a2) {
    //     int result = a2;
    //     if (a2)
    //       this[12] = a2;
    //     return result;
    //   }
    // UNRESOLVED: Purpose of the dword field at offset 0x30 (likely a pointer or handle assigned only when valid) is not evidenced by this packet.
    // UNRESOLVED: Object type owning this setter is unknown; the single caller sub_492160 must be analyzed to infer the field's meaning.
}
