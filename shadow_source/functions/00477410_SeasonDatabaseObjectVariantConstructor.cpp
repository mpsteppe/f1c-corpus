// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477410
// Canonical corpus name: sub_477410
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_477410_00477410.c

void UnknownObject::SeasonDatabaseObjectVariantConstructor()
{
    // Constructor for a variant season-database object. Calls the base-class large-constructor, stores the handle/ID parameter a2 at this+0x180, sets two index fields to the -1 sentinel, and installs the vtable pointer off_5A4600. The variant is identified only by the calling factory, not by any field here.
    // CALL: Invoke the base-class large constructor (LargeConstructor, 0x0048EAA0) to initialize inherited/large members before any derived fields are written. [callee:0x0048EAA0, source:raw]
    // ASSIGNMENT: Store the handle/ID parameter a2 into the derived field at this+0x180 (this[96]). [field:this:0x00000180, source:raw]
    // ASSIGNMENT: Initialize the index field at this+0x184 (this[97]) to the sentinel value -1. [field:this:0x00000184, source:raw]
    // ASSIGNMENT: Initialize the index field at this+0x188 (this[98]) to the sentinel value -1. [field:this:0x00000188, source:raw]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_5A4600, binding the object's virtual dispatch table. [field:this:0x00000000, global:0x005A4600, source:raw]
    // RETURN: Return the constructed object pointer (this). [source:raw]

    // Conservative worker pseudocode:
    //   void* sub_477410(void* this, int a2) {
    //     LargeConstructor();
    //     this[96] = a2;
    //     this[97] = -1;
    //     this[98] = -1;
    //     *(void**)this = &off_5A4600;
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the stored parameter a2 (a handle/ID) and of the two -1 sentinel index fields is not established by this function alone.
    // UNRESOLVED: Concrete class identity remains unknown; the season-database naming comes from the caller SeasonDatabaseObjectFactory (0x0047F440).
}
