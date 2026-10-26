// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051EB5A
// Canonical corpus name: VirtualCallWithIntegerSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualCallWithIntegerSet_0051eb5a.c

void UnknownObject::writeFieldThenCallVirtual()
{
    // Writes the integer 45 into the field at offset 0x14 of the sub-object pointed to by this+0x0, then calls the first virtual entry (this+0x0 function table) on this and returns its result. No guard; both operations execute unconditionally.
    // ASSIGNMENT: Write the constant 45 into the field at offset 0x14 of the sub-object whose pointer is stored at this+0x0. [field:obj:0x00000014, field:this:0x00000000, source:raw]
    // CALL: Read the function-pointer table stored at this+0x0 and call its first entry with this as the argument. [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // RETURN: Return the integer result of the virtual call. [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   int writeFieldThenCallVirtual(int a1) {
    //       *(int *)(*(int *)a1 + 0x14) = 45;
    //       return (*(int (**)(int))(*(int *)a1))(a1);
    //   }
    //   
    // UNRESOLVED: Owner object type and the class owning the virtual table are unknown; no caller or RTTI evidence in the packet.
    // UNRESOLVED: The meaning of the constant 45 written at offset 0x14 (flag/parameter for the callee) is not evident.
    // UNRESOLVED: Whether the first virtual entry is a constructor, notification, or update method is unknown.
    // UNRESOLVED: Field naming follows the packet bases obj (sub-object) and this (containing pointer); the object identity linking them is unresolved.
}
