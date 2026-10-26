// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498F70
// Canonical corpus name: ShortComputation_8f70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8f70_00498f70.c

void UnknownObject::ShortComputation_8f70()
{
    // Getter with no side effects: returns the dword at this+0x44 (this[17]) of the object pointed to by `this`. The caller 0x00495B30 reads this field.
    // RETURN: Returns this[17], the dword field at offset 0x44 of the object. No side effects. [field:this:0x00000044, function:0x00498F70, source:raw]

    // Conservative worker pseudocode:
    //   int ShortComputation_8f70(_DWORD *self) {
    //     return self[17];
    //   }
    // UNRESOLVED: The meaning of the field at this+0x44 and the owning object type are unknown; caller 0x00495B30 (ShortComputation_5b30) consumes the value.
    // UNRESOLVED: The ABI signature is a LEGACY placeholder (Short_Computation_Struct_Field_Getter_at_0x44); no prototype is known.
}
