// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046A220
// Canonical corpus name: ObjectConstructorWithVTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithVTable_0046a220.c

void UnknownObject::ObjectConstructorWithVTable()
{
    // Constructor that runs the shared base initializer ObjectConstructorWithZeroedFields, then writes two zeroed fields (this+0x344, this+0x348), sets a -1 sentinel at this+0x34C, and installs the vtable off_59F878 at offset 0 before returning this. Straight-line, no branches. Called once from SeasonDatabaseObjectFactory.
    // CALL: Invoke ObjectConstructorWithZeroedFields to perform shared base initialization (zeroing the base fields) before the derived fields are set [callee:0x0048C9F0, source:raw]
    // ASSIGNMENT: Set field this+0x344 (this[209]) to 0 [field:this:0x00000344, source:raw]
    // ASSIGNMENT: Set field this+0x348 (this[210]) to 0 [field:this:0x00000348, source:raw]
    // ASSIGNMENT: Set field this+0x34C (this[211]) to -1 (0xFFFFFFFF sentinel, packet init literal 18446744073709551615) [field:this:0x0000034C, source:raw]
    // ASSIGNMENT: Install the vtable pointer: write off_59F878 into the object at offset 0 [field:this:0x00000000, global:0x0059F878, source:raw]
    // RETURN: Return this; the constructor is invoked by SeasonDatabaseObjectFactory for a season database object [function:0x0046A220, caller:0x0047F440, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_46A220(void* this) {
    //     ObjectConstructorWithZeroedFields(this);
    //     *(this + 0x344) = 0;
    //     *(this + 0x348) = 0;
    //     *(this + 0x34C) = -1;
    //     *(this + 0x0) = &off_59F878;
    //     return this;
    //   }
    // UNRESOLVED: The concrete object type and the purpose of the -1 sentinel at this+0x34C are not established from this packet
    // UNRESOLVED: Semantic role of fields this+0x344 and this+0x348 (both zeroed) is unknown
}
