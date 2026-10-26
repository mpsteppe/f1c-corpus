// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046A4E0
// Canonical corpus name: ConstructorWithVTableAndSubInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithVTableAndSubInit_0046a4e0.c

void UnknownObject::ConstructorWithVTableAndSubInit()
{
    // Constructor that calls base/sub-object initializer sub_4893C0, zeros field this+0x174, sets a -1 sentinel at this+0x178, installs the vtable off_59F938 at offset 0, then clears the byte at this+0xE0 to 0 via ByteSetterAt0xe0 before returning this. Straight-line, no branches. Called once from SeasonDatabaseObjectFactory.
    // CALL: Invoke sub_4893C0 to run the base/sub-object constructor on this [callee:0x004893C0, source:raw]
    // ASSIGNMENT: Set field this+0x174 (this+372) to 0 [field:this:0x00000174, source:raw]
    // ASSIGNMENT: Set field this+0x178 (this+376) to -1 (packet init literal 18446744073709551615, max sentinel) [field:this:0x00000178, source:raw]
    // ASSIGNMENT: Install the vtable pointer: write off_59F938 into the object at offset 0 [field:this:0x00000000, global:0x0059F938, source:raw]
    // CALL: Invoke ByteSetterAt0xe0 to clear the byte at this+0xE0 to 0 [callee:0x0048A3B0, source:raw]
    // RETURN: Return this; the constructor is invoked by SeasonDatabaseObjectFactory for a season database object [function:0x0046A4E0, caller:0x0047F440, source:raw]

    // Conservative worker pseudocode:
    //   int ConstructorWithVTableAndSubInit(int this) {
    //     sub_4893C0(this);
    //     *(this + 0x174) = 0;
    //     *(this + 0x178) = -1;
    //     *(this + 0x0) = &off_59F938;
    //     ByteSetterAt0xe0((byte*)this, 0);
    //     return this;
    //   }
    // UNRESOLVED: Semantic role of sub_4893C0 as a base/sub-object initializer is DERIVED from existing analysis, not independently confirmed
    // UNRESOLVED: Purpose of the -1 sentinel at this+0x178 and of clearing the byte at this+0xE0 is not established from this packet
}
