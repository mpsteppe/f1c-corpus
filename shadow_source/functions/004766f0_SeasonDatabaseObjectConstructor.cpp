// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004766F0
// Canonical corpus name: ShortComputation_66f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_66f0_004766f0.c

void UnknownObject::SeasonDatabaseObjectConstructor()
{
    // Constructor for an object holding a season/context identifier. Calls LargeConstructor for base/member initialization, sets the vtable pointer *this to &off_5A44A0, stores the parameter a2 at this[96] (this+0x180), and initializes this[97] (this+0x184) and this[99] (this+0x18C) to -1 with this[98] (this+0x188) to 0. Returns the constructed this pointer. Existing analysis interprets it as a season database object constructor based on its caller SeasonDatabaseObjectFactory.
    // CALL: LargeConstructor() performs base class / large member initialization before the derived fields are set. [callee:0x0048EAA0, source:raw]
    // ASSIGNMENT: Set this[99] (this+0x18C) to -1 (sentinel/invalid index). [field:this:0x0000018C, source:raw]
    // ASSIGNMENT: Set this[98] (this+0x188) to 0 (counter or null handle). [field:this:0x00000188, source:raw]
    // ASSIGNMENT: Set this[97] (this+0x184) to -1 (sentinel/invalid index). [field:this:0x00000184, source:raw]
    // ASSIGNMENT: Set the vtable pointer *this to &off_5A44A0. [field:this:0x00000000, global:0x005A44A0, source:raw]
    // ASSIGNMENT: Store the identifier parameter a2 into this[96] (this+0x180). [field:this:0x00000180, source:raw]
    // RETURN: Return the constructed this pointer. [source:raw]
    // CALL: Invoked from SeasonDatabaseObjectFactory (0x0047F440) to construct the season database object. [caller:0x0047F440]

    // Conservative worker pseudocode:
    //   DWORD* sub_4766F0(DWORD* this, int a2) {
    //     LargeConstructor();
    //     this[99] = -1;
    //     this[98] = 0;
    //     this[97] = -1;
    //     *this = &off_5A44A0;
    //     this[96] = a2;
    //     return this;
    //   }
    // UNRESOLVED: The 'SeasonDatabaseObject' interpretation is DERIVED from the existing analysis and the caller name SeasonDatabaseObjectFactory (0x0047F440); the packet's canonical name is the generated ShortComputation_66f0.
    // UNRESOLVED: off_5A44A0 is treated as a vtable pointer (DERIVED); the packet does not prove its contents.
    // UNRESOLVED: Meaning of the -1 sentinel / 0 initialization and of the stored identifier a2 is not stated by the packet.
}
