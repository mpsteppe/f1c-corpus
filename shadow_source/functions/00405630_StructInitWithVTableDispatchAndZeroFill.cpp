// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405630
// Canonical corpus name: StructInitWithVTableDispatchAndZeroFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithVTableDispatchAndZeroFill_00405630.c

void UnknownObject::StructInitWithVTableDispatchAndZeroFill()
{
    // Resets a struct to its default state. Sets the sentinel at 0x1C to -1, zeroes the four dwords at 0x20/0x24/0x28/0x2C, runs VirtualCleanup on the sub-object at 0x30, dispatches the vtable method at slot +4 through the pointer at 0x34, zero-fills the trailing region from 0x44 for 0x2C bytes, clears the byte at 0x70, and returns 0.
    // ASSIGNMENT: Set the dword at this+0x1C to -1 (sentinel/invalid marker). [field:this:0x0000001C]
    // ASSIGNMENT: Zero the dword at this+0x20. [field:this:0x00000020]
    // ASSIGNMENT: Zero the dword at this+0x24. [field:this:0x00000024]
    // ASSIGNMENT: Zero the dword at this+0x28. [field:this:0x00000028]
    // ASSIGNMENT: Zero the dword at this+0x2C. [field:this:0x0000002C]
    // CALL: VirtualCleanup on the sub-object at this+0x30. [callee:0x0052D990, source:raw]
    // CALL: Indirect vtable dispatch: load the vtable pointer at this+0x34 and call the method at slot +4 with this+0x34 as receiver. [field:this:0x00000034, field:*(this+0x34):0x00000004]
    // CALCULATION: memset zero-fill from this+0x44 for 0x2C bytes, covering the trailing region through 0x70. [source:raw]
    // ASSIGNMENT: Clear the byte at this+0x70 to 0. [field:this:0x00000070]
    // RETURN: Return 0 as the reset result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_405630(char* this) {
    //     *(int*)(this + 0x1C) = -1;
    //     *(int*)(this + 0x20) = 0;
    //     *(int*)(this + 0x24) = 0;
    //     *(int*)(this + 0x28) = 0;
    //     *(int*)(this + 0x2C) = 0;
    //     VirtualCleanup(this + 0x30);
    //     (*(void(__thiscall**)(int))(*(int*)(this + 0x34) + 4))(this + 0x34);
    //     memset(this + 0x44, 0, 0x2C);
    //     this[0x70] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The concrete class owning this reset is unknown; caller context (ConditionalCleanupWithDualFree, BinaryDataDeserialization) suggests a deserialization target object.
    // UNRESOLVED: The identity of the vtable method dispatched at slot +4 is unknown.
    // UNRESOLVED: The relationship between the sub-object at 0x30 and the vtable pointer at 0x34 is not determined.
}
