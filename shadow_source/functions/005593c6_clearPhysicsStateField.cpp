// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005593C6
// Canonical corpus name: SetPhysicsStateFieldToZero
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetPhysicsStateFieldToZero_005593c6.c

void UnknownObject::clearPhysicsStateField()
{
    // Unconditionally zeroes dword this[7] (field 0x1C) of the physics-state object. Arguments a2 and a3 are unused. No guards, globals, callees, or return value.
    // ASSIGNMENT: Write zero to this[7], i.e. dword at offset 0x1C of the object. [field:this:0x0000001C, source:raw]
    // RETURN: Void return; the function only performs the single unconditional store. [function:0x005593C6, source:raw]

    // Conservative worker pseudocode:
    //   void clearPhysicsStateField(int *this, int a2, int a3) {
    //     this[7] = 0;
    //   }
    // UNRESOLVED: a2 and a3 are accepted but unused; their intended roles are unknown.
    // UNRESOLVED: The meaning of field 0x1C (state/counter per the existing analysis fill) is not grounded in packet evidence.
}
