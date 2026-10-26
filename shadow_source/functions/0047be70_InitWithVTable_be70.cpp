// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BE70
// Canonical corpus name: InitWithVTable_be70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitWithVTable_be70_0047be70.c

void UnknownObject::InitWithVTable_be70()
{
    // Object construction: runs the base initializer sub_4893C0(this), then installs the vtable pointer off_5A6788 into this[0], zero-initializes the field at offset 0x174, and returns the constructed object pointer. No guards; unconditional sequence. Called from SeasonDatabaseObjectFactory on its factory-init path.
    // CALL: Run the base initializer sub_4893C0(this) before setting any vtable/state. [callee:0x004893C0, source:raw]
    // ASSIGNMENT: Install the vtable: this[0] = &off_5A6788. [field:this:0x00000000, global:0x005A6788, source:raw]
    // ASSIGNMENT: Zero-initialize this[93] (offset 0x174). [field:this:0x00000174, source:raw]
    // RETURN: Return the constructed object pointer (this). [source:raw]
    // CALL: Called from SeasonDatabaseObjectFactory (0x0047F440) during its object-factory init path. [caller:0x0047F440, source:raw]

    // Conservative worker pseudocode:
    //   InitWithVTable_be70(this) {
    //     sub_4893C0(this);
    //     this[0] = &off_5A6788;
    //     this[93] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Object type and layout behind this are unknown (owner UNKNOWN); off_5A6788 is only DERIVED as a vtable by the legacy analysis.
    // UNRESOLVED: Role of the zeroed field at offset 0x174 (counter or flag) is unknown.
    // UNRESOLVED: Base initializer sub_4893C0 is named from the fill (DERIVED); its contract is not confirmed here.
}
