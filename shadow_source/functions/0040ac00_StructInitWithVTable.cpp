// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040AC00
// Canonical corpus name: StructInitWithVTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithVTable_0040ac00.c

void UnknownObject::StructInitWithVTable()
{
    // Struct constructor/reset: installs the vtable pointer off_59E678 at this+0x0, zeroes the five dword fields at this+0x4 through this+0x14, and returns the this pointer. No guard conditions; every write executes unconditionally. Invoked by SceneFileLoadByCurrentIndex (0x0040C240).
    // ASSIGNMENT: Install the vtable pointer off_59E678 (per existing analysis VTable_UIObject_59E678) at this+0x0. [global:0x0059E678, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x4 (this[1]). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x8 (this[2]). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero the dword at this+0xC (this[3]). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x10 (this[4]). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x14 (this[5]). [field:this:0x00000014, source:raw]
    // RETURN: Return the this pointer as the result of the constructor. [source:raw, function:0x0040AC00]

    // Conservative worker pseudocode:
    //   _DWORD* sub_40AC00(_DWORD* this) {
    //     this[0] = off_59E678;
    //     this[1] = 0;
    //     this[2] = 0;
    //     this[3] = 0;
    //     this[4] = 0;
    //     this[5] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Concrete class of `this` is unknown (UnknownObject). The installed vtable off_59E678 is named VTable_UIObject_59E678 only at DERIVED trust in existing analysis.
    // UNRESOLVED: Nothing in this function initializes fields beyond +0x14; no later members of the object are attested.
    // UNRESOLVED: The role of the constructed object in the scene-load path of caller SceneFileLoadByCurrentIndex is not established.
}
