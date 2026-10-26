// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560E50
// Canonical corpus name: MultiFieldObjectDestructorWithCleanupCalls
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldObjectDestructorWithCleanupCalls_00560e50.c

void UnknownObject::MultiFieldObjectDestructorWithCleanupCalls()
{
    // Destructor that frees three allocated sub-objects at this+0xC, this+0x1C and this+0x20, each null-guarded. The first two are freed through EmptyStub_7470 followed by FreeWrapper_7bcf (with an additional EmptyStub_0170 call before the first), and the third through ConditionalFreeOfField followed by FreeWrapper_7bcf. Called by F_3DSoundSourceDestructor (00545150), consistent with 3D sound source sub-object teardown.
    // GUARD: If the sub-object pointer at this+0xC is non-null, enter the first cleanup block [field:this:0x0000000C, source:raw]
    // CALL: Invoke the EmptyStub_0170 cleanup stub with no arguments at the start of the first block [callee:0x004B0170, source:raw]
    // GUARD: Re-read the first sub-object pointer into v2 and proceed only while it is non-null [field:this:0x0000000C, source:raw]
    // CALL: Invoke EmptyStub_7470 with the first sub-object pointer (this+0xC) as its argument [callee:0x00557470, field:this:0x0000000C, source:raw]
    // CALL: Free the first sub-object via FreeWrapper_7bcf(v2) [callee:0x00587BCF, source:raw]
    // GUARD: If the second sub-object pointer at this+0x1C is non-null, free it [field:this:0x0000001C, source:raw]
    // CALL: Invoke EmptyStub_7470 with the second sub-object pointer (this+0x1C) as its argument [callee:0x00557470, field:this:0x0000001C, source:raw]
    // CALL: Free the second sub-object via FreeWrapper_7bcf(v3) [callee:0x00587BCF, source:raw]
    // GUARD: If the third sub-object pointer at this+0x20 is non-null, free it [field:this:0x00000020, source:raw]
    // CALL: Invoke ConditionalFreeOfField on the third sub-object pointer (this+0x20) [callee:0x00560B90, source:raw]
    // CALL: Free the third sub-object via FreeWrapper_7bcf(v4) [callee:0x00587BCF, source:raw]
    // CALL: Invoked by F_3DSoundSourceDestructor (00545150) as part of 3D sound source teardown [caller:0x00545150, source:raw]

    // Conservative worker pseudocode:
    //   if (*(this + 12)) {
    //     EmptyStub_0170();
    //     v2 = *(void**)(this + 12);
    //     if (v2) {
    //       EmptyStub_7470(*(void**)(this + 12));
    //       FreeWrapper_7bcf(v2);
    //     }
    //   }
    //   v3 = *(void**)(this + 28);
    //   if (v3) {
    //     EmptyStub_7470(*(void**)(this + 28));
    //     FreeWrapper_7bcf(v3);
    //   }
    //   v4 = *(LPVOID**)(this + 32);
    //   if (v4) {
    //     ConditionalFreeOfField(v4);
    //     FreeWrapper_7bcf(v4);
    //   }
    // UNRESOLVED: The owner class is unknown; the 3D sound source attribution is inherited from the caller name and is not evidenced inside this function
    // UNRESOLVED: The different teardown shape of the third block (ConditionalFreeOfField before free, no EmptyStub_7470) suggests the sub-objects belong to distinct types, but the types are not documented
    // UNRESOLVED: Why the first block invokes EmptyStub_0170 while the others do not is not determinable
}
