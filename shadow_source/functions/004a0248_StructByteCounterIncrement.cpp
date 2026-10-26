// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0248
// Canonical corpus name: StructByteCounterIncrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructByteCounterIncrement_004a0248.c

void UnknownObject::StructByteCounterIncrement()
{
    // __usercall helper that increments a byte counter by a2. It treats the ecx argument a1 as a this-relative base and adds a2 to the byte stored at a1 - 61. No guards, fields, globals, or callees in this packet.
    // ASSIGNMENT: Compound assignment *(_BYTE *)(a1 - 61) += a2 adds the byte a2 to the counter byte located 61 bytes below the a1 base. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_4A0248(int a1, char a2) {
    //       *(_BYTE *)(a1 - 61) += a2;
    //   }
    // UNRESOLVED: The counter lives at a1 - 61, i.e. 61 bytes before the this pointer, which is unusual; the containing struct layout and the meaning of the counter are not evidenced by this packet.
    // UNRESOLVED: The ABI legacy name is Struct_Byte_Counter_Increment (trust LEGACY); the owning class is unconfirmed.
    // UNRESOLVED: No callers are recorded, so the call sites that would identify the struct type are unknown.
}
