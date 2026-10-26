// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513A56
// Canonical corpus name: FlagSetterFloatStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagSetterFloatStore_00513a56.c

void UnknownObject::FlagSetterFloatStore()
{
    // Flag-gated single-precision store: when both a1 and a2 are non-null, sets bit 0x01 of the dword at a2+8 and stores the float conversion of the double a3 at a2+40. Void return; no output when either pointer is null.
    // GUARD: Guard: return without effect when the first argument a1 is null. [source:raw]
    // GUARD: Guard: return without effect when the state pointer a2 is null. [source:raw]
    // ASSIGNMENT: Set bit 0x01 of the dword at a2+8 (OR with 1). [source:raw]
    // ASSIGNMENT: Store the float value of a3 at a2+40. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_513A56(int a1, int a2, double a3) {
    //     if (a1) {
    //       if (a2) {
    //         *(_DWORD *)(a2 + 8) |= 1u;
    //         *(float *)(a2 + 40) = a3;
    //       }
    //     }
    //   }
    // UNRESOLVED: Meaning of the flag bit 0x01 at a2+8 and the float field at a2+40 depend on the object layout known only to callers sub_513B51 and sub_518C1E.
    // UNRESOLVED: The float field is written as float while the argument arrives as double; the precision loss is an observed behavior, not an analysis claim.
    // UNRESOLVED: The two guards may reflect distinct required handles (e.g. an owner object and a state object) but their identities are unknown.
}
