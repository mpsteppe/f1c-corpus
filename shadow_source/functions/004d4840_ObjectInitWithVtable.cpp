// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D4840
// Canonical corpus name: ObjectInit_4840
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInit_4840_004d4840.c

void UnknownObject::ObjectInitWithVtable()
{
    // Object constructor: installs the class dispatch (vtable) pointer off_5ACF08 at this+0x0, then zero-initializes three dword fields at this+0x4, this+0x8 and this+0xC. Returns this.
    // ASSIGNMENT: Set vtable pointer at this+0x0 to the class dispatch table off_5ACF08. [field:this:0x00000000, global:0x005ACF08, source:raw]
    // ASSIGNMENT: Zero-initialize dword field at this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero-initialize dword field at this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero-initialize dword field at this+0xC. [field:this:0x0000000C, source:raw]
    // RETURN: Return this pointer. [function:0x004D4840, source:raw]

    // Conservative worker pseudocode:
    //   this->vtable = off_5ACF08;
    //   this->field_0x4 = 0;
    //   this->field_0x8 = 0;
    //   this->field_0xC = 0;
    //   return this;
    // UNRESOLVED: The class owning this vtable and the meaning of the three zeroed fields are not evidenced by the packet.
}
