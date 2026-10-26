// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E360
// Canonical corpus name: UtilityFunction_e360
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_e360_0048e360.c

void UnknownObject::FontResourceDestructor()
{
    // Destructor for a font resource object. Reads a Bink video resource handle at this+0xE4, resets the vtable pointer at this+0x0 to off_5AC490, then conditionally frees the Bink resource via ConditionalFreeWithBinkClose when the handle is non-null and frees a secondary allocation at this+0xFC via FreeWrapper_7bcf when non-null. Finally delegates to a base-class teardown routine (InitWithVTableCleanup) and returns its result.
    // ASSIGNMENT: Read the Bink video resource handle from field this+0xE4 into a local (v2). [field:this:0x000000E4, source:raw]
    // ASSIGNMENT: Reset the vtable pointer at this+0x0 to the class vtable off_5AC490. [field:this:0x00000000, global:0x005AC490, source:raw]
    // GUARD: If the Bink resource handle at this+0xE4 is non-null, close and free it via ConditionalFreeWithBinkClose. [field:this:0x000000E4, callee:0x00551F80, source:raw]
    // GUARD: If the secondary allocation at this+0xFC is non-null, release it via FreeWrapper_7bcf. [field:this:0x000000FC, callee:0x00587BCF, source:raw]
    // CALL: Delegate to the base-class teardown routine (InitWithVTableCleanup) with the object pointer. [source:raw]
    // RETURN: Return the result of the base teardown call. [source:raw]

    // Conservative worker pseudocode:
    //   int Destructor(void* this) {
    //     void* bink = *(void**)((char*)this + 228);
    //     *(void**)this = &off_5AC490;
    //     if (bink) ConditionalFreeWithBinkClose(bink);
    //     if (*(void**)((char*)this + 252)) FreeWrapper_7bcf(*(void**)((char*)this + 252));
    //     return InitWithVTableCleanup(this);
    //   }
    // UNRESOLVED: The concrete owner class is unknown; this+0x0 vtable off_5AC490 is not resolved to a named type.
    // UNRESOLVED: Global dword_8AFE64 appears in static analysis of this function but not in the raw body; its role here is unconfirmed.
    // UNRESOLVED: The base-class teardown routine InitWithVTableCleanup is not part of this packet's callee set and its contract is unverified.
}
