// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2BF0
// Canonical corpus name: ShortComputation_2bf0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_2bf0_004c2bf0.c

void UnknownObject::IncrementFieldAt28()
{
    // Side-effecting counter increment: performs ++this[10], a read-modify-write of the dword at this+0x28, and returns void. Called by sub_4C29F0 (0x004C29F0). The packet's template prelabel (a side-effect-free getter of 0x28) does not match the raw source and is not reflected here.
    // CALCULATION: Increment the counter by one: ++this[10], a read-modify-write of the field at this+0x28. [field:this:0x00000028, source:raw]
    // CALL: Invoked by sub_4C29F0 (0x004C29F0). [caller:0x004C29F0]

    // Conservative worker pseudocode:
    //   void sub_4C2BF0(_DWORD *this) {
    //     ++this[10];    // this + 0x28
    //   }
    // UNRESOLVED: The packet prelabel (template getter: 'returns field 0x28, no side effects') contradicts the raw source, which performs a side-effecting increment and returns void; the prelabel is not reflected in this reconstruction.
    // UNRESOLVED: The packet field entry marks this:0x28 as read-only (R), while the raw source performs a read-modify-write increment of it.
    // UNRESOLVED: The purpose of the counter at this+0x28 is not documented in this function.
}
