// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C102
// Canonical corpus name: FloatStoreFromX87ST
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatStoreFromX87ST_0053c102.c

void UnknownObject::FloatStoreFromX87ST()
{
    // Stores the double value arriving in x87 register ST(2) as a 32-bit float into the field at offset 0x8 of the object addressed by this (ecx/a1). Parameters a3..a6 are not referenced by the body. The __userpurge convention carries the value in an x87 stack register rather than the argument list.
    // ASSIGNMENT: Store the double arriving in x87 ST(2) as a float into the field at this+0x8 (field:this:0x00000008, RW). [field:this:0x00000008, source:raw, function:0x0053C102]
    // RETURN: Implicit void return; parameters a3..a6 are unused by the body. [source:raw]

    // Conservative worker pseudocode:
    //   void FloatStoreFromX87ST(float* dst) {
    //     *(float*)((char*)this + 8) = (float)ST2;
    //   }
    // UNRESOLVED: Identity of the owning object and the semantic meaning of the field at offset 0x8 are unknown.
    // UNRESOLVED: Parameters a3..a6 have no use in the body; their purpose is caller-determined.
    // UNRESOLVED: The value arrives via x87 ST(2), an artifact of the __userpurge calling convention.
}
