// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053AD50
// Canonical corpus name: sub_53AD50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53AD50_0053ad50.c

void UnknownObject::MultiFieldFreeCleanup()
{
    // Object destructor-style cleanup: restores the vtable pointer at this+0x0 to off_5B8910, then frees the three heap buffers at this[4] (0x10), this[8] (0x20) and this[12] (0x30) through FreeWrapper_7bcf, then invokes EmptyStub_0170. Called by GlobalResourceCleanup.
    // ASSIGNMENT: Set vtable field at this+0x0 to off_5B8910 (destructed-state vtable). [field:this:0x00000000, global:0x005B8910]
    // CALL: Free heap buffer at this[4] (offset 0x10) via FreeWrapper_7bcf. [field:this:0x00000010, callee:0x00587BCF]
    // CALL: Free heap buffer at this[8] (offset 0x20) via FreeWrapper_7bcf. [field:this:0x00000020, callee:0x00587BCF]
    // CALL: Free heap buffer at this[12] (offset 0x30) via FreeWrapper_7bcf. [field:this:0x00000030, callee:0x00587BCF]
    // CALL: Invoke EmptyStub_0170 after the buffer frees (callee named in raw source; absent from the callee evidence list). [source:raw]

    // Conservative worker pseudocode:
    //   this->vtable = off_5B8910;
    //   FreeWrapper_7bcf(this[4]);
    //   FreeWrapper_7bcf(this[8]);
    //   FreeWrapper_7bcf(this[12]);
    //   EmptyStub_0170();
    // UNRESOLVED: EmptyStub_0170 is called at the end but has no callee evidence entry in the packet.
    // UNRESOLVED: Buffer roles at offsets 0x10, 0x20 and 0x30 (what each allocation holds) are unknown.
    // UNRESOLVED: Local v2 holds this[4] before the vtable write and is freed; its distinct purpose is unknown.
}
