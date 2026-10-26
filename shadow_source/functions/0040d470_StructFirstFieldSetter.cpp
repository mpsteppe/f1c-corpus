// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D470
// Canonical corpus name: SimpleSetterWithSubCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SimpleSetterWithSubCall_0040d470.c

void UnknownObject::StructFirstFieldSetter()
{
    // Sets the first DWORD of the struct (this+0x0, likely a vtable or parent pointer) from parameter a2, then calls StructFieldInit (0x0040D490) to initialize the remaining fields, and returns this. Unconditional: no branches. Invoked during camera-director reset/init by 0x0040DA30.
    // ASSIGNMENT: Write parameter a2 to the first DWORD of the struct at this+0x0. [field:this:0x00000000]
    // CALL: Call StructFieldInit (0x0040D490) to initialize remaining struct fields. [callee:0x0040D490]
    // RETURN: Return this to allow chained use by the caller. [source:raw]

    // Conservative worker pseudocode:
    //   struct T *sub_40D470(struct T *this, int a2) {
    //     this->first = a2;      // this+0x0
    //     StructFieldInit();     // 0x0040D490
    //     return this;
    //   }
    // UNRESOLVED: Meaning of a2 at this+0x0 (vtable pointer vs parent object reference) is unresolved; the caller 0x0040DA30 supplies it.
    // UNRESOLVED: Fields touched by StructFieldInit (0x0040D490) are outside this function's evidence.
}
