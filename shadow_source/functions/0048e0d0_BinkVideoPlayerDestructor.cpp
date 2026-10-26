// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E0D0
// Canonical corpus name: sub_48E0D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48E0D0_0048e0d0.c

void UnknownObject::BinkVideoPlayerDestructor()
{
    // Destructor for a media player object. Reads the Bink video resource handle at this+0xE0, resets the vtable pointer at this+0x0 to off_5AC3E0, then conditionally frees the Bink resource via ConditionalFreeWithBinkClose when the handle is non-null and frees a secondary heap allocation at this+0xE8 via FreeWrapper_7bcf when non-null. Finally delegates to a base-class teardown routine (sub_485EB0) and returns its result.
    // ASSIGNMENT: Read the Bink video resource handle from field this+0xE0 into a local (v2). [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Reset the vtable pointer at this+0x0 to the class vtable off_5AC3E0. [field:this:0x00000000, global:0x005AC3E0, source:raw]
    // GUARD: If the Bink resource handle at this+0xE0 is non-null, close and free it via ConditionalFreeWithBinkClose. [field:this:0x000000E0, callee:0x00551F80, source:raw]
    // GUARD: If the secondary allocation at this+0xE8 is non-null, release it via FreeWrapper_7bcf. [field:this:0x000000E8, callee:0x00587BCF, source:raw]
    // CALL: Delegate to the base-class teardown routine (sub_485EB0) with the object pointer. [source:raw]
    // RETURN: Return the result of the base teardown call; invoked from the outer destructor DestructorWithConditionalFree_e0b0. [caller:0x0048E0B0, source:raw]

    // Conservative worker pseudocode:
    //   int Destructor(void* this) {
    //     void* bink = *(void**)((char*)this + 224);
    //     *(void**)this = &off_5AC3E0;
    //     if (bink) ConditionalFreeWithBinkClose(bink);
    //     if (*(void**)((char*)this + 232)) FreeWrapper_7bcf(*(void**)((char*)this + 232));
    //     return BaseTeardown(this);
    //   }
    // UNRESOLVED: The concrete owner class is unknown; this+0x0 vtable off_5AC3E0 is not resolved to a named type.
    // UNRESOLVED: Global dword_8AFE64 appears in static analysis of this function but not in the raw body; its role here is unconfirmed.
    // UNRESOLVED: The base-class teardown routine sub_485EB0 is not part of this packet's callee set and its contract is unverified.
}
