// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057BCE0
// Canonical corpus name: sub_57BCE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57BCE0_0057bce0.c

void UnknownObject::NetworkPhysicsDestructorChain()
{
    // Destructor for a composite network/physics/IO object. Installs the IOOps vtable (off_5B8A68) at this+0x0, tears down a network subsystem (sub_57E530, NetworkCleanup_fbe0), then walks a repeating guard-byte / HANDLE pattern: for each of eight handle slots the code closes the Win32 handle with CloseHandle when its guard byte (and the handle) are set and zeroes the slot on success. Interleaved with the handle cleanup it destroys linked-list and buffer sub-objects (LinkedBufferCleanup, sub_582CE0, sub_582A10, sub_582650, LinkedListCleanup x2, LinkedListDestroyWithVtableDestructorCall, CloseHandleWrapper + LinkedListDestructionWithVTableReleaseCall on +2760, CloseHandleWrapper + LinkedListFreeStandard on +2732, FreeIfNonNull at this+0xA78). Finally it swaps in the physics vtable off_5B8A00 at this+0x940 and chains into sub_583AE0(this), whose result is the return value.
    // ASSIGNMENT: Point the vtable slot at this+0x0 at off_5B8A68 (IOOps interface vtable). [field:this:0x00000000, global:0x005B8A68, source:raw]
    // CALL: sub_57E530() tears down an early subsystem before the network cleanup runs. [callee:0x0057E530, source:raw]
    // CALL: NetworkCleanup_fbe0(this) releases the network-facing state of the object. [callee:0x0057FBE0, source:raw]
    // GUARD: If guard byte at this+0xBF4 (this[3060]) is set and CloseHandle(handle at this+0xBEC) succeeds, zero the handle slot. [field:this:0x00000BF4, field:this:0x00000BEC, global:0x0059E1A8, source:raw]
    // CALL: LinkedBufferCleanup(this + 3020) destroys the linked buffer sub-object at this+3020. [callee:0x00582DC0, source:raw]
    // GUARD: If guard byte at this+0xBC8 (this[3016]) is set and CloseHandle(handle at this+0xBC0) succeeds, zero the handle slot. [field:this:0x00000BC8, field:this:0x00000BC0, global:0x0059E1A8, source:raw]
    // CALL: sub_582CE0(this + 2976) destroys the sub-object at this+2976. [callee:0x00582CE0, source:raw]
    // GUARD: If guard byte at this+0xB9C (this[2972]) is set and CloseHandle(handle at this+0xB94) succeeds, zero the handle slot. [field:this:0x00000B9C, field:this:0x00000B94, global:0x0059E1A8, source:raw]
    // CALL: sub_582A10(this + 2932) destroys the sub-object at this+2932. [callee:0x00582A10, source:raw]
    // GUARD: If guard byte at this+0xB70 (this[2928]) is set and CloseHandle(handle at this+0xB68) succeeds, zero the handle slot. [field:this:0x00000B70, field:this:0x00000B68, global:0x0059E1A8, source:raw]
    // CALL: sub_582650(this + 2888) destroys the sub-object at this+2888. [callee:0x00582650, source:raw]
    // GUARD: If guard byte at this+0xB44 (this[2884]) is set and CloseHandle(handle at this+0xB3C) succeeds, zero the handle slot. [field:this:0x00000B44, field:this:0x00000B3C, global:0x0059E1A8, source:raw]
    // GUARD: If guard byte at this+0xB34 (this[2868]) is set and CloseHandle(handle at this+0xB2C) succeeds, zero the handle slot. [field:this:0x00000B34, field:this:0x00000B2C, global:0x0059E1A8, source:raw]
    // CALL: LinkedListCleanup(this + 2844) destroys the linked list sub-object at this+2844. [callee:0x00581A80, source:raw]
    // GUARD: If guard byte at this+0xB18 (this[2840]) is set and CloseHandle(handle at this+0xB10) succeeds, zero the handle slot. [field:this:0x00000B18, field:this:0x00000B10, global:0x0059E1A8, source:raw]
    // CALL: LinkedListCleanup(this + 2816) destroys the linked list sub-object at this+2816. [callee:0x00581A80, source:raw]
    // GUARD: If guard byte at this+0xAFC (this[2812]) is set and CloseHandle(handle at this+0xAF4) succeeds, zero the handle slot. [field:this:0x00000AFC, field:this:0x00000AF4, global:0x0059E1A8, source:raw]
    // CALL: LinkedListDestroyWithVtableDestructorCall(this + 2788) destroys the sub-object at this+2788 through its vtable destructor. [callee:0x005819C0, source:raw]
    // CALL: CloseHandleWrapper(this + 2760) closes the handle resource of the sub-object at this+2760. [callee:0x00582310, source:raw]
    // CALL: LinkedListDestructionWithVTableReleaseCall(this + 2760) releases the same sub-object at this+2760 through its vtable. [callee:0x00581880, source:raw]
    // CALL: CloseHandleWrapper(this + 2732) closes the handle resource of the sub-object at this+2732. [callee:0x00582310, source:raw]
    // CALL: LinkedListFreeStandard(this + 2732) frees the sub-object at this+2732 with the standard list free path. [callee:0x005822B0, source:raw]
    // CALL: FreeIfNonNull(this + 0xA78) frees the allocation at this+0xA78 when it is non-null. [callee:0x00499AE0, source:raw]
    // ASSIGNMENT: Point the vtable slot at this+0x940 at off_5B8A00 (physics interface vtable) before the final cleanup chain. [field:this:0x00000940, global:0x005B8A00, source:raw]
    // RETURN: Chain into sub_583AE0(this) for final cleanup and return its result. [callee:0x00583AE0, source:raw]

    // Conservative worker pseudocode:
    //   *(void**)this = off_5B8A68;
    //   sub_57E530();
    //   NetworkCleanup_fbe0(this);
    //   if (this->flags /*+0xBF4* / && CloseHandle(this->handle /*+0xBEC* /)) this->handle = 0;
    //   LinkedBufferCleanup(this + 3020);
    //   if (this->flags /*+0xBC8* / && CloseHandle(this->handle /*+0xBC0* /)) this->handle = 0;
    //   sub_582CE0(this + 2976);
    //   if (this->flags /*+0xB9C* / && CloseHandle(this->handle /*+0xB94* /)) this->handle = 0;
    //   sub_582A10(this + 2932);
    //   if (this->flags /*+0xB70* / && CloseHandle(this->handle /*+0xB68* /)) this->handle = 0;
    //   sub_582650(this + 2888);
    //   if (this->flags /*+0xB44* / && CloseHandle(this->handle /*+0xB3C* /)) this->handle = 0;
    //   if (this->flags /*+0xB34* / && CloseHandle(this->handle /*+0xB2C* /)) this->handle = 0;
    //   LinkedListCleanup(this + 2844);
    //   if (this->flags /*+0xB18* / && CloseHandle(this->handle /*+0xB10* /)) this->handle = 0;
    //   LinkedListCleanup(this + 2816);
    //   if (this->flags /*+0xAFC* / && CloseHandle(this->handle /*+0xAF4* /)) this->handle = 0;
    //   LinkedListDestroyWithVtableDestructorCall(this + 2788);
    //   CloseHandleWrapper(this + 2760);
    //   LinkedListDestructionWithVTableReleaseCall(this + 2760);
    //   CloseHandleWrapper(this + 2732);
    //   LinkedListFreeStandard(this + 2732);
    //   FreeIfNonNull(this + 0xA78);
    //   *(void**)(this + 0x940) = off_5B8A00;
    //   return sub_583AE0(this);
    // UNRESOLVED: The owning class of this composite object is unidentified; the repeated guard-byte/HANDLE pairs (all at 4-byte stride with guard at handle+8) suggest a generated or templated member pattern but not a named type.
    // UNRESOLVED: SEH_57BCE0 (0x0059C990) is registered as the exception-handler frame for this destructor; it does not appear in the raw source text.
    // UNRESOLVED: The exact nature of each sub-object teardown (network, linked buffers, listeners at this+3020/2976/2932/2888/2844/2816/2788/2760/2732/0xA78) is inferred from the callee names only.
}
