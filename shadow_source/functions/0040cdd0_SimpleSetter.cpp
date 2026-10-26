// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040CDD0
// Canonical corpus name: SimpleSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SimpleSetter_0040cdd0.c

void UnknownObject::SimpleSetter()
{
    // Trivial __thiscall field setter: stores argument a2 at this+0x8 (this[2]) and returns the same value. No guards, no callees; unconditionally overwrites the field on every call.
    // ASSIGNMENT: Store the argument into the object field: this[2] = a2, i.e. write a2 to this+0x8. [field:this:0x00000008, source:raw]
    // RETURN: Return the stored argument a2 as the function result. [source:raw]
    // CALL: Called by SessionPhaseDispatchWithCascadeChecks (0x0040D1B0) to assign this+0x8 during session-phase dispatch. [caller:0x0040D1B0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_40CDD0(int *this, int a2) {
    //     this[2] = a2;
    //     return a2;
    //   }
    // UNRESOLVED: Meaning of the field at this+0x8 and of the value a2 are not established by this packet.
    // UNRESOLVED: Full name of the owning class is unknown; only its legacy ABI tag Simple_Setter survives.
}
