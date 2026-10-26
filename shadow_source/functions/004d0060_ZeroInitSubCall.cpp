// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D0060
// Canonical corpus name: ZeroInitSubCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroInitSubCall_004d0060.c

void UnknownObject::ZeroInitSubCall()
{
    // Trivial __thiscall object-zeroing helper: clears the field at this+0x4 to zero, then calls sub_4D0080() with no arguments and returns this. A structural twin of the ObjectConstructor pattern (00448120) per the DERIVED cluster-copy prelabel. Its single caller is sub_4D2DD0.
    // ASSIGNMENT: Zero the second dword of the object: this[1] = 0 (offset this+0x4). [field:this:0x00000004]
    // CALL: Call sub_4D0080() with no arguments. [callee:0x004D0080]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   void *sub_4D0060(void *this) {
    //     this[1] = 0;
    //     sub_4D0080();
    //     return this;
    //   }
    // UNRESOLVED: Purpose and identity of the no-argument callee sub_4D0080 is unknown here.
    // UNRESOLVED: Caller sub_4D2DD0 is recorded but its relationship to this zero-init step is unverified.
    // UNRESOLVED: The DERIVED cluster-copy prelabel ties this to ObjectConstructor (00448120) but the equivalence is not independently confirmed.
}
