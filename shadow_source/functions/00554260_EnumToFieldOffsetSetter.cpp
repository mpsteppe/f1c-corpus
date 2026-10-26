// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554260
// Canonical corpus name: EnumToFieldOffsetSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EnumToFieldOffsetSetter_00554260.c

void UnknownObject::EnumToFieldOffsetSetter()
{
    // Enum-driven conditional field setter. Dispatches on a2 through the jump table at 0x005542B0, maps one of the accepted enum values (1,2,3,4,5,6,13,14) to a dword field of `this`, and stores a3 there when the selected pointer is non-null and the current value differs. Returns 1 when a write occurred, 0 when the enum is invalid or the field already held a3.
    // CALCULATION: Dispatch on enum value a2 through the jump table at 0x005542B0; cases 1,2,3,4,5,6,13,14 select a field pointer, any other value falls through to the default path that returns 0. [global:0x005542B0, source:raw]
    // CALCULATION: Map enum a2 to a dword field of `this`: 1->this+0x00, 2->this+0x04, 3->this+0x08, 4->this+0x14, 5->this+0x18, 6->this+0x1C, 13->this+0x0C, 14->this+0x10. [source:raw]
    // GUARD: Skip the write when the selected field pointer is null or the current field value already equals a3 (*v3 == a3). [source:raw]
    // ASSIGNMENT: For enum value 14 the target is this+4 (byte offset 0x10): store a3 into this+0x10 when the current value differs. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write the incoming value: *v3 = a3 into the selected field, and set result to 1. [source:raw]
    // RETURN: Return 1 when a field was changed, 0 when the enum was invalid or the field already held a3. [source:raw]

    // Conservative worker pseudocode:
    //   switch (a2) {
    //     case 1:  field = &this->f0x00; break;
    //     case 2:  field = &this->f0x04; break;
    //     case 3:  field = &this->f0x08; break;
    //     case 4:  field = &this->f0x14; break;
    //     case 5:  field = &this->f0x18; break;
    //     case 6:  field = &this->f0x1C; break;
    //     case 13: field = &this->f0x0C; break;
    //     case 14: field = &this->f0x10; break;
    //     default: return 0;
    //   }
    //   if (field == NULL || *field == a3) return 0;
    //   *field = a3;
    //   return 1;
    // UNRESOLVED: The class behind `this` and the semantics of each mapped dword field are unidentified.
    // UNRESOLVED: Packet existing-analysis prose claims enum 5 maps to this[4]; the raw source maps case 5 to this+6 (offset 0x18), so the attested 0x10 field is written by case 14, not case 5. Raw source wins over the prose mapping.
}
