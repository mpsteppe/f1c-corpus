// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046EEC0
// Canonical corpus name: ObjectInitWithVTableState
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithVTableState_0046eec0.c

void UnknownObject::ObjectInitWithVTableState()
{
    // Object construction: runs the base initializer sub_4893C0(this), then installs the vtable pointer off_59FED0 into this[0], initializes the signed DWORD field at offset 0x174 to -1 as a sentinel/invalid-state marker, and returns the constructed object pointer. No guards; unconditional sequence. Called from SeasonDatabaseObjectFactory on its factory-init path.
    // CALL: Run the base initializer sub_4893C0(this) before setting any vtable/state. [callee:0x004893C0, source:raw]
    // ASSIGNMENT: Install the vtable: this[0] = &off_59FED0. [field:this:0x00000000, global:0x0059FED0, source:raw]
    // ASSIGNMENT: Set this[93] (offset 0x174) to -1 as a sentinel/invalid-state marker. [field:this:0x00000174, source:raw]
    // RETURN: Return the constructed object pointer (this). [source:raw]
    // CALL: Called from SeasonDatabaseObjectFactory (0x0047F440) during its object-factory init path. [caller:0x0047F440, source:raw]

    // Conservative worker pseudocode:
    //   ObjectInitWithVTableState(this) {
    //     sub_4893C0(this);
    //     this[0] = &off_59FED0;
    //     this[93] = -1;
    //     return this;
    //   }
    // UNRESOLVED: Object type and layout behind this are unknown (owner UNKNOWN); off_59FED0 is only DERIVED as a vtable by the legacy analysis.
    // UNRESOLVED: Meaning of the sentinel -1 at offset 0x174 is unknown.
    // UNRESOLVED: Base initializer sub_4893C0 is named from the fill (DERIVED); its contract is not confirmed here.
}
