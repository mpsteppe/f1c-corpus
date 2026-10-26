// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490190
// Canonical corpus name: ZeroCheckGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroCheckGetter_00490190.c

void UnknownObject::ZeroCheckGetter()
{
    // State-flag zero getter (__thiscall): returns whether the word at field this+0xE0 is zero. Simple boolean getter used to test a UI/component state flag for the zero value.
    // GUARD: Test field this+0xE0 (this[56]) for equality with 0; the guard passes (returns true) when the field is zero and fails otherwise. [field:this:0x000000E0, guard:0, source:raw]
    // RETURN: Return the boolean result of the equality test (this[56] == 0). [function:0x00490190, source:raw]
    // CALL: Called by ParameterValueClampingAcrossArray and SuspensionFloatClamp as a state-flag zero check before proceeding. [caller:0x0047A080, caller:0x0047A290, source:raw]

    // Conservative worker pseudocode:
    //   bool ZeroCheckGetter(DWORD* this) {
    //     return this[56] == 0;
    //   }
    // UNRESOLVED: The exact meaning of the flag at field this+0xE0 (e.g. enabled/active/visible) is outside this packet.
    // UNRESOLVED: Whether the flag is an enum with other nonzero states vs. a boolean is unresolved; only the zero comparison is observed.
}
