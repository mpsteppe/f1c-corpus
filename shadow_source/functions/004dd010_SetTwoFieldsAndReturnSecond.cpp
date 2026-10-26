// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD010
// Canonical corpus name: TwoFieldSetters
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoFieldSetters_004dd010.c

void UnknownObject::SetTwoFieldsAndReturnSecond()
{
    // Simple __thiscall setter on an unknown object. Writes a2 into this[12] at byte offset 0x30 (this+0x30) and a3 into this[13] at byte offset 0x34 (this+0x34), then returns a2 as the result. The existing skeleton analysis proposes scale-X / scale-Y semantics for the two fields, but that claim is DERIVED prose. Called from sub_45B950 (0x0045B950).
    // ASSIGNMENT: Store a2 into this[12] at byte offset 0x30 (field this+0x30). [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Store a3 into this[13] at byte offset 0x34 (field this+0x34). [field:this:0x00000034, source:raw]
    // RETURN: Return a2 as the function result. [function:0x004DD010, source:raw]

    // Conservative worker pseudocode:
    //   int SetTwoFieldsAndReturnSecond(void* this, int a2, int a3) {
    //     this[12] = a2;  // byte offset 0x30
    //     this[13] = a3;  // byte offset 0x34
    //     return a2;
    //   }
    // UNRESOLVED: The field semantics are unverified: the skeleton analysis proposes scale-X / scale-Y for offsets 0x30/0x34, but that is DERIVED prose without independent evidence in this packet.
    // UNRESOLVED: The object class owning this __thiscall is unknown; the packet owner is UnknownObject with no evidence.
}
