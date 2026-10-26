// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553310
// Canonical corpus name: ConditionalResourceCleanup_3310
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalResourceCleanup_3310_00553310.c

void UnknownObject::ConditionalResourceCleanup_3310()
{
    // Resource cleanup driven by type flags. When bit 0 or bit 1 of the flags at this+0x00 is set, the raw pointer at this+0x18 is freed through FreeWrapper_7bcf and zeroed. Independently of the flags, a non-null pointer at this+0x14 is released through ObjectResetWithVirtualRelease(dword_8B78A0, this+0x14), freed if it survives the reset, and zeroed. Ends with a call to EmptyStub_0170. Called from ResourceCascadeCleanup.
    // GUARD: Proceed to the offset 0x18 cleanup only when bit 0 or bit 1 of the flag word at this+0x00 is set [field:this:0x00000000, source:raw]
    // GUARD: Within the flag block, free the secondary resource slot only when the pointer at this+0x18 is non-null [field:this:0x00000018, callee:0x00587BCF]
    // CALL: Free the pointer at this+0x18 through the FreeWrapper_7bcf memory free wrapper [field:this:0x00000018, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the secondary slot: *(this + 0x18) = 0 [field:this:0x00000018]
    // GUARD: Process the primary slot only when the pointer at this+0x14 is non-null [field:this:0x00000014]
    // CALL: Release the primary resource: ObjectResetWithVirtualRelease(dword_8B78A0, *(this + 0x14)) [callee:0x00540EB0, global:0x008B78A0, field:this:0x00000014]
    // GUARD: After the reset, free the primary slot again only if the pointer at this+0x14 is still non-null [field:this:0x00000014, callee:0x00587BCF]
    // CALL: Free the pointer at this+0x14 through the FreeWrapper_7bcf memory free wrapper [field:this:0x00000014, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the primary slot: *(this + 0x14) = 0 [field:this:0x00000014]
    // CALL: Invoke EmptyStub_0170() as the final step of the routine [function:0x00553310, source:raw]
    // RETURN: Returns void; invoked from the ResourceCascadeCleanup teardown path [function:0x00553310, caller:0x005539F0]

    // Conservative worker pseudocode:
    //   if ((*(this) & 1) || (*(this) & 2)) {
    //     if (*(this + 0x18)) FreeWrapper_7bcf(*(this + 0x18));
    //     *(this + 0x18) = 0;
    //   }
    //   if (*(this + 0x14)) {
    //     ObjectResetWithVirtualRelease(dword_8B78A0, *(this + 0x14));
    //     if (*(this + 0x14)) FreeWrapper_7bcf(*(this + 0x14));
    //     *(this + 0x14) = 0;
    //   }
    //   EmptyStub_0170();
    // UNRESOLVED: EmptyStub_0170 appears in the raw source but has no packet callee entry, so its address and semantics are not evidenced
    // UNRESOLVED: Meaning of flag bits 0 and 1 at this+0x00 and the object types of the resource slots are unknown
    // UNRESOLVED: The identity and role of the global dword_8B78A0 passed to ObjectResetWithVirtualRelease are not evidenced
}
