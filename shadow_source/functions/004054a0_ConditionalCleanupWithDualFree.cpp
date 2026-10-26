// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004054A0
// Canonical corpus name: ConditionalCleanupWithDualFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalCleanupWithDualFree_004054a0.c

void UnknownObject::ConditionalCleanupWithDualFree()
{
    // __thiscall cleanup that runs a vtable-backed sub-struct init/zero-fill, conditionally closes a file handle stored at this+0xC (zeroing it afterward), conditionally frees a heap buffer stored at this+0x18, then re-initializes the struct via CameraViewStructInitializer and returns its result. Used by the multi-stage cleanup path that owns this object.
    // CALL: Unconditionally call StructInitWithVTableDispatchAndZeroFill (0x00405630) on entry to initialize a vtable-backed sub-struct and zero-fill it. [callee:0x00405630, source:raw]
    // GUARD: Guard on this+0xC (file handle) being non-null before closing it. [field:this:0x0000000C, source:raw]
    // CALL: When the guard passes, close the file handle with FileCloseWithLock (0x00587D02) passing this+0xC. [callee:0x00587D02, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set this+0xC = 0 after the handle has been closed. [field:this:0x0000000C, source:raw]
    // GUARD: Guard on this+0x18 (heap buffer pointer) being non-null before freeing it. [field:this:0x00000018, source:raw]
    // CALL: When the guard passes, free the buffer with FreeWrapper_7bcf (0x00587BCF) passing this+0x18. [callee:0x00587BCF, field:this:0x00000018, source:raw]
    // CALL: Re-initialize the struct via CameraViewStructInitializer(this) and return its result; the target address of CameraViewStructInitializer is not present in the packet's callee evidence. [source:raw]
    // RETURN: Return the result of CameraViewStructInitializer. [source:raw]
    // CALL: Called by MultiStageCleanupWithFree (0x00405410) as the final cleanup stage of its owning object. [caller:0x00405410, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4054A0(int this) {
    //     StructInitWithVTableDispatchAndZeroFill();
    //     if (*(int*)(this + 0xC)) { FileCloseWithLock(*(int*)(this + 0xC)); *(int*)(this + 0xC) = 0; }
    //     if (*(void**)(this + 0x18)) FreeWrapper_7bcf(*(void**)(this + 0x18));
    //     return CameraViewStructInitializer(this);
    //   }
    // UNRESOLVED: CameraViewStructInitializer call target has no callee evidence entry in the packet, so its address cannot be confirmed.
    // UNRESOLVED: Object type and the nature of the vtable-backed sub-struct initialized by StructInitWithVTableDispatchAndZeroFill are unknown.
    // UNRESOLVED: Purpose of the buffer freed at this+0x18 (read-only here, so its initial value is set elsewhere).
}
