// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540EB0
// Canonical corpus name: ObjectResetWithVirtualRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectResetWithVirtualRelease_00540eb0.c

void UnknownObject::ObjectResetWithVirtualRelease()
{
    // Object reset paired with a virtual release. When the secondary object a2 is present and holds a releaseable resource at a2+0x20, repeatedly call ArithmeticComparison_0f90(a2) while the reference count at a2+0x14 is positive, zero that reference count, invoke the resource object's virtual release method (vtable entry at offset 8, stdcall) and store its result into this+0, then clear the resource slot at a2+0x20.
    // GUARD: Gate the whole reset on a2 being non-null and the resource slot *(a2 + 32) being non-null [source:raw]
    // LOOP: While the reference count *(int*)(a2 + 20) is greater than 0, call ArithmeticComparison_0f90(a2) to drain outstanding references [callee:0x00540F90, source:raw]
    // ASSIGNMENT: v3 = *(a2 + 32) reads the resource object, then the reference count *(a2 + 20) is zeroed [source:raw]
    // CALL: Invoke the resource object's virtual release: stdcall through the vtable at *(v3) entry 8, and store its result into *this [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the resource slot: *(a2 + 32) = 0 [source:raw]
    // RETURN: Returns void; called from eight teardown/cleanup routines (RenderTargetCleanup, AudioResourceFree, SubBufferFree, AudioResourceCleanup, ConditionalFreeByFlag_28b0, ConditionalResourceCleanup_3310, sub_553370, ResourceTeardownWithStateArrayReset) [caller:0x0053F270, caller:0x00540CB0, caller:0x00541420, caller:0x00552760, caller:0x005528B0, caller:0x00553310, caller:0x00553370, caller:0x00558990, function:0x00540EB0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 && *(int*)(a2 + 32)) {
    //     while (*(int*)(a2 + 20) > 0) ArithmeticComparison_0f90(a2);
    //     v3 = *(int*)(a2 + 32);
    //     *(int*)(a2 + 20) = 0;
    //     *this = vtbl(v3)[8 / 4](v3);
    //     *(int*)(a2 + 32) = 0;
    //   }
    //   return;
    // UNRESOLVED: The a2 object layout (resource pointer at +0x20, reference count at +0x14) is accessed by raw offsets in the decompiled source and is not defined as packet fields
    // UNRESOLVED: The resource object type behind the virtual release call (vtable entry at offset 8) is unknown
    // UNRESOLVED: The prelabel is a cluster_copy from structural twin 0040d470 (DERIVED trust), but the owner trust in the packet remains UNKNOWN and is kept as such
}
