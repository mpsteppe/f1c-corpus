// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448E90
// Canonical corpus name: AABBCollisionBodyInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AABBCollisionBodyInitializer_00448e90.c

void UnknownObject::AABBCollisionBodyInitializer()
{
    // AABB collision body initializer. Zeroes the 24-byte header of the this object, then sets four trailing fields to defaults: the next/link pointer at +0x1C to 0, the body type byte at +0x19 to 0, the word handle at +0x1A to -1 (INVALID sentinel) and the active flag byte at +0x18 to 1. Returns the this pointer.
    // CALL: memset(this, 0, 0x18) zeroes the 24-byte header region of the object. [source:raw]
    // ASSIGNMENT: Write 0 into the dword at this + 28 (+0x1C): next/free-list pointer set to null. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Write 0 into the byte at this + 25 (+0x19): body type set to default 0. [field:this:0x00000019, source:raw]
    // ASSIGNMENT: Write -1 (INVALID sentinel) into the word at this + 26 (+0x1A): handle/index set to invalid. [field:this:0x0000001A, source:raw]
    // ASSIGNMENT: Write 1 into the byte at this + 24 (+0x18): active/in-use flag enabled. [field:this:0x00000018, source:raw]
    // RETURN: Return the this pointer (constructed object). [function:0x00448E90, source:raw]

    // Conservative worker pseudocode:
    //   int sub_448E90(int this) {
    //     memset((void *)this, 0, 0x18);
    //     *(_DWORD *)(this + 28) = 0;
    //     *(_BYTE *)(this + 25) = 0;
    //     *(_WORD *)(this + 26) = -1;
    //     *(_BYTE *)(this + 24) = 1;
    //     return this;
    //   }
    // UNRESOLVED: Semantic roles of the fields (active flag, type byte, invalid handle, next pointer) are DERIVED from the legacy name, not independently confirmed.
    // UNRESOLVED: The object identity and its relationship to the broad-phase collision proxy pool are unresolved.
    // UNRESOLVED: Callers span several collision subsystems (allocator, mesh adjacency, stream lookup, capsule pipeline); the shared allocation context is not evidenced.
}
