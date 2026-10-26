// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485900
// Canonical corpus name: DestructorWithConditionalFree_5900
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFree_5900_00485900.c

void UnknownObject::DualSubObjectDestructor()
{
    // Destructor: frees buffer pointers at this+340 and this+280 when non-null, runs ConditionalDualCleanup on sub-objects at this+288 and this+224, chains to base-class destructor sub_485EB0, and frees self via FreeWrapper_7bcf when flag a2 bit 0 is set. Returns this. Class identity and full field layout are unknown.
    // GUARD: Guard: read pointer at this+340; only freed when non-null. [source:raw, field:this:0x00000154]
    // CALL: FreeWrapper_7bcf on the buffer pointer stored at this+340. [source:raw, callee:0x00587BCF, field:this:0x00000154]
    // CALL: ConditionalDualCleanup on the two-field sub-object embedded at this+288. [source:raw, callee:0x00499B50]
    // GUARD: Guard: read pointer at this+280; only freed when non-null. [source:raw, field:this:0x00000118]
    // CALL: FreeWrapper_7bcf on the buffer pointer stored at this+280. [source:raw, callee:0x00587BCF, field:this:0x00000118]
    // CALL: ConditionalDualCleanup on the two-field sub-object embedded at this+224. [source:raw, callee:0x00499B50]
    // CALL: Call base-class destructor sub_485EB0 on this to continue the destruction chain. [source:raw, callee:0x00485EB0]
    // GUARD: Guard: if (a2 & 1) != 0, this object was heap-allocated and must be freed. [source:raw]
    // CALL: FreeWrapper_7bcf(this) deallocates the object when the flag bit is set. [source:raw, callee:0x00587BCF]
    // RETURN: Return this (thiscall convention returns the object address). [source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall DualSubObjectDestructor(this, char a2) {
    //     if (*(_DWORD*)(this + 340)) FreeWrapper_7bcf(*(LPVOID*)(this + 340));
    //     ConditionalDualCleanup(this + 288);
    //     if (*(_DWORD*)(this + 280)) FreeWrapper_7bcf(*(LPVOID*)(this + 280));
    //     ConditionalDualCleanup(this + 224);
    //     sub_485EB0(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Owner class identity is unknown; the two freed pointers at this+280 and this+340 suggest owned buffers or sub-objects.
    // UNRESOLVED: Layout of the embedded sub-objects at this+224 and this+288 is only partially known via ConditionalDualCleanup.
    // UNRESOLVED: The a2 flag semantics (in-heap allocator bit vs caller-supplied destroy flag) are not established.
}
