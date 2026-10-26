// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051184F
// Canonical corpus name: TripleFieldSetter_184f
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleFieldSetter_184f_0051184f.c

void UnknownObject::TripleFieldSetter()
{
    // Writes three consecutive DWORD fields of the receiver object from three parameters with a parameter-to-offset remapping: a2 into this+0x48 (this[18]), a3 into this+0x40 (this[16]), a4 into this+0x44 (this[17]). Returns the original this pointer. All three writes are unconditional and the function performs no guards and no other operations.
    // ASSIGNMENT: Stores parameter a2 into this[18] (offset 0x48) [field:this:0x00000048, source:raw]
    // ASSIGNMENT: Stores parameter a3 into this[16] (offset 0x40) [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Stores parameter a4 into this[17] (offset 0x44) [field:this:0x00000044, source:raw]
    // RETURN: Returns the original this pointer (result = a1 at entry) [source:raw]
    // CALL: Invoked by sub_5118E6 (005118E6) [caller:0x005118E6, source:raw]

    // Conservative worker pseudocode:
    //   this[16] = a3;  // offset 0x40
    //   this[17] = a4;  // offset 0x44
    //   this[18] = a2;  // offset 0x48
    //   return this;
    // UNRESOLVED: The receiver object type and the meaning of the three set fields (offsets 0x40, 0x44, 0x48) are unknown
    // UNRESOLVED: The parameter-to-offset remapping (a2 lands at 0x48, a3 at 0x40, a4 at 0x44) has no semantic explanation
}
