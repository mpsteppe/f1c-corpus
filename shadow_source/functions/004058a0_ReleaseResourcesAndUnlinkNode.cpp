// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004058A0
// Canonical corpus name: ObjectConstructorWithVTableAndSubFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithVTableAndSubFree_004058a0.c

void UnknownObject::ReleaseResourcesAndUnlinkNode()
{
    // Object teardown helper: installs the initial vtable, releases the audio resource, removes this object's node from a keyed linked list, swaps to a second vtable, then frees the child allocation at this+0x4 when it is non-null.
    // ASSIGNMENT: Install initial vtable pointer off_59E490 at this+0x0. [field:this:0x00000000, global:0x0059E490, source:raw]
    // CALL: Release the audio resource associated with this object. [callee:0x00405B00, source:raw]
    // CALL: Remove this object's node from the linked list key lookup and capture its result. [callee:0x00407BE0, source:raw]
    // ASSIGNMENT: Swap the vtable pointer at this+0x0 to off_59E4B4. [field:this:0x00000000, global:0x0059E4B4, source:raw]
    // GUARD: Guard on the child pointer at this+0x4 (this[1]) being non-null. [field:this:0x00000004, source:raw]
    // CALL: When the guard passes, free the child allocation at this+0x4 via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000004, source:raw]
    // RETURN: Return the saved result (the free wrapper result when the guard passed, otherwise the linked-list removal result). [source:raw]

    // Conservative worker pseudocode:
    //   void* sub_4058A0(int* this) {
    //     this[0] = &off_59E490;
    //     AudioResourceRelease();
    //     int result = LinkedListNodeRemovalByKey(this);
    //     this[0] = &off_59E4B4;
    //     if (this[1] != 0) return FreeWrapper_7bcf(this[1]);
    //     return result;
    //   }
    // UNRESOLVED: The two distinct vtable objects off_59E490 and off_59E4B4 are identified only by address; their class identities are unverified.
    // UNRESOLVED: The meaning of the integer returned by LinkedListNodeRemovalByKey is not established here.
}
